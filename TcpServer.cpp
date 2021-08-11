#include "TcpServer.h"


TcpServer::TcpServer(){
    //constructor
}

void TcpServer::init(const int IDV){
    socketNum = socket(AF_INET, SOCK_STREAM, 0);
    if (socketNum < 0) {
        perror("error creating socket");
    }

}

void TcpServer::bindSocket(std::string sourceIP,const int sourcePort){
    socketPort = sourcePort;
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(socketPort);

    if (bind(socketNum, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(socketNum, 5) < 0) {
        perror("error listening to a socket");
    }
}

void TcpServer::acceptSocket(){
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
   clientSocket = accept(socketNum,  (struct sockaddr *) &client_sin,  &addr_len);

    if (clientSocket < 0) {
        perror("error accepting client");
    }
}

void TcpServer::sendSocket(const char *messege){
    int sent_bytes = send(clientSocket, messege, strlen(messege), 0);

    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

void TcpServer::recvSocket(char *buffer, size_t len){
    int expected_data_len = len;
    int read_bytes = recv(clientSocket, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
    // connection is closed
    }
    else if (read_bytes < 0) {
    // error
    }
    else {
        std::cout << buffer;
    }
}

void TcpServer::closeSocket(){
    close(socketNum);
}