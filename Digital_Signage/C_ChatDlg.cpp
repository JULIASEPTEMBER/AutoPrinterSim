// C_ChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Digital_Signage.h"
#include "C_ChatDlg.h"
#include "afxdialogex.h"
#include "JekoAutoMachineServer.h"


// C_ChatDlg 对话框

IMPLEMENT_DYNAMIC(C_ChatDlg, CDialogEx)
	C_ChatDlg::C_ChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_ChatDlg::IDD, pParent)
	, nCount_SaveClientSocket(0)
{
	pJekoAutoMachineServer = new CJekoAutoMachineServer;
	pJekoAutoMachineServer->pEdit = &m_Edit_Output;
	pJekoAutoMachineServer->_Init();
}

C_ChatDlg::~C_ChatDlg()
{
}

void C_ChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RECEIVE, m_Edit_Output);
	DDX_Control(pDX, IDC_COMBO_SER_CLI, m_Combo_Type);
	DDX_Control(pDX, IDC_EDIT_IP_LOCATION, m_Edit_IpLocation);
	DDX_Control(pDX, IDC_EDIT_PORT, m_Edit_Port);
	DDX_Control(pDX, IDC_EDIT_SEND, m_Edit_Send);
}


BEGIN_MESSAGE_MAP(C_ChatDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &C_ChatDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &C_ChatDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &C_ChatDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT2, &C_ChatDlg::OnBnClickedButtonDisconnect2)
	ON_WM_KEYUP()
	ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()


// C_ChatDlg 消息处理程序




void C_ChatDlg::rec(void)///读取服务器
{
	WCHAR  pBuf [1025];//二次反馈
	char cc[1024];
	size_t nBufSize=1024;   
	nBufSize = m_sConnectSocket.Receive(cc, 1024); 
	cc[nBufSize] = 0;
	//receive successfully?
	if (nLenbtReceFromServer!=SOCKET_ERROR)
	{ 
		nBufSize =  nBufSize * 2;
		c2w(pBuf, nBufSize, cc);
		pBuf[nBufSize] = 0;
		m_Edit_Output.SetWindowText((WCHAR*)pBuf);//="ss";//+=*pBuf;//读取服务器
		Out_Set_GetInfo_Translate((WCHAR*)pBuf, nBufSize);

		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox(L"信息接收错误！",MB_OK|MB_ICONSTOP);
	}


}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_pDlg->rec();
	CAsyncSocket::OnReceive(nErrorCode);
}


void CListeningSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CSocket::OnAccept(nErrorCode);

	m_pDlg->OnAccept();
}


void C_ChatDlg::OnAccept(void)
{
	static UINT nSaveIp[10];
	static UINT nCount;
	CClientSocket* pSocket=new CClientSocket(this);

	CString cs;
	//接受连接请求
	//SaveClientSocket[nCount_SaveClientSocket].nIP = (UINT)pSocket;
	//SaveClientSocket[nCount_SaveClientSocket].nCode = 0;
	//nCount_SaveClientSocket ++;

	if (m_pSocket->Accept(*pSocket))
	{
		//对连接套接字初始化
		pSocket->Initialize(pFC_Get);
		pThisSock = pSocket;
		//cs.Format(L"有一个客户端已经连接进入我们的服务器\r\n");
		//m_Edit_Output.SetWindowTextW(cs);//连接客户端
		int get = pJekoAutoMachineServer->_SeekForEmpty(pSocket);
		if(get != -1)
		{
			pSocket->place =  get;
			pSocket->pJekoAutoMachineServer =  pJekoAutoMachineServer;
			cs.Format(L"有一个客户端已经连接进入我们的服务器\r\n");
			//m_Edit_Output.SetWindowTextW(cs);//连接客户端
		}
		else
		{
			cs.Format(L"out of range 12235\r\n");
			m_Edit_Output.SetWindowTextW(cs);//连接客户端
		}
		//假如连接列表
		//Out_SetConnect(1);
		//m_connectionList.AddTail(pSocket);
	}
	else
		delete pSocket;

}




void C_ChatDlg::OnBnClickedButtonSend()
{

	UINT nLen;
	WCHAR wc[1025];
	char cc[1024];
	nLen = m_Edit_Send.GetWindowTextLengthW(); 
	m_Edit_Send.GetWindowTextW(wc, nLen + 1);
	if(m_Save_TCPINFO.type == 1)//在服务器中发送消息到客户端
	{
		w2c(cc, wc, nLen);
		pThisSock->Send(cc, nLen);
	}
	else//在客户端中发送消息给服务器
	{ 
		w2c(cc, wc, nLen); 
		m_sConnectSocket.Send(cc, nLen);
	} 
	// TODO: 在此添加控件通知处理程序代码
}


void C_ChatDlg::ConnectServer(int port)
{

	//创建侦听套接字对象
	m_pSocket=new CListeningSocket(this);
	//用获得的通信端口侦听
	if (m_pSocket->Create(port))
	{
		CString strTemp; 
		strTemp.Format(L"端口号：%4d",port); 

		CString cs;
		GetHostAddresss(cs); 
		if (!m_pSocket->Listen())
		{
			AfxMessageBox(L"侦听失败！");
			CDialog::OnOK();
			//	return TRUE;
		}
	}
}


void C_ChatDlg::ConnectClient(CString csIP, int port)
{
	WCHAR wc[100];
	wcscpy(wc, csIP);
	UpdateData(TRUE);
	m_sConnectSocket.Create();	
	m_sConnectSocket.Connect(wc,port);//哪个小朋友这么幸运呢
}


void C_ChatDlg::GetHostAddresss(CString &strlPAddr)
{
	char HostName[100];
	gethostname(HostName, sizeof(HostName));
	hostent* hn;
	hn = gethostbyname(HostName);
	strlPAddr = inet_ntoa(*(struct in_addr *)hn->h_addr_list[0]);
}


void C_ChatDlg::Create()
{
	CDialog::Create(C_ChatDlg::IDD);
	//ShowWindow(SW_SHOW);
	ReadInputInformations();
	pChatDlgSub = this;
	m_sConnectSocket.SetParent(this);
	pJekoAutoMachineServer->m_hWnd = m_hWnd;

}


void C_ChatDlg::SaveInputInformations()
{
	HANDLE hFile;
	UINT nLen ;
	DWORD dw;
	CString cs;
	WCHAR wc[200];

	::DeleteFile(L"SaveLinkingInformations.julia1");
	hFile = ::CreateFile(L"SaveLinkingInformations.julia1", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  


	m_Combo_Type.GetWindowText(wc, 2);
	m_Save_TCPINFO.type = wc[0] == 'S' ? 1 : 2;

	nLen = m_Edit_IpLocation.GetWindowTextLengthW();
	m_Edit_IpLocation.GetWindowText(wc, nLen + 1);
	for(int i = 0 ;i <  nLen + 1 ; i ++)
		m_Save_TCPINFO.wcIP[i] = wc[i];

	nLen = m_Edit_Port.GetWindowTextLengthW();
	m_Edit_Port.GetWindowText(wc, nLen + 1);
	m_Save_TCPINFO.port = _wtoi(wc);

	::WriteFile(hFile, (BYTE*)&m_Save_TCPINFO, sizeof(Save_TCPINFO), &dw, NULL);

	::CloseHandle(hFile);



}


void C_ChatDlg::ReadInputInformations()
{
	HANDLE hFile;
	UINT nLen ;
	DWORD dw;
	CString cs;

	hFile = ::CreateFile(L"SaveLinkingInformations.julia1", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	nLen = ::GetFileSize(hFile, NULL);

	if(!nLen)
	{
		::CloseHandle(hFile);
		return;
	}

	::ReadFile(hFile, (BYTE*)&m_Save_TCPINFO, nLen, &dw, NULL);
	::CloseHandle(hFile);

	m_Combo_Type.SetWindowTextW(m_Save_TCPINFO.type == 1 ? L"Server" : L"Client");
	m_Edit_IpLocation.SetWindowTextW(m_Save_TCPINFO.wcIP);
	cs.Format(L"%d", m_Save_TCPINFO.port);
	m_Edit_Port.SetWindowTextW(cs);



	//m_Save_TCPINFO
}


void C_ChatDlg::Sendinfo_char(char* cc, UINT nLen)
{

	pThisSock->Send(cc, nLen);
}


void CClientSocket::GetInfoFromClient(WCHAR *wc, UINT nLen)
{

	pParDlg->m_Edit_Output.SetWindowTextW(wc);//读取客户端 
}


void C_ChatDlg::c2w(wchar_t *pwstr,size_t &len,const char *str)

{
	if(str)
	{

		size_t nu = strlen(str);

		size_t n =(size_t)MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,NULL,0);

		//if(n>=len)n=len-1;

		MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,pwstr,(int)n);

		pwstr[n]=0;
		len = n;
	}

}


char *C_ChatDlg::w2c(char *pcstr,const wchar_t *pwstr, size_t& len)

{

	int nlength=wcslen(pwstr);

	//获取转换后的长度
	int nbytes = WideCharToMultiByte( 0, // specify the code page used to perform the conversion
		0,         // no special flags to handle unmapped characters
		pwstr,     // wide character string to convert
		nlength,   // the number of wide characters in that string
		NULL,      // no output buffer given, we just want to know how long it needs to be
		0,

		NULL,      // no replacement character given
		NULL );    // we don't want to know if a character didn't make it through the translation

	// make sure the buffer is big enough for this, making it larger if necessary
	/*if(nbytes>len)   nbytes=len;
	else*/ len = nbytes;
	// 通过以上得到的结果，转换unicode 字符为ascii 字符
	WideCharToMultiByte( 0, // specify the code page used to perform the conversion
		0,         // no special flags to handle unmapped characters
		pwstr,   // wide character string to convert
		nlength,   // the number of wide characters in that string
		pcstr, // put the output ascii characters at the end of the buffer
		nbytes,                           // there is at least this much space there
		NULL,      // no replacement character given
		NULL ); 
	return pcstr ;

}


void C_ChatDlg::OnBnClickedButtonDisconnect()
{

	if(m_Save_TCPINFO.type == 1)//在服务器中发送消息到客户端
	{ 
		m_sConnectSocket.Close();//(cc, nLen);
	}
	else//在客户端中发送消息给服务器
	{  
		//pThisSock->ShutDown();//(cc, nLen);
		pThisSock->Close();//(cc, nLen);
	} 
	// TODO: 在此添加控件通知处理程序代码
}


void C_ChatDlg::OnBnClickedButtonDisconnect2()
{


	CString cs, cs0 = L"";
	int temp[10];
	int Prime[3] = {1039, 1049, 1051};
	char info[100000], total[100000];
	UINT nGet;
	total[0] = 0;
	int from = 0;//100000000
	for(UINT i = from; i < from + 100; i ++)
	{
		for(UINT j = 0; j < 10; j ++)
		{
			if(j == 3)
				i = i;
			//i += 100000000;
			pJekoAutoMachineServer->_Encry_Code(info, i, j);strcat(total, info);
			if(pJekoAutoMachineServer->_Decrypt(&nGet, info) && nGet == i){strcat(total, "correct!\t");}
			else {strcat(total, "error!!!!!!!!!!!!!!!!!!!!!!!\r\n\r\n\r\n\r\n");}
			//i-=100000000;
		}
	}
pJekoAutoMachineServer->_Decrypt(&nGet, "49311306");
nGet = nGet;
	//_Encry_Code(info, 0, 0);
	//strcat(total, info);
	//strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 1);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 2);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 3);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 4);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 5);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 6);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 7);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 8);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	//_Encry_Code(info, 0, 9);strcat(total, info);strcat(total, "\r\n");
	//_Decrypt(info);
	WCHAR wc[100000];
	UINT nLen = 0;
	c2w(wc, nLen, total);
	m_Edit_Output.SetWindowTextW(wc);
	//MessageBoxA(0, total, 0, 0);
return;



	for(int i = 0; i < 20; i ++)
	{
		temp[0] = i + Prime[0];
		temp[1] = i + Prime[1];

		temp[2] = Prime[2] * i;
		temp[3] = 0
			+ ((temp[0] / 1000) % 10) * 10000000
			+ ((temp[1] / 1000) % 10) * 1000000
			+ ((temp[0] / 100) % 10 ) * 100000
			+ ((temp[1] / 100) % 10	) * 10000
			+ ((temp[0] / 10) % 10	) * 1000
			+ ((temp[1] / 10) % 10	) * 100
			+ ((temp[0] / 1) % 10	) * 10
			+ ((temp[1] / 1) % 10	) * 1;
		temp[4] = (temp[3] / 10000000) % 10 
				+ (temp[3] / 1000000) % 10
				+ (temp[3] / 100000) % 10
				+ (temp[3] / 10000) % 10;
		temp[5] = (temp[3] / 1000) % 10 
				+ (temp[3] / 100) % 10
				+ (temp[3] / 10) % 10
				+ (temp[3] / 1) % 10;
		temp[6] = temp[4] * temp[5];
		temp[7] = temp[6] + temp[2];
		temp[8] = temp[3] * 100 + (temp[7] % 100);
		cs.Format(L"ori: %5d  encr:%d\r\n", i, temp[8]);
		cs0 += cs;
	}
	MessageBox(cs0);

	//((CClientSocket*)pJekoAutoMachineServer->st_TCPSer[0].client.pClass)->OnClose(0);
	//pJekoAutoMachineServer->_ClearClientTemp(0);
	// TODO: 在此添加控件通知处理程序代码
}


void C_ChatDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}



LRESULT C_ChatDlg::OnMyMessage(WPARAM wParam, LPARAM lParam) {

	_SENDMSG* pp = (_SENDMSG*)&_outsendformat;
	switch(wParam)
	{
	case POST__DISCONNECT:
		((CClientSocket*)(pJekoAutoMachineServer)->st_TCPSer[(int)lParam].client.pClass)->OnClose(0);
		((CJekoAutoMachineServer*)pJekoAutoMachineServer)->_ClearClientTemp((int)lParam);
		delete ((CClientSocket*)(pJekoAutoMachineServer)->st_TCPSer[(int)lParam].client.pClass);
		break;
	case POST________SEND:
		{
			((CClientSocket*)(pJekoAutoMachineServer)->st_TCPSer[(int)pp->ID].client.pClass)->Send(pp->info, pp->len);
		}
		break;
	case POST__SEND_CLOSE:
		{
			((CClientSocket*)(pJekoAutoMachineServer)->st_TCPSer[(int)pp->ID].client.pClass)->Send(pp->info, pp->len);
			((CClientSocket*)(pJekoAutoMachineServer)->st_TCPSer[(int)pp->ID].client.pClass)->OnClose(0);
			((CJekoAutoMachineServer*)pJekoAutoMachineServer)->_ClearClientTemp((int)pp->ID);
			if((pJekoAutoMachineServer)->st_TCPSer[(int)pp->ID].client.info) delete (pJekoAutoMachineServer)->st_TCPSer[(int)pp->ID].client.info;
			(pJekoAutoMachineServer)->st_TCPSer[(int)pp->ID].client.info = 0;
			delete ((CClientSocket*)(pJekoAutoMachineServer)->st_TCPSer[(int)pp->ID].client.pClass);
		}
		break;
	case POST______BEGSER:
		OnBnClickedButtonConnect();
		break;
	case POST_____MONITOR:
		{
			char cc[1000];
			UINT nLen = wcslen(cInfoMonitor);
			w2c(cc, cInfoMonitor, nLen);
			((C_ChatDlg*)_SendMonitor)->m_sConnectSocket.Send(cc, nLen);
			//((C_ChatDlg*)_SendMonitor)->m_sConnectSocket.Send(cInfoMonitor, nLen);
		}
		break;
	}
	return 1;
}
