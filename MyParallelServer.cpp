
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <strings.h>
#include <cstdio>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <bits/sigthread.h>
#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *c) {
    int sockfd, portno;

    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    int newsockfd, clilen;
    struct sockaddr_in cli_addr;
    struct params* info = new params;
    listen(sockfd, SOMAXCONN);
    clilen = sizeof(cli_addr);
    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));


    while (true) {
        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (newsockfd < 0)	{
            if (errno == EWOULDBLOCK) {
                //time out!
                stop();
                break;
            }	else	{
                perror("other error");
                exit(3);
            }
        }
        //setting params
        info->sockfd = newsockfd;
        info->clientHandler = c;
        pthread_t thread;
        //creating thread and sending to handle client
        if (pthread_create(&thread, nullptr, MyParallelServer::parallelService,info) != 0){
            perror("thread failed");
        }
        closeServer.push_back(pair<pthread_t,int>(thread,newsockfd));
        threads.push_back(thread);

    }
}

 void* MyParallelServer::parallelService(void* newParams) {
   struct params *info = (struct params*)newParams;
   int sockfd = info->sockfd;
   info->clientHandler->handleClient(sockfd);
}

/*
 * making all the clients wait till all are done
 */
void MyParallelServer::stop() {
    for (auto thread: this->threads) {
        pthread_join(thread, nullptr);
    }
    for(auto pair: this->closeServer){
        close(pair.first);
        //todo - how to close threads
    }


}
