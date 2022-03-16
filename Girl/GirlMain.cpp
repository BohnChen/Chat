/**
 * The communication between process
 * Bohn Chen 2022.03.13
 */
#include "../Header/GirlH/header.h"

Girl girl;
int main(int argc, char* argv[])
{

	std::cout << "I am coming, too." << std::endl;
	// char recvBuf[128] { 0 };

	signal(SIGINT, sigQuitHandleFunc);

	while (1) {
		// the below two values must be assigned every time
		girl.timeout.tv_sec = 5;
		girl.timeout.tv_usec = 500000;
		if (girl.addSelectListen() == 0) {
			std::cout << "timeout, my dear." << std::endl;
		} else {
			// The boy ctrl + c quit
			if (girl.listenFdR() == 0) {
				char tempMsg[64];
				girl.writeToMsgQ(tempMsg, 9);
				break;
			}
			// I use ctrl + d quit
			if (girl.listenStdIn() == 0) {
				char tempMsg[64];
				girl.writeToMsgQ(tempMsg, 9);
				break;
			}
		}
	}

	return 0;
}
void sigQuitHandleFunc(int sigNum)
{
	std::cout << "Catch a sigNum: " << sigNum << std::endl;
	char tempMsg[64];
	girl.writeToMsgQ(tempMsg, 9);
	exit(0);
}
