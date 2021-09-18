#include "Socket.h"

void Socket::setSocketNum(const int socket)
{
	m_socketNum = socket;
}

int Socket::getSocketNum() const
{
	return m_socketNum;
}

void Socket::setIpV(const int ipV)
{
	m_ipV = ipV;
}

int Socket::getIpV() const
{
	return m_ipV;
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

	if (bind(getSocketNum(), (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		perror("error binding socket");
	}
}

void Socket::closeSocket()
{
	close(getSocketNum());
}
