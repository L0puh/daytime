#include "daytime.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if (argc != 3) {
      printf("USAGE: ./client <ip> <port>");
      exit(-1);
   }
   struct sockaddr_in servaddr;
   int sockfd = init_client(atoi(argv[2]), argv[1], &servaddr, sizeof(servaddr));
   connect_client(sockfd, &servaddr);
   get_input(sockfd);
   return 0;
}
