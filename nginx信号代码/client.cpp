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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#define MAXLINE 32
#define error_exit(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr; // 网际套接字地址结构


    // 创建网际(AF_INET)字节流(SOCK_STREAM)套接字(TCP)
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        error_exit("socket");

    // 建立连接：connect参数2强制转换成指向"通用套接字地址结构"的指针（开发此函数时，void*还不可用）   
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET; // 地址族
    servaddr.sin_port = htons(atoi(argv[2])); // 端口号（主机字节序到网络字节序）
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) // IP地址（呈现形式到数值）
        error_exit("inet_pton");
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        error_exit("connect");

    /* read函数读取服务器的应答，并用fputs输出结果“Thu Jan 12 10:45:52 2017\r\n”(26个字符)。
     * 因为TCP是一个没有记录边界的字节流协议，这26个字节可以有多种返回方式（包含26个字节的单个TCP分节、每个分节只含1个字节的26个分节等）。
     * 如果数据量很大，就不能确保一次read调用能返回服务器的整个应答，因此总把read编写在某个循环中。 */
    /*while ((n = read(sockfd, recvline, MAXLINE)) > 0) { // read()返回0：表明对端关闭连接
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF) 
            error_exit("fputs");
    }*/
    while (fgets(recvline, MAXLINE, stdin)) { // read()返回0：表明对端关闭连接
		printf("read length : %d \n", strlen(recvline));
		if(strlen(recvline) >= 1)
		{
			recvline[strlen(recvline)-1] = '\0'; 
		}
		printf("send : [%s] end", recvline);
        write(sockfd, recvline, MAXLINE);
		const char * close1 = "close";
		if(strcmp(recvline, close1) == 0)
		{
			close(sockfd);
			return 0;
		}
    }
    if (n < 0) // read()返回负值：表明发生错误
        error_exit("read");

    exit(0); // Unix在一个进程终止时总是关闭该进程所有打开的描述符（TCP套接字就此被关闭）
}