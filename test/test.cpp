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
	HashTable hash;

	hash.Insert("SMITH", "password");
	hash.Insert("SMORC", "awdhguiha");
	hash.Insert("TRAN", "qwiornvowe");

	REQUIRE(hash.Search("SMITH")->getPassword() == "password");
	REQUIRE(hash.Search("TRAN")->getPassword() == "qwiornvowe");
	REQUIRE(hash.Search("SMORC")->getPassword() == "awdhguiha");
}