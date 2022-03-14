#include "../Header/BoyH/header.h"

int Boy::listenFdR()
{
	int ret;
	if (FD_ISSET(fdr, &rdset)) {
		std::cout << "msg from pipe: ";
		memset(msg, 0, sizeof(msg));
		ret = read(fdr, msg, sizeof(msg));
		std::cout << msg << std::endl;
	}
	// -1 means error.
	return ret;
}
