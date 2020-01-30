#include "HashTable.hpp"

int HashTable::HashFunction(std::string UserID)
{
	int key;
	for(unsigned int i = 0; i < UserID.length(); i++)
	{
		key += (int) UserID[i];
	}
	return key % 90000;
}

void HashTable::Insert(std::string UserID, std::string password)
{
	int HashValue = HashFunction(UserID);
    Node * current = new Node(UserID, password);
    current->setNext(this->table[HashValue]);
    this->table[HashValue] = current;
}

Node * HashTable::Search(std::string UserID)
{
	int HashValue = HashFunction(UserID);
	Node * current = this->table[HashValue];

	while(current != nullptr)
	{
		if(current->getUserID() == UserID)
		{
			break;
		}
		current = current->getNext();
	}
	return current;
}