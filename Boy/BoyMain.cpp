/**
 * The communication between process
 * Bohn Chen 2022.03.13
 */
#include "../Header/BoyH/header.h"

int main(int argc, char* argv[])
{
	Boy boy;

	std::cout << "I am coming!" << std::endl;

	while (1) 
	{
		boy.addSelectListen();
		boy.listenFdR();
		boy.listenStdIn();
	}

	return 0;
}
