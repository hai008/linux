
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_EVENT_PIPE_H_INCLUDED_
#define _NGX_EVENT_PIPE_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


typedef struct ngx_event_pipe_s  ngx_event_pipe_t;

typedef ngx_int_t (*ngx_event_pipe_input_filter_pt)(ngx_event_pipe_t *p,
                                                    ngx_buf_t *buf);
typedef ngx_int_t (*ngx_event_pipe_output_filter_pt)(void *data,
                                                     ngx_chain_t *chain);


struct ngx_event_pipe_s {
    ngx_connection_t  *upstream;//与上游服务器的链接
    ngx_connection_t  *downstream;//与下游客户端的链接

    ngx_chain_t       *free_raw_bufs;     /* 直接接收自上游服务器的缓冲区链表，保存的是未经任何处理的数据。这个链表是逆序的，后接受的响应插在链表头处 */

    ngx_chain_t       *in;    // 表示接收到的上游响应缓冲区，其数据是经过input_filter处理的

    ngx_chain_t      **last_in;    // 指向刚收到的一个缓冲区


    ngx_chain_t       *out; // 保存着将要发给客户端的缓冲区链表。在写入临时文件成功时，会把in中的缓冲区添加到out中
    ngx_chain_t      **last_out;

    ngx_chain_t       *free;    // 等待释放的缓冲区

    ngx_chain_t       *busy;    // 表示上次调用ngx_http_output_filter函数发送响应时没有发送完的缓冲区链表


    /*
     * the input filter i.e. that moves HTTP/1.1 chunks
     * from the raw bufs to an incoming chain
     */

    ngx_event_pipe_input_filter_pt    input_filter;     // 处理接收到的、来自上游服务器的数据

    void                             *input_ctx;    // 用于input_filter的的参数，一般是ngx_http_request_t的地址


    ngx_event_pipe_output_filter_pt   output_filter;// 向下游发送响应的函数
    void                             *output_ctx;// output_filter的参数，指向ngx_http_request_t

    unsigned           read:1; // 1：表示当前已读取到上游的响应
    unsigned           cacheable:1;// 1：启用文件缓存
    unsigned           single_buf:1; // 1：表示接收上游响应时，一次只能接收一个ngx_buf_t缓冲区
    unsigned           free_bufs:1;// 1：一旦不再接收上游包体，将尽可能地释放缓冲区
    unsigned           upstream_done:1;// 1：表示Nginx与上游交互已经结束
    unsigned           upstream_error:1;// 1：Nginx与上游服务器的连接出现错误
    unsigned           upstream_eof:1; // 1：表示与上游服务器的连接已关闭
    unsigned           upstream_blocked:1; /* 1：表示暂时阻塞读取上游响应的的流程。此时会先调用ngx_event_pipe_write_to_downstream
    函数发送缓冲区中的数据给下游，从而腾出缓冲区空间，再调用ngx_event_pipe_read_upstream
    函数读取上游信息 */
    unsigned           downstream_done:1;// 1：与下游的交互已结束
    unsigned           downstream_error:1;    // 1：与下游的连接出现错误

    unsigned           cyclic_temp_file:1; // 1：复用临时文件。它是由ngx_http_upstream_conf_t中的同名成员赋值的

    ngx_int_t          allocated;     // 已分配的缓冲区数据

    ngx_bufs_t         bufs;    // 记录了接收上游响应的内存缓冲区大小，bufs.size表示每个内存缓冲区大小，bufs.num表示最多可以有num个缓冲区

    ngx_buf_tag_t      tag;    // 用于设置、比较缓冲区链表中的ngx_buf_t结构体的tag标志位


    ssize_t            busy_size;/* busy缓冲区中待发送响应长度的最大值，当到达busy_size时，必须等待busy缓冲区发送了足够的数据，
     才能继续发送out和in中的内容 */

    off_t              read_length;     // 已经接收到来自上游响应包体的长度


    off_t              max_temp_file_size;     // 表示临时文件的最大长度

    ssize_t            temp_file_write_size;    // 表示一次写入文件时数据的最大长度


    ngx_msec_t         read_timeout;     // 读取上游响应的超时时间

    ngx_msec_t         send_timeout;    // 向下游发送响应的超时时间

    ssize_t            send_lowat;    // 向下游发送响应时，TCP连接中设置的send_lowat“水位”


    ngx_pool_t        *pool;     // 连接池

    ngx_log_t         *log;    // 日志


    ngx_chain_t       *preread_bufs;     // 表示在接收上游服务器响应头部阶段，已经读取到响应包体

    size_t             preread_size;    // 表示在接收上游服务器响应头部阶段，已经读取到响应包体长度

    ngx_buf_t         *buf_to_file;    // 用于缓存文件


    ngx_temp_file_t   *temp_file;     // 存放上游响应的临时文件


    /* STUB */ int     num;     // 已使用的ngx_buf_t缓冲区数目

};


ngx_int_t ngx_event_pipe(ngx_event_pipe_t *p, ngx_int_t do_write);
ngx_int_t ngx_event_pipe_copy_input_filter(ngx_event_pipe_t *p, ngx_buf_t *buf);
ngx_int_t ngx_event_pipe_add_free_buf(ngx_event_pipe_t *p, ngx_buf_t *b);


#endif /* _NGX_EVENT_PIPE_H_INCLUDED_ */
