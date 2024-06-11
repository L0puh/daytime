#ifndef DAYTIME_H
#define DAYTIME_H

#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 4028


void get_input(int sockfd);
void get_err(int res);
void get_sys_err(int res);


int init_client(uint port, char* ip, struct sockaddr_in*, size_t size);
int init_client_v4(uint port, char* ip, struct sockaddr_in*, size_t size);
int init_client_v6(uint port, char* ip, struct sockaddr_in6*, size_t size);
void connect_client(int sockfd, struct sockaddr_in* servaddr);


void init_server(uint port, char* ip);


#endif 
