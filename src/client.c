#include "daytime.h"

int main() {
   struct sockaddr_in *servaddr;
   int sockfd = init_client(13, "129.6.15.28", servaddr);
   connect_client(sockfd, servaddr);
   get_input(sockfd);

   return 0;
}
