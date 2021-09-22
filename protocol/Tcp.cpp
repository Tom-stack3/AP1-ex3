#include "Tcp.h"

void Tcp::init(const int ipV, int connectionSocket)
{
	if (connectionSocket < 0)
	{
		perror("error creating socket");
	}

	this->setSocketNum(connectionSocket);
	m_connectionSocket = connectionSocket;
	this->setIpV(ipV);
}

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

	if (connect(this->getSocketNum(), (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		perror("error connecting to server");
	}
	// If we got connected to a server, we use our own socket to communicate
	m_connectionSocket = this->getSocketNum();
}

void Tcp::listenSocket()
{
	if (listen(this->getSocketNum(), m_queueSize) < 0)
	{
		perror("error listening to a socket");
	}
}

int Tcp::acceptSocket()
{
	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);
	int client_sock = accept(this->getSocketNum(), (struct sockaddr *)&client_sin, &addr_len);
	// Meaning the timeout for accepting is reached
	if (client_sock < 0)
	{
		return client_sock;
	}
	// We just created a new socket for the specific client
	m_connectionSocket = client_sock;
	return client_sock;
}

void Tcp::sendSocket(std::string message)
{
	int data_len = strlen(message.c_str());
	int sent_bytes = send(m_connectionSocket, message.c_str(), data_len, 0);
	if (sent_bytes < 0)
	{
		perror("error sending message to server");
	}
}

void Tcp::recvSocket(char *buffer, int len)
{
	// Fill the buffer with zeros at first
	std::memset(buffer, 0, len);
	// Load the data received into the buffer
	int read_bytes = recv(m_connectionSocket, buffer, len, 0);
	if (read_bytes == 0)
	{
		// Connection is closed
		perror("connection is closed");
	}
	else if (read_bytes < 0)
	{
		// Error
		perror("error");
	}
	else
	{
		// Everything is OK :)
	}
}

void Tcp::setQueueSize(int s)
{
	m_queueSize = s;
}