/*
 * client : timeget_cli
 * a program get the server's time right now!
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc_np.h>
#include <strings.h>

int main(int argc, char **argv)
{
	int ret, cli_sock;
	struct sockaddr_in ser_addr;

	bzero(&ser_addr, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(10005);
	inet_pton(AF_INET, argv[1], &ser_addr.sin_addr);

	cli_sock = socket(PF_INET, SOCK_STREAM, 0);
	ret = connect(cli_sock, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
	if(ret < 0)
	{
		return 0;
	}

	while(1)
	{
		char *buf;
		int len;
		buf = (char *)malloc(1028);
		bzero(buf, sizeof(buf));
		len = read(cli_sock, buf, 1028);
		fputs(buf, stdout);
		close(cli_sock);
		break;
	}
	return 0;
}
