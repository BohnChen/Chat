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
		girl.addSelectListen();
		girl.listenFdR();
		girl.listenStdIn();
	}

	return 0;
}
