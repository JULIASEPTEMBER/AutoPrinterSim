// ClientSocket.cpp : 实现文件
//

#include "stdafx.h"
//#include "TCP.h"
#include "ClientSocket.h"
#include "JekoAutoMachineServer.h"
//#include "TCPDlg.h"
#include "resource.h"

// CClientSocket
// 
CClientSocket::CClientSocket(C_ChatDlg* pDlg)
	: nLen_bt_Buffer(0)
	, place(0)
	, close(0)
{

	pParDlg = pDlg;
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 成员函数


void CClientSocket::Initialize(PLCIDECALLBACK pFC)
{
	ExchangeData(0, pFC, 0);
}


void c2w(wchar_t *pwstr,size_t len,const char *str)
{
	if(str)
	{
		size_t nu = strlen(str);

		size_t n =(size_t)MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,NULL,0);

		if(n>=len)n=len-1;

		MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,pwstr,(int)n);

		pwstr[n]=0;

	}
}


void CClientSocket::OnReceive(int nErrorCode)//读取客户端接收到并且发送出去
{
	// TODO: 在此添加专用代码和/或调用基类

	//WCHAR *pBuf=new WCHAR[1025];///接收处理
	//WCHAR inPut[1024];
	//int nBufSize=1024;
	//CString strReceived;
	//  RECEIVE________________________________
	nLen_bt_Buffer = Receive(bt_Buffer,1024);
	bt_Buffer[nLen_bt_Buffer] = 0;

	pJekoAutoMachineServer->_TranslateClient(place, bt_Buffer, nLen_bt_Buffer);

	//Send(bt_Buffer,nLen_bt_Buffer);///////////////////	
	//CString cs;
	//cs.Format(L"%x", (UINT*)bt_Buffer);
	//OUT_Socket_GetInfo((char*)bt_Buffer, nLen_bt_Buffer, (UINT)this, (UINT)pParDlg);
	////WCHAR cc[1000];
	////接收到客户端消息
	//c2w(inPut, nLen_bt_Buffer * 2, (char*)bt_Buffer);
	//GetInfoFromClient((WCHAR*)inPut, nLen_bt_Buffer);
	//delete pBuf;

	CSocket::OnReceive(nErrorCode);
}


int CALLBACK CClientSocket::ExchangeData(int hhv, PLCIDECALLBACK pFC, void *pParam)
{
	Funname = pFC;                     //连接函数
	return 0;
}


void CClientSocket::OnSend(int nErrorCode)
{
	if(close)
	{
		Close();
	}
}
 

void CClientSocket::OnClose(int nErrorCode)
{
		Close();
	CSocket::OnClose(nErrorCode);

}