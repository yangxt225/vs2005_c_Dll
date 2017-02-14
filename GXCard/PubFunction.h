#ifndef __PUBFUNCTION_H__
#define __PUBFUNCTION_H__


// 写日志，日志文件位于当前目录下
void WriteLog(char *fmt, ...);

// 字符转Hex
BYTE Char2Hex(char ch);
BYTE TwoChar2Hex(char lchar, char rchar);
/*Hex 转字符
如：输入"20", Hex进制为"14", 输出字符为"14".
用于报文头转换
*/ 

int Dword2Hex(DWORD value, char *output);

BYTE Hex2Char(BYTE ucHex);
BYTE Hex2TwoChar(BYTE ucHex, char *cHight, char *cLow);

/*BCD码：用4位二进制数来表示1位十进制数中的0~9这10个数码
	返回：BCD码
	参数：传入10进制数
	如: 输入入"20"，输出BCD码值 "20". 可以用于日期YYYYMMDD的转换。
*/
BYTE	ByteToBCD(BYTE ucHex);


#endif


