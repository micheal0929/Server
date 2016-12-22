#include <string>
#include <stdlib.h>
//#include "json\json.h"
#ifndef BUFFER_H_
#define BUFFER_H_
#define BUFF_SIZE 1024

class Buffer
{
public:
	Buffer();
	~Buffer();
	char* GetRecvBuffer(void);
	char* GetSendBuffer(void);

private:
	char* m_sendbuffer;
	char* m_recvbuffer;
};


#endif	//BUFFER_H_