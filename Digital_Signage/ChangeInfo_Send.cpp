// ChangeInfo_Send.cpp : 实现文件
//

#include "stdafx.h"
#include "Digital_Signage.h"
#include "ChangeInfo_Send.h"
#include "afxdialogex.h"


// CChangeInfo_Send 对话框

IMPLEMENT_DYNAMIC(CChangeInfo_Send, CDialogEx)

	CChangeInfo_Send::CChangeInfo_Send(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangeInfo_Send::IDD, pParent)
	, nCountpSaveID(0)
	, nCurrentId(0)
	, nCountBackStack(0)
{

}

CChangeInfo_Send::~CChangeInfo_Send()
{
}

void CChangeInfo_Send::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID_SENDPIC, m_Edit_id_Send);
	DDX_Control(pDX, IDC_EDIT_GETLEMP, m_Edit_id_Call);
	DDX_Control(pDX, IDC_EDIT_TYPE, m_Edit_Type);
	DDX_Control(pDX, IDC_EDIT_CALL_INFO, m_Call_Logic);
	DDX_Control(pDX, IDC_EDIT_LIST_LOCATION, m_Edit_List);
	DDX_Control(pDX, IDC_EDIT_REGIS_NUM, m_Edit_Identif);
	DDX_Control(pDX, IDC_EDIT_OUTPUT_VIEW, m_Edit_Output);
	DDX_Control(pDX, IDC_EDIT_DELETE, m_Edit_Delete);
	DDX_Control(pDX, IDC_EDIT_ROW, m_Edit_Row);
	DDX_Control(pDX, IDC_EDIT_COLUMN, m_Edit_Column);
	DDX_Control(pDX, IDC_EDIT_OUTPUT_VIEW2, m_Edit_Jason);
	DDX_Control(pDX, IDC_EDIT_OUTPUT_REPLACELAYOUT, m_Edit_Replace);
}


BEGIN_MESSAGE_MAP(CChangeInfo_Send, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADDPIC, &CChangeInfo_Send::OnBnClickedButtonAddpic)
	ON_BN_CLICKED(IDC_BUTTON_KNOWN, &CChangeInfo_Send::OnBnClickedButtonKnown)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CChangeInfo_Send::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CChangeInfo_Send::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SAVEJASON, &CChangeInfo_Send::OnBnClickedButtonSavejason)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_REPLACE, &CChangeInfo_Send::OnBnClickedButtonSaveReplace)
	ON_BN_CLICKED(IDC_BUTTON_SETMULTIPLE, &CChangeInfo_Send::OnBnClickedButtonSetmultiple)
END_MESSAGE_MAP()


// CChangeInfo_Send 消息处理程序


void CChangeInfo_Send::OnBnClickedButtonAddpic()
{
	CFileDialog Dialog(TRUE);
	UINT nLen;
	if(Dialog.DoModal() == IDOK)
	{
		ReadFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&m_CChangeInfo_Send_fileinfo, nLen);
		CString cs;
		cs = Dialog.GetFileName();
		WCHAR wc[255];
		wcscpy(wc, cs);
		for(int i = 0; i < 255; i ++)
			m_CChangeInfo_Send_fileinfo.wc[GetIntFromEidt(&m_Edit_id_Send)][i] = wc[i];
		SaveFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&m_CChangeInfo_Send_fileinfo, nLen);
		//MessageBox(cs);
		SaveFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&m_CChangeInfo_Send_fileinfo, sizeof(CChangeInfo_Send_fileinfo));
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CChangeInfo_Send::OnBnClickedButtonKnown()
{

	m_Edit_Type.SetWindowTextW(L"");
	// TODO: 在此添加控件通知处理程序代码
}


void CChangeInfo_Send::Create()
{
	CDialog::Create(CChangeInfo_Send::IDD);
	UINT nLen;
	ReadFile_InPath(L"savesave_CChangeInfo_Send.rrr", (BYTE*)&m_CChangeInfo_Send_fileinfo, nLen);

	ReadFile_InPath(L"0.FileOrder", btSaveItemGet, nLen);
	BYTE bt[1000000];
	nLen =  0;
	ReadFile_InPath(L"当前的jason代码", bt, nLen);
	if(nLen)
		m_Edit_Jason.SetWindowTextW((WCHAR*)bt);
	nLen =  0;
	ReadFile_InPath(L"当前的代换代码", bt, nLen);
	if(nLen)
		m_Edit_Replace.SetWindowTextW((WCHAR*)bt);


	ReadFile_InPath(L"登录信息.txt", bt, nLen);
	c2w(wcCheckLoginInfo, nCheckLoginInfo, (char*)bt);
	int cx,cy; 
	cx = GetSystemMetrics(SM_CXSCREEN); 
	cy = GetSystemMetrics(SM_CYSCREEN); 



	CRect rcTemp; 
	rcTemp.BottomRight() = CPoint(cx, cy); 
	rcTemp.TopLeft() = CPoint(0, 0); 
	MoveWindow(&rcTemp);
}


int CChangeInfo_Send::GetIntFromEidt(CEdit* edit)
{

	UINT nLen;
	WCHAR wc[200];
	nLen = edit->GetWindowTextLengthW();
	edit->GetWindowTextW(wc, nLen + 1);
	return _wtoi(wc);
}


void CChangeInfo_Send::SaveFile_InPath(CString csPath, BYTE* bt, UINT nLen)
{

	DWORD dw;	
	HANDLE hFile;	   																 
	::DeleteFile(csPath);
	hFile = ::CreateFile(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  

	::WriteFile(hFile,  bt, nLen, &dw, 0);  
	::CloseHandle(hFile);
	//	csoutput += L"存储文件成功" ;
	//	m_output.SetWindowTextW(csoutput);

}


void CChangeInfo_Send::ReadFile_InPath(CString csPath, BYTE* bt, UINT &nLen)
{


	DWORD dw;
	HANDLE hFile;
	hFile = ::CreateFile(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL); 
	nLen = ::GetFileSize(hFile, NULL) ;
	::ReadFile(hFile,  bt, nLen , &dw, 0); 

	::CloseHandle(hFile);
	// TODO: 在此添加控件通知处理程序代码
}


void CChangeInfo_Send::OnBnClickedButtonAdd()
{

	WCHAR wc[255];
	UINT nLen;
	ItemGet* pAll;
	CString cs, cs0;

	cs.Format(L"%d", GetIntFromEidt(&m_Edit_Identif));

	cs += L".FileOrder";
	ReadFile_InPath(cs, (BYTE*)btSaveItemGet, nLen);
	if(nLen == 0)
		*(UINT*)btSaveItemGet = 0;

	pAll = (ItemGet*)(btSaveItemGet + sizeof(UINT));

	nCountpSaveID = (UINT*)btSaveItemGet;

	GetInfoFromEdit(&m_Call_Logic, (WCHAR*)pAll[*nCountpSaveID].wcOrder, nLen);
	GetInfoFromEdit(&m_Edit_List, (WCHAR*)pAll[*nCountpSaveID].wcFileName, nLen);
	pAll[*nCountpSaveID].nRow = GetIntFromEidt(&m_Edit_Row);
	pAll[*nCountpSaveID].nColumn = GetIntFromEidt(&m_Edit_Column);
	(*nCountpSaveID) ++;

	SaveFile_InPath(cs, (BYTE*)btSaveItemGet, *nCountpSaveID * sizeof(ItemGet) + sizeof(UINT)); 

	for(int i = 0; i < *nCountpSaveID; i ++)
	{
		cs.Format(L"%d\t", i); cs0 += cs;
		cs0 += L"指令: ";
		cs0 += pAll[i].wcOrder;
		cs0 += L"\t\t对应列表: ";
		cs0 += pAll[i].wcFileName;
		cs0 += L"\r\n";
		cs.Format(L"行:%d, 列:%d\r\n", pAll[i].nRow, pAll[i].nColumn);
		cs0 += cs;
	}
	m_Edit_Output.SetWindowTextW(cs0);
}


void CChangeInfo_Send::OnBnClickedButtonDelete()
{
	UINT nDel = GetIntFromEidt(&m_Edit_Delete);
	WCHAR wc[255];
	UINT nLen;
	ItemGet* pAll;
	CString cs, cs0, csPath;

	csPath.Format(L"%d", GetIntFromEidt(&m_Edit_Identif)); 
	csPath += L".FileOrder";
	ReadFile_InPath(csPath, (BYTE*)btSaveItemGet, nLen);
	if(nLen == 0)
		*(UINT*)btSaveItemGet = 0;
	if(*btSaveItemGet == 0)
		return;
	pAll = (ItemGet*)(btSaveItemGet + sizeof(UINT));

	nCountpSaveID = (UINT*)btSaveItemGet;
	if(nDel <  *nCountpSaveID) 
		for(int i = nDel; i < *nCountpSaveID; i ++)
		{
			pAll[i] =  pAll[i + 1];
		}
		if(nDel <  *nCountpSaveID) 

			(*nCountpSaveID ) --;
		for(int i = 0; i < *nCountpSaveID; i ++)
		{
			cs.Format(L"%d\t", i); cs0 += cs;
			cs0 += L"指令: ";
			cs0 += pAll[i].wcOrder;
			cs0 += L"\t\t对应列表: ";
			cs0 += pAll[i].wcFileName;
			cs0 += L"\r\n";
			cs.Format(L"行:%d, 列:%d\r\n", pAll[i].nRow, pAll[i].nColumn);
			cs0 += cs;
		}
		cs.Format(L"删除了%d\r\n", nDel); cs0 += cs;
		m_Edit_Output.SetWindowTextW(cs0);
		// TODO: 在此添加控件通知处理程序代码
		SaveFile_InPath(csPath, (BYTE*)btSaveItemGet, *nCountpSaveID * sizeof(ItemGet) + sizeof(UINT)); 
}


void CChangeInfo_Send::GetInfoFromCombo(CComboBox* edit, WCHAR* wc, UINT& nLen)
{


	nLen = edit->GetWindowTextLengthW();
	edit->GetWindowTextW(wc, nLen + 1);
}


void CChangeInfo_Send::GetInfoFromEdit(CEdit* edit, WCHAR* wc, UINT& nLen)
{


	nLen = edit->GetWindowTextLengthW();
	edit->GetWindowTextW(wc, nLen + 1);
}


void CChangeInfo_Send::OnBnClickedButtonSavejason()
{
	BYTE bt[1024];
	UINT nLen = 0;
	nLen = m_Edit_Jason.GetWindowTextLengthW();
	m_Edit_Jason.GetWindowTextW((WCHAR*)bt, nLen + 1); 
	SaveFile_InPath(L"当前的jason代码", bt, (nLen + 1) * sizeof(WCHAR)); 
	//SetCursorPos(110, 220);
	//mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);//点下左键
	//mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);//松开左键
	//mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);//点下右键
	//mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);//松开右键
	// TODO: 在此添加控件通知处理程序代码
}


void CChangeInfo_Send::OnBnClickedButtonSaveReplace()
{

	BYTE bt[1024];
	UINT nLen = 0;
	nLen = m_Edit_Replace.GetWindowTextLengthW();
	m_Edit_Replace.GetWindowTextW((WCHAR*)bt, nLen + 1); 
	SaveFile_InPath(L"当前的代换代码", bt, (nLen + 1) * sizeof(WCHAR)); 
	// TODO: 在此添加控件通知处理程序代码
}


void CChangeInfo_Send::c2w(wchar_t *pwstr,size_t &len,const char *str)

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


int CChangeInfo_Send::CheckLoginInfo(WCHAR *wcLogin, UINT nLen)
{
	int count = 0;
	int pos = 0;

	for(int i = 0 ;i < nCheckLoginInfo; i ++)
	{
		count= 0;
		for(int j = 0; j < nLen; j ++)
		{
			if(wcCheckLoginInfo[i + j] == wcLogin[j])
				count ++;
			else
				count = 0;
		}
		if(count == nLen)
		{
			pos = i;
			break;
		}
	}

	if(pos)
	{
		CString cs;
		cs = L"\n";
		WCHAR wc[10];
		wcscpy(wc, cs);
		for(int i = pos ;; i --)
		{
			if(wcCheckLoginInfo[i] == wc[0])
			{
				pos = i + 1;
				break;
			}
		}
		return _wtoi(wcCheckLoginInfo + pos);
	}
	return 0;
}


void CChangeInfo_Send::FillStackInf(
	UINT IP,//for the pointer which need to be recall
	ItemGet* CurrentItem, //save the current step that need to get
	UINT nCurrentRow,//need this value to stand for the count of getting rows
	UINT nFound,//make this to stand for if there exists the needed information

	//the following function will only be used in large amount get
	UINT Total,//if There wants to get several Words There will be a total that stands for all the details has finished,
	UINT nThis,//Stands for the page of total that describe the getting proc
	ItemGet* begItem,
	UINT nTypeChange//ThisWantChange == 1 means to give back the info
	//== 2, instantly check the words in list and output them all
	)
{

	backStack[nCountBackStack].CurrentItem = CurrentItem;
	backStack[nCountBackStack].nCurrentRow = nCurrentRow;
	backStack[nCountBackStack].IP = IP;
	backStack[nCountBackStack].nFound = nFound;
	backStack[nCountBackStack].nThis = nThis;
	backStack[nCountBackStack].Total = Total; 
	backStack[nCountBackStack].begItem = begItem;
	backStack[nCountBackStack].nTypeChange = nTypeChange;
	nCountBackStack ++;
}




void CChangeInfo_Send::Refresh_buffer_Get()
{

}


UINT CChangeInfo_Send::GetList_fromSQL(WCHAR* wcListname, UINT nCount)
{
	return 0;
}

