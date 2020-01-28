#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "Node.hpp"
#include "Encryption.hpp"
#include "HashTable.hpp"

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
	// Opens the lastNames.txt and rawData.txt text files to read from and to write to respectively
	std::ifstream in("textfiles/lastNames.txt");
	std::ofstream out("textfiles/rawData.txt");

	// Variables
	std::string temp;
	std::string lastName;
	std::string password;
	std::string User;

	// Access Encryption
	Encryption e;

	// Reads from lastName.txt to get last name, generates a password, and then writes to rawData.txt
	while(std::getline(in, temp))
	{
		lastName = temp.substr(0, temp.find(" "));		// Gets the last name only from each line
		password = e.generatePassword(lastName); 		// Generates a 9 character password based on the last name
		User = lastName + " " + password + "\n";
		out << User; 									// Writes the last name and generated password to rawData.txt
	}
	in.close();
	out.close();

	// Opens the rawData.txt and encryptedData.txt text files to read from and to write to respectively
	std::ifstream in2("textfiles/rawData.txt");
	std::ofstream out2("textfiles/encryptedData.txt");

	// Reads from rawData.txt to get both the userID and password, encrypts the password, and then writes to encryptedData.txt
	while(std::getline(in2, temp))
	{
		lastName = temp.substr(0, temp.find(" ")); 							// Gets the userID from each line
		password = e.encryptPassword(temp.substr(temp.find(" ") + 1, 9)); 	// Gets the password from each line and then encrypts it
		User = lastName + " " + password + "\n";
		out2 << User; 														// Writes the userID and password to encryptedData.txt
	}
	in2.close();
	out2.close();


	HashTable * hash = new HashTable();
	std::ifstream in3("textfiles/encryptedData.txt");
	std::string encryptTemp;

	while(std::getline(in3, encryptTemp))
	{
		hash->Insert(encryptTemp.substr(0, encryptTemp.find(" ")), encryptTemp.substr(encryptTemp.find(" ") + 1, 9));
	}
	in3.close();

	return 0;
}