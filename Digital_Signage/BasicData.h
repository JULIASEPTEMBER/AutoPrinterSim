#pragma once


#define DX_DRAWLINE			1//画线函数
#define DX_GYROSCOPE		2//陀螺仪传输三角形函数
#define DX_XBOXCTRL			3//XBOX传输操作信息
#define DX_ERAZEANGLE		4//激光雷达中的一段角度绘制清零
#define DX_GPSOUTPUT		5//激光雷达中的一段角度绘制清零
#define OT_DRIVECAR			6//在3d类中输出车体移动控制信号writer-〉byte nLen
#define CTRL_MOTION			7//位移台控制
#define CTRL_FREQ_T			8//超声波开始测距
#define CTRL_FREQ_R			9//接收到超声波回复
#define CTRL_FREQ_R2		10//接收到超声波回复
#define CTRL_FREQ_R3		11//接收到超声波回复
#define CTRL_GETGPSPOS_DX	12//dx通过主类调用gps
#define CTRL_RECEIVE		13//接收上位机串口信息
#define TESTANGLE_FORRUN	14//测试车体对应速度和旋转时间所转动过角度
#define CTRL_RECEIVEBACK	15//受控端返回主机信息
#define OT_DRIVECAR2		16//在3d类中输出车体移动控制信号writer-〉byte nLen
#define OT_DRIVECAR3		17//在3d类中输出车体移动控制信号writer-〉byte nLen
#define CTRL_TCP_IP_T		18//通讯回调//客户端发送
#define CTRL_TCP_IP_R		19//通讯回调
#define CRece_From_Client	20//从客户端读取信息
#define CTRL_TCP_IP_T_Ser	21//通讯回调
#define CRece_From_Server	22//通讯回调
#define CROOM_TEST_INFO		23//屋内添加情况
#define CROOM_TEST_BACK		24//在图中点击,加回去,继承当前的所有位置信息
#define ADD_RUNNINGFACTOR	25//添加运动参数(具有默认值)
#define OUTPUT_DLG_STRING	26//添加运动参数(具有默认值)




#define DEBUG_STATE				 1 //自行调试状态（输入激光雷达、陀螺仪、手柄信息、输出小车运行指令）
#define PC_STATE				 2// 上位机简易指令单元，手柄信号， 输出为小车运行指令
#define CAR_STATE				 3//小车运行模式，输入为上位机控制信号，输出为小车运行指令
#define NODX_STATE				 4//小车运行模式，输入为上位机控制信号，输出为小车运行指令无dx模式
#define PIC_STATE				 5//拍照模式,将当前激光雷达的内容进行拍照
#define PIC_READ_STATE			 6//拍照模式,将当前激光雷达拍照内容进行显示
#define PIC_STATE_CTRLMODE		 7//拍照模式,控制小车进行拍照,pc端
#define PIC_STATE_CTRLMODE_Car	 8//拍照模式,控制小车进行拍照,小车端
#define PIC_STATE_COMMUNI		 9//通讯模式
#define PIC_STATE_SUBCOMMUNI	 10//通讯模式小车
#define GPS_CTRL_MODE_PC		 11//路径控制模式电脑版
#define GPS_CTRL_MODE_CAR		 12//路径控制模式小车版
#define MOTION_XY				 13//位移台
#define BEZIERMODE				 14//贝塞尔曲线测试
#define HONEY_ROBOT				 15//小宝机器人
#define FREQUENCY				 16//速度谱线frequency Spectrogram
#define EARS_TWO				 17//双耳效应测试
#define FREQUENCY2				 18//空中画笔
#define HONEY_CLOSE_LOOP		 19//小宝闭环控制
#define TOTALLY_CTRL			 20//整机控制(含有两路测距,按下键盘1234可以对两路进行测距)
#define CHECK_COMMUNICATE		 21//测试协议功能(车体移动\霍尔返回\超声波距离测定)
#define CALCULATE_POS			 22//一键绘图(两发两收)绘制机器人相对于目标桌面的位置
#define TWOSIDE_ONEORDER		 23//双路发送一声号令(新版定位)
#define DARLING_CTRL_GPS		 24//控制小宝机器人并且进行gps定位操作
#define DARLING_GPS_PC			 25//控制小宝机器人按照gps导航进行运动
#define DARLING_GPS_CAR			 26//机器人进行自主的方向矫正(控制后轮运动)
#define DARLING_TEST_ANGLE_PC	 27//测定转角
#define DARLING_TEST_ANGLE_CAR	 28//测定转角车体版
#define DARLING_GPSGO_ANGLE_PC	 29//标准gps导航
#define DARLING_GPSGO_ANGLE_CAR	 30//标准gps导航
#define NewUltrasonic_8Out		 31//8路输出信号
#define DoubleRoll_Running_CAR	 32//两轮式转角控制
#define GET_ONE_ORDER			 33//下位机接收超声测距信息pad读取当前测距信息和TWOSIDE_ONEORDER进行匹配
#define Ctrl_MotorDish			 34//上菜电机
#define TestTCPIP_Opera			 35//网络通讯
#define Leading_PC				 36//导航新版
#define Leading_Pad				 37//导航下位机
#define Calculate_RollTime		 38//计算转角时间//两轮模式
#define Leading_Pad2			 39//导航下位机新版二合一
#define SpeakLoud				 40//大声讲话
#define AUTO_Dish				 41//自动化送菜循环
#define Mapping_Details			 42//绘制谱线自动转角
#define DrawSurroundings		 43//绘制周围场景
#define GoAgain					 44//重复之前运动轨迹
#define CompareWith				 45//超声波两次数据采集对比
#define SendTCP_SER				 46//tcp  
#define SendTCP_CLI				 47//tcp  
#define Compare5Line			 48// 五组数据比对
#define RunDeltaStep			 49//移动梯度获取(在一个梯度诞生时停止运动)这个过程是自动的
#define SetTestPlatform			 50//屋内物品摆放设置
#define OutputOrderAndGetDis	 51//输出命令并且获取距离
#define OutputOrderAndGetDiscar	 52//输出命令并且获取距离
#define ORDER_TO_GO_WAY			 53//设定按照路线行驶包括设置超声波接收通道对距离信息进行交互
#define ORDER_TO_GIVEBACK		 54//设定按照路线行驶包括设置超声波接收通道对距离信息进行交互
#define TCP_CLI_RUN				 55//当前通讯控制两用  
#define Gyroscope_Give			 56//获取陀螺仪信息  
#define MicroWave				 57//电磁炉波形选择功率  
#define SendTest_Ul				 58//测试当前探头输出信号,并接受回复  
#define go_surroundings			 59//行驶到探头位置(多车体)
#define HanNuo					 60
#define SendGoUltra				 61//新版功能定位
#define SendPathGo				 62//向下位机发送运动步骤//通讯过程监控当前超声探头距离
#define Communicate_SetUl		 63//向下位机发送运动步骤
#define Communicate_GetUl		 64//向下位机发送运动步骤
#define Communicate_GetUl2		 65//向下位机发送运动步骤
#define Robot_byMrWangAndMrHuang 66//机器人寻路
#define RobSend					 67//机器人寻路
#define RobotHeadIcon			 68//机器人寻路
#define GoTheMostMessagebox		 69//显示机器人大概外框和行驶控制内容
#define TcpAll_demo				 70//显示机器人大概外框和行驶控制内容
#define SendGoStraight			 71//按下o键车体就往前走
#define GoAndout				 72//输出信号并翻译其中信号
#define Tcp_Send_Map			 73//服务器
#define Tcp_Get_Map				 74//客户端
#define OutputInfo				 75//客户端
#define CGoStraight				 76//客户端




#define MSG_CTRL_BEGIN   	0
#define MSG_CTRL_ID   		1
#define MSG_CTRL_TYPE   	2
#define MSG_CTRL_BUFF0   	3
#define MSG_CTRL_BUFF1   	4
#define MSG_CTRL_BUFF2   	5
#define MSG_CTRL_BUFF3   	6
#define MSG_CTRL_BUFF4   	7
#define MSG_CTRL_BUFF5   	8
#define MSG_CTRL_SUM   		9
#define MSG_CTRL_END   		10

#define MAX_SPEED 22

#define call_GYROSCOPE_Ang 1
#define call_GYROSCOPE_Mag 2



typedef int (CALLBACK* PLCIDECALLBACK)(int *pInfo);//定义类型PLCIDECALLBACK


struct call_LASERDRAWLINE{
	UINT Flag;//1
	float fAngle;       //角度
	float fLength;		//长度
	UINT EndPag;
};//根据角度长度进行绘制


struct call_GYROSCOPE{
	UINT Flag;//2
	float x, y, z;
	float Mag_x, Mag_y, Mag_z;
	UINT nCheckType;//选取类型
};


struct call_XBOXCTRL{
	UINT Flag;//3
};

struct call_LASER_ERAZEANGLE{
	UINT Flag;//4
	float fFrom, fTo;
};


struct DriveState{
	int nLeftDir, nLeftSpeed, nRightDir, nRightSpeed;
};
struct PhotographLaser{
	int Click;
	BYTE bt[10];
};

struct call_Dlg_SetRange{
	UINT Flag;//5
	float fBeg, fEnd;
};


struct DX_LENGTH_WITH_COLOR{
	float fLength[10], fEnd;//长度
	COLORREF Color_Each[10];//颜色
	UINT nCount;//目前用上的上述成对数组个数

};//不同长度的连续线性对应响应的颜色

struct Gap_Linear{//线性参数

	float fJumpSpace ;//跳变空间，用于设定在一个连续区段内查找到断开点时容错范围
	UINT   nBreakMax ;//最大容错次数
	float  fLinear   ;//线性度
};

struct GPS_POS_A//基站 
{
	BYTE Type;//1
	WCHAR ID;//序号
	WCHAR Distance01;
	WCHAR Distance02;
	WCHAR Distance12;
};



struct GPS_POS_T//标签
{
	BYTE Type;//2
	BYTE TagID;//标签id
	WCHAR ID;//序号
	WCHAR Distance0;
	WCHAR Distance1;
	WCHAR Distance2;
	WCHAR Distance3;
};



struct call_GPS_POSITION{
	UINT Flag;//5
	GPS_POS_A pout;
};


struct call_DRIVECAR_ORDER{
	UINT Flag;//6
	BYTE *bt;//control order code
	UINT nLen;//control order length
};


struct call_MOTION_XY{//控制位移台运动
	UINT Flag;//7
	UINT nDirHor, nRunHor, nDirVec, nRunVec;

};

struct call_FREQ_RX
{
	UINT Flag;//9 CTRL_FREQ_R
	BYTE *bt;
	UINT nLen;

};

struct call_GPS_by_DX
{
	UINT Flag;//CTRL_GETGPSPOS_DX	12

};


struct call_Receive_From//从上位机读取数据
{
	UINT Flag;//CTRL_RECEIVE
	BYTE * bt;
	UINT nLen;
};


struct call_TestAngleForRun//测试车体旋转角度和旋转时间
{
	UINT Flag;//TESTANGLE_FORRUN
	int time, rate;
	float window;
	float k, b;
	int tt[10];
};


struct call_GiveBackToPC
{
	UINT Flag;//CTRL_RECEIVEBACK
	BYTE* bt;
	UINT nLen;
};


struct call_TCP_T
{
	UINT Flag;//CTRL_TCP_IP_R
	BYTE* bt;
	UINT nLen;
};


struct call_TCP_T_Ser
{
	UINT Flag;//CTRL_TCP_IP_T_Ser
	BYTE* bt;
	UINT nLen;
};


struct call_TCP_R
{
	UINT Flag;//CTRL_TCP_IP_T
	BYTE* bt;
	UINT nLen;
};

struct call_TCP_ServerGet
{
	UINT Flag;//CRece_From_Client
	BYTE* bt;
	UINT nLen;
};


struct call_SetInfo
{
	UINT Flag;//CROOM_TEST_INFO
	BYTE* bt;
	UINT nLen;
};


struct call_SetCarBack
{
	UINT Flag;//ADD_RUNNINGFACTOR
	int dis, factor, delta;//走多远,回归量, 差值

};


struct output_Information_indlg
{
	UINT Flag;//OUTPUT_DLG_STRING
	CString cs;
};

struct Save_TCPINFO
{
	int type, port;
	WCHAR wcIP[255];
	UINT nLenIP;
};


struct ItemGet//the saving file consists two parts first is a UINT witch contains the Length of CheckList, second is this struct
{
	WCHAR wcOrder[255];//指令
	WCHAR wcFileName[255];//文件名称  
	UINT nRow, nColumn;
};
struct OrderWantMenu
{
	UINT IP;//for the pointer which need to be recall
	ItemGet* CurrentItem; //save the current step that need to get
	UINT nCurrentRow;//need this value to stand for the count of getting rows
	UINT nFound;//make this to stand for if there exists the needed information

	//the following function will only be used in large amount get
	UINT Total;//if There wants to get several Words There will be a total that stands for all the details has finished;
	UINT nThis;//Stands for the page of total that describe the getting proc
	ItemGet* begItem;
	UINT nTypeChange;//ThisWantChangeThis type is 0 means there exists one calling database proc else if this param is 1 means that the back sentence needs to be a succeed of fault
};
class CBasicData
{
public:
	CBasicData(void);
	~CBasicData(void);
};


	static const int 
		MAXSAVE = 0X80000000,
		MAXEXISTINGPERIOD = 50000,
		MASK___CORRUPT = (1 << 0),
		MASK__REGISTER = (1 << 1), 
		MASK___PACKAGE = (1 << 2), 
		MASK___USEPACK = (1 << 3), 
		MASK_____FAULT = (1 << 4), 
		MASK_HEARTBEAT = (1 << 5),
		MASK____NEWBAG = (1 << 6),
		MASK_ANONYMOUS = (1 << 7),
		MASK___PUBLISH = (1 << 8),
		MASK___WEB_KEY = (1 << 9),
		MASK___WEB_PRT = (1 << 10),
		
		PACKAGESTATE_SAFE = 1, 
		PACKAGESTATE_ = 1, 
		PACKAGESTATE___NULL = 0, 
		PACKAGESTATE___FINE = 1, 
		PACKAGESTATE___DAY1 = 2, 
		PACKAGESTATE___DAY2 = 3, 
		PACKAGESTATE___DAY3 = 4, 
		PACKAGESTATE___DAY4 = 5, 
		PACKAGESTATE___DAY5 = 6, 
		PACKAGESTATE_EXPIRE = 7, 
		PACKAGESTATE___USED = 0X40, 
		PACKAGESTATE__UNCHK = 0X80
		;  
	
	struct _RUN_CLIENT{
		int nMask, current;
		char machineidStirng[20];
		int ID_Machine;
		UINT ID_Package;
		int nTimeoutStamp;
		int pClass;
		BYTE irq;
		char* info;
	};
	struct _RUN_SERVER{ 
		int nMaskFin;
		BYTE irq;
	};
	struct _RUN_STORAGE{
		_RUN_CLIENT client;
		_RUN_SERVER server;
	};
	
struct OUTPUT_OPERATING{
	UINT nType;
	UINT nLen;
	BYTE* buffer;
};

#define WM_MYMESSAGE (WM_USER+100)


#define POST__DISCONNECT    1
#define POST________SEND    2
#define POST__SEND_CLOSE    3
#define POST______BEGSER    4
#define POST_____MONITOR    5

struct _SENDMSG{
	int ID;
	int len;
	char* info;
};


extern _SENDMSG _outsendformat;
extern int _SendMonitor;
extern int _enableMonitor;
extern WCHAR cInfoMonitor[1000];


