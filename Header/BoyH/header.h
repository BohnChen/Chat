/**
 * the header of boy
 */
#ifndef __BOY_HEADER_H__
#define __BOY_HEADER_H__

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

void sigIntHandleFunc(int sigNum);

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
	}

	int addSelectListen();
	int listenFdR();
	int listenStdIn();

	struct timeval timeout;

	private:
	int fdw;
	int fdr;
	char msg[128];
	fd_set rdset;
};

#endif
