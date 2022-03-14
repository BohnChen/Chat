#include "../Header/BoyH/header.h"

int Boy::addSelectListen()
	{
		FD_ZERO(&rdset);
		FD_SET(fdr, &rdset);
		FD_SET(STDIN_FILENO, &rdset);
		// fdr is the bigger fd, because it was initialized lastly
		return select(fdr + 1, &rdset, NULL, NULL, &timeout);
	}
