#include "TcpClient.h"

void TcpClient::init(const int ipV)
{
	int sock = socket(ipV, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("error creating socket");
	}

	this->socketNum = sock;
	this->ipV = ipV;
}

void TcpClient::bindSocket(const char *sourceIp, const int sourcePort)
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

	if (bind(this->socketNum, (struct sockaddr *) &sin, sizeof(sin)) < 0)
	{
		perror("error binding socket");
	}
}

void TcpClient::connectSocket(const char *destIp, const int destPort)
{
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = this->ipV;
	sin.sin_addr.s_addr = inet_addr(destIp);
	sin.sin_port = htons(destPort);

	if (connect(this->socketNum, (struct sockaddr *) &sin, sizeof(sin)) < 0)
	{
		perror("error connecting to server");
	}
}

void TcpClient::sendSocket(std::string message)
{
	char data_addr[] = "Im a message";
	int data_len = strlen(data_addr);
	int sent_bytes = send(this->socketNum, data_addr, data_len, 0);

	if (sent_bytes < 0)
	{
		perror("error sending message to server");
	}
}

void TcpClient::recvSocket(char *buffer, int len)
{
	int read_bytes = recv(this->socketNum, buffer, len, 0);
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

void TcpClient::closeSocket()
{
	close(this->socketNum);
}