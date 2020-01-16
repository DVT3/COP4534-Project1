#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

class Encryption
{
	public:
		std::string generatePassword(std::string UserID);
		std::string encryptPassword(std::string password);
};

#endif