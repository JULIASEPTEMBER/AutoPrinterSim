#pragma once

// CListeningSocket ÃüÁîÄ¿±ê
class C_ChatDlg;
class CListeningSocket : public CSocket
{
public:
	C_ChatDlg* m_pDlg;
	CListeningSocket(C_ChatDlg* pDlg);
	virtual ~CListeningSocket();
	virtual void OnAccept(int nErrorCode);
};


