// GXCard.cpp : 定义 DLL 应用程序的入口点。
//

#include "stdafx.h"
#include "GXCard.h"
#include <tchar.h>

#define  SIZE_BUFFER	512
#define  HEAD_LENGTH	7
#define  COM_HEAD_LENGTH		7


// 创建win32控制台程序->选择DLL，创建动态库
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch(ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

int GXCARD_API TestFunc(char *input, char *output)
{
	char cSend[SIZE_BUFFER] = {0};
	memset(cSend, 0, sizeof(cSend));
	char infoCode[] = "1002";
	cSend[0] = TwoChar2Hex(infoCode[0], infoCode[1]);
	cSend[1] = TwoChar2Hex(infoCode[2], infoCode[3]);
	memcpy(cSend+2, "\x00\x00", 2);
	cSend[4] = 0x00;
	int nlen = HEAD_LENGTH+207;
	cSend[5] = nlen >> 8;
	cSend[6] = nlen - (nlen >> 8)*256;
	int nlength = (int)(cSend[5] << 8) + (unsigned char)cSend[6];
	memcpy(cSend+HEAD_LENGTH, "\x31\x30\x30\x32\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x36\x33\x31\x30\x30\x31\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x36\x33\x31\x30\x30\x31\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x36\x33\x31\x30\x30\x31\x36\x33\x31\x30\x30\x31\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x33\x31\x30\x34\x38\x34\x30\x38\x30\x30\x30\x30\x30\x30\x30\x31\x33\x31\x33\x20\x20\x20\x20\x20\x20\x20\x20\x35\x35\x41\x46\x41\x41\x36\x30\x31\x31\x31\x31\x31\x31\x20\x20\x20\x20\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x45\x39\x35\x33\x45\x39\x35\x33\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x31\x34\x30\x31\x30\x30\x30\x30\x30\x30\x30\x31\x30\x30\x30\x30\x30\x30\x30\x30\x46\x30\x42\x43\x46\x30\x42\x43\x30\x30\x30\x30\x30\x31\x30\x31\x38\x33\x30\x30\x30\x20\x20\x30\x30\x30\x30\x30\x30", 207);
	memcpy(output, cSend, nlen);
	char cHeadTrans[15] = {0};
	memset(cHeadTrans, 0, sizeof(cHeadTrans));
	cHeadTrans[14] = '\0';		// 字符结束
	for (int i=0; i<HEAD_LENGTH; ++i)
		Hex2TwoChar(output[i], &cHeadTrans[2*i], &cHeadTrans[2*i+1]);
	WriteLog("cSend_Head : %s\r\n", cHeadTrans);
	WriteLog("cSend_Data : %s\r\n", cSend+HEAD_LENGTH);
	return 0;
}

