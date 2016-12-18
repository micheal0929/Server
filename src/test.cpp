#include "clientInfo.h"
#include "public_struct.h"
#include "mythread.h"
#pragma comment(lib,"ws2_32.lib")
#define PORT 9000
void func1(SOCKET sock);
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
	std::cout << " port :" << serveraddr.sin_port << std::endl;

	//std::thread t1(func1,sock);
	ClientManager* cm = new ClientManager;
	Client c1 = Client();
	std::string name = "plr";
	std::string psw = "123";
	c1.SetUserInfo(name, psw);
	long int clientsock;
	SOCKADDR_IN clientaddr;
	int socklen = sizeof(clientaddr);
	while (1)
	{
		clientsock = accept(sock, (SOCKADDR*)&clientaddr, &socklen);
		if (clientsock == INVALID_SOCKET)
		{
			std::cout << "accept error";
			break;
		}
		c1.SetUserSock(clientsock);
		c1.SetUserIP(clientaddr);
		cm->AccountCheck(&(c1.GetUserName()), &(c1.GetUserPassword()));
		cm->DisplayAllUsers();
	}

	delete cm;
	cm = NULL;
	return 0;
}
void func1(SOCKET sock)
{
	
}
