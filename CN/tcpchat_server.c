#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define port 4000
void chat(int newsock)
{
	char buffer[100];
	while(1)
	{
		recv(newsock,buffer,sizeof(buffer),0);
		printf("From client:%s",buffer);
		if(strcmp(buffer,"bye\n")==0)
		break;
		fgets(buffer,sizeof(buffer),stdin);
		send(newsock,buffer,sizeof(buffer),0);
	}
}
int main()
{
	struct sockaddr_in servaddr,newaddr;
	socklen_t size;
	int serversock,newsock,n;
	serversock=socket(PF_INET,SOCK_STREAM,0);
	if(serversock>0)
	printf("\nSocket successfully created");
	servaddr.sin_family = PF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	n=bind(serversock,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(n==0)
	printf("\nSuccessfully binded");
	listen(serversock,1);
	size=sizeof(newaddr);
	printf("\nserver ready");
	newsock=accept(serversock,(struct sockaddr *)&newaddr,&size);
	if(newsock>0)
	printf("\n Accepted");
	chat(newsock);
	close(newsock);
	return 0;
}
