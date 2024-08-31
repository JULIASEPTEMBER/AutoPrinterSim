#pragma once

// CMySocket ÃüÁîÄ¿±ê
class C_ChatDlg;
class CMySocket : public CAsyncSocket
{
public:
	C_ChatDlg* m_pDlg;


	CMySocket();
	virtual ~CMySocket();
	virtual void OnReceive(int nErrorCode);
	void SetParent(C_ChatDlg* pDlg);
};


