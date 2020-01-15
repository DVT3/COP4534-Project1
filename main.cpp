#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

std::string generatePassword(std::string lastNames);

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
		password = generatePassword(lastNames);
		User = lastNames + " " + password + "\n";
		out << User;
	}
	in.close();
	out.close();
}

std::string generatePassword(std::string lastNames)
{
	std::string password = "";
	int random;
	int num;

	for(int i = 0; i < lastNames.length(); i++)
	{
		random += (int) lastNames[i];
	}
	srand(random);
	for(int i = 0; i < 9; i++)
	{
		num = rand() % 26 + 97;
		password += (char) num;
	}
	return password;
}