#include "stdafx.h"
#include "PubFunction.h"

#define SUB_CAPITAL			(BYTE)('A' - 0x0A)			// ��д��ĸ�ַ����ӦHEX�Ĳ�ֵ
#define SUB_SMALL				(BYTE)('a' - 0x0A)			// Сд��ĸ�ַ����ӦHEX�Ĳ�ֵ
#define SUB_NUMERIC			(BYTE)0x30					// �����ַ����Ӧ��HEXֵ�Ĳ�


void WriteLog(char *fmt, ...)
{
	FILE *fp;
	va_list argptr;
	int cnt;
	char fileName[512];
	char szBuff[512];

	// ��ȡ����ʱ��
	SYSTEMTIME time;
	GetLocalTime(&time);
	
	// ��������Ϊ�ļ���������־��¼
	sprintf_s(fileName, 512, "dbg%04d%02d%02d.log", time.wYear, time.wMonth, time.wDay);
	
	va_start(argptr, fmt);
		fopen_s(&fp, fileName, "a+");
		if (fp != NULL)
		{
			memset(szBuff, 0, sizeof(szBuff));
			cnt = fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d]", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
			cnt = vfprintf(fp, fmt, argptr);
			fclose(fp);
		}
	va_end(argptr);
}

// �ַ�תHex
BYTE Char2Hex(char ch)
{
	BYTE bHex = 0;
	if (ch >= '0' && ch <= '9')
		bHex = (BYTE)(ch - SUB_NUMERIC);
	else if (ch >= 'a' && ch <= 'z')
		bHex = (BYTE)(ch - SUB_SMALL);
	else if (ch >= 'A' && ch <= 'Z')
		bHex = (BYTE)(ch - SUB_CAPITAL);
	else
		bHex = 0x00;
	return bHex;
}
// ��2�ֽ�charת��Ϊһ��BYTE��HEX
BYTE TwoChar2Hex(char lchar, char rchar)
{
	return ((Char2Hex(lchar) << 4) + Char2Hex(rchar));
}

// ������ ת hex
int Dword2Hex(DWORD value, char *output)
{
	assert(value>100);
	assert(value<100000000);
	int i = 0, r;
	while(value)
	{
		r = value%16;
		if (r<9)
			output[i] = r + '0';
		else
			output[i] = r + 'A';
		value = value/16;
		++i;
	}
	return 0;
}

BYTE Hex2Char(BYTE ucHex)
{
	BYTE bChar;
	if (ucHex >= 0 && ucHex <= 9)
		bChar = (BYTE)(ucHex + SUB_NUMERIC);
	else if(ucHex >= 10 && ucHex <= 15)
		bChar = (BYTE)(ucHex + SUB_CAPITAL);
	else
		bChar = 0x30;
	return bChar;
}

BYTE Hex2TwoChar(BYTE ucHex, char *cHight, char *cLow)
{
	*cHight = Hex2Char(ucHex >> 4);
	*cLow = Hex2Char(ucHex & 0x0F);
	return 0;
}

BYTE ByteToBCD(BYTE ucHex)
{
	return ((BYTE)(ucHex / 10)) * 16 + ucHex % 10;
}
