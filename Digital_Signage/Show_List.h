#pragma once
#include "afxcmn.h"


// CShow_List �Ի���

class CShow_List : public CDialogEx
{
	DECLARE_DYNAMIC(CShow_List)

public:
	CShow_List(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShow_List();

// �Ի�������
	enum { IDD = IDD_DIALOG_SHOW_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void Create();
	CTabCtrl m_Tab_OutputList;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	void SetWindowText_Needed(CString cs, int x, int y);
	void OutputLamp(int prop);
};
