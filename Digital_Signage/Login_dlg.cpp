// Login_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Digital_Signage.h"
#include "Login_dlg.h"
#include "afxdialogex.h"


// CLogin_dlg 对话框

IMPLEMENT_DYNAMIC(CLogin_dlg, CDialogEx)

	CLogin_dlg::CLogin_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin_dlg::IDD, pParent)
	, loginStyle(0)
{

}

CLogin_dlg::~CLogin_dlg()
{
}

void CLogin_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_Eidt_ID);
	DDX_Control(pDX, IDC_EDIT_PASSWARD, m_Edit_Passward);
}


BEGIN_MESSAGE_MAP(CLogin_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLogin_dlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CLogin_dlg::OnBnClickedButtonExit)
END_MESSAGE_MAP()


// CLogin_dlg 消息处理程序


void CLogin_dlg::OnBnClickedButtonLogin()
{
	m_Eidt_ID;
	m_Edit_Passward;
	WCHAR wc[100], wcc[100];
	UINT nLen;
	GetInfoFromEdit(&m_Eidt_ID, wc, nLen);
	CString cs;
	cs = L"admin";
	wcscpy(wcc, cs);
	if(nLen == 0)
		return;
	for(int i = 0 ;i < nLen; i ++)
	{
		if(wcc[i] != wc[i])
		{	loginStyle = 1;

		}
	}
	GetInfoFromEdit(&m_Edit_Passward, wc, nLen);
	cs = L"admin1234567";
	wcscpy(wcc, cs);
	if(nLen == 0)
		return;
	for(int i = 0 ;i < nLen; i ++)
	{
		if(wcc[i] != wc[i])
		{
			loginStyle = 1;

		}
	}
	loginStyle = 1 - loginStyle;
	Out_Opendlg();
	// TODO: 在此添加控件通知处理程序代码
}


void CLogin_dlg::OnBnClickedButtonExit()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CLogin_dlg::Create()
{
	CDialog::Create(CLogin_dlg::IDD);
	ShowWindow(SW_SHOW);
	int cx,cy; 
	cx = GetSystemMetrics(SM_CXSCREEN); 
	cy = GetSystemMetrics(SM_CYSCREEN); 



	CRect rcTemp; 
	rcTemp.BottomRight() = CPoint(cx, cy); 
	rcTemp.TopLeft() = CPoint(0, 0); 
	MoveWindow(&rcTemp);
}


void CLogin_dlg::GetInfoFromEdit(CEdit* edit, WCHAR* wc, UINT& nLen)
{


	nLen = edit->GetWindowTextLengthW();
	edit->GetWindowTextW(wc, nLen + 1);
}
