// MySocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
///#include "cltst2.h"
#include "MySocket.h"
///#include "cltst2Dlg.h"


// CMySocket

CMySocket::CMySocket()
{m_pDlg=NULL;
}

CMySocket::~CMySocket()
{
}


// CMySocket ��Ա����


void CMySocket::SetParent(C_ChatDlg* pDlg)
{
	m_pDlg=pDlg;

}
