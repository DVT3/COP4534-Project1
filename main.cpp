#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

std::string generatePassword();

int main()
{
	std::ifstream in("lastNames.txt");
	std::ofstream out("rawData.txt");

	std::string lastNames;
	std::string temp;
	std::string password;
	std::string User;

	while(std::getline(in, temp))
	{
		lastNames = temp.substr(0, temp.find_first_of(" ", 0));
		password = generatePassword();
		User = lastNames + "\t" + password + "\n";
		out << User;
	}
	in.close();
	out.close();
}

std::string generatePassword()
{
	std::string password = "";
	srand(0);
	int num;
	for(int i = 0; i < 9; i++)
	{
		num = rand() % 26 + 97;
		password += (char) num;
	}
	return password;
}