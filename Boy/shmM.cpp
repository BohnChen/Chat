#include "../Header/BoyH/header.h"

int shmM(int fla, char *str, int shmid, struct Data* data)
{
	shmid = shmget(1001, 4096, IPC_CREAT | 0600);
	ERROR_CHECK(shmid, -1, "Boy : shmget ")
	data = (struct Data*)shmat(shmid, NULL, 0);
	ERROR_CHECK(data, (void*)-1, "Boy : shmat");
	strcpy(data->msg, str);
	data->flag = fla;
	return 1;
}
