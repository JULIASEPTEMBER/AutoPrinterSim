#pragma once


// C_ChatDlg 对话框


#include "MySocket.h"

#include "ListeningSocket.h"
#include "ClientSocket.h"
#include "afxwin.h"
class CJekoAutoMachineServer;

class C_ChatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C_ChatDlg)

public:
	C_ChatDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_ChatDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_TCPIPTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	CMySocket m_sConnectSocket;
	CJekoAutoMachineServer* pJekoAutoMachineServer; 
	void rec(void);
	//listen
	CListeningSocket* m_pSocket;
	void OnAccept(void);
	void Create();
	BYTE btReceFromServer[10000];
	UINT nLenbtReceFromServer;
	call_TCP_ServerGet pCall;
	int CALLBACK ExchangeData(int hhv, PLCIDECALLBACK pFC, void *pParam);//连接函数
	PLCIDECALLBACK Funname;               //定义 函数名 
	CEdit m_Edit_Output;
	PLCIDECALLBACK pFC_Get;
	CClientSocket* pThisSock;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonConnect();
	CComboBox m_Combo_Type;
	CEdit m_Edit_IpLocation;
	CEdit m_Edit_Port;
	CEdit m_Edit_Send;
	void ConnectServer(int port = 0);
	void ConnectClient(CString csIP, int port = 0);
	void GetHostAddresss(CString &strlPAddr); 
	void SaveInputInformations();
	void ReadInputInformations();
	Save_TCPINFO m_Save_TCPINFO;
	void Sendinfo_char(char* cc, UINT nLen);
	void Out_SetConnect(int i);
	struct Description_Struct
	{
		UINT nIP;//socket地址
		UINT nCode;//工号
		UINT nType;
	};//to remember each client connected to our server and let the nCode varify during the Pad's self intro
	Description_Struct SaveClientSocket[200];//new a 200 length prop saving buffer 
	int nCount_SaveClientSocket;//count for the amount of client socket info struct
	
	C_ChatDlg* pChatDlgSub;//pointer to this dialog(useless)
	void c2w(wchar_t *pwstr,size_t &len,const char *str);//change char into wchar
	char *w2c(char *pcstr,const wchar_t *pwstr, size_t& len);//change wide char into char
	void Out_Set_GetInfo_Translate(WCHAR *wc, UINT nLen);//while there exist buffer from server then we use this function to translate
	struct ExchangeKeywords
	{
		WCHAR wcGot[255];
	};
	ExchangeKeywords m_ExchangeKeywords[255];//save the data from stack and when the count
	void CheckSucceed(WCHAR* wcSource);//input the source pointer 
	void OutputJasonCode();//ready to replace all informations in jason edit show
	int QuickReplace_Buffer(WCHAR *buffer, UINT nLen, WCHAR *wcSource, UINT nLenS, WCHAR *wcTarget, UINT nLenT);//replace the source keyword into target and return the total length 
	int CheckEnd_OrNextStep(WCHAR* wc, UINT nLen);//thiswill represent if this is the last row
	afx_msg void OnBnClickedButtonDisconnect();
	afx_msg void OnBnClickedButtonDisconnect2();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnMyMessage(WPARAM w,LPARAM l);
};
