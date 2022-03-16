/**
 * the header of girl
 */
#ifndef __GIRL_HERDER_H__
#define __GIRL_HERDER_H__

#include <bits/types/struct_timeval.h>
#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <sys/select.h>
#include <unistd.h>
#include <sys/time.h>
#include <csignal>
#include <sys/msg.h>


#define ERROR_CHECK(ret, errorno, errorInfo) \
	{                                          \
		if (ret == errorno) {                    \
			std::cerr << errorInfo << std::endl;   \
			return -1;                             \
		}                                        \
	}

void sigQuitHandleFunc(int sigNum);


// rewrite msgbuf
struct MsgBuf {
	long mtype;
	char mtext[128];
};




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
		std::cout << "~Girl(): Bye" << std::endl;
	}

	int addSelectListen();
	int listenFdR();
	int listenStdIn();
	int writeToMsgQ(char *msg, int msgType);
	
	struct timeval timeout;

	private:
	int fdr;
	int fdw;
	char msg[128];
	fd_set rdset;
	int msgid;
	struct MsgBuf msgBufStruct;
};

#endif
