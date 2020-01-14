#ifndef NODE
#define NODE

#include <string>

class Node
{
	public:
		Node(std::string LN, std::string P) {UserID = LN; password = P;}
		std::string getUserID() {return UserID;}
		std::string getPassword() {return password;}
		void setEncryptedPassword(std::string EP) {EncryptedPassword = EP;}
		std::string getEncryptedPassword() {return EncryptedPassword;}
		void setNext(Node * nextNode) {next = nextNode;}
		Node * getNext() {return next;}
	private:
		std::string UserID;
		std::string password;
		std::string EncryptedPassword = "";
		Node * next = nullptr;
};

#endif