#pragma once
#include "BasicData.h"

// CClientSocket ÃüÁîÄ¿±ê
class C_ChatDlg;
class CJekoAutoMachineServer;
class CClientSocket : public CSocket
{
public:
	CClientSocket(C_ChatDlg* pDlg);
	virtual ~CClientSocket();
	void Initialize(PLCIDECALLBACK pFC);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	BYTE bt_Buffer[10000];
	int close;
	UINT nLen_bt_Buffer;
	
	CJekoAutoMachineServer* pJekoAutoMachineServer; 
	int place;
	int CALLBACK ExchangeData(int hhv, PLCIDECALLBACK pFC, void *pParam); 
	PLCIDECALLBACK Funname;              
	call_TCP_ServerGet pCall;
	void GetInfoFromClient(WCHAR *wc, UINT nLen);//output edit view information
	void OUT_Socket_GetInfo(char* cc, UINT nLen, UINT pInput, UINT Par); //a bridge function to transfer informations to other class
	C_ChatDlg* pParDlg;
	
};


