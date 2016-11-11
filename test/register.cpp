#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <mips/register.hpp>
#include <mips/const_register.hpp>
#include <mips/normal_register.hpp>

TEST_CASE("Constant register cannot be modified", "[const_register]") {
	mips::const_register<0> reg;

	REQUIRE(reg.read() == 0);
	reg.write(10);
	REQUIRE(reg.read() == 0);
}

TEST_CASE("Normal register can be modified", "[normal_register]") {
	mips::normal_register reg(12);

	REQUIRE(reg.read() == 12);
	reg.write(8);
	REQUIRE(reg.read() == 8);
}
