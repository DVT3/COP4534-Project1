#define CATCH_CONFIG_MAIN

#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "catch/catch.hpp"
#include "../Node.hpp"
#include "../Encryption.hpp"
#include "../HashTable.hpp"

TEST_CASE("class Node")
{
	Node n("Daniel", "ninewords");

	REQUIRE(n.getUserID() == "Daniel");
	REQUIRE(n.getPassword() == "ninewords");
	REQUIRE(n.getNext() == nullptr);

	Node * pointer = new Node("UserID", "password");
	n.setNext(pointer);

	REQUIRE(n.getNext() == pointer);
	REQUIRE(n.getNext()->getUserID() == "UserID");
	REQUIRE(n.getNext()->getPassword() == "password");
}

TEST_CASE("class Encryption")
{
	Encryption e;

	std::string password1 = e.generatePassword("SMITH");
	std::string password2 = e.generatePassword("DOUGLAS");
	std::string password3 = e.generatePassword("MICHEL");

	REQUIRE(password1 != password2);
	REQUIRE(password1 != password3);
	REQUIRE(password2 != password3);

	REQUIRE(e.encryptPassword("hello") == "qsypg");
	REQUIRE(e.encryptPassword("anvoekfld") == "jbiswttyh");
}

TEST_CASE("class HashTable")
{
	HashTable * hash = new HashTable();
	Encryption e;
	std::ifstream in1("textfile/rawData.txt");
	std::ifstream in2("textfile/encryptedData.txt");
	std::string temp;
	std::string UserID;
	std::string password;

	while(std::getline(in2, temp))
	{
		UserID = temp.substr(0, temp.find(" "));
		password = temp.substr(temp.find(" ") + 1, 9);
		hash->Insert(UserID, password);
	}

	while(std::getline(in1, temp))
	{
		UserID = temp.substr(0, temp.find(" "));
		password = temp.substr(temp.find(" ") + 1, 9);
		password = e.encryptPassword(password);
		REQUIRE(hash->Search(UserID)->getUserID() == UserID);
		REQUIRE(hash->Search(UserID)->getPassword() == password); 
	}

	in1.close();
	in2.close();
}