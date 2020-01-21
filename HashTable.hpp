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
		int HashFunction(int key);
		void Insert(std::string UserID, std::string password);
	private:
		Node ** table;
		const int TABLE_SIZE = 26;
		Node ** head = new Node * [TABLE_SIZE];
};

#endif