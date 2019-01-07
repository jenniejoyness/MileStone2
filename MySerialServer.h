
#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "Server.h"
#include <cstdio>
#include <cstdlib>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <cstring>

#include <sys/socket.h>

class MySerialServer : public Server {
public:
    void open(int port, ClientHandler* c) override;
    void stop() override;
    static void serialService(int sockfd,ClientHandler* c);

};


#endif //MILESTONE2_MYSERIALSERVER_H
