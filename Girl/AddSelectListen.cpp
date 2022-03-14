#include "../Header/GirlH/header.h"

int Girl::addSelectListen()
	{
		FD_ZERO(&rdset);
		FD_SET(fdr, &rdset);
		FD_SET(STDIN_FILENO, &rdset);
		return select(fdw + 1, &rdset, NULL, NULL, NULL);
	}
