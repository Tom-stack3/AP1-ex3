#include "Server.h"

int main()
{
    int port = 55555;

    Tcp tcp{};
    Tcp *tcpp = &tcp;
    tcpp->init(AF_INET);
    tcpp->bindSocket("127.0.0.1", port);

    std::cout << "Wating for client..." << std::endl;
    tcpp->acceptSocket();
    std::cout << "Client is connected!" << std::endl;
    Classified::distMetric euc = &EucDistance::getDist;
    DataManager d = DataManager();
    d.setDistMetric(euc);
    SocketIO soc = SocketIO(tcpp);

    DefaultIO *dio = &soc;

    CLI c = CLI(dio, &d);
    c.start();

    tcp.closeSocket();
}
