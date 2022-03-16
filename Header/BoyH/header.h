/**
 * the header of boy
 */
#ifndef __BOY_HEADER_H__
#define __BOY_HEADER_H__

#include <bits/types/struct_timeval.h>
#include <csignal>
#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <signal.h>
#include <string.h>
#include <sys/select.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define ERROR_CHECK(ret, errorno, errorInfo) \
	{                                          \
		if (ret == errorno) {                    \
			std::cerr << errorInfo << std::endl;   \
			return -1;                             \
		}                                        \
	}

struct Data {
	// 0: read 1:Didn't read 2:over
	int flag;
	char msg[1024];
};

class Boy {

	public:
	Boy()
			: fdw { open("BoyWGirlR.pipe", O_WRONLY) }
			, fdr { open("GirlWBoyR.pipe", O_RDONLY) }
			, msg { 0 }
	{
		timeout.tv_sec = 5;
		timeout.tv_usec = 500000;
	}

	// RAII : Resource Acquisition Is Initialization
	~Boy()
	{
		close(fdw);
		close(fdr);
		std::cout << "~Boy() exe." << std::endl;
	}

	int addSelectListen();
	int listenFdR(int shmid, struct Data* data);
	int listenStdIn();
	struct timeval timeout;

	private:
	int fdw;
	int fdr;
	char msg[128];
	fd_set rdset;
};

void sigIntHandleFunc(int sigNum);
int shmM(int flag, char *str, int shmid, struct Data* data);
#endif
