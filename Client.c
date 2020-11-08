#include<stdio.h>
#include<stdlib.h>
#include<sys/types>
#include<netinet/in.h>
#include<string.h>
void main()
            {
char msg[100],msg1[100];
intsd, len, cd;
structsockaddr_in saddr,caddr;
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd>=0)
{
printf("socket created\n");
}
saddr.sin_family=AF_INET;
saddr.sin_port=htons(2220);
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
cd=connet(sd,(structsockaddr_in *)&saddr,sizeof(saddr));
if(cd<0)
{
printf("not connected");
exit(1);
}
while(strncmp(msg,"bye",3)!=0)
{
bzero(msg,100);
pintf("client message:");
fgets(msg,100,stdin);
write(sd,msg,strln(msg));
bzero(msg1,100);
read(sd,msg1,100);
printf("/n message from server:%s",msg1);
}
}
