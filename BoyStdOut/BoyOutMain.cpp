/**
 * This is boy's screen
 * BohnChen 2022-03-15
 */
#include "../Header/BoyStdOutH/header.h"

int main(int argc, char* argv[])
{
	// int flag = 0;
	std::cout << "pid is " << getpid() << std::endl;

	sleep(5);
	BoyStdOut boyOut;

	while (1) {
		// if (boyOut.OutPutMsg() == -1) {
		// 	std::cerr << "shm quit " << std::endl;
		// 	break;
		// }
		boyOut.OutPutMsg();
	}
	return 0;
}
