#include "TextReader.hpp"
#include "Encryption.hpp"
#include "HashTable.hpp"

void TextReader::CreateTextFile(std::string infile, std::string outfile, bool encrypt)
{
	// Opens the lastNames.txt and rawData.txt text files to read from and to write to respectively
	std::ifstream in(infile);
	std::ofstream out(outfile);

	// Variables
	std::string temp;
	std::string userID;
	std::string password;
	std::string User;

	Encryption e;

	// Reads from lastName.txt to get last name, generates a password, and then writes to rawData.txt
	while(std::getline(in, temp))
	{
		userID = temp.substr(0, temp.find(" "));		// Gets the last name only from each line
		if(encrypt == false)
		{
			password = e.generatePassword(userID); 		// Generates a 9 character password based on the last name
		}
		else
		{
			password = e.encryptPassword(temp.substr(temp.find(" ") + 1, 9)); 	// Gets the password from each line and then encrypts it
		}
		User = userID + " " + password + "\n";
		out << User; 									// Writes the last name and generated password to rawData.txt
	}

	in.close();
	out.close();
}