/************************************************************************/
/* ������ͨһ��ͨ ͨ��ϵͳ ���ļ�.
*/
/************************************************************************/
#ifndef __GXCARD_H__
#define __GXCARD_H__


// GXCARD_EXPORTS ����������Ŀ���Ե�Ԥ������������.
#ifdef GXCARD_EXPORTS
#define GXCARD_API __declspec(dllexport)
#else
#define GXCARD_API __declspec(dllimport)
#endif

#ifndef EXTERN_C
#define EXTERN_C    extern "C"
#endif

/*���ڲ��Զ�̬���Ƿ�ɹ������ӿ�*/
EXTERN_C int GXCARD_API TestFunc(char* input, char *output);



#endif



