
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_HTTP_SCRIPT_H_INCLUDED_
#define _NGX_HTTP_SCRIPT_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>


typedef struct {
    /*关于pos && code: 每次调用code,都会将解析到的新的字符串放入pos指向的字符串处，
	然后将pos向后移动，下次进入的时候，会自动将数据追加到后面的。
	对于ip也是这个原理，code里面会将e->ip向后移动。移动的大小根据不同的变量类型相关。
	ip指向一快内存，其内容为变量相关的一个结构体，比如ngx_http_script_copy_capture_code_t，
	结构体之后，又是下一个ip的地址。比如移动时是这样的 :
	code = (ngx_http_script_copy_capture_code_t *) e->ip;
    e->ip += sizeof(ngx_http_script_copy_capture_code_t);//移动这么多位移。
	*/ 
    u_char                     *ip;

    u_char                     *pos;
    ngx_http_variable_value_t  *sp;//这里貌似是用sp来保存中间结果，比如保存当前这一步的进度，到下一步好用e->sp--来找到上一步的结果。

    ngx_str_t                   buf;//存放结果，也就是buffer，pos指向其中。
    ngx_str_t                   line;//记录请求行URI  e->line = r->uri;

    /* the start of the rewritten arguments */
    u_char                     *args;

    unsigned                    flushed:1;
    unsigned                    skip:1;
    unsigned                    quote:1;
    unsigned                    is_args:1;
    unsigned                    log:1;

    ngx_int_t                   status;
    ngx_http_request_t         *request;//所属的请求
} ngx_http_script_engine_t;

//参考文章：
//http://blog.csdn.net/dingyujie/article/details/7515904
typedef struct {
    ngx_conf_t                 *cf;  //配置信息
    ngx_str_t                  *source; //需要compile的字符串

    ngx_array_t               **flushes; //保存普通变量在变量表中的index 
    ngx_array_t               **lengths; //处理变量长度的处理子数组
    ngx_array_t               **values;  //处理变量内容的处理子数组

    ngx_uint_t                  variables; //普通变量的个数，而非其他三种(args变量，$n变量以及常量字符串)  
    ngx_uint_t                  ncaptures; //当前处理时，出现的$n变量的最大值，如配置的最大为$3，那么ncaptures就等于3 
    
    /* 
     * 以位移的形式保存$1,$2...$9等变量，即响应位置上置1来表示，主要的作用是为dup_capture准备， 
     * 正是由于这个mask的存在，才比较容易得到是否有重复的$n出现。 
     */  
    ngx_uint_t                  captures_mask;
    ngx_uint_t                  size;  //待compile的字符串中，”常量字符串“的总长度  

    /*  
     * 对于main这个成员，有许多要挖掘的东西。main一般用来指向一个 
     * ngx_http_script_regex_code_t的结构，那么这个main到底起到了什么作用呢？ 
     * 这里有对它进行分析。 
     */  
    void                       *main;

    unsigned                    compile_args:1; //是否需要处理请求参数 
    unsigned                    complete_lengths:1; //是否设置lengths数组的终止符，即NULL
    unsigned                    complete_values:1; //是否设置values数组的终止符 
    unsigned                    zero:1; //values数组运行时，得到的字符串是否追加'\0'结尾 
    unsigned                    conf_prefix:1; //是否在生成的文件名前，追加路径前缀
    unsigned                    root_prefix:1; //同conf_prefix 

    /* 
     * 这个标记位主要在rewrite模块里使用，在ngx_http_rewrite中， 
     * if (sc.variables == 0 && !sc.dup_capture) { 
     *     regex->lengths = NULL; 
     * } 
     * 没有重复的$n，那么regex->lengths被置为NULL，这个设置很关键，在函数 
     * ngx_http_script_regex_start_code中就是通过对regex->lengths的判断，来做不同的处理， 
     * 因为在没有重复的$n的时候，可以通过正则自身的captures机制来获取$n，一旦出现重复的， 
     * 那么pcre正则自身的captures并不能满足我们的要求，我们需要用自己handler来处理。 
     */  
    unsigned                    dup_capture:1;
    unsigned                    args:1; //待compile的字符串中是否发现了'?'
} ngx_http_script_compile_t;


typedef struct {
    ngx_str_t                   value;
    ngx_uint_t                 *flushes;
    void                       *lengths;
    void                       *values;
} ngx_http_complex_value_t;


typedef struct {
    ngx_conf_t                 *cf;
    ngx_str_t                  *value;
    ngx_http_complex_value_t   *complex_value;

    unsigned                    zero:1;
    unsigned                    conf_prefix:1;
    unsigned                    root_prefix:1;
} ngx_http_compile_complex_value_t;


typedef void (*ngx_http_script_code_pt) (ngx_http_script_engine_t *e);
typedef size_t (*ngx_http_script_len_code_pt) (ngx_http_script_engine_t *e);


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   len;
} ngx_http_script_copy_code_t;


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   index;
} ngx_http_script_var_code_t;


typedef struct {
    ngx_http_script_code_pt     code;
    ngx_http_set_variable_pt    handler;
    uintptr_t                   data;
} ngx_http_script_var_handler_code_t;


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   n;
} ngx_http_script_copy_capture_code_t;


#if (NGX_PCRE)

typedef struct {
    ngx_http_script_code_pt     code;
    ngx_http_regex_t           *regex;
    ngx_array_t                *lengths;
    uintptr_t                   size;
    uintptr_t                   status;
    uintptr_t                   next;

    uintptr_t                   test:1;
    uintptr_t                   negative_test:1;
    uintptr_t                   uri:1;
    uintptr_t                   args:1;

    /* add the r->args to the new arguments */
    uintptr_t                   add_args:1;

    uintptr_t                   redirect:1;
    uintptr_t                   break_cycle:1;

    ngx_str_t                   name;
} ngx_http_script_regex_code_t;


typedef struct {
    ngx_http_script_code_pt     code;

    uintptr_t                   uri:1;
    uintptr_t                   args:1;

    /* add the r->args to the new arguments */
    uintptr_t                   add_args:1;

    uintptr_t                   redirect:1;
} ngx_http_script_regex_end_code_t;

#endif


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   conf_prefix;
} ngx_http_script_full_name_code_t;


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   status;
    ngx_http_complex_value_t    text;
} ngx_http_script_return_code_t;


typedef enum {
    ngx_http_script_file_plain = 0,
    ngx_http_script_file_not_plain,
    ngx_http_script_file_dir,
    ngx_http_script_file_not_dir,
    ngx_http_script_file_exists,
    ngx_http_script_file_not_exists,
    ngx_http_script_file_exec,
    ngx_http_script_file_not_exec
} ngx_http_script_file_op_e;


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   op;
} ngx_http_script_file_code_t;


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   next;
    void                      **loc_conf;
} ngx_http_script_if_code_t;


typedef struct {
    ngx_http_script_code_pt     code;
    ngx_array_t                *lengths;
} ngx_http_script_complex_value_code_t;


typedef struct {
    ngx_http_script_code_pt     code;
    uintptr_t                   value;
    uintptr_t                   text_len;
    uintptr_t                   text_data;
} ngx_http_script_value_code_t;


void ngx_http_script_flush_complex_value(ngx_http_request_t *r,
    ngx_http_complex_value_t *val);
ngx_int_t ngx_http_complex_value(ngx_http_request_t *r,
    ngx_http_complex_value_t *val, ngx_str_t *value);
ngx_int_t ngx_http_compile_complex_value(ngx_http_compile_complex_value_t *ccv);
char *ngx_http_set_complex_value_slot(ngx_conf_t *cf, ngx_command_t *cmd,
    void *conf);


ngx_int_t ngx_http_test_predicates(ngx_http_request_t *r,
    ngx_array_t *predicates);
char *ngx_http_set_predicate_slot(ngx_conf_t *cf, ngx_command_t *cmd,
    void *conf);

ngx_uint_t ngx_http_script_variables_count(ngx_str_t *value);
ngx_int_t ngx_http_script_compile(ngx_http_script_compile_t *sc);
u_char *ngx_http_script_run(ngx_http_request_t *r, ngx_str_t *value,
    void *code_lengths, size_t reserved, void *code_values);
void ngx_http_script_flush_no_cacheable_variables(ngx_http_request_t *r,
    ngx_array_t *indices);

void *ngx_http_script_start_code(ngx_pool_t *pool, ngx_array_t **codes,
    size_t size);
void *ngx_http_script_add_code(ngx_array_t *codes, size_t size, void *code);

size_t ngx_http_script_copy_len_code(ngx_http_script_engine_t *e);
void ngx_http_script_copy_code(ngx_http_script_engine_t *e);
size_t ngx_http_script_copy_var_len_code(ngx_http_script_engine_t *e);
void ngx_http_script_copy_var_code(ngx_http_script_engine_t *e);
size_t ngx_http_script_copy_capture_len_code(ngx_http_script_engine_t *e);
void ngx_http_script_copy_capture_code(ngx_http_script_engine_t *e);
size_t ngx_http_script_mark_args_code(ngx_http_script_engine_t *e);
void ngx_http_script_start_args_code(ngx_http_script_engine_t *e);
#if (NGX_PCRE)
void ngx_http_script_regex_start_code(ngx_http_script_engine_t *e);
void ngx_http_script_regex_end_code(ngx_http_script_engine_t *e);
#endif
void ngx_http_script_return_code(ngx_http_script_engine_t *e);
void ngx_http_script_break_code(ngx_http_script_engine_t *e);
void ngx_http_script_if_code(ngx_http_script_engine_t *e);
void ngx_http_script_equal_code(ngx_http_script_engine_t *e);
void ngx_http_script_not_equal_code(ngx_http_script_engine_t *e);
void ngx_http_script_file_code(ngx_http_script_engine_t *e);
void ngx_http_script_complex_value_code(ngx_http_script_engine_t *e);
void ngx_http_script_value_code(ngx_http_script_engine_t *e);
void ngx_http_script_set_var_code(ngx_http_script_engine_t *e);
void ngx_http_script_var_set_handler_code(ngx_http_script_engine_t *e);
void ngx_http_script_var_code(ngx_http_script_engine_t *e);
void ngx_http_script_nop_code(ngx_http_script_engine_t *e);


#endif /* _NGX_HTTP_SCRIPT_H_INCLUDED_ */
