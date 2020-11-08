#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
void main()
{
char msg[100],msg1[100];
intsd,ad,len;
stuctsockaddr_insaddr,caddr;
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd>=0)
{
printf("socket created\n");
}
saddr.sin_family=AF_INET;
saddr.sin_port=htons(2200);
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
if(bind(sd,(structsockaddr_in *)&saddr,sizeof(saddr))<0)
{
printf("error");
exit(1);
}
printf("binding successful\n");
printf("server listening....\n");
listen(sd,5);
len=sizeof(caddr);
ad=accept(sd,(structsockaddr_in *)NULL,NULL);
printf("connection established");
while(strncmp(msg,"bye",3)!=0)
{
bzero(msg,100);
read(ad,msg,100);
printf("client message:%s",msg);
printf("server message:");
fgets(msg1,100,stdin);
writead,msg1,strlen(msg1));
}
}
