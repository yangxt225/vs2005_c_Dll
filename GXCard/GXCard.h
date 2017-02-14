/************************************************************************/
/* 广西交通一卡通 通信系统 主文件.
*/
/************************************************************************/
#ifndef __GXCARD_H__
#define __GXCARD_H__


// GXCARD_EXPORTS ：可以在项目属性的预编译器中设置.
#ifdef GXCARD_EXPORTS
#define GXCARD_API __declspec(dllexport)
#else
#define GXCARD_API __declspec(dllimport)
#endif

#ifndef EXTERN_C
#define EXTERN_C    extern "C"
#endif

/*用于测试动态库是否成功导出接口*/
EXTERN_C int GXCARD_API TestFunc(char* input, char *output);



#endif



