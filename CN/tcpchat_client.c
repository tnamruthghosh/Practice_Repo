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
		printf("To server:");
		fgets(buffer,sizeof(buffer),stdin);
		send(newsock,buffer,sizeof(buffer),0);
		recv(newsock,buffer,sizeof(buffer),0);
		printf("From server:%s",buffer);
		if(strcmp(buffer,"bye\n")==0)
		break;
	}
}
int main()
{
	struct sockaddr_in addr;
	int newsock;
	newsock=socket(PF_INET,SOCK_STREAM,0);
	if(newsock>0)
	printf("\n client Socket successfully created");
	addr.sin_family = PF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(newsock,(struct sockaddr *)&addr,sizeof(addr));
	chat(newsock);
	close(newsock);
	return 0;
}

