#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#define port 5000
int main()
{
	int servsock,n;
	time_t ticks;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t size;
	char buffer[100],str[100];
	servsock = socket(PF_INET,SOCK_DGRAM,0);
	if(servsock>0)
	printf("\nsocket created");
	servaddr.sin_family = PF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	n=bind(servsock,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(n==0)
	printf("\nBind successfull");
	size = sizeof(cliaddr);
	recvfrom(servsock,buffer,sizeof(buffer),0,(struct sockaddr *)&cliaddr,&size);
	printf("\nmsg received:%s",buffer);
	ticks = time(NULL);
	strcpy(str,ctime(&ticks));
	snprintf(buffer,sizeof(buffer),"%s",str);
	sendto(servsock,buffer,sizeof(buffer),0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
	printf("\n\n");
	close(servsock);
	return 0;
}


