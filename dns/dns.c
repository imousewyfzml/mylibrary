/*
                                UDP Protocol Simple Server

*/
/* server_udp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define DEFAULT_PORT 5050
#define MAX_EVENTS   10
#define MAX_FDS      10

static int do_it(int sSocket);

int main(int argc, char** argv)
{
    int sPort = DEFAULT_PORT;
    int sSocket = 0;
    struct sockaddr_in ser;
    /* use epoll */
    struct epoll_event ev;
    struct epoll_event events[MAX_EVENTS];
    int epollfd;
    int nfds;
    int n;
    
    
    printf("Server waiting...\n");
    
    sSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(sSocket < 0)
    {
        perror("socket");
        return -1;
    }
    
    ser.sin_family = AF_INET;
    ser.sin_port = htons(sPort);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if(bind(sSocket, (struct sockaddr*)&ser, sizeof(ser)) < 0)
    {
        perror("bind");
        return -1; 
    }
    

    /* USE epoll  */
    epollfd = epoll_create(MAX_FDS);
    if (epollfd == -1)
    {
        perror("epoll_create");
        return -1;
    }
    
    ev.events = EPOLLIN;
    ev.data.fd = sSocket;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sSocket,&ev) == -1)
    {
        perror("epoll_ctl");
        return -1;
    }
    
    for(;;)
    {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1)
        {
            perror("epoll_wait");
            return -1;
        }

        for (n = 0; n < nfds; ++n)
        {
    
            if (events[n].data.fd = sSocket)
            {
		        if (do_it(sSocket) != 0)
                {
                    break;
                }
            }
	    }
    }

    close(sSocket);
    
    return 0;
}

int do_it(int sSocket)
{
    int sRecv = 0;
    int sLen = 0;
    int sSend = 0;
    char recv_buf[4096] = {0};
    struct sockaddr_in cli;
    char send_buf[]="Hello! I Am a Server!";
    
    sLen = sizeof(cli);
    memset(recv_buf, 0, sizeof(recv_buf));

    sRecv = recvfrom(sSocket, recv_buf, 4096, 0, (struct sockaddr*)&cli, (unsigned int*)&sLen);
    if((sRecv < 0)||(sRecv == 0))
    {
        perror("recvfrom");
	return -1;
    }
    else
    {
        printf("recvfrom(): [%s]\n", recv_buf);
        printf("recvfrom() client IP: [%s]\n", inet_ntoa(cli.sin_addr));
        printf("recvfrom() client PORT: [%d]\n", ntohs(cli.sin_port));
        /* replay*/
    }
        
    sSend = sendto(sSocket, send_buf, sizeof(send_buf), 0, (struct sockaddr*)&cli, sizeof(cli));
    if((sSend < 0)||(sSend == 0))
    {
        perror("perror");
        return -1;
    }
    printf("sendto() Succeeded!\n");

    return 0;
}
