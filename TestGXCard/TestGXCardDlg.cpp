// TestGXCardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include <afxsock.h>
#include "TestGXCard.h"
#include "TestGXCardDlg.h"
#include "PubFunctionCpy.h"
#include "GXCard.h"

#pragma comment(lib,"GXCard.lib") 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//typedef int (*fnTestFunc)(char *, char *);
//typedef int (*fnInitServerConfig)(char *, int);
//typedef int (*fnCommon_Initialize)(const int);
//typedef int (*fnCommon_Destroy)(const int);
//typedef int (*fnCashIncrease)(const int, const DWORD, PPURCHASEINCREASE, BOOL);

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestGXCardDlg 对话框




CTestGXCardDlg::CTestGXCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestGXCardDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestGXCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_rEditOut);
}

BEGIN_MESSAGE_MAP(CTestGXCardDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CTestGXCardDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTestGXCardDlg 消息处理程序

BOOL CTestGXCardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//hinst = LoadLibrary("GXCard");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void CTestGXCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestGXCardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CTestGXCardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 输出信息接口
void CTestGXCardDlg::AppendText(CRichEditCtrl *pRichEdit, LPCTSTR lpszText, BOOL isNewLine/* = TRUE*/)
{
	char szOut[1024] = {0};
	strcpy(szOut, lpszText);
	if (isNewLine)
		strcat(szOut,"\n");
	int nLen = pRichEdit->GetWindowTextLength () + 1; 
	pRichEdit->SetFocus (); 
	pRichEdit->SetSel (nLen, nLen); 
	pRichEdit->ReplaceSel (szOut); 
}

void CTestGXCardDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	char output[512] = {0};
	char input[512] = {0};
	//fnTestFunc TestFunc;
	//TestFunc = (fnTestFunc)GetProcAddress(hinst, "TestFunc");
	//if (TestFunc == NULL)
	//	return;
	TestFunc(input, output);
	//output[50] = '\0';
	char cHeadTrans[15] = {0};
	memset(cHeadTrans, 0, sizeof(cHeadTrans));
	cHeadTrans[14] = '\0';		// 字符结束
	for (int i=0; i<7; ++i)
		Hex2TwoChar(output[i], &cHeadTrans[2*i], &cHeadTrans[2*i+1]);
	AppendText(&m_rEditOut, cHeadTrans, FALSE);
	AppendText(&m_rEditOut, &output[7]);
}

