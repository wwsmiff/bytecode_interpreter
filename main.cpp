#include <iostream>
#include "CPU.hpp"

int main(void)
{
	CPU noah;
	noah.readFile("test.asm");
	noah.execute();

	return 0;
}
