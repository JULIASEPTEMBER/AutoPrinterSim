#pragma once
#include "afxwin.h"


// CLogin_dlg 对话框

class CLogin_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin_dlg)

public:
	CLogin_dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLogin_dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Eidt_ID;
	CEdit m_Edit_Passward;
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonExit();
	void Create();
	void Out_Opendlg();
    void  GetInfoFromEdit(CEdit* edit, WCHAR* wc, UINT& nLen);
	int GetIntFromEidt(CEdit* edit);
	int loginStyle;


};
