/**
 * The communication between process
 * Bohn Chen 2022.03.13
 */
#include "../Header/BoyH/header.h"

int shmid;
struct Data* data { 0 };
Boy boy;

int main(int argc, char* argv[])
{

	signal(SIGINT, sigIntHandleFunc);

	std::cout << "I am coming!" << std::endl;

	while (1) {

		// The two values below should be assigned every time
		boy.timeout.tv_sec = 5;
		boy.timeout.tv_usec = 500000;
		if (boy.addSelectListen() == 0) {
			std::cout << "boy, you timeout" << std::endl;
		} else {
			// The girl ctrl + c offline
			if (boy.listenFdR(shmid, data) == 0) {
				char tempMsg[64] = { "Bye" };
				std::cout << "girl quit" << std::endl;
				shmM(2, tempMsg, shmid, data);
				shmctl(shmid, IPC_RMID, NULL);
				break;
			}
			// Boy ctrl + d quit
			if (boy.listenStdIn() == 0) {
				char tempMsg[64] = { "Bye" };
				std::cout << "Boy ctrl + d" << std::endl;
				shmM(2, tempMsg, shmid, data);
				shmctl(shmid, IPC_RMID, NULL);
				break;
			}
		}
	}
	return 0;
}
void sigIntHandleFunc(int sigNum)
{
	std::cout << "Catch a SIGINT: " << sigNum << std::endl;
	char tempMsg[64] = { "Bye" };
	shmM(2, tempMsg, shmid, data);
	shmctl(shmid, IPC_RMID, NULL);
	exit(0);
}
