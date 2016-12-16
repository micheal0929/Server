#include <iostream>
#include <stdint.h>

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

public:
	Client();
	~Client();
	inline void ChangeStatus(bool state);
	inline bool UpRank(RankType rank);
	inline void SetUserInfo(UserNameType& name, UserPasswordType& password);

private:
	UserNameType m_user_name;			
	UserPasswordType m_user_password;
	IPType m_user_ip;
	PortType m_user_port;
	AreaType m_user_area;
	RankType m_user_rank;
	bool m_user_status;
};

class ClientManager{
public:
	ClientManager();
	~ClientManager();
	
	bool AccountCheck(Client::UserNameType& name, \
		Client::UserPasswordType& password);//用于检测新用户的用户名和密码是否可以使用


};

#endif //CLIENTINFO_H_