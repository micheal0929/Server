#include "clientInfo.h"

Client::Client():m_user_name(""), m_user_password("")
{
	
}

Client::~Client()
{

}
//bool Client::operator==(const Client& c) const
//{
//	if (!c.GetUserName().compare(this->GetUserName()))
//	{
//		return true;
//	}
//	return false;
//}
inline void Client::ChangeStatus(bool state)
{
	m_user_status = state;
}

inline bool Client::UpRank(RankType rank)
{
	
}
/*inline*/ void Client::SetUserInfo(UserNameType& name, UserPasswordType& password)
{
	m_user_name = name;
	m_user_password = password;
	
}
inline void Client::SetUserRank(RankType rank)
{
		
}
/*inline*/ void Client::SetUserAddr(SOCKADDR_IN clientaddr)
{
	m_addr = clientaddr;
	m_user_ip = inet_ntoa(clientaddr.sin_addr);
	m_user_port = PORT;
	
}
/*inline*/ void Client::SetUserSock(SockType sock)
{
	m_sockid = sock;
}
void Client::ShowInfo(void) const
{
	std::cout << "\t"<< m_user_name << "\t" << m_user_password << std::endl;
	std::cout << "\t"<< m_user_ip << "\t" << m_user_port << std::endl;
}
inline Client::UserNameType Client::GetUserName(void) const
{
	return m_user_name;
}
inline Client::UserPasswordType Client::GetUserPassword(void) const
{
	return m_user_password;
}
inline Client::IPType Client::GetUserIP(void) const
{
	return m_user_ip;
}
inline Client::PortType Client::GetUserPort(void) const
{
	return m_user_port;
}
inline Client::AreaType Client::GetUserArea(void) const
{
	return m_user_area;
}
inline Client::RankType Client::GetUserRank(void) const
{
	return m_user_rank;
}
/*inline*/ Client::SockType Client::GetUserSock(void) const
{
	return m_sockid;
}
inline bool Client::GetUserState(void) const
{
	return m_user_status;
}

ClientManager::ClientManager()
{

}
ClientManager::~ClientManager()
{

}
bool ClientManager::AccountCheck(Client& nc)
{
	if (nc.GetUserName().empty() || nc.GetUserPassword().empty())//若为空则返回
		return false;
	else
	{
		for (client_set_iterator it = m_myclients.begin(); it != m_myclients.end(); ++it)
		{
			if (!nc.GetUserName().compare(it->GetUserName()))//用户名已存在
			{
				return false;
			}
		}//用户名不存在
		
		addNewClient(nc);
		return true;
	}
	
}
void ClientManager::DisplayAllUsers(void)
{
	std::cout << "\tUserName:\tUserPsd" << std::endl;
	for (client_set_iterator it = m_myclients.begin(); it != m_myclients.end(); ++it)
	{
		it->ShowInfo();
	}
}
inline void ClientManager::addNewClient(Client& nc)
{
	m_myclients.insert(nc);
}
ClientManager::client_set ClientManager::GetClientSet(void)
{
	return m_myclients;
}