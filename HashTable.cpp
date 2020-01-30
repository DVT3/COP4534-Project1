#include "HashTable.hpp"

/***************************************************************
Student Name: Daniel Tran
File Name: HashTable.cpp
Assignment number: Project 1

This is the file that creates and manages the hash table for this
project. The HashFunction method takes in the user ID and creates
a key based on the sum of the ASCII values of the characters in
the user ID. The method returns the key % 90000, giving the hash
value. The Insert method takes in the user ID and encrypted
password. A hash value is generated from the user ID. A current
pointer is initialized as a new Node and then the method sets
the new node's next pointer to whatever is at the top of the
stack at that hash value. Afterwards, the table pointer at that
hash value is set to the current pointer. The Search function
takes in the user ID to find the hash value. Then, the current
node is set to the table pointer at that hash value. The method
goes through the hash value stack until it either encounters a
pointer with the same user ID passed into the method or a nullptr.
Then, the method returns the current pointer.
***************************************************************/

int HashTable::HashFunction(std::string UserID)
{
	int key;

	// Converts each character in the user ID into an int value and then adds it to the key.
	for(unsigned int i = 0; i < UserID.length(); i++)
	{
		key += (int) UserID[i];
	}

	return key % 90000;
}

void HashTable::Insert(std::string UserID, std::string password)
{
	int HashValue = HashFunction(UserID);			// Gets the hash value
    Node * current = new Node(UserID, password);	// Creates the node object
    current->setNext(this->table[HashValue]);		// Sets the newly made node object's next pointer to whatever is at the head of the stack
    this->table[HashValue] = current;				// Sets the head of the stack to the new node object
}

Node * HashTable::Search(std::string UserID)
{
	int HashValue = HashFunction(UserID);		// Gets the hash value
	Node * current = this->table[HashValue];	// Sets the current pointer to the head of the stack

	// Goes through the stack. If a user ID in the stack is found that is the same as the user ID passed into the method, break from the loop. Else keep going until the pointer points to a nullptr
	while(current != nullptr)
	{
		if(current->getUserID() == UserID)
		{
			break;
		}
		current = current->getNext();
	}
	return current;	// returns the pointer, whether it found it or not. With how everything is set up, this should never return a nullptr
}