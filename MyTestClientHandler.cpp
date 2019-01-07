
#include <cstdio>
#include <cstdlib>
#include <strings.h>
#include <unistd.h>
#include <sstream>
#include <cstring>
#include "MyTestClientHandler.h"


//todo קבל תז
MyTestClientHandler::MyTestClientHandler(Solver solver, FileCacheManager &fileCacheManager) {
    this->solver = solver;
    this->cacheManager = fileCacheManager;
}

void MyTestClientHandler::handleClient(int socketId) {
    char buffer[256];
    ssize_t n;
    char* chr;
    if (socketId < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while (true) {
        /* If connection is established then start communicating */
        bzero(buffer, 256);
        n = read(socketId, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if (strcmp(buffer, "end") == 0) {
            return;
        }

        printf("Here is the message: %s\n", buffer);

        //get solution from disk
        if (this->cacheManager.hasSolution()) {
            string s = this->cacheManager.getSolution();
            chr = const_cast<char *>(s.c_str());
        } else {

        }
        /* Write a response to the client */
        n = write(socketId, chr, 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}