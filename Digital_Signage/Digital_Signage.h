
// Digital_Signage.h : Digital_Signage Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDigital_SignageApp:
// �йش����ʵ�֣������ Digital_Signage.cpp
//


class CSocketDecription;
extern CSocketDecription* m_SocketDescription;
class CDigital_SignageApp : public CWinAppEx
{
public:
	CDigital_SignageApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDigital_SignageApp theApp;
class CThreadOrderCatch;
extern CThreadOrderCatch* pOrderCatch;
