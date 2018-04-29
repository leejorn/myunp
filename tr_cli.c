/*
 * this a t r cli
 * author : leejorn
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc_np.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int cli_fd;
	struct sockaddr_in ser_addr;

	cli_fd = socket(PF_INET, SOCK_STREAM, 0);

	bzero(&ser_addr, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(10000);
	inet_pton(AF_INET, argv[1], &ser_addr.sin_addr);

	connect(cli_fd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));

	while(1)
	{
		char *buf;
		int nread;

		buf = (char *)malloc(1024);
		bzero(buf, sizeof(buf));
		nread = read(cli_fd, buf, 1024);
		fputs(buf, stdout);
	}

	return 0;
}
