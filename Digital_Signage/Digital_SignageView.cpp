
// Digital_SignageView.cpp : CDigital_SignageView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Digital_Signage.h"
#endif

#include "Digital_SignageDoc.h"
#include "Digital_SignageView.h"
#include "JekoAutoMachineServer.h"
#include "CThreadOrderCatch.h"
int _SendMonitor = 0;
int _enableMonitor = 0;
WCHAR cInfoMonitor[1000];
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#define DELETE_INFO
// CDigital_SignageView
CDigital_SignageView* pThis;
IMPLEMENT_DYNCREATE(CDigital_SignageView, CView)

BEGIN_MESSAGE_MAP(CDigital_SignageView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDigital_SignageView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_COMMAND(ID_OUTPUT_BITMAP, &CDigital_SignageView::OnOutputBitmap)
	ON_WM_MBUTTONDOWN()
END_MESSAGE_MAP()

// CDigital_SignageView 构造/析构

CDigital_SignageView::CDigital_SignageView()
	: HasBeenConnect(0)
{
	// TODO: 在此处添加构造代码

}

CDigital_SignageView::~CDigital_SignageView()
{
}

BOOL CDigital_SignageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDigital_SignageView 绘制

void CDigital_SignageView::OnDraw(CDC* /*pDC*/)
{
	CDigital_SignageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDigital_SignageView 打印


void CDigital_SignageView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDigital_SignageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDigital_SignageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDigital_SignageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDigital_SignageView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDigital_SignageView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDigital_SignageView 诊断

#ifdef _DEBUG
void CDigital_SignageView::AssertValid() const
{
	CView::AssertValid();
}

void CDigital_SignageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDigital_SignageDoc* CDigital_SignageView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDigital_SignageDoc)));
	return (CDigital_SignageDoc*)m_pDocument;
}
#endif //_DEBUG


// CDigital_SignageView 消息处理程序


int CDigital_SignageView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	pThis = this;
	int i = 0;
	m_stOrderList.csOrder[i] = L"作业指导书"; i++;
	m_stOrderList.csOrder[i] = L"心跳"; i++;
	m_stOrderList.csOrder[i] = L"工号"; i++;
	m_stOrderList.csOrder[i] = L"工单计数"; i++;
	m_stOrderList.csOrder[i] = L"安灯呼叫"; i++;
	m_stOrderList.csOrder[i] = L"作业清单"; i++;
	m_stOrderList.csOrder[i] = L"文档查询"; i++;
	m_stOrderList.csOrder[i] = L"作业发放"; i++;
	m_stOrderList.csOrder[i] = L"站点:"; i++;


	//m_stOrderList.csOrder[i] = L"1"; i ++;
	//m_stOrderList.csOrder[i] = L"2"; i ++;
	//m_stOrderList.csOrder[i] = L"3"; i ++;
	//m_stOrderList.csOrder[i] = L"4"; i ++;
	//m_stOrderList.csOrder[i] = L"5"; i ++;
	//m_stOrderList.csOrder[i] = L"6"; i ++;
	//m_stOrderList.csOrder[i] = L"7"; i ++;
	//m_stOrderList.csOrder[i] = L"8"; i ++; 
	m_stOrderList.total = i;
	TestChangeWCHAR();
	//m_Show_Informations.SetParent(this);
	//ShowWindow(SW_HIDE);

	TCPCreatThread();//创建线程
	// TODO:  在此添加您专用的创建代码
	m_C_ChatDlg.Create();
	m_C_ChatDlg.m_Combo_Type.SetWindowText(L"Server");
	m_CChangeInfo_Send_Dlg.Create();

	//m_Login_dlg.Create();
	m_C_ChatDlg2.Create();
	m_C_ChatDlg2.m_Combo_Type.SetWindowText(L"Client");
	m_C_ChatDlg2.ShowWindow(SW_SHOW);

	_SendMonitor = (int)&m_C_ChatDlg2;

	RECT rc;
	//m_C_ChatDlg2.GetClientRect(&rc);
	//m_C_ChatDlg.MoveWindow(20, 20, rc.right - rc.left, rc.bottom - rc.top);
	//m_C_ChatDlg2.MoveWindow(600, 20, rc.right - rc.left, rc.bottom - rc.top);
	WCHAR wc[100];
	char CC[100];
	UINT nLen;
	ReadFile_InPath(L"连接ip.txt", (BYTE*)CC, nLen);
	CC[nLen] = 0;
	c2w(wc, nLen, CC);
#ifndef DELETE_INFO
	m_C_ChatDlg.ShowWindow(SW_SHOW);
	//m_C_ChatDlg2.ShowWindow(SW_SHOW);
#else

	m_C_ChatDlg2.m_Edit_IpLocation.SetWindowTextW(wc);
	m_C_ChatDlg.OnBnClickedButtonConnect();
	m_C_ChatDlg2.OnBnClickedButtonConnect();
	m_C_ChatDlg.ShowWindow(SW_HIDE);
	m_C_ChatDlg2.ShowWindow(SW_HIDE);

#endif
	m_Show_Informations.Create();
	m_CShow_List.Create();
	m_SetOperaGuid.Create();

	//OnLoadBitmap();
	return 0;
}


UINT TCPThreadProc(LPVOID pm)
{
	CString cs;
	cs = L"心跳";
	WCHAR wc[10];
	char cc[10];
	UINT nLen;
	wcscpy(wc, cs);
	pThis->w2c(cc, wc, nLen);
	cc[nLen] = 0;
	pThis->c2w(wc, nLen, cc);

	::Sleep(500);
	//pThis->m_C_ChatDlg.OnBnClickedButtonConnect();
	while (1)
	{
		::Sleep(10);
		pThis->m_C_ChatDlg.pJekoAutoMachineServer->_LOOPThread();
		//if(pThis->HasBeenConnect)
		//{
		//	pThis->m_C_ChatDlg.Sendinfo_char(cc, nLen);
		//	::Sleep(5000);
		//}
	}
	return 0;
}


void  CDigital_SignageView::TCPCreatThread(void)
{

	m_pThread_TCP =
		AfxBeginThread(TCPThreadProc, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED, NULL);

	if (m_pThread_TCP)
	{
		m_pThread_TCP->m_bAutoDelete = FALSE;
		m_pThread_TCP->ResumeThread();
	}




	/*   */
}


#define testbuffer2 "\r\n\
<LR><FB><FS>菜品: 小香风奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号 : 888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品 : 小香风奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号 : 888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品 : 小熊猫奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号 : 888 </FS> </FB> </LR>\r\n\
"

char getlocalTest[10000];
char testChangable[10000];
void C_ChatDlg::OnBnClickedButtonConnect()
{

	strcpy(testChangable, testbuffer);
	pOrderCatch->_ConvertToScreen(getlocalTest, testChangable, strlen(testbuffer));
#ifdef asdasd

	//CComboBox m_Combo_Type;
	//CEdit m_Edit_IpLocation;
	//CEdit m_Edit_Port;
	char buffer[2000], * bufpointer = testbuffer;
	int len;
	int count = 0;
	char* beginPlace = bufpointer;
	int nLineCount = 0;
	int nLen = strlen(bufpointer);
	buffer[0] = 0;
	pOrderCatch->_ConvertToScreen(buffer, bufpointer, nLen);
	return;
	for (int i = 0; i < nLen; i++)
	{
		if (i != nLen - 1 && bufpointer[i + 1] != 0x0d)//len
		{
			nLineCount++;
		}
		else if (bufpointer[i] == 0x0d)
		{
			strcat(buffer, "\r\n");
			count += 2;
		}
		else
		{
			char local[100];
			nLineCount++;

			for (int j = 0; j < nLineCount; j++)
			{
				local[j] = beginPlace[j];
			}
			local[nLineCount] = 0;
			pOrderCatch->
				_ConvertFont(buffer, &count, local, nLineCount);
			beginPlace = bufpointer + i + 3;
			nLineCount = 0;
			i += 2;
		}
	}
	//pOrderCatch->_ConvertFont(buffer, len, testbuffer)
	return;
#endif
	SaveInputInformations();

	if (m_Save_TCPINFO.type == 1)
		ConnectServer(m_Save_TCPINFO.port);
	else
	{
		_enableMonitor = 1;
		ConnectClient(m_Save_TCPINFO.wcIP, m_Save_TCPINFO.port);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CLogin_dlg::Out_Opendlg()
{
	if (loginStyle)
	{
		pThis->m_CChangeInfo_Send_Dlg.ShowWindow(SW_SHOW);
		pThis->m_Login_dlg.ShowWindow(SW_HIDE);
	}
	else
	{

		pThis->m_OutputInfo.Create();
		pThis->m_OutputInfo.ShowWindow(SW_SHOW);
		//pThis->m_CShow_List.ShowWindow(SW_SHOW);
		pThis->m_Login_dlg.ShowWindow(SW_HIDE);
	}
	//pThis->TestChangeWCHAR();

}


void CClientSocket::OUT_Socket_GetInfo(char* wc, UINT nLen, UINT pInput, UINT Par)
{

	pThis->CheckGot(wc, nLen, pInput, Par);
}


void CDigital_SignageView::c2w(wchar_t* pwstr, size_t& len, const char* str)

{

	if (str)

	{

		size_t nu = strlen(str);

		size_t n = (size_t)MultiByteToWideChar(CP_ACP, 0, (const char*)str, (int)nu, NULL, 0);

		//if(n>=len)n=len-1;

		MultiByteToWideChar(CP_ACP, 0, (const char*)str, (int)nu, pwstr, (int)n);
		pwstr[n] = 0;
		len = n;
	}

}


char* CDigital_SignageView::w2c(char* pcstr, const wchar_t* pwstr, size_t& len)
{

	int nlength = wcslen(pwstr);

	//获取转换后的长度
	int nbytes = WideCharToMultiByte(0, // specify the code page used to perform the conversion
		0,         // no special flags to handle unmapped characters
		pwstr,     // wide character string to convert
		nlength,   // the number of wide characters in that string
		NULL,      // no output buffer given, we just want to know how long it needs to be
		0,

		NULL,      // no replacement character given
		NULL);    // we don't want to know if a character didn't make it through the translation

	// make sure the buffer is big enough for this, making it larger if necessary
	/*if(nbytes>len)   nbytes=len;
	else*/ len = nbytes;
	// 通过以上得到的结果，转换unicode 字符为ascii 字符
	WideCharToMultiByte(0, // specify the code page used to perform the conversion
		0,         // no special flags to handle unmapped characters
		pwstr,   // wide character string to convert
		nlength,   // the number of wide characters in that string
		pcstr, // put the output ascii characters at the end of the buffer
		nbytes,                           // there is at least this much space there
		NULL,      // no replacement character given
		NULL);
	return pcstr;

}


void CDigital_SignageView::TestChangeWCHAR()
{



	return;
	//return;
	CString cs, cs0;
	UINT nLen;
	WCHAR wc[499];
	char cc[499];
	cs = L"作业指导书";
	wcscpy(wc, cs);
	nLen = (cs.GetLength() + 1) * 2;
	w2c(cc, wc, nLen);

	//MessageBox(cs0);
}


void C_ChatDlg::Out_SetConnect(int i)
{
	pThis->HasBeenConnect = 1;
}


void CDigital_SignageView::CheckGot(char* cc, UINT nLen, UINT pInput, UINT nPar)
{
	UINT Got;
	WCHAR wc[1024], wccs[256];
	char ccSave[1024];
	UINT nCheck, nListGet;
	UINT nWitchClient;
	static int nFlagStep;//stand for the getting code buffer when this turns  out to be 1 next info will stand for the listfile name
	UINT* nCurrentBeh;
	CString cs;
	int RemLen;
	RemLen = nLen;
	cc[nLen] = 0;
	nLen++;
	c2w(wc, nLen, (char*)cc);
	//////((CClientSocket*)pInput)->Send(cc, nLen);/////////////////////send info to the caller

	for (int i = 0; i < ((C_ChatDlg*)nPar)->nCount_SaveClientSocket; i++)//to check out if These client socket were registed
	{
		if (((C_ChatDlg*)nPar)->SaveClientSocket[i].nIP == pInput)
		{
			nWitchClient = i;
			nCurrentBeh = &(((C_ChatDlg*)nPar)->SaveClientSocket[i].nCode);// if there exists such client then first let the filelist code to be 0
		}
	}

	for (int i = 0; i < m_stOrderList.total; i++)// This one is to make sure that the calling info is a key word in the keywordslist
	{
		wcscpy(wccs, m_stOrderList.csOrder[i]);
		nCheck = 0;
		for (int j = 0; j < m_stOrderList.csOrder[i].GetLength(); j++)
		{
			if (wccs[j] == wc[j])
				nCheck++;
			else
			{
				nCheck = 0; break;
			}
		}

		if (nCheck == m_stOrderList.csOrder[i].GetLength())//This key word may not be the full equal sentence
		{
			nCheck = i + 1;
			break;
		}
	}
	ItemGet* pAll;
	UINT nCount;

	if (nFlagStep == 1)//if there used to be a code regist then this num should be for the code editing use
	{
		*nCurrentBeh = _wtoi(wc);
		nFlagStep = 0;
		return;
	}
	else if (!nCheck)//if there were't any key words Then it should be filelist checking proc
	{

		cs.Format(L"%d", (int)(*nCurrentBeh));
		cs += L".FileOrder";
		ReadFile_InPath(cs, m_CChangeInfo_Send_Dlg.btSaveItemGet, nLen);
	}

	nCount = *(UINT*)m_CChangeInfo_Send_Dlg.btSaveItemGet;//There exists counted length item;
	pAll = (ItemGet*)(m_CChangeInfo_Send_Dlg.btSaveItemGet + sizeof(UINT));//This exist a pointer to the buffer struct
	nListGet = NoneKeywordsOrderChecked(pAll, nCount, wc);//let The return to be Changed into

	switch (nCheck)
	{
	case 1:////作业指导书
		SendMaps(*nCurrentBeh, pInput);
		Output_ButtonFromAndroid(nCheck);
		break;
		//case 2://心跳 
		//	break;
	case 3://工号 //回传jason代码
	{
		int currentStuff;//the login will not change the opera guid map
		//* nCurrentBeh = pThis->m_CChangeInfo_Send_Dlg.CheckLoginInfo(wc, nLen);
		//if(* nCurrentBeh)
		//	ReadFileAndChangeKeywards(* nCurrentBeh, pInput);
		currentStuff = pThis->m_CChangeInfo_Send_Dlg.CheckLoginInfo(wc, nLen);
		if (currentStuff)
			ReadFileAndChangeKeywards(currentStuff, pInput);
		else
		{
			cc[0] = '0';
			((CClientSocket*)pInput)->Send(cc, 1);
			::Sleep(100);
			cc[0] = 'i';
			cc[1] = 'n';
			cc[2] = 'f';
			cc[3] = 'o';
			((CClientSocket*)pInput)->Send(cc, 4);
		}
	}
	break;
	case 4://工单计数
	{
		Output_ButtonFromAndroid(nCheck);
		//Output_ButtonFromAndroid(nCheck);
		pThis->m_CChangeInfo_Send_Dlg.Out_replaceCode(wc, nLen);//this function is to get the replace edit info and translate all the info from client while there needs call to sql

		m_CChangeInfo_Send_Dlg.m_Edit_Output.SetWindowTextW(wc);//发送表单申请 发送申请 
		m_CChangeInfo_Send_Dlg.FillStackInf(pInput, &pAll[0], 0, 0, 0, 0, &pAll[0], 1);
#ifdef DELETE_INFO//send single order

		w2c(ccSave, wc, nLen);


		m_C_ChatDlg2.m_sConnectSocket.Send(ccSave, nLen);
#endif
		char cc[100000];
		UINT saveLen;
		cs = wc;
		cs += "\r\n";
		wcscpy(wc, cs);
		w2c(ccSave, wc, nLen);
		saveLen = 0;
		pThis->m_CChangeInfo_Send_Dlg.ReadFile_InPath(L"allWeSave_BasicWords.vS", (BYTE*)cc, saveLen);

		for (int i = 0; i < nLen; i++)
		{
			cc[saveLen + i] = ccSave[i];
		}
		pThis->m_CChangeInfo_Send_Dlg.SaveFile_InPath(L"allWeSave_BasicWords.vS", (BYTE*)cc, saveLen + nLen);

		static int constoutput;

		m_CShow_List.SetWindowText_Needed(wc, 0, 50 + constoutput * 20);
		constoutput++;
	}
	/////////////////////	nFlagStep = 1;//this won't be used in code
	break;
	case 5://安灯呼叫 
		Output_ButtonFromAndroid(nCheck);
		m_CShow_List.OutputLamp(1);
		break;
		//case 6://作业清单
		//	Output_ButtonFromAndroid(nCheck);
		//	break;
		//case 7://文档查询
		//	{
		//		CString cs = L"表student";
		//		wcscpy(wc, cs);
		//		w2c(cc, wc, nLen);
		//		m_C_ChatDlg2.
		//			m_sConnectSocket.Send(cc, nLen);/////////////////////发送信息给下位机
		//		Output_ButtonFromAndroid(nCheck);
		//	}
		//	break;
		//case 8://作业发放 
		//	Output_ButtonFromAndroid(nCheck);
		//	break;
	case 9://let the id change and make sure that the guiding map is proper

		*nCurrentBeh = _wtoi(wc + 3);//to give the current pad id and let the operating guid differ
		/////////////////////	nFlagStep = 1;
		break;
	default:
	{
		{
			if (nListGet)
			{
				cs = pAll[nListGet - 1].wcFileName;
				wcscpy(wc, cs);



				w2c(ccSave, wc, nLen);
				m_CChangeInfo_Send_Dlg.m_Edit_Output.SetWindowTextW(wc);//发送表单申请 发送申请
				m_CChangeInfo_Send_Dlg.FillStackInf(pInput, &pAll[nListGet - 1], 0, 0, 0, 0, &pAll[0], 0);

#ifdef DELETE_INFO//send single order

				m_C_ChatDlg2.m_sConnectSocket.Send(ccSave, nLen);/////////////////////发送信息给下位机 下位机内容发送成功之后添加一个end
#endif
				//进行结束位置标定清空当前堆栈开始下一段读取
			}
		}
	}
	break;

	}



}


BYTE bt_file_read[1000000];


void CDigital_SignageView::SendMaps(int i, UINT input)
{
	UINT nLen = 0;
	UINT nParts;
	int count = 0;
	char cSend[3];

	ReadFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&m_CChangeInfo_Send_Dlg.m_CChangeInfo_Send_fileinfo, nLen);
	CString cs = &(m_CChangeInfo_Send_Dlg.m_CChangeInfo_Send_fileinfo.wc[i][0]);
	ReadFile_InPath(&(m_CChangeInfo_Send_Dlg.m_CChangeInfo_Send_fileinfo.wc[i][0]), bt_file_read, nLen);
	nParts = nLen / 1000;
	for (count = 0; count < nParts; count++)
	{
		((CClientSocket*)input)->Send((char*)(bt_file_read + count * 1000), 1000);
	}
	((CClientSocket*)input)->Send((char*)(bt_file_read + count * 1000), nLen - nParts * 1000);
	::Sleep(100);
	cSend[0] = 'i';
	cSend[1] = 'm';
	cSend[2] = 'g';
	((CClientSocket*)input)->Send(cSend, 3);

}


void CDigital_SignageView::ReadFile_InPath(CString csPath, BYTE* bt, UINT& nLen)
{


	DWORD dw;
	HANDLE hFile;
	hFile = ::CreateFile(csPath, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	nLen = ::GetFileSize(hFile, NULL);
	::ReadFile(hFile, bt, nLen, &dw, 0);

	::CloseHandle(hFile);
	// TODO: 在此添加控件通知处理程序代码
}


void CDigital_SignageView::Output_ButtonFromAndroid(int i)
{
	CString cs;
	cs.Format(L"%d", i);
	m_CChangeInfo_Send_Dlg.m_Edit_Type.SetWindowTextW(m_stOrderList.csOrder[i - 1]);


}


void CDigital_SignageView::OrderOfGet(int row, int column, int nFlag)
{
	static int SaveCurrentBeg;
	if (nFlag)
		SaveCurrentBeg = 0;
	if (!nFlag)
	{

	}
	SaveCurrentBeg++;
}


void C_ChatDlg::Out_Set_GetInfo_Translate(WCHAR* wc, UINT nLen)
{
	UINT* want, * current;
	int remnLen = nLen;
	current = &pThis->m_CChangeInfo_Send_Dlg.backStack[0].nCurrentRow;
	want = &pThis->m_CChangeInfo_Send_Dlg.backStack[0].CurrentItem->nRow;
	CString css;
	WCHAR wcEnd[4];
	CString cs, cs2;
	WCHAR wcTarget[10], wcTarget2[10];
	cs = L"\t";
	cs2 = L"\r";
	wcscpy(wcTarget2, cs2);
	wcscpy(wcTarget, cs);
	css = L"end";
	wcscpy(wcEnd, css);
	if (pThis->m_CChangeInfo_Send_Dlg.nCountBackStack == 0)
		return;
	if (pThis->m_CChangeInfo_Send_Dlg.backStack[0].nTypeChange == 1)//send what we got instantly
	{
#ifdef DELETE_INFO//send to client 
		char cc[1024];
		w2c(cc, wc, nLen);
		((CClientSocket*)pThis->m_CChangeInfo_Send_Dlg.backStack[0].IP)->Send(cc, nLen);/////////////////////发送信息给下位机 
		::Sleep(100);
		cc[0] = 'i';
		cc[1] = 'n';
		cc[2] = 'f';
		cc[3] = 'o';
		((CClientSocket*)pThis->m_CChangeInfo_Send_Dlg.backStack[0].IP)->Send(cc, 4);/////////////////////发送信息给下位机 
#endif
		pThis->m_CChangeInfo_Send_Dlg.nCountBackStack--;
		return;
	}
	if (wcEnd[0] == wc[0] && wcEnd[1] == wc[1] && wcEnd[2] == wc[2] && pThis->m_CChangeInfo_Send_Dlg.nCountBackStack)//check if there is a end buffer and shut down current stack
	{
		{
			for (int i = 0; i < pThis->m_CChangeInfo_Send_Dlg.nCountBackStack; i++)//to push the stack to the head
				pThis->m_CChangeInfo_Send_Dlg.backStack[i] = pThis->m_CChangeInfo_Send_Dlg.backStack[i + 1];
			pThis->m_CChangeInfo_Send_Dlg.nCountBackStack--;
			if (remnLen != 5)//there has one \r\n after the end

				Out_Set_GetInfo_Translate(wc + 3, remnLen - 3);
			return;
		}
	}
	if (*want == *current)//if we got the wanted row
	{
		int nCheck = 0;
		int countT = 0;
		char cc[1024];
		int total = cs.GetLength();
		if (pThis->m_CChangeInfo_Send_Dlg.backStack[0].CurrentItem->nColumn == 0)//wanted column is 0 that is to say we need the first param 
		{
			for (int j = 0; j < nLen; j++)
			{
				if (wc[j] == wcTarget[0] || wc[j] == wcTarget2[0])
				{
					wc[j] = 0;
					break;;
				}
			}
			CheckSucceed(wc);
			int currentend = 0;
			currentend = CheckEnd_OrNextStep(wc, remnLen);
			if (currentend)
			{
				(*current)++;
				Out_Set_GetInfo_Translate(wc + currentend, remnLen - currentend);

				return;
			}
			(*current)++;
			return;
		}
		else
		{
			for (int i = 0; i < nLen; i++)
			{
				nCheck = 0;
				for (int j = 0; j < total; j++)
				{
					if (wcTarget[j] == wc[i])
						nCheck++;
					else
					{
						nCheck = 0; break;
					}
				}
				if (nCheck == total)
				{
					countT++;//this check is begin with 1 column cause the beginning of this line was already checked
					if (countT == pThis->m_CChangeInfo_Send_Dlg.backStack[0].CurrentItem->nColumn)//check the correct column
					{
						for (int j = i + 1; j < nLen; j++)//the i + 1 was becaust wc[i] should be the \t or \r or 0
						{
							if (wc[j] == wcTarget[0] || wc[j] == wcTarget2[0])//find out the \t or \r or 0
							{
								wc[j] = 0;
								break;
							}
						}
						CheckSucceed(wc + i + 1);
						int currentend = 0;
						currentend = CheckEnd_OrNextStep(wc, remnLen);
						if (currentend)
						{
							(*current)++;
							Out_Set_GetInfo_Translate(wc + currentend, remnLen - currentend);

							return;
						}
						break;
					}
				}
			}
		}
	}
	else
	{
		int currentend = 0;
		currentend = CheckEnd_OrNextStep(wc, remnLen);
		if (currentend)
		{
			(*current)++;
			Out_Set_GetInfo_Translate(wc + currentend, remnLen - currentend);
			return;
		}
	}
	(*current)++;
}


int CDigital_SignageView::NoneKeywordsOrderChecked(ItemGet* CheckList, UINT nListLen, WCHAR* wcGet)
{
	CString cs;
	int nListGet = 0;//What is first list founded key word;
	for (int i = 0; i < nListLen; i++)//
	{
		nListGet = 0;
		cs = CheckList[i].wcOrder;
		if (CheckList[i].wcOrder[0])
		{
			for (int j = 0; j < cs.GetLength(); j++)
			{
				if (CheckList[i].wcOrder[j] == wcGet[j])
					nListGet++;
				else
				{
					nListGet = 0; break;
				}
			}
			if (nListGet == cs.GetLength() && wcGet[cs.GetLength()] == 0)
			{
				return i + 1;
				break;
			}
		}
	}
	return 0;
}


void CDigital_SignageView::ReadFileAndChangeKeywards(int nCheckFileId, UINT nIpPointerClient)
{

	ItemGet* pAll;
	UINT nCount;
	CString cs;
	UINT nLen;
	char ccSave[1024];
	WCHAR wc[1024];
	cs.Format(L"%d", nCheckFileId);
	cs += L".FileOrder";
	ReadFile_InPath(cs, m_CChangeInfo_Send_Dlg.btSaveItemGet, nLen);

	nCount = *(UINT*)m_CChangeInfo_Send_Dlg.btSaveItemGet;//There exists counted length item;
	pAll = (ItemGet*)(m_CChangeInfo_Send_Dlg.btSaveItemGet + sizeof(UINT));//This exist a pointer to the buffer struct
	for (int nListGet = 1; nListGet < nCount + 1; nListGet++)
	{
		m_CChangeInfo_Send_Dlg.m_Edit_Output.SetWindowTextW(wc);//发送表单申请 发送申请 
		m_CChangeInfo_Send_Dlg.FillStackInf(nIpPointerClient, &pAll[nListGet - 1], 0, 0, nCount, nListGet - 1, &pAll[0], 0);
	}
	for (int nListGet = 1; nListGet < nCount + 1; nListGet++)
	{
#ifdef DELETE_INFO//send to server 
		cs = pAll[nListGet - 1].wcFileName;
		cs += L",";
		wcscpy(wc, cs);
		w2c(ccSave, wc, nLen);
		m_C_ChatDlg2.m_sConnectSocket.Send(ccSave, nLen);/////////////////////发送信息给下位机 下位机内容发送成功之后添加一个end
#endif
		//	::Sleep(100);
	}
	//进行结束位置标定清空当前堆栈开始下一段读取 
}


void C_ChatDlg::CheckSucceed(WCHAR* wcSource)
{
	char cc[1024];
	UINT nLen = 100;
	w2c(cc, wcSource, nLen);
	pThis->m_CChangeInfo_Send_Dlg.backStack[0].nFound = 1;//   

	if (pThis->m_CChangeInfo_Send_Dlg.backStack[0].Total)//if this order is a serious then we need to save the data for call back
	{
		int nbegCopy = 0;//copy the seeking wc to list
		for (int j = 0;; j++)
		{
			m_ExchangeKeywords[pThis->m_CChangeInfo_Send_Dlg.backStack[0].nThis].wcGot[j] = wcSource[j];
			if (wcSource[j] == 0)
			{
				break;
			}
		}
	}
	if (pThis->m_CChangeInfo_Send_Dlg.backStack[0].Total == pThis->m_CChangeInfo_Send_Dlg.backStack[0].nThis + 1)
		OutputJasonCode();
	pThis->m_CChangeInfo_Send_Dlg.m_Edit_Output.SetWindowTextW(wcSource);
#ifdef DELETE_INFO//back single 
	//		((CClientSocket*)pThis->m_CChangeInfo_Send_Dlg.backStack[0].IP)->Send(cc, nLen);/////////////////////发送信息给下位机 
#endif
}


void C_ChatDlg::OutputJasonCode()
{
	UINT nCount;
	CString csLenS, csLenT;
	WCHAR wc[1024];
	char cc[1024];
	UINT nLen = 1024;

	nCount = pThis->m_CChangeInfo_Send_Dlg.m_Edit_Jason.GetWindowTextLengthW();
	pThis->m_CChangeInfo_Send_Dlg.m_Edit_Jason.GetWindowTextW(wc, nCount + 1);
	for (int i = 0; i < pThis->m_CChangeInfo_Send_Dlg.backStack[0].Total; i++)
	{

		csLenS = pThis->m_CChangeInfo_Send_Dlg.backStack[0].begItem[i].wcOrder;
		csLenT = m_ExchangeKeywords[i].wcGot;
		if (csLenS.GetLength())
			nCount = QuickReplace_Buffer(wc, nCount, pThis->m_CChangeInfo_Send_Dlg.backStack[0].begItem[i].wcOrder, csLenS.GetLength(),
				m_ExchangeKeywords[i].wcGot, csLenT.GetLength());
	}

	//pThis->m_CChangeInfo_Send_Dlg.backStack[0].CurrentItem 
	w2c(cc, wc, nLen);
#ifdef DELETE_INFO//send to client 
	((CClientSocket*)pThis->m_CChangeInfo_Send_Dlg.backStack[0].IP)->Send(cc, nLen);/////////////////////发送信息给下位机 
	::Sleep(100);
	int countinfo = 0;
	cc[countinfo] = 'i'; countinfo++;
	cc[countinfo] = 'n'; countinfo++;
	cc[countinfo] = 'f'; countinfo++;
	cc[countinfo] = 'o'; countinfo++;
	((CClientSocket*)pThis->m_CChangeInfo_Send_Dlg.backStack[0].IP)->Send(cc, 4);/////////////////////发送信息给下位机 
#else
	pThis->m_CChangeInfo_Send_Dlg.m_Edit_Jason.SetWindowTextW(wc);
#endif
}


int C_ChatDlg::QuickReplace_Buffer(WCHAR* buffer, UINT nLen, WCHAR* wcSource, UINT nLenS, WCHAR* wcTarget, UINT nLenT)
{
	int nCheck;
	WCHAR wcTemp[1024];
	UINT nPoint = 0;
	CString cs, cs0;
	//for(int i = 0 ;i < nLen; i ++)
	//{
	//	cs.Format(L"(%c-%x)%d", buffer[i], buffer[i], i);cs0 += cs;
	//}
	//	cs.Format(L"\r\n(%d)\r\n", nLen);cs0 += cs;
	//for(int i = 0 ;i < nLenS; i ++)
	//{
	//	cs.Format(L"(%c-%x)%d", wcSource[i], wcSource[i], i);cs0 += cs;
	//}
	//	cs.Format(L"\r\n(%d)\r\n", nLenS);cs0 += cs;
	//for(int i = 0 ;i < nLenT; i ++)
	//{
	//	cs.Format(L"(%c-%x)%d", wcTarget[i], wcTarget[i], i);cs0 += cs;
	//}
	//	cs.Format(L"\r\n(%d)\r\n", nLenT);cs0 += cs;
	//	MessageBox(cs0);
	for (int i = 0; i < nLen; i++)
	{
		wcTemp[nPoint] = buffer[i];

		for (int j = 0; j < nLenS; j++)
		{
			if (buffer[i + j] == wcSource[j] && nLenS)
				nCheck++;
			else
			{
				nCheck = 0;
				break;
			}
			if (nCheck == nLenS)//if we got the correct msg
			{
				for (int k = 0; k < nLenT; k++)
				{
					wcTemp[nPoint] = wcTarget[k];
					nPoint++;
				}
				i += nLenS - 1;//this menner is for the i++ 

				break;
			}
		}
		//MessageBox(wcTemp);
		if (!nCheck)
			nPoint++;
	}
	for (int i = 0; i < nPoint; i++)
	{
		buffer[i] = wcTemp[i];
	}
	buffer[nPoint] = 0;
	return nPoint;
}


int C_ChatDlg::CheckEnd_OrNextStep(WCHAR* wc, UINT nLen)
{

	CString cs, cs2;
	WCHAR wcTarget[10], wcTarget2[10];
	cs2 = L"\r";
	wcscpy(wcTarget2, cs2);
	int currentend = 0;
	//the j= 1 below means there exists one \r\n after end so there should be a offset
	for (int j = 1; j < nLen; j++)//the i + 1 was becaust wc[i] should be the \t or \r or 0
	{
		if (wc[j] == wcTarget2[0])//find out the \t or \r or 0
		{
			currentend = j + 2;//\r\n is the last thing
			break;
		}
	}
	if (currentend != nLen && currentend)
	{
		return currentend;
	}
	return 0;
}


void CChangeInfo_Send::Out_replaceCode(WCHAR* wc, UINT nLen)
{
	return;
	////////////////////////////////////////////////////
	//update workOrder set 好坏 = 数量 where workOrder = '工单号'
	//TO UPDATE THE THREE WORDS INTO GETTING BUF
	//表单计数: 良品 数量: 127389 工单号: 237498 
	//WHILE goodProducts STANDS FOR THE 良品
	//rejects STANDS FOR THE 不良品
	///////////////////////////////////////////////////////////
	BYTE bt[1024];
	WCHAR* wcc;
	UINT nLenRem = nLen, flag = 0;
	CString cs1, cs2, csTemp;
	WCHAR wcC1[1024], wcC2[1024], wcTemp[10];
	UINT nLen1, nLen2, nLenTemp, nTemp[10];

	nLen = m_Edit_Replace.GetWindowTextLengthW();

	m_Edit_Replace.GetWindowTextW((WCHAR*)bt, nLen + 1);

	SaveFile_InPath(L"当前的代换代码", bt, (nLen + 1) * sizeof(WCHAR));

	wcc = (WCHAR*)bt;

	cs2 = L"好坏";

	wcscpy(wcC2, cs2);

	nLen2 = cs2.GetLength();



	csTemp = L"不良品";

	wcscpy(wcTemp, csTemp);

	nLenTemp = csTemp.GetLength();

	flag = 0;

	for (int i = 0; i < nLenTemp; i++)
	{
		if (wcTemp[i] == wc[6 + i])
			flag++;
		else
			flag = 0;
	}
	if (flag > 1)//不良品
	{

		cs1 = L"rejects";
		flag = 1;
	}
	else
	{
		cs1 = L"goodProducts";
		flag = 0;
	}

	wcscpy(wcC1, cs1);

	nLen1 = cs1.GetLength();

	pThis->m_C_ChatDlg.QuickReplace_Buffer(wcc, nLen, wcC2, nLen2, wcC1, nLen1);

	///it has been changed into qualited


	nTemp[0] = _wtoi(wc + 13 + flag);

	cs1.Format(L"%d", nTemp[0]);

	wcscpy(wcC1, cs1);

	nLen1 = cs1.GetLength();

	pThis->m_C_ChatDlg.QuickReplace_Buffer(wcc, nLen, wcC2, nLen2, wcC1, nLen1);

	csTemp = L"号";
	wcscpy(wcTemp, csTemp);
	for (int i = 0; i < nLen; i++)
	{
		if (wc[i] == wcTemp[0])
		{
			flag = i + 3;
		}
	}


	nTemp[0] = _wtoi(wc + 13 + flag);

	cs1.Format(L"%d", nTemp[0]);

	wcscpy(wcC1, cs1);

	nLen1 = cs1.GetLength();

	pThis->m_C_ChatDlg.QuickReplace_Buffer(wcc, nLen, wcC2, nLen2, wcC1, nLen1);



}





void CDigital_SignageView::OnOutputBitmap()
{
	//OnLoadBitmap();
	// TODO: 在此添加命令处理程序代码
}



void CChangeInfo_Send::OnBnClickedButtonSetmultiple()
{
	pThis->m_SetOperaGuid.ShowWindow(SW_SHOW);

	// TODO: 在此添加控件通知处理程序代码
}


void CSetOperaGuid::OnBnClickedButtonSetall()
{
	int checkbutton[50];
	if (1)
	{
		int i = 0;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_1))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_2))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_3))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_4))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_5))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_6))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_7))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_8))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_9))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_10))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_11))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_12))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_13))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_14))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_15))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_16))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_17))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_18))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_19))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_20))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_21))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_22))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_23))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_24))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_25))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_26))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_27))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_28))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_29))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_30))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_31))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_32))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_33))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_34))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_35))->GetCheck(); i++;
		checkbutton[i] = ((CButton*)GetDlgItem(IDC_RADIO_36))->GetCheck(); i++;
		CString cs, cs0;
		for (int j = 0; j < 36; j++)
		{
			cs.Format(L"(%d, on-%d)", j, checkbutton[j]); cs0 += cs;
		}
		MessageBox(cs0);
	}
	CFileDialog Dialog(TRUE);
	UINT nLen;
	if (Dialog.DoModal() == IDOK)
	{

		pThis->m_CChangeInfo_Send_Dlg.ReadFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&pThis->m_CChangeInfo_Send_Dlg.m_CChangeInfo_Send_fileinfo, nLen);
		CString cs;
		cs = Dialog.GetFileName();
		WCHAR wc[255];
		wcscpy(wc, cs);
		for (int j = 0; j < 36; j++)
		{
			if (checkbutton[j] == 1)
				for (int i = 0; i < 255; i++)
				{
					pThis->m_CChangeInfo_Send_Dlg.m_CChangeInfo_Send_fileinfo.wc[j + 1][i] = wc[i];
				}
		}
		pThis->m_CChangeInfo_Send_Dlg.SaveFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&pThis->m_CChangeInfo_Send_Dlg.m_CChangeInfo_Send_fileinfo, nLen);
		//MessageBox(cs);
		pThis->m_CChangeInfo_Send_Dlg.SaveFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&pThis->m_CChangeInfo_Send_Dlg.m_CChangeInfo_Send_fileinfo, sizeof(CChangeInfo_Send_fileinfo));
	}

	//MessageBox(cs0);
	//		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);//选上
	//((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);//不选上
	//((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck();//返回1表示选上，0表示没选
	// TODO: 在此添加控件通知处理程序代码
}



void CChangeInfo_Send::OrderList_SendAll(UINT* nListIdHead, UINT nCountList)
{

	for (int i = 0; i < nCountList; i++)
	{
		CString cs = &(ListSave_Buffer[nListIdHead[i]][0]);
		pThis->m_C_ChatDlg2.Out_Set_GetInfo_Translate(&(ListSave_Buffer[nListIdHead[i]][0]), cs.GetLength());
	}
}


UINT CDigital_SignageView::CheckTwoBufferSave(WCHAR* wc1, WCHAR* wc2)
{
	CString cs1, cs2;
	cs1 = wc1;
	cs2 = wc2;
	if (cs1.GetLength() != cs2.GetLength())
		return 0;
	for (int i = 0; i < cs1.GetLength(); i++)
	{
		if (wc1[i] != wc2[i])
			return 0;
	}
	return 1;
}


UINT CChangeInfo_Send::GetListIdFromBuffer(WCHAR* name, UINT nLen)
{
	for (int i = 0; i < nCountwcListSave; i++)
	{
		if (pThis->CheckTwoBufferSave(name, &wcListSave[i][0]))
			return i + 1;
	}
	return 0;
}


void CChangeInfo_Send::Init_SetListInfo()
{
	//for(int i = 0 ;i < 

}






void CDigital_SignageView::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//::MessageBox(0, 0, 0, 0);

	CView::OnMButtonDown(nFlags, point);
}
