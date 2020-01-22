#include "Encryption.hpp"

std::string Encryption::generatePassword(std::string UserID)
{
	std::string password = "";
	int random;
	int num;

	for(unsigned int i = 0; i < UserID.length(); i++)
	{
		random += (int) UserID[i];
	}
	srand(random);
	for(int i = 0; i < 9; i++)
	{
		num = rand() % 26 + 97;
		password += (char) num;
	}
	return password;
}

std::string Encryption::encryptPassword(std::string password)
{
	std::string encryptedPassword;
	std::string key = "jones";
	for(unsigned int i = 0; i < password.length(); i++)
	{
		int x = ((password[i] - 97) + (key[i] - 97)) % 26 + 'a';
		encryptedPassword.push_back(x);
	}
	return encryptedPassword;
}