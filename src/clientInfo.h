#include <iostream>
#include <stdint.h>
#include <string>
#include <unordered_set>

#ifdef _WIN32
#include <winsock.h>
#else

#endif
#ifndef CLIENTINFO_H_
#define CLIENTINFO_H_


class Client{

public:
    typedef std::string UserNameType;
	typedef std::string UserPasswordType;
	typedef std::string IPType;
	typedef uint32_t PortType;
	typedef uint32_t AreaType;
	typedef uint32_t RankType;
	typedef uint64_t SockType;

public:
	Client();
	~Client();
	inline void ChangeStatus(bool state);
	inline bool UpRank(RankType rank);
	inline void SetUserInfo(UserNameType& name, UserPasswordType& password);
	inline void SetUserRank(RankType rank);
	inline void SetUserIP(SOCKADDR_IN&);
	inline void SetUserSock(SockType);
	void ShowInfo(void) const;

	inline UserNameType GetUserName(void) const;
	inline UserPasswordType GetUserPassword(void) const;
	inline IPType GetUserIP(void) const;
	inline PortType GetUserPort(void) const;
	inline AreaType GetUserArea(void) const;
	inline RankType GetUserRank(void) const;
	inline SockType GetUserSock(void) const;
	inline bool GetUserState(void) const;

	bool operator==(const Client& c)const;

	UserNameType m_user_name;			
	UserPasswordType m_user_password;
private:

	IPType m_user_ip;
	PortType m_user_port;
	AreaType m_user_area;
	RankType m_user_rank;
	SockType m_sockid;
	bool m_user_status;
	
	
};
struct myhash
{
	size_t operator()(const Client& c)const
	{
		size_t m1 = std::tr1::hash<Client::UserNameType>()(c.GetUserName());
		size_t m2 = std::tr1::hash<Client::UserPasswordType>()(c.GetUserPassword());
		size_t m3 = std::tr1::hash<Client::IPType>()(c.GetUserIP());
		size_t m4 = std::tr1::hash<Client::PortType>()(c.GetUserPort());
		size_t m5 = std::tr1::hash<Client::AreaType>()(c.GetUserArea());
		size_t m6 = std::tr1::hash<Client::RankType>()(c.GetUserRank());
		size_t m7 = std::tr1::hash<Client::SockType>()(c.GetUserSock());
		return m1^m2;
	}
};
class ClientManager{
public:
	typedef std::unordered_set<Client, myhash> client_set;
	typedef std::unordered_set<Client, myhash>::iterator client_set_iterator;
	ClientManager();
	~ClientManager();
	
	bool AccountCheck(Client::UserNameType* name, \
		Client::UserPasswordType* password);//检测新用户
	void DisplayAllUsers(void);
private:
	inline void addNewClient(Client& nc);//添加新用户
	
private:
	client_set myclients;
#ifdef _WIN32
	SOCKADDR_IN client_addr;
	SOCKET client_sock;
#else
	sockaddr client_addr;
#endif

};

#endif //CLIENTINFO_H_