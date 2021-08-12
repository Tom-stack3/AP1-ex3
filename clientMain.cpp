#include "clientMain.h"

int main(){
    Tcp cl{};
    Socket& client = cl;

    client.init(AF_INET);
    client.connectSocket("127.0.0.1", 7444);
    char buffer [30] = {0};
    client.recvSocket(buffer, 30);
    std::cout <<"From server:" << buffer << std::endl;
    std::string userInput;
    getline (std::cin, userInput);
    Reader r = Reader(userInput);
    std::string str = r.toString();
    cl.sendSocket(str);
    client.closeSocket();
}