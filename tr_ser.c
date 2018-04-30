/*
 * this a t r ser
 * author : leejorn
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>

char welstr[] = "Welcom To My Room, You Can Speek Now!!\n";

int main(int argc, char **argv)
{
	int ser_fd;
	struct sockaddr_in ser_addr;

	ser_fd = socket(PF_INET, SOCK_STREAM, 0);

	bzero(&ser_addr, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	ser_addr.sin_port = htons(10000);

	bind(ser_fd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
	listen(ser_fd, 5);

	while(1)
	{
		int cli_fd = accept(ser_fd, (struct sockaddr *)NULL, NULL);

		write(cli_fd, welstr, sizeof(welstr));
	}

	return 0;
}
