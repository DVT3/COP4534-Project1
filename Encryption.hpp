#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/***************************************************************
Student Name: Daniel Tran
File Name: Encryption.hpp
Assignment number: Project 1

The Encryption.hpp file declares the generatePassword function
and the encryptPassword function.
***************************************************************/

class Encryption
{
	public:
		std::string generatePassword(std::string UserID);
		std::string encryptPassword(std::string password);
};

#endif