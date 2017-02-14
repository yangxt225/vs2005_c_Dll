// TestGXCardDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTestGXCardDlg �Ի���
class CTestGXCardDlg : public CDialog
{
// ����
public:
	CTestGXCardDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTGXCARD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	HINSTANCE hinst;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedSetIP();

	// ��Ϣ����ӿ�
	void AppendText(CRichEditCtrl *pRichEdit, LPCTSTR lpszText, BOOL isNewLine = TRUE);
	
	int Res;			// ����״̬��(0:�ɹ�)
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
