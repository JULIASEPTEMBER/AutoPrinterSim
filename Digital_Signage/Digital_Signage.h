
// Digital_Signage.h : Digital_Signage 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CDigital_SignageApp:
// 有关此类的实现，请参阅 Digital_Signage.cpp
//


class CSocketDecription;
extern CSocketDecription* m_SocketDescription;
class CDigital_SignageApp : public CWinAppEx
{
public:
	CDigital_SignageApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
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
