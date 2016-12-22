#include "clientInfo.h"
#include "public_struct.h"
//#include <json/json.h>
#include <thread>
#define BUF_SIZE 1024
void func1();
ClientManager* cm = new ClientManager;

int main()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}
	


	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	
	SOCKADDR_IN serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.S_un.S_addr = INADDR_ANY;
	serveraddr.sin_port = htons(PORT);
	int ret;
	ret = bind(sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (ret < 0)
		std::cout << "bind error" << std::endl;

	ret = listen(sock, 10);
	if (ret < 0)
		std::cout << "listen error" << std::endl;

	std::cout << "start listen at ip:" << serveraddr.sin_addr.S_un.S_addr;
	std::cout << " port :" << ntohs(serveraddr.sin_port) << std::endl;

	
	std::thread t1(func1);
	
	Client c1 = Client();
	std::string name = "plr";
	std::string psw = "123";
	c1.SetUserInfo(name, psw);
	long int clientsock;
	SOCKADDR_IN clientaddr;
	int socklen = sizeof(clientaddr);
	while (1)
	{
		clientsock = accept(sock, (SOCKADDR*)&clientaddr, &socklen);//有新的客户端连接
		if (clientsock == INVALID_SOCKET)
		{
			std::cout << "accept error";
			break;
		}
		c1.SetUserSock(clientsock);
		c1.SetUserAddr(clientaddr);
		cm->AccountCheck(c1);
		cm->DisplayAllUsers();
		
	}
	t1.join();
	delete cm;
	cm = NULL;
	return 0;
}
void func1()
{
#ifdef _WIN32
	fd_set readset;
	int max = 0;
	std::cout << "sub thread runing!" <<std::endl;
	char* recbuffer = new char[BUF_SIZE];
	for(;;)
	{
		FD_ZERO(&readset);
		for(auto it:cm->GetClientSet())
		{

			FD_SET(it.GetUserSock(), &readset);
			if(max < it.GetUserSock())
			{
				max = it.GetUserSock();
			}
		}
		int nready = select(max+1, &readset, NULL, NULL, NULL);//已连接的客户端发送消息
		while(nready > 0)
		{
			for(auto it:cm->GetClientSet())
			{
				if(FD_ISSET(it.GetUserSock(), &readset))//接受到来自客户端的消息
				{
					int retval = recv(it.GetUserSock(), recbuffer, BUF_SIZE, 0);
					//do service
					std::cout << "client : " << it.GetUserSock() << "send msg" << std::endl;
					--nready;
					break;
				}
			}
		}

	}
#else

#endif
	
	
}
