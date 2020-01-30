#ifndef NODE_HPP
#define NODE_HPP

#include <string>

/***************************************************************
Student Name: Daniel Tran
File Name: Node.hpp
Assignment number: Project 1

The node file takes in two strings, a userID and a password, and
then stores it in a node. The node's next pointer is set to a
nullptr. You can set the node's next pointer with setNext. There
is a getter function for the userID, password, and next pointer.
***************************************************************/

class Node
{
	public:
		Node(std::string LN, std::string P) {UserID = LN; password = P;}
		std::string getUserID() {return UserID;}
		std::string getPassword() {return password;}
		void setNext(Node * nextNode) {next = nextNode;}
		Node * getNext() {return next;}
	private:
		std::string UserID;
		std::string password;
		Node * next;
};

#endif