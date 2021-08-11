#include "clientMain.h"

int main(){
    Udp cl{};
    Socket& client = cl;

    client.init(AF_INET);
    client.connectSocket("127.0.0.1", 7444);
    client.sendSocket("Hello :)");
    client.closeSocket();
}