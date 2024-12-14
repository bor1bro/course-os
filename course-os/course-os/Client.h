#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Structure that contains all user's info
struct User
{
	std::string name;
	std::string password;
	std::string message;
};
//Function to register user in the system
User* RegisterUser(std::string, std::string);
//Function to authorize user in the system
User* AuthorizeUser(std::string, std::string);
//Function to check if user is registered
bool CheckUserRegistered(User*);

