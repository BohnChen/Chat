/**
 * The communication between process
 * Bohn Chen 2022.03.13
 */
#include "../Header/GirlH/header.h"

int main(int argc, char* argv[])
{
	Girl girl;

	std::cout << "I am coming, too." << std::endl;
	// char recvBuf[128] { 0 };

	while (1) {
		// the below two values must be assigned every time
		girl.timeout.tv_sec = 5;
		girl.timeout.tv_usec = 500000;
		if (girl.addSelectListen() == 0)
		{
			std::cout << "timeout, my dear." << std::endl;
		}
		else 
		{
			// The boy ctrl + c quit
			if (girl.listenFdR() == 0)
				break;
			// I use ctrl + d quit
			if (girl.listenStdIn() == 0)
				break;
		}
	}

	return 0;
}
