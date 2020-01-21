#define CATCH_CONFIG_MAIN

#include <string>

#include "Node.hpp"

TEST_CASE("node")
{
	Node n("Daniel", "ninewords");
	REQUIRE(n.getUserID() == "Daniel");
	REQUIRE(n.getPassword() == "ninewords");
	REQUIRE(n.getNext() == nullptr);
}