#include "Tcp.h"

void Tcp::init(const int ipV)
{
	int sock = socket(ipV, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("error creating socket");
	}

	this->setSocketNum(sock);
	this->setIpV(ipV);
}

void Tcp::connectSocket(const char *destIp, const int destPort)
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
	// if we got connected to a server, we use our own socket to communicate.
	this->connectionSocket = this->getSocketNum();
}

void Tcp::acceptSocket()
{
	if (listen(this->getSocketNum(), 5) < 0)
	{
		perror("error listening to a socket");
	}

	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);
	int client_sock = accept(this->getSocketNum(), (struct sockaddr *) &client_sin, &addr_len);
	if (client_sock < 0)
	{
		perror("error accepting client");
	}
	// we just created a new socket for the spesific client.
	this->connectionSocket = client_sock;
}

void Tcp::sendSocket(std::string message)
{
	int data_len = strlen(message.c_str());
	int sent_bytes = send(this->connectionSocket, message.c_str(), data_len, 0);
	if (sent_bytes < 0)
	{
		perror("error sending message to server");
	}
}

void Tcp::recvSocket(char *buffer, int len)
{
	int read_bytes = recv(this->connectionSocket, buffer, len, 0);
	if (read_bytes == 0)
	{
		// connection is closed
		perror("connection is closed");
	}
	else if (read_bytes < 0)
	{
		// error
		perror("error");
	}
	else
	{
		// everything is OK :)
		// std::cout << buffer;
	}
}