/**
 * the header of boy
 */

#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>

class Boy {

	public:
	Boy()
			: fdw { open("BoyWGirlR.pipe", O_WRONLY) }
			, fdr { open("GirlWBoyR.pipe", O_RDONLY) }
			, msg { 0 }
	{
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
	

	private:
	int fdw;
	int fdr;
	char msg[128];
	fd_set rdset;
};
