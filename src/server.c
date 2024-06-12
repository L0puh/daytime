#include "daytime.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
   if (argc != 2) {
      printf("USAGE: ./server <port>");
      exit(-1);
   }
   int sockfd = init_server(atoi(argv[1]));
   accept_connections(sockfd);
   return 0;
}
