#ifndef HASH_TABLE
#define HASH_TABLE

#include "Node.hpp"

#include <iostream>
#include <string>
#include <sstream>

class HashTable
{
	public:
		HashTable();
		int HashFunction(std::string UserID);
		void Insert(std::string UserID, std::string password);
		Node * Search(std::string UserID);
	private:
		const int TABLE_SIZE = 26;
		Node ** table = new Node * [TABLE_SIZE];
};

#endif