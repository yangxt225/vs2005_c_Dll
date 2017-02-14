// TestGXCardDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTestGXCardDlg 对话框
class CTestGXCardDlg : public CDialog
{
// 构造
public:
	CTestGXCardDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTGXCARD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	HINSTANCE hinst;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedSetIP();

	// 信息输出接口
	void AppendText(CRichEditCtrl *pRichEdit, LPCTSTR lpszText, BOOL isNewLine = TRUE);
	
	int Res;			// 操作状态码(0:成功)
	CRichEditCtrl m_rEditOut;
	CString testOutStr;
	afx_msg void OnBnClickedOpenComm();
	
	CComboBox m_ComPort;
	int nPort;
	CEdit m_EditIncrease;
	afx_msg void OnBnClickedCaseIncrease();
public:
	afx_msg void OnCbnSelchangeComport();
};
