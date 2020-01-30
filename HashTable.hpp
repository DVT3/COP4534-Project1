#ifndef HASH_TABLE
#define HASH_TABLE

#include "Node.hpp"

#include <iostream>
#include <string>
#include <sstream>

/***************************************************************
Student Name: Daniel Tran
File Name: HashTable.hpp
Assignment number: Project 1

This is the header file for HashTable.cpp. This file declares the
hash algorithm. It also has methods that allow for inserting into
the hash table and searching the hash table. A Node pointer array
named table is initialized with null pointers.
***************************************************************/

class HashTable
{
	public:
		int HashFunction(std::string UserID);
		void Insert(std::string UserID, std::string password);
		Node * Search(std::string UserID);
	private:
		Node * table [90000] = {nullptr};
};

#endif