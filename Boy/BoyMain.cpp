/**
 * The communication between process
 * Bohn Chen 2022.03.13
 */
#include "../Header/BoyH/header.h"
#include <cstring>

int main(int argc, char* argv[])
{
	// Boy boy;
	while ( 1 ) {
		int shmid = shmget(1000, 4096, IPC_CREAT | 0600);
		char* p = (char*)shmat(shmid, NULL, 0);
		ERROR_CHECK(p, (void*)-1, "BoyStdOut : shmat");

		std::cin >> p;
		// strcpy(p, "Good Job, Man!");
	}

#if 0
	std::cout << "I am coming!" << std::endl;

	signal(SIGINT, sigIntHandleFunc);
	while (1) {

		// The two values below should be assigned every time
		boy.timeout.tv_sec = 5;
		boy.timeout.tv_usec = 500000;
		if (boy.addSelectListen() == 0)
		{
			std::cout << "boy, you timeout" << std::endl;
		} else
		{
			// The girl ctrl + c offline
			if (boy.listenFdR() == 0)
				break;
			// Boy ctrl + d quit
			if (boy.listenStdIn() == 0)
				break;
		}
	}
#endif
	return 0;
}
