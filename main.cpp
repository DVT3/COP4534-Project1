#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "Encryption.hpp"

int main()
{
	std::ifstream in("lastNames.txt");
	std::ofstream out("rawData.txt");

	std::string lastName;
	std::string temp;
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

	std::ifstream in2("rawData.txt");
	std::ofstream out2("encryptedData.txt");

	while(std::getline(in2, temp))
	{
		lastName = temp.substr(0, temp.find(" "));
		password = e.encryptPassword(temp.substr(temp.find(" ") + 1, 9));
		User = lastName + " " + password + "\n";
		out2 << User;
	}
	in2.close();
	out2.close();
}