// Show_List.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Digital_Signage.h"
#include "Show_List.h"
#include "afxdialogex.h"


// CShow_List �Ի���

IMPLEMENT_DYNAMIC(CShow_List, CDialogEx)

CShow_List::CShow_List(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShow_List::IDD, pParent)
{

}

CShow_List::~CShow_List()
{
}

void CShow_List::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab_OutputList);
}


BEGIN_MESSAGE_MAP(CShow_List, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CShow_List::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CShow_List ��Ϣ�������
void CShow_List::Create()
{
	CDialog::Create(CShow_List::IDD);
	m_Tab_OutputList.InsertItem(1, L"�б�鿴1");
	m_Tab_OutputList.InsertItem(2, L"�б�鿴2");
	m_Tab_OutputList.InsertItem(3, L"�б�鿴3");
	m_Tab_OutputList.SetWindowTextW(L"hahahsh"); 
	//ShowWindow(SW_SHOW);
}


void CShow_List::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{ 
	RECT rc;
	HBRUSH hbr;
	HDC dc = ::GetDC(m_Tab_OutputList.m_hWnd);

	::GetClientRect(m_hWnd, &rc);
	rc.top += 40;
	hbr= CreateSolidBrush(RGB(255,255,255)); 
	::FillRect(dc, &rc, hbr);
	::DeleteDC(dc);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	//OutputLamp(1);
}

void CShow_List::SetWindowText_Needed(CString cs, int x, int y)
{
	RECT rc;
	HBRUSH hbr;
	HDC dc = ::GetDC(m_Tab_OutputList.m_hWnd);

	::GetClientRect(m_hWnd, &rc);
	rc.top += 40;
	hbr= CreateSolidBrush(RGB(255,255,255));  
	::DeleteDC(dc);
	 dc = ::GetDC(m_Tab_OutputList.m_hWnd);
	 ::TextOutW(dc, x, y, cs, cs.GetLength() );
	::DeleteDC(dc);
}


void CShow_List::OutputLamp(int prop)
{
	RECT rc;
	HBRUSH hbr;
	HDC dc = ::GetDC(m_Tab_OutputList.m_hWnd);

	::GetClientRect(m_hWnd, &rc);
	rc.top += 40;  
	hbr= CreateSolidBrush(RGB(255,0,0)); 
	::FillRect(dc, &rc, hbr);
	::TextOutW(dc, 100, 100, L"Ա���ں���                ", 20);
	::DeleteDC(dc);
}

