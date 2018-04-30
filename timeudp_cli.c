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

	sock_cli = socket(PF_INET, SOCK_DGRAM, 0);

	while(fgets(sendline, 1024, stdin) != NULL)
	{
		sendto(sock_cli, sendline, strlen(sendline), 0, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
		n = recvfrom(sock_cli, recvline, 1024, 0, NULL, NULL);
		recvline[n] = 0;
		printf("get back : %s\n", recvline);
		//fputs(recvline, stdout);
	}

	return 0;
}
