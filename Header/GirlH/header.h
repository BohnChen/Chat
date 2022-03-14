/**
 * the header of girl
 */

#include <bits/types/struct_timeval.h>
#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/time.h>

class Girl {

	public:
	Girl()
			: fdr { open("BoyWGirlR.pipe", O_RDONLY) }
			, fdw { open("GirlWBoyR.pipe", O_WRONLY) }
			, msg { 0 }
	{
		timeout.tv_sec = 10;
		timeout.tv_usec = 500000;
	}

	// RAII : Resource Acquisition Is Initialization
	~Girl()
	{
		close(fdr);
		close(fdw);
	}

	int addSelectListen();
	int listenFdR();
	int listenStdIn();
	
	struct timeval timeout;

	private:
	int fdr;
	int fdw;
	char msg[128];
	fd_set rdset;
};
