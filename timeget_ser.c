/* 
 * server : timeget_ser
 * a program send this server's time right now!
 */

#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>

char *now_time()
{
	time_t now;
	time(&now);

	return ctime(&now);
}

int main(int argc, char **argv)
{
	int ser_sock;
	struct sockaddr_in ser_addr;

	bzero(&ser_addr, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	ser_addr.sin_port = htons(10005);

	ser_sock = socket(PF_INET, SOCK_STREAM, 0);
	bind(ser_sock, (struct sockaddr *)&ser_addr, sizeof(ser_addr));

	listen(ser_sock, 5);

	while(1)
	{
		char *now;
		int cli_sock;

		cli_sock = accept(ser_sock, (struct sockaddr *)NULL, NULL);

		now = now_time();
		write(cli_sock, now, strlen(now));
		printf("Hello world !! %d\n", cli_sock);
		close(cli_sock);
	}
	return 0;
}
