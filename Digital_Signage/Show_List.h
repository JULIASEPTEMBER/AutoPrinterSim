#pragma once
#include "afxcmn.h"


// CShow_List 对话框

class CShow_List : public CDialogEx
{
	DECLARE_DYNAMIC(CShow_List)

public:
	CShow_List(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShow_List();

// 对话框数据
	enum { IDD = IDD_DIALOG_SHOW_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void Create();
	CTabCtrl m_Tab_OutputList;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	void SetWindowText_Needed(CString cs, int x, int y);
	void OutputLamp(int prop);
};
