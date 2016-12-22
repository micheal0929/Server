#include "buffer.h"


Buffer::Buffer()
{
	m_sendbuffer = (char *)calloc(BUFF_SIZE, sizeof(char));
	m_recvbuffer = (char *)calloc(BUFF_SIZE, sizeof(char));
}

Buffer::~Buffer()
{
	free(m_sendbuffer);
	free(m_recvbuffer);
}


char* Buffer::GetRecvBuffer()
{
	return m_sendbuffer;
}

char* Buffer::GetSendBuffer()
{
	return m_recvbuffer;
}