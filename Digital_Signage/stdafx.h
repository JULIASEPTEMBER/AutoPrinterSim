
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��







#include <afxsock.h>            // MFC �׽�����չ



//����	���ƴ���
//    �ź�	           ����	    ����	
const BYTE CTL_SD	    =0x53;	//֡��ʼ	
const BYTE CTL_ED	    =0x45;	//֡����			
const BYTE CTL_ACK	    =0x41;	//ȷ��	
const BYTE CTL_ACKP	    =0x42;  //���ݰ���ȷ��
const BYTE CTL_NAK	    =0x4E;	//����ȷ��

//�ġ�	������
//    ����	            ����	����
const BYTE FC_CONNECT	=0x00;	//�������豸������
const BYTE FC_DISCONN	=0x01;	//�Ͽ����豸������
const BYTE FC_RUN	    =0x02;	//�豸����
const BYTE FC_STOP	    =0x03;	//�豸ֹͣ
const BYTE FC_IL_WRITE	=0x04;	//д��ָ����ļ�
const BYTE FC_IL_READ	=0x05;	//����ָ����ļ�
const BYTE FC_IL_DATA	=0x06;	//ָ�������

const BYTE FC_TX_DATA	=0x0f;  //��������

const BYTE FC_GET_BIT	=0x10;	//��ȡλԪ��
const BYTE FC_SET_BIT	=0x11;	//����λԪ��
const BYTE FC_GET_WORD	=0x12;	//��ȡλԪ���顢��Ԫ��
const BYTE FC_SET_WORD	=0x13;	//����λԪ���顢��Ԫ��
const BYTE FC_DBG_START	=0x20;	//��ʼ���
const BYTE FC_DBG_END	=0x21;	//ֹͣ���
const BYTE FC_DBG_RUN_TO=0x22;	//������ָ����










#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


