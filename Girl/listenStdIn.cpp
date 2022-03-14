#include "../Header/GirlH/header.h"

int Girl::listenStdIn()
{
	int ret;
	if (FD_ISSET(STDIN_FILENO, &rdset)) {
		std::cout << "msg from stdin: " << std::endl;
		memset(msg, 0, sizeof(msg));
		read(STDIN_FILENO, msg, sizeof(msg));
		ret = write(fdw, msg, strlen(msg));
	}
	// -1 means error.
	return ret;
}
