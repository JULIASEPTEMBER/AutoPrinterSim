#pragma once
#include "afxwin.h"


// CLogin_dlg �Ի���

class CLogin_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin_dlg)

public:
	CLogin_dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogin_dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
