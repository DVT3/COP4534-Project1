#ifndef NODE_HPP
#define NODE_HPP

#include <string>

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
		Node * next = nullptr;
};

#endif