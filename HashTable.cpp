#include "HashTable.hpp"

HashTable::HashTable()
{
	this->table = new Node * [TABLE_SIZE];
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		this->table[i] = nullptr;
	}
}

int HashTable::HashFunction(int key)
{
	return key % TABLE_SIZE;
}

void HashTable::Insert(std::string UserID, std::string password)
{
	int key = (int) UserID.at(0) - 97;
	int HashValue = HashFunction(key);
	Node * current = new Node(UserID, password);

	if(table[HashValue] == nullptr)
	{
		table[HashValue] = current;
		this->head[HashValue] = table[HashValue];
	}
	else
	{
		current->setNext(this->head[HashValue]);
		table[HashValue] = current;
		this->head[HashValue] = current;
	}
}