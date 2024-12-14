#include "Client.h"

//int CreateClientSocket()
//{
//	int client_socket = socket(AF_INET, SOCK_STREAM, 0);
//
//	sockaddr_in server_address;
//	server_address.sin_family = AF_INET;
//	server_address.sin_port = htons(8080);
//	server_address.sin_addr.s_addr = INADDR_ANY;
//
//	connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
//
//	return client_socket;
//}
//
//void SendMessageToServer(int client_socket)
//{
//	const char* message = "Hello, server!";
//
//	send(client_socket, message, strlen(message), 0);
//}

User* RegisterUser(std::string username, std::string password)
{
	User* user = nullptr;
	if (!username.empty() && !password.empty())
	{
		user->name = username;
		user->password = password;
	}

	return user;
}

User* AuthorizeUser(std::string username, std::string password)
{
	//check if registered (needs file parse func)
	////if true -> close auth wndw and let type messages
	////if false -> error - not registered

	User* user = nullptr;

	user->name = username;
	user->password = password;

	if (!CheckUserRegistered(user))
	{
		std::cerr << "User is not registered";
		return NULL;
	}

	return user;
}

bool CheckUserRegistered(User* user)
{
	std::ifstream file("registered_users.txt");
	std::string str;
	std::string username;
	std::string password;

	if (!file)
	{
		std::cerr << "Error accessing registered users data";
		return FALSE;
	}

	while (!file.eof())
	{
		for (int index = 0; index < 2; index++)
		{
			std::getline(file, str, ' ');
			if (index == 0)
			{
				username = str;
			}
			else
			{
				password = str;
			}
		}
		return user->name == username && user->password == password;
	}
	return FALSE;
}