#include "../Header/GirlH/header.h"

void sigQuitHandleFunc(int sigNum)
{
	std::cout << "Catch a sigNum: " << sigNum << std::endl;
}
