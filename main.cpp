#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "Node.hpp"
#include "Encryption.hpp"
#include "HashTable.hpp"

int main()
{
	std::ifstream in("textfiles/lastNames.txt");
	std::ofstream out("textfiles/rawData.txt");

	std::string temp;
	std::string lastName;
	std::string password;
	std::string User;

	Encryption e;

	while(std::getline(in, temp))
	{
		lastName = temp.substr(0, temp.find(" "));
		password = e.generatePassword(lastName);
		User = lastName + " " + password + "\n";
		out << User;
	}
	in.close();
	out.close();

	std::ifstream in2("textfiles/rawData.txt");
	std::ofstream out2("textfiles/encryptedData.txt");

	while(std::getline(in2, temp))
	{
		lastName = temp.substr(0, temp.find(" "));
		password = e.encryptPassword(temp.substr(temp.find(" ") + 1, 9));
		User = lastName + " " + password + "\n";
		out2 << User;
	}
	in2.close();
	out2.close();

	HashTable * hash = new HashTable();
	std::ifstream in3("textfiles/encryptedData.txt");

	while(std::getline(in3, temp))
	{
		lastName = temp.substr(0, temp.find(" "));
		password = temp.substr(temp.find(" ") + 1, 9);
		hash->Insert(lastName, password);
	}
	in3.close();

	std::string ComparePassword;
	std::ifstream in4("textfiles/rawData.txt");
	while(std::getline(in4, temp))
	{
		lastName = temp.substr(0, temp.find(" "));
		password = temp.substr(temp.find(" ") + 1, 9);
		ComparePassword = hash->Search(lastName)->getPassword();
		std::cout << password + " == " + ComparePassword << std::endl;
	}
	in4.close();
}