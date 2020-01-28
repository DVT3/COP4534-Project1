#include <iostream>
#include <cstdlib>
#include <sstream>

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
	TextReader t;
	Encryption e;
	HashTable * hash = new HashTable();

	std::string temp;
	std::string userID;
	std::string password;
	std::string encryptedPassword;

	t.CreateTextFile("textfiles/lastNames.txt", "textfiles/rawData.txt", false);
	t.CreateTextFile("textfiles/rawData.txt", "textfiles/encryptedData.txt", true);
	t.InsertFromText("textfiles/encryptedData.txt");

	std::ifstream in("textfiles/rawData.txt");

	for(int i = 0; i < 5; i++)
	{
		std::getline(in, temp);
		userID = temp.substr(0, temp.find(" "));
		password = e.generatePassword(userID);
		encryptedPassword = hash->Search(userID)->getPassword();
		std::cout << userID << " - Plaintext password: " << password << " | Encrypted Password: " << encryptedPassword << std::endl;
	}

	return 0;
}