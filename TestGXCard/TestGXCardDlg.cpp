// TestGXCardDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTestGXCardDlg �Ի���




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


// CTestGXCardDlg ��Ϣ�������

BOOL CTestGXCardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//hinst = LoadLibrary("GXCard");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestGXCardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CTestGXCardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// �����Ϣ�ӿ�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	cHeadTrans[14] = '\0';		// �ַ�����
	for (int i=0; i<7; ++i)
		Hex2TwoChar(output[i], &cHeadTrans[2*i], &cHeadTrans[2*i+1]);
	AppendText(&m_rEditOut, cHeadTrans, FALSE);
	AppendText(&m_rEditOut, &output[7]);
}

