#pragma once
#include "afxwin.h"


// COutputInfo 对话框

class COutputInfo : public CDialogEx
{
	DECLARE_DYNAMIC(COutputInfo)

public:
	COutputInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COutputInfo();

	// 对话框数据
	enum { IDD = IDD_DIALOG_OUTPUT_VIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void Create();
	void OnLoadBitmap();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CEdit m_Edit_Produce_Num;
	CEdit m_Edit_Pull_Type;
	CEdit m_Edit_Product_Name;
	CEdit m_Edit_Plan_Amount;
	CEdit m_Edit_Good_Prod;
	CEdit m_Edit_State;
	CEdit m_Edit_Prop;
	CEdit m_Edit_Reject_Amount;
	CEdit m_Edit_Real_Population;
	CEdit m_Edit_Product_ID;
	CEdit m_Edit_Date;
	CEdit m_Edit_Step;
	CEdit m_Edit_MenuCount;
	CEdit m_Edit_Standard_Ability;
	CEdit m_Edit_Reject_Ratio;
	CEdit m_Edit_Standard_Population;
	CEdit m_Edit_Pull_Master;
	CEdit m_Edit_PE;
	CEdit m_Edit_QC_Master;
	CEdit m_Edit_IPQC;
	CEdit m_Edit_QC;
	void SetEditState(CEdit* edit);//to let each edit to become the same background
	void NoneOutlines(CEdit* edit);//to cover the outlines of edits
	
	void SaveFile_InPath(CString csPath, BYTE* bt, UINT nLen);//
	void ReadFile_InPath(CString csPath, BYTE* bt, UINT &nLen);//
	WCHAR wcInfoSetSave[100][255];//saveall items and save in file during the lbd proc

	afx_msg void OnBnClickedButtonAmountDeliver();//
	void Disappear_BUTTON();//hide up left button
	afx_msg void OnBnKillfocusButtonAmountDeliver();//leave the focus of button
};
