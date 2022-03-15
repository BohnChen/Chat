/**
 * the header of girl
 */

#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>

class Girl {

	public:
	Girl()
			: fdr { open("BoyWGirlR.pipe", O_RDONLY) }
			, fdw { open("GirlWBoyR.pipe", O_WRONLY) }
			, msg { 0 }
	{
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
	

	private:
	int fdr;
	int fdw;
	char msg[128];
	fd_set rdset;
};
