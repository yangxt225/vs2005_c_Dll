#ifndef __PUBFUNCTIONCPY_H__
#define __PUBFUNCTIONCPY_H__

// д��־����־�ļ�λ�ڵ�ǰĿ¼��
void WriteLog(char *fmt, ...);

// �ַ�תHex
BYTE Char2Hex(char ch);
BYTE TwoChar2Hex(char lchar, char rchar);
/*Hex ת�ַ�
�磺����"20", Hex����Ϊ"14", ����ַ�Ϊ"14".
*/ 
BYTE Char2Hex(char ch);
BYTE Hex2TwoChar(BYTE ucHex, char *cHight, char *cLow);

/*BCD�룺��4λ������������ʾ1λʮ�������е�0~9��10������
	���أ�BCD��
	����������10������
	��: ������"20"�����BCD��ֵ "20". ������������YYYYMMDD��ת����
*/
BYTE	ByteToBCD(BYTE ucHex);

#endif


