/**
 * message queue
 * BohnChen 2022-03-16
 */

#include "../Header/GirlStdOutH/header.h"
int main(int argc, char* argv[])
{
	while (1) {
		int msgid = msgget(1000, IPC_CREAT | 0600);
		ERROR_CHECK(msgid, -1, "GirlStdOut: msgget");
		struct MsgBuf msgBufStruct {
			0, 0
		};
		int ret = msgrcv(msgid, &msgBufStruct, sizeof(msgBufStruct.mtext), 0, 0);
		ERROR_CHECK(ret, -1, "GirlStdOut: msgrcv");
		if (msgBufStruct.mtype == 9)
			break;
		else
			std::cout << msgBufStruct.mtext << std::endl;
	}

	return 0;
}
