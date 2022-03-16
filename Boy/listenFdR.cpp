#include "../Header/BoyH/header.h"

int Boy::listenFdR(int shmid, struct Data* data)
{
	int ret;
	if (FD_ISSET(fdr, &rdset)) {
		// std::cout << "msg from pipe: ";
		memset(msg, 0, sizeof(msg));
		ret = read(fdr, msg, sizeof(msg));
		// write msg to shared memory.
		shmM(0, msg, shmid, data);
		// std::cout << msg << std::endl;
	}
	return ret;
}
