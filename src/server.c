#include "daytime.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
   if (argc != 3) {
      printf("USAGE: ./server <ip> <port>");
      exit(-1);
   }
   init_server(atoi(argv[3]), argv[1]);
   return 0;
}
