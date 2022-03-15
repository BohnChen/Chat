#include "../Header/BoyStdOutH/header.h"

int BoyStdOut::OutPutMsg() 
{
	shmid = shmget(1000, 4096, IPC_CREAT|0600);
	shmMsg = (char *)shmat(shmid, NULL, 0);
	ERROR_CHECK(shmMsg, (void *)-1, "BoyStdOut : shmat");
	std::cout << shmMsg << std::endl;
	// *shmMsg = 0;
	return 1;
}
