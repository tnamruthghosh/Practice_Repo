#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#define port 5000
int main()
{
	int sock;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t size;
	char buffer[100];
	sock = socket(PF_INET,SOCK_DGRAM,0);
	if(sock>0)
	printf("\nsocket created");
	servaddr.sin_family = PF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("enter message:");
	scanf("%s",buffer);
	size = sizeof(cliaddr);
	sendto(sock,buffer,sizeof(buffer),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr *)&cliaddr,&size);
	printf("\nmsg received from server:%s",buffer);
	close(sock);
	return 0;
}



