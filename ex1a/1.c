
server.c

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>

int main()

{

  int cs,ns,fd,n;
  int bufsize=1024;
  char *buffer=malloc(bufsize);
  struct sockaddr_in address;
  char fname[255];
  address.sin_family=AF_INET;
  address.sin_port=htons(15000);
  address.sin_addr.s_addr=
INADDR_ANY;
  cs=socket(AF_INET,SOCK_STREAM,0);
  bind(cs,(struct sockaddr *)&address,sizeof(address));
  listen(cs,3);
  ns=accept(cs,(struct sockaddr *)NULL,NULL);
  recv(ns,fname,255,0);
  fd=open(fname,O_RDONLY);
  n=read(fd,buffer,bufsize);
  send(ns,buffer,n,0);
  close(ns);
  return close(cs);

}


 
client.c

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
  int cs,n;
  int bufsize=1024;
  char *buffer=malloc(bufsize);
  char fname[255];
  struct sockaddr_in address;
  address.sin_family=AF_INET;
  address.sin_port=htons(15000);
  inet_pton(AF_INET,argv[1],&address.sin_addr);
  cs=socket(AF_INET,SOCK_STREAM,0);
  connect(cs,(struct sockaddr *)&address,sizeof(address));
  printf("\nEnter filename: ");scanf("%s",fname);
  send(cs,fname,255,0);
  while((recv(cs,buffer,bufsize,0))>0)
  printf("%s",buffer);
  printf("\nEOF\n");
  return close(cs);
}
steps to execute:

-->netstat -tulnp
-->gcc server.c
-->./a.out 631

open another terminal

-->gcc client.c
-->./a.out 127.0.0.1

