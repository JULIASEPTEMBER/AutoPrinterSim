#pragma once


// CSetOperaGuid 对话框

class CSetOperaGuid : public CDialogEx
{
	DECLARE_DYNAMIC(CSetOperaGuid)

public:
	CSetOperaGuid(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetOperaGuid();

// 对话框数据
	enum { IDD = IDD_DIALOG_SET_OPERA_GUID };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_R1;
	int m_R2;
	int m_R3;
	int m_R4;
	int m_R5;
	int m_R6;
	int m_R7;
	int m_R8;
	int m_R9;
	int m_R10;
	int m_R11;
	int m_R12;
	int m_R13;
	int m_R14;
	int m_R15;
	int m_R16;
	int m_R17;
	int m_R18;
	int m_R19;
	int m_R20;
	int m_R21;
	int m_R22;
	int m_R23;
	int m_R24;
	int m_R25;
	int m_R26;
	int m_R27;
	int m_R28s;
	int m_R29;
	int m_R30;
	void Create();
	afx_msg void OnBnClickedButtonSetall();//to let all position to have one same guid pic
	afx_msg void OnBnClickedButtonCheckBlank();//make all the radio to be zero 
};
