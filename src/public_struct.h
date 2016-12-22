#include "clientInfo.h"
#include "buffer.h"
#ifndef PUBLIC_STRUCT_H_
#define PUBLIC_STRUCT_H_

void RecMsg(SOCKET sock)
{
	int ret;
	Buffer* bf = new Buffer();
	//ret = recvfrom(sock,bf->GetRecvBuffer(), BUFF_SIZE, 1,);
	ret = recv(sock, bf->GetRecvBuffer(), BUFF_SIZE, 0);
	if(ret < 0)
	{
		std::cout << "recv error" << std::endl;
	}


}	



#endif //PUBLIC_STRUCT_H_