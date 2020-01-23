#include "HashTable.hpp"

HashTable::HashTable()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = nullptr;
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
	}
	else
	{
		current->setNext(table[HashValue]);
		table[HashValue] = current;
	}
}

Node * HashTable::Search(std::string UserID)
{
	int key = (int) UserID.at(0) - 97;
	int HashValue = HashFunction(key);
	Node * current = table[HashValue];

	while(current->getNext() != nullptr)
	{
		if(current->getUserID() == UserID)
		{
			return current;
		}
		current = current->getNext();
	}
	return nullptr;
}