/**
 * the header of BoyStdOut
 */

#include <unistd.h>
#include <bits/types/struct_timeval.h>
#include <csignal>
#include <signal.h>
#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>

#define  ERROR_CHECK(ret, errorno, errorInfo) {if (ret == errorno){\
	std::cerr << errorInfo << std::endl;\
	return -1;}}\


void sigIntHandleFunc(int sigNum);



class BoyStdOut {

	public:
	BoyStdOut()
			// : fdr { open("GirlWBoyR.pipe", O_RDONLY) }
			// : pipeMsg { 0 }
			: shmid { 0 }
			, shmMsg { 0 }
	{
		timeout.tv_sec = 5;
		timeout.tv_usec = 500000;
	}

	// RAII : Resource Acquisition Is Initialization
	~BoyStdOut()
	{
		delete [] shmMsg;
		delete [] pipeMsg;
		shmdt(shmMsg);
		// close(fdr);
	}

	int OutPutMsg();
	int addSelectListen();
	int listenFdR();
	int listenStdIn();
	struct timeval timeout;


	private:
	char *pipeMsg;
	int shmid;
	char *shmMsg;
	// int fdr;
	fd_set rdset;
};
