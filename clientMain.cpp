#include "clientMain.h"

int main(){
    Tcp tcpC{};
    Socket& client = tcpC;

    client.init(AF_INET);
    client.connectSocket("127.0.0.1", 5555);
    client.sendSocket("Hello :)");
    client.closeSocket();
}