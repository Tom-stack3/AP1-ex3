#include "Socket.h"

void Socket::setSocketNum(const int socket)
{
	this->socketNum = socket;
}

int Socket::getSocketNum() const
{
	return this->socketNum;
}

void Socket::setIpV(const int ipV)
{
	this->ipV = ipV;
}

int Socket::getIpV() const
{
	return this->ipV;
}

void Socket::bindSocket(const char *sourceIp, const int sourcePort)
{
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	if (std::string(sourceIp) == "INADDR_ANY")
	{
		sin.sin_addr.s_addr = INADDR_ANY;
	}
	else
	{
		sin.sin_addr.s_addr = inet_addr(sourceIp);
	}

	sin.sin_port = htons(sourcePort);

	if (bind(this->socketNum, (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		perror("error binding socket");
	}
}

void Socket::closeSocket()
{
	close(this->socketNum);
}
