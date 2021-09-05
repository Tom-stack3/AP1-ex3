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

	char data[] = "first_msg";
	int data_len = sizeof(data);

	if (sendto(this->getSocketNum(), data, data_len, 0, (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		perror("error writing to socket");
	}
	// we set the other socket to interact with.
	m_other = sin;
}

void Udp::acceptSocket()
{
	struct sockaddr_in from;
	memset(&from, 0, sizeof(from));
	unsigned int from_len = sizeof(struct sockaddr_in);
	char buffer[Socket::BUFFER_SIZE];
	int bytes = recvfrom(this->getSocketNum(), buffer, sizeof(buffer), 0, (struct sockaddr *)&from, &from_len);
	if (bytes < 0)
	{
		perror("error reading from socket");
	}

	m_other = from;
}

void Udp::sendSocket(std::string message)
{
	int data_len = strlen(message.c_str());
	int sent_bytes = sendto(this->getSocketNum(), message.c_str(), data_len, 0, (struct sockaddr *)&m_other, sizeof(m_other));
	if (sent_bytes < 0)
	{
		perror("error sending message to server");
	}
}

void Udp::recvSocket(char *buffer, int len)
{
	unsigned int from_len = sizeof(struct sockaddr_in);
	int read_bytes = recvfrom(this->getSocketNum(), buffer, len, 0, (struct sockaddr *)&m_other, &from_len);
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
	}
}