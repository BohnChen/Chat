/**
 * the header of BoyStdOut
 */
#ifndef __BOYSTDOUT_H__
#define __BOYSTDOUT_H__

#include <bits/types/struct_timeval.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
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

typedef struct Data {
	// 1: read 0:Didn't read 2:over
	int flag;
	char msg[1024];
} * pData;

class BoyStdOut {

	public:
	BoyStdOut()
			: shmid { 0 }
			, data { 0 }
	{
	}

	// RAII : Resource Acquisition Is Initialization
	~BoyStdOut()
	{
		// shmdt(data);
		std::cout << "~BoyStdOut() Bye" << std::endl;
	}

	int OutPutMsg();
	int shmid;
	pData data;
};

#endif
