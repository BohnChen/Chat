#include "../Header/GirlH/header.h"

int Girl::listenFdR()
{
	int ret;
	if (FD_ISSET(fdr, &rdset)) {
		// std::cout << "msg from pipe: ";
		memset(msg, 0, sizeof(msg));
		ret = read(fdr, msg, sizeof(msg));
		// error if mtype less than 1
		writeToMsgQ(msg, 1);
		// std::cout << msg << std::endl;
	}
	// -1 means error.
	return ret;
}
