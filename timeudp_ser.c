#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>


char sermsg[] = "welcome to my room !!\n";

int main(int argc, char **argv)
{
	int sock_ser;
	struct sockaddr_in ser_addr;

	bzero(&ser_addr, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(10001);
	ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	sock_ser = socket(AF_INET, SOCK_DGRAM, 0);

	bind(sock_ser, (struct sockaddr *)&ser_addr, sizeof(ser_addr));

	for(;;)
	{
		struct sockaddr_in cli_addr;
		char climsg[1024];
		socklen_t len;
		int n;

		len = sizeof(cli_addr);
		n = recvfrom(sock_ser, climsg, 1024, 0, (struct sockaddr *)&cli_addr, &len);
		climsg[n] = 0;
		printf("recv msg : %s\n", climsg);

		sendto(sock_ser, climsg, n, 0, (struct sockaddr *)&cli_addr, len);

		printf("send msg\n");
	}

	return 0;
}

/*
void dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{  
	int n;  
	socklen_t len;  
	char mesg[1024];

	//每当一个数据报到达时，先接收数据，然后再把数据返回给客户端 
	while( 1 )  
	{  
		len = clilen;  
		n = recvfrom(sockfd, mesg, 1024, 0, pcliaddr, &len);  
		sendto(sockfd, mesg, n, 0, pcliaddr, len);  
	} 

	return;
}  

int main(int argc, char **argv)  
{ 
	int sockfd;  
	struct sockaddr_in servaddr, cliaddr;  

	//建立一个基于IPv4数据报(udp)的套接字  
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);  
	memset(&servaddr, 0, sizeof(servaddr));  
	servaddr.sin_family = AF_INET;  
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(10001);  

	//把socket和socket地址结构联系起来  
	bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));  
	dg_echo(sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));  
						
	return 0;  
}  
*/
