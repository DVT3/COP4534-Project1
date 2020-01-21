#define CATCH_CONFIG_MAIN

#include <sstream>
#include <string>

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
}