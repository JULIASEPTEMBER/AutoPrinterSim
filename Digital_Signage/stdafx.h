
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





#define testbuffer "<FB><center>**���̲���**</center></FB>\\r\
<FB><FS2> <center>350014</center></FS2></FB>\\r\
<center>ȡ�ͺ�</center>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
������ţ�cy257815350962290688\\r\
�µ�ʱ��:2023-12-13 10:26:10\\r\
\\r\
*************��Ʒ*************** \\r\
\\r\
С������͵��⣨Ĭ�ϣ�<right>X2 45.00</right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
С������͵��⣨Ĭ�ϣ�<right>X2 45.00</right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
С��è���͵��⣨Ĭ�ϣ�<right>X1 29.00</right>\\r\
********************************\\r\
<FH>\\r\
<LR>�ϼƣ���125.00, �Ż�:-0.01</LR>\\r\
<LR>���ţ�888,������5</LR>\\r\
<right>ʵ��֧������0.00 </right>\\r\
<LR>��ע��</LR>\\r\
</FH>\\r\
<FS><center>**��**</center></FS>\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>��Ʒ��,С������͵���</FS></FB></LR>\\r\
<LR><FB><FS>���ţ�,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>��Ʒ��,С������͵���</FS></FB></LR>\\r\
<LR><FB><FS>���ţ�,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>��Ʒ��,С��è���͵���</FS></FB></LR>\\r\
<LR><FB><FS>���ţ�,888 </FS> </FB> </LR>\\r\
"


#define testbuffer2 "<FB><center>**���̲���**</center></FB>\r\n\
<FB><FS2> <center>350014</center></FS2></FB>\r\n\
<center>ȡ�ͺ�</center>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
������ţ�cy257815350962290688\r\n\
�µ�ʱ�䣺2023-12-13 10:26:10\r\n\
\r\n\
*************��Ʒ*************** \r\n\
\r\n\
С������͵��⣨Ĭ�ϣ�<right>X2  45.00 </right> \r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
С������͵��⣨Ĭ�ϣ�<right>X2  45.00 </right>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
С��è���͵��⣨Ĭ�ϣ�<right>X1  29.00 </right>\r\n\
********************************\r\n\
<FH>\r\n\
<LR>�ϼƣ���125.00, �Ż�: -0.01 </LR>\r\n\
<LR>���ţ�888, ������5</LR>\r\n\
<right>ʵ��֧������100.00 </right>\r\n\
<right>��û��֣�100 </right>\r\n\
<LR>��ע��</LR>\r\n\
</FH>\r\n\
<FS><center> **�� * *</center></FS>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>��Ʒ:,С������͵���</FS></FB></LR>\r\n\
<LR><FB><FS>����:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>��Ʒ:,С������͵���</FS></FB></LR>\r\n\
<LR><FB><FS>����:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>��Ʒ:,С��è���͵���</FS></FB></LR>\r\n\
<LR><FB><FS>����:,888</FS></FB></LR>\r\n\
"


#define testbuffer "<FB><center>**�̸�Ȧ**</center></FB>\\r\
<FB><FS2> <center>����888</center></FS2></FB>\\r\
<center>ȡ�ͺ�</center>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
������ţ�cy257815350962290688\\r\
�µ�ʱ��:2023-12-13 10:26:10\\r\
\\r\
*************��Ʒ*************** \\r\
\\r\
С������͵��⣨Ĭ�ϣ�<right>X2 45.00 </right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
С������͵��⣨Ĭ�ϣ�<right>X2 45.00 </right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
С��è���͵��⣨Ĭ�ϣ�<right>X1 29.00 </right>\\r\
********************************\\r\
<FH>\\r\
<LR>�ϼƣ���125.00,�Ż�:-0.01  </LR>\\r\
<LR>������5</LR>\\r\
<right>ʵ��֧������100.00 </right>\\r\
<right>200����+ ��80.00���+ ��10 ΢��֧�� </right>\\r\
<right>��û��֣�100 </right>\r\n\
<LR>��ע��</LR>\\r\
</FH>\\r\
<FS><center>**��**</center></FS>\\r\
\\r\
\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>��Ʒ��,С������͵���</FS></FB></LR>\\r\
<LR><FB><FS>���ţ�,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>��Ʒ��,С������͵���</FS></FB></LR>\\r\
<LR><FB><FS>���ţ�,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>��Ʒ��,С��è���͵���</FS></FB></LR>\\r\
<LR><FB><FS>���ţ�,888 </FS> </FB> </LR>\\r\
"


#define testbuffer3 "<FB><center>**���̲���**</center></FB>\r\n\
<FB><FS2> <center>350014</center></FS2></FB>\r\n\
<center>ȡ�ͺ�</center>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
������ţ�cy257815350962290688\r\n\
�µ�ʱ�䣺2023-12-13 10:26:10\r\n\
\r\n\
*************��Ʒ*************** \r\n\
\r\n\
С������͵��⣨Ĭ�ϣ�<right>X2  45.00 </right> \r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
С������͵��⣨Ĭ�ϣ�<right>X2  45.00 </right>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
С��è���͵��⣨Ĭ�ϣ�<right>X1  29.00 </right>\r\n\
********************************\r\n\
<FH>\r\n\
<LR>�ϼƣ���125.00, �Ż�: -0.01 </LR>\r\n\
<LR>���ţ�888, ������5</LR>\r\n\
<right>ʵ��֧������100.00 </right>\r\n\
<right>��û��֣�100 </right>\r\n\
<LR>��ע��</LR>\r\n\
</FH>\r\n\
<FS><center> **�� * *</center></FS>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>��Ʒ:,С������͵���</FS></FB></LR>\r\n\
<LR><FB><FS>����:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>��Ʒ:,С������͵���</FS></FB></LR>\r\n\
<LR><FB><FS>����:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>��Ʒ:,С��è���͵���</FS></FB></LR>\r\n\
<LR><FB><FS>����:,888</FS></FB></LR>\r\n\
"