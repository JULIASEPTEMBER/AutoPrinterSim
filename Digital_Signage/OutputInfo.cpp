// OutputInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "Digital_Signage.h"
#include "OutputInfo.h"
#include "afxdialogex.h"


// COutputInfo 对话框

IMPLEMENT_DYNAMIC(COutputInfo, CDialogEx)

	COutputInfo::COutputInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(COutputInfo::IDD, pParent)
{

}

COutputInfo::~COutputInfo()
{
}

void COutputInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PRODUCE_NUM, m_Edit_Produce_Num);
	DDX_Control(pDX, IDC_EDIT_PULL_TYPE, m_Edit_Pull_Type);
	DDX_Control(pDX, IDC_EDIT_PRODUCT_NAME, m_Edit_Product_Name);
	DDX_Control(pDX, IDC_EDIT_PLAN_AMOUNT, m_Edit_Plan_Amount);
	DDX_Control(pDX, IDC_EDIT_GOOD_PROD, m_Edit_Good_Prod);
	DDX_Control(pDX, IDC_EDIT_STATE, m_Edit_State);
	DDX_Control(pDX, IDC_EDIT_PROP, m_Edit_Prop);
	DDX_Control(pDX, IDC_EDIT_REJECT_AMOUND, m_Edit_Reject_Amount);
	DDX_Control(pDX, IDC_EDIT_REAL_POPULATION, m_Edit_Real_Population);
	DDX_Control(pDX, IDC_EDIT_PRODUCT_ID, m_Edit_Product_ID);
	DDX_Control(pDX, IDC_EDIT_DATE, m_Edit_Date);
	DDX_Control(pDX, IDC_EDIT_STEP, m_Edit_Step);
	DDX_Control(pDX, IDC_EDIT_MENUCOUNT, m_Edit_MenuCount);
	DDX_Control(pDX, IDC_EDIT_STANDARD_ABILITY, m_Edit_Standard_Ability);
	DDX_Control(pDX, IDC_EDIT_REJECT_RATIO, m_Edit_Reject_Ratio);
	DDX_Control(pDX, IDC_EDIT_STANDARD_POPULATION, m_Edit_Standard_Population);
	DDX_Control(pDX, IDC_EDIT_PULL_MASTER, m_Edit_Pull_Master);
	DDX_Control(pDX, IDC_EDIT_PE, m_Edit_PE);
	DDX_Control(pDX, IDC_EDIT_QC_MASTER, m_Edit_QC_Master);
	DDX_Control(pDX, IDC_EDIT_IPQC, m_Edit_IPQC);
	DDX_Control(pDX, IDC_EDIT_QC, m_Edit_QC);
}


BEGIN_MESSAGE_MAP(COutputInfo, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_CTLCOLOR()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_AMOUNT_DELIVER, &COutputInfo::OnBnClickedButtonAmountDeliver)
	ON_BN_KILLFOCUS(IDC_BUTTON_AMOUNT_DELIVER, &COutputInfo::OnBnKillfocusButtonAmountDeliver)
END_MESSAGE_MAP()


// COutputInfo 消息处理程序
void COutputInfo::Create()
{
	CDialog::Create(COutputInfo::IDD);
}


BYTE szBuffer[10000000];
BYTE szBuffer2[10000000];
HDC M_GdhMemoryDCB;
HBITMAP M_Gdhb;

HDC m_hDC;
void COutputInfo::OnLoadBitmap()
{

	{


		m_hDC=::GetDC(m_hWnd);
		::TextOut(m_hDC,2,2,L"rrt",3);
		// TODO: 在此添加消息处理程序代码和/或调用默认值
		HANDLE hFile;DWORD uBytes;LPVOID pMapFile;HBITMAP ho;
		//HDC hMemoryDCB;

		hFile=::CreateFile( L"电子看板表面布局图.bmp",GENERIC_READ|GENERIC_WRITE,0, NULL, OPEN_ALWAYS,	  0,NULL);
		::ReadFile(hFile,szBuffer,8000000,&uBytes,NULL);
		CloseHandle(hFile); pMapFile=szBuffer;
		//M_Gd.hd=hdc;
		//HDC hdc; //hdc= m_hDC;


		if ((M_Gdhb = 
			::CreateDIBitmap( m_hDC, 
			(LPBITMAPINFOHEADER)((PBYTE)pMapFile +
			sizeof(BITMAPFILEHEADER)),		
			CBM_INIT,		 
			(PBYTE)pMapFile + 
			((BITMAPFILEHEADER *) pMapFile)->bfOffBits,	
			(LPBITMAPINFO)((PBYTE)pMapFile + sizeof(BITMAPFILEHEADER)),	
			DIB_RGB_COLORS)) == NULL)
			::TextOut(m_hDC,0,20,L"GDer",5);	
		//////////////////////////////
		LPBITMAPINFOHEADER had;
		had=(LPBITMAPINFOHEADER)((PBYTE)szBuffer + sizeof(BITMAPFILEHEADER));

		had->biHeight;

		had->biWidth;
		CString cs, csTemp;

		for(int i = 0 ;i < 100; i ++)
		{
			//if((UINT)((PBYTE)szBuffer)[i] == 255)
			{
				csTemp.Format(L"%d---", (UINT)((PBYTE)szBuffer)[i]);  cs += csTemp;
				//csTemp.Format(L"%d-----%d", (UINT)((PBYTE)szBuffer)[i], i); //cs = csTemp;
				//break;
			}
		}
		//分析改变位图内容
		///ResetFile_BMP((BYTE*)szBuffer, 	had->biWidth, had->biHeight);
		//start = 56;
		//MessageBox(cs);

		//////////////////////////////////
		M_GdhMemoryDCB= CreateCompatibleDC(m_hDC);
		ho=(HBITMAP)SelectObject(M_GdhMemoryDCB,M_Gdhb);
		BitBlt(m_hDC,0,0,had->biWidth,had->biHeight,M_GdhMemoryDCB,0,0,SRCCOPY);	




		//	CView::OnLButtonDown(nFlags, point);
	}


	// TODO: 在此添加命令处理程序代码
}



void COutputInfo::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//	OnLoadBitmap();
	//OnLoadBitmap();
	int nCount = 0;
	;
	m_Edit_Produce_Num              .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Produce_Num           .GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Pull_Type 				.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Pull_Type 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Product_Name 			.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Product_Name 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Plan_Amount 			    .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Plan_Amount 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Good_Prod 				.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Good_Prod 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_State 					.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_State 				.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Prop 					.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Prop 					.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Reject_Amount 			.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Reject_Amount 		.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Real_Population 		    .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Real_Population 		.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Product_ID 			    .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Product_ID 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Date 					.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Date 					.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Step 					.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Step 					.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_MenuCount 				.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_MenuCount 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Standard_Ability 		.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Standard_Ability 		.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Reject_Ratio 			.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Reject_Ratio 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Standard_Population 	    .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Standard_Population 	.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_Pull_Master 			    .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_Pull_Master 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_PE 					    .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_PE 					.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_QC_Master 				.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_QC_Master 			.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_IPQC 					.GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_IPQC 					.GetWindowTextLengthW() + 1); nCount ++;
	m_Edit_QC 					    .GetWindowTextW(&wcInfoSetSave[nCount][0], m_Edit_QC 					.GetWindowTextLengthW() + 1); nCount ++;
	
	SaveFile_InPath(L"SaveLib_AllInfo", (BYTE*)wcInfoSetSave, sizeof(WCHAR) * 255 * 100);
	NoneOutlines(&m_Edit_Produce_Num               );
	NoneOutlines(&m_Edit_Pull_Type 				   );
	NoneOutlines(&m_Edit_Product_Name 			   );
	NoneOutlines(&m_Edit_Plan_Amount 			   );
	NoneOutlines(&m_Edit_Good_Prod 				   );
	NoneOutlines(&m_Edit_State 					   );
	NoneOutlines(&m_Edit_Prop 					   );
	NoneOutlines(&m_Edit_Reject_Amount 			   );
	NoneOutlines(&m_Edit_Real_Population 		   );
	NoneOutlines(&m_Edit_Product_ID 			   );
	NoneOutlines(&m_Edit_Date 					   );
	NoneOutlines(&m_Edit_Step 					   );
	NoneOutlines(&m_Edit_MenuCount 				   );
	NoneOutlines(&m_Edit_Standard_Ability 		   );
	NoneOutlines(&m_Edit_Reject_Ratio 			   );
	NoneOutlines(&m_Edit_Standard_Population 	   );
	NoneOutlines(&m_Edit_Pull_Master 			   );
	NoneOutlines(&m_Edit_PE 					   );
	NoneOutlines(&m_Edit_QC_Master 				   );
	NoneOutlines(&m_Edit_IPQC 					   );
	NoneOutlines(&m_Edit_QC 					   );
	Disappear_BUTTON();
	CDialogEx::OnLButtonDown(nFlags, point);
}


void COutputInfo::OnPaint()
{
	OnLoadBitmap();
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	SetEditState(&m_Edit_Produce_Num               );
	SetEditState(&m_Edit_Pull_Type 				   );
	SetEditState(&m_Edit_Product_Name 			   );
	SetEditState(&m_Edit_Plan_Amount 			   );
	SetEditState(&m_Edit_Good_Prod 				   );
	SetEditState(&m_Edit_State 					   );
	SetEditState(&m_Edit_Prop 					   );
	SetEditState(&m_Edit_Reject_Amount 			   );
	SetEditState(&m_Edit_Real_Population 		   );
	SetEditState(&m_Edit_Product_ID 			   );
	SetEditState(&m_Edit_Date 					   );
	SetEditState(&m_Edit_Step 					   );
	SetEditState(&m_Edit_MenuCount 				   );
	SetEditState(&m_Edit_Standard_Ability 		   );
	SetEditState(&m_Edit_Reject_Ratio 			   );
	SetEditState(&m_Edit_Standard_Population 	   );
	SetEditState(&m_Edit_Pull_Master 			   );
	SetEditState(&m_Edit_PE 					   );
	SetEditState(&m_Edit_QC_Master 				   );
	SetEditState(&m_Edit_IPQC 					   );
	SetEditState(&m_Edit_QC 					   );
	UINT nLen;
	ReadFile_InPath(L"SaveLib_AllInfo", (BYTE*)wcInfoSetSave, nLen);
	if(nLen == 0)
		return;
	int nCount = 0;
	;
	m_Edit_Produce_Num              .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Pull_Type 				.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Product_Name 			.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Plan_Amount 			    .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Good_Prod 				.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_State 					.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Prop 					.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Reject_Amount 			.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Real_Population 		    .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Product_ID 			    .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Date 					.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Step 					.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_MenuCount 				.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Standard_Ability 		.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Reject_Ratio 			.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Standard_Population 	    .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_Pull_Master 			    .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_PE 					    .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_QC_Master 				.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_IPQC 					.SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	m_Edit_QC 					    .SetWindowTextW(&wcInfoSetSave[nCount][0]); nCount ++;
	

	// 不为绘图消息调用 CDialogEx::OnPaint()
}


void COutputInfo::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	///OnLoadBitmap();

	CDialogEx::OnMouseMove(nFlags, point);
}


HBRUSH COutputInfo::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(IDC_EDIT_PULL_TYPE == pWnd->GetDlgCtrlID() ||
		IDC_EDIT_DATE == pWnd->GetDlgCtrlID())
		pDC->SetBkColor(RGB(0,0,64));//设置字体背景颜色
	else
		pDC->SetBkColor(RGB(0,0,0));//设置字体背景颜色

	{
		pDC->SetTextColor(RGB(255,255,255));//设置编辑框字体的颜色

		CFont font;
		font.CreatePointFont(300,L"华文楷体");
		pDC->SelectObject(&font);//设置字体
		//  return m_brush;
	} 
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


int COutputInfo::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	return 0;
}


void COutputInfo::SetEditState(CEdit* edit)
{

	CFont font;
	font.CreatePointFont(700,L"华文楷体");
	edit->SetFont(&font);
}


void COutputInfo::NoneOutlines(CEdit* edit)
{
	RECT rc, rcTemp;
	edit->GetWindowRect(&rc);
	
//	RECT rc;
	HBRUSH hbr;
	HDC dc = ::GetDC(m_hWnd);
	COLORREF col = ::GetPixel(dc, rc.left + 5, rc.top + 5);

	//::GetClientRect(m_hWnd, &rc);
	//rc.top += 40;
	hbr= CreateSolidBrush(col); 
	rcTemp = rc;
	rcTemp.bottom = rcTemp.top + 4;
	::FillRect(dc, &rcTemp, hbr);


	
	rcTemp = rc;
	rcTemp.right = rcTemp.left + 4;
	::FillRect(dc, &rcTemp, hbr);

	rcTemp = rc;
	rcTemp.left = rcTemp.right - 4;
	::FillRect(dc, &rcTemp, hbr);

	
	rcTemp = rc;
	rcTemp.top = rcTemp.bottom - 4;
	::FillRect(dc, &rcTemp, hbr);
	::DeleteDC(dc);

}


void COutputInfo::SaveFile_InPath(CString csPath, BYTE* bt, UINT nLen)
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


void COutputInfo::ReadFile_InPath(CString csPath, BYTE* bt, UINT &nLen)
{


	DWORD dw;
	HANDLE hFile;
	hFile = ::CreateFile(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL); 
	nLen = ::GetFileSize(hFile, NULL) ;
	::ReadFile(hFile,  bt, nLen , &dw, 0); 

	::CloseHandle(hFile);
	// TODO: 在此添加控件通知处理程序代码
}


void COutputInfo::OnBnClickedButtonAmountDeliver()
{
	// TODO: 在此添加控件通知处理程序代码
}


void COutputInfo::Disappear_BUTTON()
{

	RECT rc, rcTemp; 
	::SetFocus(0);
	
//	RECT rc;
	HBRUSH hbr;
	HDC dc = ::GetDC(0);
	COLORREF col = ::GetPixel(dc, 3, 3);

	::GetClientRect(m_hWnd, &rc);
	//rc.top += 40;
	hbr= CreateSolidBrush(col); 
	rcTemp.left = 2;
	rcTemp.right = 200;
	rcTemp.top = 2;
	rcTemp.bottom = 27;
	::FillRect(dc, &rcTemp, hbr);
	// OnBnKillfocusButtonAmountDeliver();
	//::SetFocus(m_hWnd);
}


void COutputInfo::OnBnKillfocusButtonAmountDeliver()
{
	// TODO: 在此添加控件通知处理程序代码
}
