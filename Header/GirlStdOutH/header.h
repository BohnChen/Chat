#include <iostream>
#include <sys/msg.h>

#define ERROR_CHECK(ret, errorno, errorInfo) \
	{                                          \
		if (ret == errorno) {                    \
			std::cerr << errorInfo << std::endl;   \
			return -1;                             \
		}                                        \
	}
// rewrite msgbuf
struct MsgBuf {
	long mtype;
	char mtext[128];
};

