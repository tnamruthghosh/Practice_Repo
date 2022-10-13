#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define port 4000
int main()
{
	char buffer[100];
	struct sockaddr_in servaddr,cliaddr;
	socklen_t size;
	int servsock,n;
	servsock = socket(AF_INET,SOCK_DGRAM,0);
	if(servsock>0)
	printf("server Socket created successfully\n");
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	n=bind(servsock,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(n==0)
	printf("Successfully binded to the client\n");
	size=sizeof(cliaddr);
	while(1)
	{
		recvfrom(servsock,buffer,sizeof(buffer),0,(struct sockaddr *)&cliaddr,&size);
		printf("From client: %s",buffer);
		if(strcmp(buffer,"bye\n")==0)
		break;
		else
		printf("To client:");
		fgets(buffer,sizeof(buffer),stdin);
		sendto(servsock,buffer,sizeof(buffer),0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
	}
	close(servsock);
	return 0;
}
	
	
	
