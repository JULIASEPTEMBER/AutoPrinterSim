
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持







#include <afxsock.h>            // MFC 套接字扩展



//三、	控制代码
//    信号	           代码	    描述	
const BYTE CTL_SD	    =0x53;	//帧开始	
const BYTE CTL_ED	    =0x45;	//帧结束			
const BYTE CTL_ACK	    =0x41;	//确认	
const BYTE CTL_ACKP	    =0x42;  //数据包包确认
const BYTE CTL_NAK	    =0x4E;	//不能确认

//四、	功能码
//    命令	            代码	描述
const BYTE FC_CONNECT	=0x00;	//建立与设备的连接
const BYTE FC_DISCONN	=0x01;	//断开与设备的连接
const BYTE FC_RUN	    =0x02;	//设备运行
const BYTE FC_STOP	    =0x03;	//设备停止
const BYTE FC_IL_WRITE	=0x04;	//写入指令表文件
const BYTE FC_IL_READ	=0x05;	//读出指令表文件
const BYTE FC_IL_DATA	=0x06;	//指令表数据

const BYTE FC_TX_DATA	=0x0f;  //传送数据

const BYTE FC_GET_BIT	=0x10;	//获取位元件
const BYTE FC_SET_BIT	=0x11;	//设置位元件
const BYTE FC_GET_WORD	=0x12;	//获取位元件组、字元件
const BYTE FC_SET_WORD	=0x13;	//设置位元件组、字元件
const BYTE FC_DBG_START	=0x20;	//开始监控
const BYTE FC_DBG_END	=0x21;	//停止监控
const BYTE FC_DBG_RUN_TO=0x22;	//运行至指定处










#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif





#define testbuffer "<FB><center>**万商财神**</center></FB>\\r\
<FB><FS2> <center>350014</center></FS2></FB>\\r\
<center>取餐号</center>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
订单编号：cy257815350962290688\\r\
下单时间:2023-12-13 10:26:10\\r\
\\r\
*************商品*************** \\r\
\\r\
小香风奶油蛋糕（默认）<right>X2 45.00</right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
小香风奶油蛋糕（默认）<right>X2 45.00</right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
小熊猫奶油蛋糕（默认）<right>X1 29.00</right>\\r\
********************************\\r\
<FH>\\r\
<LR>合计：￥125.00, 优惠:-0.01</LR>\\r\
<LR>桌号：888,人数：5</LR>\\r\
<right>实际支付：￥0.00 </right>\\r\
<LR>备注：</LR>\\r\
</FH>\\r\
<FS><center>**完**</center></FS>\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>菜品：,小香风奶油蛋糕</FS></FB></LR>\\r\
<LR><FB><FS>桌号：,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>菜品：,小香风奶油蛋糕</FS></FB></LR>\\r\
<LR><FB><FS>桌号：,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>菜品：,小熊猫奶油蛋糕</FS></FB></LR>\\r\
<LR><FB><FS>桌号：,888 </FS> </FB> </LR>\\r\
"


#define testbuffer2 "<FB><center>**万商财神**</center></FB>\r\n\
<FB><FS2> <center>350014</center></FS2></FB>\r\n\
<center>取餐号</center>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
订单编号：cy257815350962290688\r\n\
下单时间：2023-12-13 10:26:10\r\n\
\r\n\
*************商品*************** \r\n\
\r\n\
小香风奶油蛋糕（默认）<right>X2  45.00 </right> \r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
小香风奶油蛋糕（默认）<right>X2  45.00 </right>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
小熊猫奶油蛋糕（默认）<right>X1  29.00 </right>\r\n\
********************************\r\n\
<FH>\r\n\
<LR>合计：￥125.00, 优惠: -0.01 </LR>\r\n\
<LR>桌号：888, 人数：5</LR>\r\n\
<right>实际支付：￥100.00 </right>\r\n\
<right>获得积分：100 </right>\r\n\
<LR>备注：</LR>\r\n\
</FH>\r\n\
<FS><center> **完 * *</center></FS>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品:,小香风奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品:,小香风奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品:,小熊猫奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号:,888</FS></FB></LR>\r\n\
"


#define testbuffer "<FB><center>**商赋圈**</center></FB>\\r\
<FB><FS2> <center>桌号888</center></FS2></FB>\\r\
<center>取餐号</center>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
订单编号：cy257815350962290688\\r\
下单时间:2023-12-13 10:26:10\\r\
\\r\
*************商品*************** \\r\
\\r\
小香风奶油蛋糕（默认）<right>X2 45.00 </right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
小香风奶油蛋糕（默认）<right>X2 45.00 </right>\\r\
<FH2><FW2>----------------</FW2></FH2>\\r\
小熊猫奶油蛋糕（默认）<right>X1 29.00 </right>\\r\
********************************\\r\
<FH>\\r\
<LR>合计：￥125.00,优惠:-0.01  </LR>\\r\
<LR>人数：5</LR>\\r\
<right>实际支付：￥100.00 </right>\\r\
<right>200积分+ ￥80.00余额+ ￥10 微信支付 </right>\\r\
<right>获得积分：100 </right>\r\n\
<LR>备注：</LR>\\r\
</FH>\\r\
<FS><center>**完**</center></FS>\\r\
\\r\
\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>菜品：,小香风奶油蛋糕</FS></FB></LR>\\r\
<LR><FB><FS>桌号：,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>菜品：,小香风奶油蛋糕</FS></FB></LR>\\r\
<LR><FB><FS>桌号：,888 </FS></FB></LR>\\r\
\\r\
\\r\
\\r\
\\r\
\\r\
<LR><FB><FS>菜品：,小熊猫奶油蛋糕</FS></FB></LR>\\r\
<LR><FB><FS>桌号：,888 </FS> </FB> </LR>\\r\
"


#define testbuffer3 "<FB><center>**万商财神**</center></FB>\r\n\
<FB><FS2> <center>350014</center></FS2></FB>\r\n\
<center>取餐号</center>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
订单编号：cy257815350962290688\r\n\
下单时间：2023-12-13 10:26:10\r\n\
\r\n\
*************商品*************** \r\n\
\r\n\
小香风奶油蛋糕（默认）<right>X2  45.00 </right> \r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
小香风奶油蛋糕（默认）<right>X2  45.00 </right>\r\n\
<FH2><FW2>----------------</FW2></FH2>\r\n\
小熊猫奶油蛋糕（默认）<right>X1  29.00 </right>\r\n\
********************************\r\n\
<FH>\r\n\
<LR>合计：￥125.00, 优惠: -0.01 </LR>\r\n\
<LR>桌号：888, 人数：5</LR>\r\n\
<right>实际支付：￥100.00 </right>\r\n\
<right>获得积分：100 </right>\r\n\
<LR>备注：</LR>\r\n\
</FH>\r\n\
<FS><center> **完 * *</center></FS>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品:,小香风奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品:,小香风奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号:,888 </FS></FB></LR>\r\n\
\r\n\
\r\n\
\r\n\
<LR><FB><FS>菜品:,小熊猫奶油蛋糕</FS></FB></LR>\r\n\
<LR><FB><FS>桌号:,888</FS></FB></LR>\r\n\
"