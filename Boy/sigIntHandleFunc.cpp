#include "../Header/BoyH/header.h"

void sigIntHandleFunc(int sigNum)
{
	std::cout << "Catch a SIGINT: " << sigNum << std::endl;
}
