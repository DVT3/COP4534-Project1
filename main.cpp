#include <iostream>
#include <cstdlib>
#include <sstream>

#include "Node.hpp"
#include "TextReader.hpp"
#include "Encryption.hpp"
#include "HashTable.hpp"

#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

/***************************************************************
Student Name: Daniel Tran
File Name: main.cpp
Assignment number: Project 1

This is the main file for the overall project. The main file will
open, read from, and write too textfiles. The main file will read
from lastNames.txt and generate a password for each last name in
the file. It will then write to a new textfile: rawData.txt.
The file will then read the passwords from rawData.txt and
encrypt the password and write the last name and encrypted
password to another textfile: encryptedData.txt. The file will
then read from encryptedData.txt and hash the userID and password
to a hash table. Afterwords, the file will test some of the hashed
data.
***************************************************************/

int main()
{
	// Objects
	TextReader t;
	Encryption e;
	HashTable hash;

	// Variables
	std::string temp;
	std::string userID;
	std::string password;
	std::string changedPassword;
	std::string encryptedPassword;

	// Creates rawData.txt and encryptedData.txt
	t.CreateTextFile("textfiles/lastNames.txt", "textfiles/rawData.txt", false);
	t.CreateTextFile("textfiles/rawData.txt", "textfiles/encryptedData.txt", true);

	// Inserts data from encryptedData.txt into hash table
	std::ifstream in("textfiles/encryptedData.txt");
	while(std::getline(in, temp))
	{
		userID = temp.substr(0, temp.find(" "));
		password = temp.substr(temp.find(" ") + 1, 9);
		hash.Insert(userID, password);
	}
	in.close();

	// Reads data from rawData.txt and compares the first five passwords from it with the password it finds in the hash table with the same userID
	std::cout << "Check legal User ID and Passwords:" << std::endl;
	std::cout << "UserID\t\tPlaintext Password\tEncrypted Password\tResult" << std::endl;
	std::ifstream in2("textfiles/rawData.txt");
	for(int i = 0; i < 5; i++)
	{
		std::getline(in2, temp);
		userID = temp.substr(0, temp.find(" "));
		password = e.encryptPassword(temp.substr(temp.find(" ") + 1, 9));
		encryptedPassword = hash.Search(userID)->getPassword();
		if(password == encryptedPassword)
		{
			std::cout << userID << "\t\t" << password << "\t\t" << encryptedPassword << "\t\tMATCH" << std::endl;
		}
		else
		{
			std::cout << userID << "\t\t" << password << "\t\t" << encryptedPassword << "\t\tNO MATCH" << std::endl;

		}
	}
	in2.close();

	std::cout << std::endl;

	// Reads data from rawData.txt, changes a character in the password with something else, then compares it to a password found in the hash table with the same userID
	std::cout << "Check legal User ID and illegal Passwords:" << std::endl;
	std::cout << "UserID\t\tPlaintext Password\tEncrypted Password\tResult" << std::endl;
	std::ifstream in3("textfiles/rawData.txt");
	for(int i = 0; i < 5; i++)
	{
		std::getline(in3, temp);
		userID = temp.substr(0, temp.find(" "));
		password = temp.substr(temp.find(" ") + 1, 9);
		password.at(4) = password.at(4) + 1;
		changedPassword = e.encryptPassword(password);
		encryptedPassword = hash.Search(userID)->getPassword();
		if(password == encryptedPassword)
		{
			std::cout << userID << "\t\t" << password << "\t\t" << encryptedPassword << "\t\tMATCH" << std::endl;
		}
		else
		{
			std::cout << userID << "\t\t" << password << "\t\t" << encryptedPassword << "\t\tNO MATCH" << std::endl;

		}
	}
	in3.close();
}