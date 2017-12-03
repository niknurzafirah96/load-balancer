#include <stdio.h>

#include <string.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <netinet/in.h>



int main() {

  int sockets;

  struct sockaddr_in server;
  
char mess[3000];
  

sockets=socket(AF_INET,SOCK_STREAM,0);
  
if(sockets==-1) {

    printf("could not create socket");
  

}
  
puts("socket created");

  server.sin_addr.s_addr=inet_addr("192.168.202.128"); 
  
server.sin_family=AF_INET;

  server.sin_port=htons(7777);


  if(connect(sockets,(struct sockaddr *)&server,sizeof(server))<0) {
    
perror("fail connect to loadbalancer");

    return 1;

  }

printf("Text a message :");
  
scanf("%s",mess);

  if(send(sockets,mess,strlen(mess),0) < 0) {

    puts("fail to sent");

    return 1;
 
  } 
  
close(sockets);  
  
return 0;

}




