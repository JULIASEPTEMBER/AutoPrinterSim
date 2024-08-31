// SetOperaGuid.cpp : 实现文件
//

#include "stdafx.h"
#include "Digital_Signage.h"
#include "SetOperaGuid.h"
#include "afxdialogex.h"


// CSetOperaGuid 对话框

IMPLEMENT_DYNAMIC(CSetOperaGuid, CDialogEx)

CSetOperaGuid::CSetOperaGuid(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetOperaGuid::IDD, pParent)
	, m_R1(0)
	, m_R2(0)
	, m_R3(0)
	, m_R4(0)
	, m_R5(0)
	, m_R6(0)
	, m_R7(0)
	, m_R8(0)
	, m_R9(0)
	, m_R10(0)
	, m_R11(0)
	, m_R12(0)
	, m_R13(0)
	, m_R14(0)
	, m_R15(0)
	, m_R16(0)
	, m_R17(0)
	, m_R18(0)
	, m_R19(0)
	, m_R20(0)
	, m_R21(0)
	, m_R22(0)
	, m_R23(0)
	, m_R24(0)
	, m_R25(0)
	, m_R26(0)
	, m_R27(0)
	, m_R28s(1)
	, m_R29(0)
	, m_R30(0)
{

}

CSetOperaGuid::~CSetOperaGuid()
{
}

void CSetOperaGuid::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSetOperaGuid, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SETALL, &CSetOperaGuid::OnBnClickedButtonSetall)
	ON_BN_CLICKED(IDC_BUTTON_CHECK_BLANK, &CSetOperaGuid::OnBnClickedButtonCheckBlank)
END_MESSAGE_MAP()


// CSetOperaGuid 消息处理程序


	void CSetOperaGuid::Create()
	{
		CDialog::Create(CSetOperaGuid::IDD);
	}





	void CSetOperaGuid::OnBnClickedButtonCheckBlank()
	{
		((CButton *)GetDlgItem(IDC_RADIO_1 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_2 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_3 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_4 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_5 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_6 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_7 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_8 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_9 ))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_10))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_11))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_12))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_13))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_14))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_15))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_16))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_17))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_18))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_19))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_20))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_21))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_22))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_23))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_24))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_25))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_26))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_27))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_28))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_29))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_30))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_31))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_32))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_33))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_34))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_35))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_36))->SetCheck(FALSE);



		// TODO: 在此添加控件通知处理程序代码
	}
