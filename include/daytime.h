#ifndef DAYTIME_H
#define DAYTIME_H

#include <sys/socket.h>
#include <netinet/in.h>
#define MAXLINE 4028

int init_client(uint port, char* ip, struct sockaddr_in*);
void init_server(uint port, char* ip);
void connect_client(int sockfd, struct sockaddr_in* servaddr);
void get_input(int sockfd);

void get_err(int res);
void get_sys_err(int res);

#endif 
