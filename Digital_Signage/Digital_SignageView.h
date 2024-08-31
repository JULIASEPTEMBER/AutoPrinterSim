
// Digital_SignageView.h : CDigital_SignageView 类的接口
//

#include "Show_Informations.h"
#include "C_ChatDlg.h"
#include "ChangeInfo_Send.h"
#include "Login_dlg.h"
#include "Show_List.h"
#include "OutputInfo.h"
#include "SetOperaGuid.h"

#pragma once


class CDigital_SignageView : public CView
{
protected: // 仅从序列化创建
	CDigital_SignageView();
	DECLARE_DYNCREATE(CDigital_SignageView)

	// 特性
public:
	CDigital_SignageDoc* GetDocument() const;

	// 操作
public:

	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 实现
public:
	virtual ~CDigital_SignageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CShow_Informations m_Show_Informations;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void TCPCreatThread(void);			
	friend UINT TCPThreadProc(LPVOID pm);

	CWinThread* m_pThread_TCP;
	C_ChatDlg m_C_ChatDlg;
	C_ChatDlg m_C_ChatDlg2;//client --sql
	CChangeInfo_Send m_CChangeInfo_Send_Dlg;
	CLogin_dlg m_Login_dlg;

	void c2w(wchar_t *pwstr,size_t &len,const char *str);
	char *w2c(char *pcstr,const wchar_t *pwstr, size_t& len);
	void TestChangeWCHAR();
	UINT HasBeenConnect;
	struct stOrderList
	{
		CString csOrder[255];
		int total;
	};
	stOrderList m_stOrderList;//to save the checkin order
	void CheckGot(char * cc, UINT nLen, UINT pInput, UINT nPar);//receive from client and analyze the details of the buffer, and jump to other functions witch will request info from sql
	void SendMaps(int i, UINT input);//send work guiding bmp
	void ReadFile_InPath(CString csPath, BYTE* bt, UINT &nLen);//read a file and return the buffer pointer and length
	void Output_ButtonFromAndroid(int i);//this belongs to the check got function witch will be ctrl by flag easier to calculate
	void OrderOfGet(int row, int column, int nFlag);//begin to get one particular row and column(currently no use)
	void ReadFileAndChangeKeywards(int nCheckFileId, UINT nIpPointerClient);//to get all info according to the order list named listOrderFile, and replace the keywords in js code
	int NoneKeywordsOrderChecked(ItemGet * CheckList, UINT nListLen, WCHAR* wcGet);//if There were not any checking keywords were targeted Then we let the FileList checking proc begin
	int nFlag_SearchAllKeyWords;//
	CShow_List m_CShow_List;//state that cannot use for settings change
	
	
	afx_msg void OnOutputBitmap();
	COutputInfo m_OutputInfo;
	CSetOperaGuid m_SetOperaGuid;
	UINT CheckTwoBufferSave(WCHAR* wc1, WCHAR* wc2);//if they are same return 1

	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Digital_SignageView.cpp 中的调试版本
inline CDigital_SignageDoc* CDigital_SignageView::GetDocument() const
{ return reinterpret_cast<CDigital_SignageDoc*>(m_pDocument); }
#endif

