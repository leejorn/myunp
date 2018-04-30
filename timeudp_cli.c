#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int sock_cli;
	struct sockaddr_in ser_addr;
	int n;
	char sendline[1024], recvline[1024];

	bzero(&ser_addr, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(10001);
	inet_pton(AF_INET, argv[1], &ser_addr.sin_addr);

	sock_cli = socket(AF_INET, SOCK_DGRAM, 0);

	while(fgets(sendline, 1024, stdin) != NULL)
	{
		sendto(sock_cli, sendline, strlen(sendline), 0, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
		printf("finish send\n");
		n = recvfrom(sock_cli, recvline, 1024, 0, NULL, NULL);
		printf("get back : %d\n", n);
		recvline[n] = 0;
		//fputs(recvline, stdout);
	}

	return 0;
}

/*
void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen)  
{ 
	int n;  
	char sendline[1024], recvline[1024 + 1];  

	//从终端获取一行字符串，将其写入套接字    
    	//然后从套接字一行字符串，将其写入终端    
 	while (fgets(sendline, 1024, fp) != NULL) 
	{  
		sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);  
		n = recvfrom(sockfd, recvline, 1024, 0, NULL, NULL);  
		recvline[n] = 0;  
		fputs(recvline, stdout);  
	}  
}

int main(int argc, char **argv)  
{  
	int  sockfd;  
	struct sockaddr_in  servaddr;  

	if (argc != 2)  
		printf("usage: udpcli <IPaddress>");  

	//创建用于TCP协议的套接字   
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);  
	memset(&servaddr, 0, sizeof(servaddr));  
	servaddr.sin_family = AF_INET;  
	servaddr.sin_port = htons(10001);  

	//将程序的参数1(argv[1])转换成套接字地址结构    
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);  
	dg_cli(stdin, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));  
	return 0;  
}  
*/
