#include "daytime.h"
#include <errno.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int init_client(uint port, char* ip, struct sockaddr_in* servaddr, size_t size){
   printf("[+] init client\n");
   int sockfd;
   bzero(servaddr, size);
   get_err((sockfd = socket(AF_INET, SOCK_STREAM, 0)));
   servaddr->sin_family = AF_INET;
   servaddr->sin_port = htons(port);
   get_err(inet_pton(AF_INET, ip, &servaddr->sin_addr));
   return sockfd;
}
void connect_client(int sockfd, struct sockaddr_in* servaddr){
   get_sys_err(connect(sockfd, (const struct sockaddr*)servaddr, sizeof(*servaddr)));
   printf("[+] connect client\n");
}
void get_input(int sockfd){
   int bytes = 0;
   char buffer[MAXLINE];
   while((bytes = read(sockfd, buffer, MAXLINE)) > 0){
      buffer[bytes+1] = '\0';
      printf("%d bytes were recieved\n", bytes);
      printf("message: %s\n", buffer);
   }
   close(sockfd);
}

void init_server(uint port, char* ip){
   printf("[+] init server\n");
}

void get_err(int res){
   if (res != -1) return;
   printf("error is detected\n");
   exit(-1);

}
void get_sys_err(int res){
   if (res == 0) return;
   printf("%s\n", strerror(errno));
   exit(-1);
}
