#include "clientMain.h"

int main(){
    Tcp cl{};
    Socket& client = cl;

    client.init(AF_INET);
    client.connectSocket("127.0.0.1", 7444);
    char buffer [50] = {0};
    client.recvSocket(buffer, 50);
    std::cout <<"From server:" << buffer << std::endl;
    std::string userInput;
    getline (std::cin, userInput);
    Reader r = Reader(userInput);
    std::string str = r.toString();
    cl.sendSocket(str);
    char outputBuffer [1000] = {0};
    client.recvSocket(outputBuffer, 1000);
    std::cout << outputBuffer << std::endl;
    Writer w = Writer(std::string("./ClientsInputAddress.csv" ));
    w.write(outputBuffer);
    client.closeSocket();
}