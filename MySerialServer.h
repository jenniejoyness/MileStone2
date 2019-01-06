
#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

class MySerialServer : public Server {
public:
    void open(int port, ClientHandler c);
    void stop();

};


#endif //MILESTONE2_MYSERIALSERVER_H
