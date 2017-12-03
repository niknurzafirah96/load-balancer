#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main() { 
  int sockets,clientsocket,c,size,serversocket1,serversocket2;
  struct sockaddr_in loadbalancer,client,server1,server2;
  char clientsentence[3000];
  sockets=socket(AF_INET,SOCK_STREAM,0);
  if(sockets==-1) {
    printf("socket cannot created");	
  }	
  puts("loadbalancer socket created");
  loadbalancer.sin_family=AF_INET;
  loadbalancer.sin_addr.s_addr=INADDR_ANY;
  loadbalancer.sin_port=htons(7777);
  if(bind(sockets,(struct sockaddr *)&loadbalancer,sizeof(loadbalancer))<0) {
    perror("fail connect to server");
    return 1;
  }
  puts("bind done");
  listen(sockets,3);	
  puts("waiting for connection");
  c = sizeof(struct sockaddr_in);
  clientsocket=accept(sockets,(struct sockaddr *)&client, (socklen_t *)&c);
  if(clientsocket<0) {
    perror("accept failed");
    return 1; 
  }
  puts("connection accepted");
  size= recv(clientsocket,clientsentence,3000,0);
  if(strcmp(clientsentence,"boy")==0) {	
    serversocket1=socket(AF_INET,SOCK_STREAM,0);
    server1.sin_family=AF_INET;
    server1.sin_addr.s_addr=inet_addr("192.168.40.134");
    server1.sin_port=htons(8888);	
    if(connect(serversocket1,(struct sockaddr *)&server1,sizeof(server1))<0) {
      perror("fail connect to loadbalancer");
      return 1;
    }	
   if(send(serversocket1,clientsentence,strlen(clientsentence),0)<0) {
     puts("fail to send");
     return 1;
   }
   close(serversocket1);
} 
else if(strcmp(clientsentence,"girl")==0) {	
  serversocket2=socket(AF_INET,SOCK_STREAM,0);     
  server2.sin_family=AF_INET;
  server2.sin_addr.s_addr=inet_addr("192.168.40.135");
  server2.sin_port=htons(9999);
  if(connect(serversocket2,(struct sockaddr *)&server2,sizeof(server2))<0) {
    perror("fail to connect to loadbalancer");   
    return 1;        
  }
if(send(serversocket2,clientsentence,strlen(clientsentence),0)<0) {       
  puts("fail to send")        
  return 1;
        
}
close(serversocket2);
} 
else { 
  printf("error message not server");
}
}
