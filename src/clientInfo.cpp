#include "clientInfo.h"

Client::Client():m_user_name(NULL),m_user_password(NULL)
{
}

Client::~Client()
{

}

inline void Client::ChangeStatus(bool state)
{
	m_user_status = state;
}

inline bool Client::UpRank(Client::RankType rank)
{

}
inline void Client::SetUserInfo(UserNameType& name, UserPasswordType& password)
{
	m_user_name = name;
	m_user_password = password;
}


bool ClientManager::AccountCheck(Client::UserNameType& name, \
								 Client::UserPasswordType& password)
{
	//TODO
}