#include <stdio.h>


#include <string.h>


#include <sys/socket.h>


#include <arpa/inet.h>


#include <unistd.h>




int main() {

  
  int sockets,clientsocket,c,size;
  

  struct sockaddr_in server,client;

  
  char clientsentence[3000];


  
  sockets=socket(AF_INET,SOCK_STREAM,0);

  
  if(sockets==-1);

 
  
  puts("socket created");
  


  server.sin_family=AF_INET;
  

  server.sin_addr.s_addr=INADDR_ANY;

  
  server.sin_port=htons(8888);
  
  

if(bind(sockets,(struct sockaddr *)&server,sizeof(server))<0) {
    
     
perror("fail connect to server");
    
     
return 1;

  
  }
  


  puts("bind done");

 
  listen(sockets,3);


  
  puts("waiting for connection");

  
c=sizeof(struct sockaddr_in);

  

clientsocket = accept(sockets,(struct sockaddr *)&client,(socklen_t *)&c);

  if(clientsocket < 0) {


    perror("accept failed");


    return 1;

  
  }


  
puts("connection accepted");



  size=recv(clientsocket,clientsentence,3000,0);

  
printf("%s",clientsentence);


}
