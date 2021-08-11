#include "Udp.h"

void Udp::init(const int ipV)
{
	int sock = socket(ipV, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		perror("error creating socket");
	}

    this->setSocketNum(sock);
    this->setIpV(ipV);
}

void Udp::connectSocket(const char *destIp, const int destPort)
{
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = this->getIpV();
	sin.sin_addr.s_addr = inet_addr(destIp);
	sin.sin_port = htons(destPort);

    if (connect(this->getSocketNum(), (struct sockaddr *) &sin, sizeof(sin)) < 0)
	{
		perror("error connecting to server");
	}

    // we set the other socket to interact with.
    this->other = sin;
}

void Udp::acceptSocket(){
    // UDP accepts from everyone
    memset(&other, 0, sizeof(other));
}

void Udp::sendSocket(std::string message)
{
	int data_len = strlen(message.c_str());
    int sent_bytes = sendto(this->getSocketNum(), message.c_str(), data_len, 0, (struct sockaddr *) &other, sizeof(other));
	if (sent_bytes < 0)
	{
		perror("error sending message to server");
	}
}

void Udp::recvSocket(char *buffer, int len)
{
    unsigned int from_len = sizeof(struct sockaddr_in);
    int read_bytes = recvfrom(this->getSocketNum(), buffer, sizeof(buffer), 0, (struct sockaddr *) &other, &from_len);
	if (read_bytes == 0)
	{
		// connection is closed
	}
	else if (read_bytes < 0)
	{
		// error
	}
	else
	{
		std::cout << buffer;
	}
}