#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define port 4000
int main()
{
	char buffer[100];
	struct sockaddr_in servaddr;
	socklen_t size;
	int clisock;
	clisock = socket(AF_INET,SOCK_DGRAM,0);
	if(clisock>0)
	printf("server Socket created successfully\n");
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	while(1)
	{
		printf("To server:");
		fgets(buffer,sizeof(buffer),stdin);
		sendto(clisock,buffer,sizeof(buffer),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
		if(strcmp(buffer,"bye\n")==0)
		break;
		size = sizeof(servaddr);
		recvfrom(clisock,buffer,sizeof(buffer),0,(struct sockaddr *)&servaddr,&size);
		printf("From server: %s",buffer);
	}
	close(clisock);
	return 0;
}
	
	
	

