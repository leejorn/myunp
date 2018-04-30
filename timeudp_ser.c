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

	sock_ser = socket(PF_INET, SOCK_DGRAM, 0);

	bind(sock_ser, (struct sockaddr *)&ser_addr, sizeof(ser_addr));

	for(;;)
	{
		struct sockaddr_in cli_addr;
		char climsg[1024];
		socklen_t len;
		int n;

		n = recvfrom(sock_ser, climsg, 1024, 0, (struct sockaddr *)&cli_addr, &len);
		climsg[n] = 0;
		printf("recv msg : %s\n", climsg);

		sendto(sock_ser, sermsg, strlen(sermsg), 0, (struct sockaddr *)&cli_addr, len);
	}

	return 0;
}
