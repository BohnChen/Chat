#include "../Header/GirlH/header.h"

int Girl::writeToMsgQ(char *msg, int msgType)
{
	msgid = msgget(1000, IPC_CREAT|0600);
	ERROR_CHECK(msgid, -1, "Girl::writeToMsgQ");
	msgBufStruct.mtype = msgType;
	strcpy(msgBufStruct.mtext, msg);
	int ret = msgsnd(msgid, &msgBufStruct, strlen(msgBufStruct.mtext), 0);
	ERROR_CHECK(ret, -1, "writeToMsgQ : msgsnd");

	return 1;
}
