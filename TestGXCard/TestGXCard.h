// TestGXCard.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestGXCardApp:
// �йش����ʵ�֣������ TestGXCard.cpp
//

class CTestGXCardApp : public CWinApp
{
public:
	CTestGXCardApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestGXCardApp theApp;