#include <iostream>
#include <stdint.h>
#include <set>
#include <string>
#include <unordered_set>

#ifdef _WIN32
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")
#else

#endif
#ifndef CLIENTINFO_H_
#define CLIENTINFO_H_

#define PORT 9000
    

class Client{

public:
	typedef std::string UserNameType;
	typedef std::string UserPasswordType;
	typedef std::string IPType;
	typedef uint32_t PortType;
	typedef uint32_t AreaType;
	typedef uint32_t RankType;
	typedef uint64_t SockType;
	typedef	SOCKADDR_IN AddrType;

public:
	Client();
	~Client();
	inline void ChangeStatus(bool state);
	inline bool UpRank(RankType rank);
	/*inline*/ void SetUserInfo(UserNameType& name, UserPasswordType& password);
	inline void SetUserRank(RankType rank);
	/*inline*/ void SetUserAddr(SOCKADDR_IN clientaddr);
	/*inline */void SetUserSock(SockType sock);
	void ShowInfo(void) const;

	inline UserNameType GetUserName(void) const;
	inline UserPasswordType GetUserPassword(void) const;
	inline IPType GetUserIP(void) const;
	inline PortType GetUserPort(void) const;
	inline AreaType GetUserArea(void) const;
	inline RankType GetUserRank(void) const;
	/*inline*/ SockType GetUserSock(void) const;
	inline bool GetUserState(void) const;

	/*bool operator==(const Client& c)const
	{
		if (!c.GetUserName().compare(this->GetUserName()))
		{
			return true;
		}
		return false;
	}*/
	bool operator<(const Client& c)const
	{
		return this->m_user_name.compare(c.m_user_name);
	}

	UserNameType m_user_name;			
	UserPasswordType m_user_password;
private:

	IPType m_user_ip;
	PortType m_user_port;
	AreaType m_user_area;
	RankType m_user_rank;
	SockType m_sockid;
	AddrType m_addr;
	bool m_user_status;
	
	
};
//struct myhash
//{
//	size_t operator()(const Client& c)const
//	{
//		size_t m1 = std::hash<Client::UserNameType>()(c.GetUserName());
//		size_t m2 = std::hash<Client::UserPasswordType>()(c.GetUserPassword());
//		size_t m3 = std::hash<Client::IPType>()(c.GetUserIP());
//		size_t m4 = std::hash<Client::PortType>()(c.GetUserPort());
//		size_t m5 = std::hash<Client::AreaType>()(c.GetUserArea());
//		size_t m6 = std::hash<Client::RankType>()(c.GetUserRank());
//		size_t m7 = std::hash<Client::SockType>()(c.GetUserSock());
//		return m1^m2^m3^m4^m5^m6^m7;
//	}
//};
class ClientManager{
public:
	typedef std::set<Client> client_set;
	typedef std::set<Client>::iterator client_set_iterator;
	ClientManager();
	~ClientManager();
	
	bool AccountCheck(Client& nc);//检测新用户
	void DisplayAllUsers(void);
	client_set GetClientSet(void);
private:
	inline void addNewClient(Client& nc);//添加新用户
	
private:
	client_set m_myclients;
#ifdef _WIN32
	SOCKADDR_IN client_addr;
	SOCKET client_sock;
#else
	sockaddr client_addr;
#endif

};

#endif //CLIENTINFO_H_