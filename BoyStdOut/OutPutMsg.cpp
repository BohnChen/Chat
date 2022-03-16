#include "../Header/BoyStdOutH/header.h"

int BoyStdOut::OutPutMsg()
{
	shmid = shmget(1001, 4096, IPC_CREAT | 0600);
	ERROR_CHECK(shmid, -1, "BoyStdOut: shmget");
	data = (Data*)shmat(shmid, NULL, 0);
	ERROR_CHECK(data, (void*)-1, "BoyStdOut: shm");
	data->flag = 1;
	while (1) {
		if (data->flag == 0) {
			// msg isn't read
			std::cout << data->msg << std::endl;
			data->flag = 1;
			// strcpy(data->msg, "0");
		} else if (data->flag == 1) {
			// msg has already been read
		} else if (data->flag == 2) {
			// over
			std::cout << "sentences" << std::endl;
			exit(0);
		}
	}
	return 1;
}
