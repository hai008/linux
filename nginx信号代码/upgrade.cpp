// sudo kill -9  `ps aux | grep a.out | grep -v grep | awk '{print $2}'`
// sudo kill -USR2 `ps aux | grep a.out | grep -v grep | awk '{print $2}'`
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/epoll.h>

#include <errno.h>
#define OPEN_MAX 100

#define LOCAL_PORT 6666　　　　　　   //本地服务端口
#define MAX 5　　　　　　　　　　　　 //最大连接数量
typedef pid_t ngx_pid_t;
#define NGX_OK 0
#define NGX_ERROR -1
#define NGX_AGAIN -2
#define NGX_BUSY -3
#define NGX_DONE -4
#define NGX_DECLINED -5
#define NGX_ABORT -6

typedef intptr_t ngx_int_t;
typedef uintptr_t ngx_uint_t;
typedef intptr_t ngx_flag_t;

#define ngx_memzero(buf, n) (void)memset(buf, 0, n) //ngx_memzero使用的是memset原型，memset使用汇编进行编写
#define ngx_memset(buf, c, n) (void)memset(buf, c, n)

sig_atomic_t ngx_reap;
sig_atomic_t ngx_sigio;
sig_atomic_t ngx_sigalrm;
sig_atomic_t ngx_terminate;
sig_atomic_t ngx_quit;
sig_atomic_t ngx_debug_quit;
ngx_uint_t ngx_exiting;
sig_atomic_t ngx_reconfigure;
sig_atomic_t ngx_reopen;

sig_atomic_t ngx_change_binary;
ngx_pid_t ngx_new_binary;
ngx_uint_t ngx_inherited;
ngx_uint_t ngx_daemonized;

sig_atomic_t ngx_noaccept;
ngx_uint_t ngx_noaccepting;
ngx_uint_t ngx_restart;

typedef struct
{
  int signo;                  //信号的编号
  const char *signame;        //信号的字符串表现形式
  const char *name;           //信号名称
  void (*handler)(int signo); //信号处理函数
} ngx_signal_t;

#define ngx_signal_helper(n) SIG##n
#define ngx_signal_value(n) ngx_signal_helper(n)

#define ngx_value_helper(n) #n
#define ngx_value(n) ngx_value_helper(n)

#define ngx_random random

/* TODO: #ifndef */
#define NGX_SHUTDOWN_SIGNAL QUIT
#define NGX_TERMINATE_SIGNAL TERM
#define NGX_NOACCEPT_SIGNAL WINCH
#define NGX_RECONFIGURE_SIGNAL HUP

#define NGX_REOPEN_SIGNAL USR1
#define NGX_CHANGEBIN_SIGNAL USR2

#define ngx_cdecl
#define ngx_libc_cdecl
void ngx_signal_handler(int signo);
//此处定义了所有nginx所支持的信号
ngx_signal_t signals[] = {
    {ngx_signal_value(NGX_RECONFIGURE_SIGNAL),
     "SIG" ngx_value(NGX_RECONFIGURE_SIGNAL),
     "reload",
     ngx_signal_handler},

    {ngx_signal_value(NGX_REOPEN_SIGNAL),
     "SIG" ngx_value(NGX_REOPEN_SIGNAL),
     "reopen",
     ngx_signal_handler},

    {ngx_signal_value(NGX_NOACCEPT_SIGNAL),
     "SIG" ngx_value(NGX_NOACCEPT_SIGNAL),
     "",
     ngx_signal_handler},

    {ngx_signal_value(NGX_TERMINATE_SIGNAL),
     "SIG" ngx_value(NGX_TERMINATE_SIGNAL),
     "stop",
     ngx_signal_handler},

    {ngx_signal_value(NGX_SHUTDOWN_SIGNAL),
     "SIG" ngx_value(NGX_SHUTDOWN_SIGNAL),
     "quit",
     ngx_signal_handler},

    {ngx_signal_value(NGX_CHANGEBIN_SIGNAL),
     "SIG" ngx_value(NGX_CHANGEBIN_SIGNAL),
     "",
     ngx_signal_handler},

    {SIGALRM, "SIGALRM", "", ngx_signal_handler},

    {SIGINT, "SIGINT", "", ngx_signal_handler},

    {SIGIO, "SIGIO", "", ngx_signal_handler},

    {SIGCHLD, "SIGCHLD", "", ngx_signal_handler},

    {SIGSYS, "SIGSYS, SIG_IGN", "", SIG_IGN},

    {SIGPIPE, "SIGPIPE, SIG_IGN", "", SIG_IGN},

    {0, NULL, "", NULL}};

ngx_int_t
ngx_init_signals()
{
  ngx_signal_t *sig;
  struct sigaction sa;

  for (sig = signals; sig->signo != 0; sig++)
  {
    ngx_memzero(&sa, sizeof(struct sigaction));
    sa.sa_handler = sig->handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(sig->signo, &sa, NULL) == -1)
    {

      return NGX_ERROR;
    }
  }

  return NGX_OK;
}

void ngx_signal_handler(int signo)
{
  printf("ngx_signal_handler\n");
  const char *action;
  switch (signo)
  {

  //quit信号
  case ngx_signal_value(NGX_SHUTDOWN_SIGNAL):
    ngx_quit = 1;
    action = ", shutting down";
    break;

  //终止信号
  case ngx_signal_value(NGX_TERMINATE_SIGNAL):
  case SIGINT:
    ngx_terminate = 1;
    action = ", exiting";
    break;

  //winch信号，停止接受accept
  case ngx_signal_value(NGX_NOACCEPT_SIGNAL):
    if (ngx_daemonized)
    {
      ngx_noaccept = 1;
      action = ", stop accepting connections";
    }
    break;

  //sighup信号用来reconfig
  case ngx_signal_value(NGX_RECONFIGURE_SIGNAL):
    ngx_reconfigure = 1;
    action = ", reconfiguring";
    break;

  //用户信号，用来reopen
  case ngx_signal_value(NGX_REOPEN_SIGNAL):
    ngx_reopen = 1;
    action = ", reopening logs";
    break;

  //热代码替换
  case ngx_signal_value(NGX_CHANGEBIN_SIGNAL):
    printf("NGX_CHANGEBIN_SIGNAL\n");
    if (getppid() > 1 || ngx_new_binary > 0)
    {

      /*
                 * Ignore the signal in the new binary if its parent is
                 * not the init process, i.e. the old binary's process
                 * is still running.  Or ignore the signal in the old binary's
                 * process if the new binary's process is already running.
                 */
      /* 这里给出了详细的注释，更通俗一点来讲，就是说，进程现在是一个
                * master(新的master进程)，但是当他的父进程old master还在运行的话，
                * 这时收到了USR2信号，我们就忽略它，不然就成了新master里又要生成
                * master。。。另外一种情况就是，old master已经开始了生成新master的过程
                * 中，这时如果又有USR2信号到来，那么也要忽略掉。。。(不知道够不够通俗=.=)
                参考文档：http://blog.csdn.net/dingyujie/article/details/7192144
                */
      action = ", ignoring";
      //ignore = 1;
      ngx_change_binary = 1;
      break;
    }

    //正常情况下，需要热代码替换，设置标志位
    ngx_change_binary = 1;
    action = ", changing binary";
    break;

  case SIGALRM:
    ngx_sigalrm = 1;
    break;

  case SIGIO:
    ngx_sigio = 1;
    break;

  case SIGCHLD:
    ngx_reap = 1;
    break;
  }
}
#define MAXLINE 32
#define error_exit(msg) \
  do                    \
  {                     \
    perror(msg);        \
    exit(EXIT_FAILURE); \
  } while (0)
int main(int argc, char *argv[])
{
  printf("bg main\n");
  printf("%d\n", getpid());
  ngx_init_signals();
  struct epoll_event event;      // 告诉内核要监听什么事件
  struct epoll_event wait_event[OPEN_MAX]; //内核监听完的结果

  //1.创建tcp监听套接字
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  //2.绑定sockfd
  struct sockaddr_in my_addr;
  bzero(&my_addr, sizeof(my_addr));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(8001);
  my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if(argc == 1)
  {
    bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr));

  //3.监听listen
    listen(sockfd, 10);
   
  }
  else
  {
    printf("%d", argc);
    printf(argv[0]);
    printf(argv[1]);
    printf(argv[2]);
     sockfd = atoi(argv[1]);
  }
  //4.epoll相应参数准备
  int fd[OPEN_MAX];
  int i = 0, maxi = 0;
  memset(fd, -1, sizeof(fd));
  fd[0] = sockfd;

  int epfd = epoll_create(10); // 创建一个 epoll 的句柄，参数要大于 0， 没有太大意义
  if (-1 == epfd)
  {
    perror("epoll_create");
    return -1;
  }
  printf("socked %d \n", sockfd);
  event.data.fd = sockfd; //监听套接字
  event.events = EPOLLIN; // 表示对应的文件描述符可以读

  //5.事件注册函数，将监听套接字描述符 sockfd 加入监听事件
  int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &event);
  if (-1 == ret)
  {
    perror("epoll_ctl");
    return -1;
  }

  //6.对已连接的客户端的数据处理
  while (1)
  {
    // 监视并等待多个文件（标准输入，udp套接字）描述符的属性变化（是否可读）
    // 没有属性变化，这个函数会阻塞，直到有变化才往下执行，这里没有设置超时
      printf("bf epoll_wait\n");
      ret = epoll_wait(epfd, wait_event, OPEN_MAX, -1);
      //printf("signal %d!", ret);
      if (ret == -1 && errno == EINTR)//收到信号
      {
        printf("signal!\n");
        printf("signal!\n");
        if (ngx_change_binary)
        {
          ngx_pid_t  pid;
          pid = fork();
          if(pid == 0)
          {
            printf("new binary\n");
            char csockfd[64];
            ngx_change_binary = 0;
            snprintf(csockfd, 64, "%d", sockfd);
            char * newargv[ ]={"a.out",csockfd,"/etc/passwd",(char *)0};
            char * envp[ ]={"PATH=/bin",0};
            execve("/home/l/upgrate/a.out",newargv,envp);

          }
          sleep(1);
         
        }
        
        //continue;
      }
      printf("ngx_change_binary :%d", ngx_change_binary);

      if(ngx_change_binary)
      {
        bool bexit = true;
        for (i = 1; i < OPEN_MAX; i++)
        {
          if (fd[i] > 0 )//还有未处理的链接
          {
             bexit = false;
          }
        }
        if(bexit)
        {
          exit(0);
        }
      }
	  for(int i = 0; i < ret; ++i)
	  {
		  //6.1监测sockfd(监听套接字)是否存在连接
		  if ((sockfd == wait_event[i].data.fd) && (EPOLLIN == wait_event[i].events & EPOLLIN))
		  {
			struct sockaddr_in cli_addr;
			socklen_t clilen = sizeof(cli_addr);

			if(ngx_change_binary == 0)//不在升级中
			{
				//6.1.1 从tcp完成连接中提取客户端

				int connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

				//6.1.2 将提取到的connfd放入fd数组中，以便下面轮询客户端套接字
				for (int ic = 1; ic < OPEN_MAX; ic++)
				{
				  if (fd[ic] < 0)
				  {
						fd[ic] = connfd;
						event.data.fd = connfd;
						event.events = EPOLLIN;
						int retAdd = epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &event);

						if (-1 == retAdd)
						{
							perror("epoll_ctl");
							return -1;
						}

						break;
					}
				}
			}
        	else
			{
				  
			}
		  }

		  //6.2继续响应就绪的描述符
		  for (i = 1; i <= maxi; i++)
		  {
			if (fd[i] < 0)
			  continue;

			if ((fd[i] == wait_event.data.fd) && (EPOLLIN == wait_event.events & (EPOLLIN | EPOLLERR)))
			{
			  int len = 0;
			  char buf[128] = "";

			  //6.2.1接受客户端数据
			  if ((len = recv(fd[i], buf, sizeof(buf), 0)) < 0)
			  {
				buf[127] = '\0';
				printf(buf);
				if (errno == ECONNRESET) //tcp连接超时、RST
				{
				  close(fd[i]);
				  fd[i] = -1;
				}
				else
				  perror("read error:");
			  }
			  else if (len == 0) //客户端关闭连接
			  {
				close(fd[i]);
				fd[i] = -1;
			  }
			  else //正常接收到服务器的数据
				send(fd[i], buf, len, 0);

			  //6.2.2所有的就绪描述符处理完了，就退出当前的for循环，继续poll监测
			  if (--ret <= 0)
				break;
			}
		  }
	  }
  }

  return 0;
}