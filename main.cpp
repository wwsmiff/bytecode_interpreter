#include <iostream>
#include "CPU.hpp"

int main(int argc, char *argv[])
{
	CPU noah;
	
	if(argc < 2)
	{
		std::cout << "Usage: ./main <filename>\n";
	}
	else
	{
		noah.readFile(argv[1]);
		noah.execute();
	}
	
	return 0;
}
