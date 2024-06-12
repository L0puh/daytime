#include "daytime.h"
#include <errno.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <time.h>
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

int init_server(uint port){
   printf("[+] init server\n");
  
   int sockfd;
   const int enable = 1;
   struct sockaddr_in servaddr;
  
   get_err((sockfd = socket(AF_INET, SOCK_STREAM, 0)));
   get_err(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)));

   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
   servaddr.sin_port = htons(port);
   
   get_err(bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)));
   get_err(listen(sockfd, QUERY));
 
   return sockfd;
}

void accept_connections(int sockfd){
   int connfd;
   time_t cur_time;
   char buffer[MAXLINE];
   while(1){
      get_err((connfd = accept(sockfd, NULL, NULL)));
      printf("[+] new connection\n");
      
      cur_time = time(NULL);
      snprintf(buffer, sizeof(buffer), "%.24s\r\n", ctime(&cur_time));
  
      get_err(write(connfd, buffer, strlen(buffer)));
      get_err(close(connfd));
   }
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
