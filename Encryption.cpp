#include "Encryption.hpp"

/***************************************************************
Student Name: Daniel Tran
File Name: Encryption.cpp
Assignment number: Project 1

This file will generate a password based on the last name passed
into the method. It will also encrypt a password passed into
the method with a vigenere cipher.
***************************************************************/

std::string Encryption::generatePassword(std::string UserID)
{
	// Variables
	std::string password = "";
	int random;
	int num;

	// Generates a number based on the ascii values of each character in the userID
	for(unsigned int i = 0; i < UserID.length(); i++)
	{
		random += (int) UserID[i];
	}

	// Changes the seed based on the previously made generated number
	srand(random);

	// Generates 9 random lowercase characters into a string
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
	std::string key = "jones"; // Key for the vigenere cipher

	// Cipher's each character in the password. Should run 9 times
	for(unsigned int i = 0; i < password.length(); i++)
	{
		int x;

		// Vigenere cipher. Shifts the key character back to the first character if i => 5.
		if(i < 5)
		{
			x = ((password[i] - 97) + (key[i] - 97)) % 26 + 'a';
		}
		else
		{
			x = ((password[i] - 97) + (key[i - 5] - 97)) % 26 + 'a';
		}
		
		// Adds encrypted character to return string
		encryptedPassword.push_back(x);
	}
	return encryptedPassword;
}