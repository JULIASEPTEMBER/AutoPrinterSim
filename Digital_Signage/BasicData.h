#pragma once


#define DX_DRAWLINE			1//���ߺ���
#define DX_GYROSCOPE		2//�����Ǵ��������κ���
#define DX_XBOXCTRL			3//XBOX���������Ϣ
#define DX_ERAZEANGLE		4//�����״��е�һ�νǶȻ�������
#define DX_GPSOUTPUT		5//�����״��е�һ�νǶȻ�������
#define OT_DRIVECAR			6//��3d������������ƶ������ź�writer-��byte nLen
#define CTRL_MOTION			7//λ��̨����
#define CTRL_FREQ_T			8//��������ʼ���
#define CTRL_FREQ_R			9//���յ��������ظ�
#define CTRL_FREQ_R2		10//���յ��������ظ�
#define CTRL_FREQ_R3		11//���յ��������ظ�
#define CTRL_GETGPSPOS_DX	12//dxͨ���������gps
#define CTRL_RECEIVE		13//������λ��������Ϣ
#define TESTANGLE_FORRUN	14//���Գ����Ӧ�ٶȺ���תʱ����ת�����Ƕ�
#define CTRL_RECEIVEBACK	15//�ܿض˷���������Ϣ
#define OT_DRIVECAR2		16//��3d������������ƶ������ź�writer-��byte nLen
#define OT_DRIVECAR3		17//��3d������������ƶ������ź�writer-��byte nLen
#define CTRL_TCP_IP_T		18//ͨѶ�ص�//�ͻ��˷���
#define CTRL_TCP_IP_R		19//ͨѶ�ص�
#define CRece_From_Client	20//�ӿͻ��˶�ȡ��Ϣ
#define CTRL_TCP_IP_T_Ser	21//ͨѶ�ص�
#define CRece_From_Server	22//ͨѶ�ص�
#define CROOM_TEST_INFO		23//����������
#define CROOM_TEST_BACK		24//��ͼ�е��,�ӻ�ȥ,�̳е�ǰ������λ����Ϣ
#define ADD_RUNNINGFACTOR	25//����˶�����(����Ĭ��ֵ)
#define OUTPUT_DLG_STRING	26//����˶�����(����Ĭ��ֵ)




#define DEBUG_STATE				 1 //���е���״̬�����뼤���״�����ǡ��ֱ���Ϣ�����С������ָ�
#define PC_STATE				 2// ��λ������ָ�Ԫ���ֱ��źţ� ���ΪС������ָ��
#define CAR_STATE				 3//С������ģʽ������Ϊ��λ�������źţ����ΪС������ָ��
#define NODX_STATE				 4//С������ģʽ������Ϊ��λ�������źţ����ΪС������ָ����dxģʽ
#define PIC_STATE				 5//����ģʽ,����ǰ�����״�����ݽ�������
#define PIC_READ_STATE			 6//����ģʽ,����ǰ�����״��������ݽ�����ʾ
#define PIC_STATE_CTRLMODE		 7//����ģʽ,����С����������,pc��
#define PIC_STATE_CTRLMODE_Car	 8//����ģʽ,����С����������,С����
#define PIC_STATE_COMMUNI		 9//ͨѶģʽ
#define PIC_STATE_SUBCOMMUNI	 10//ͨѶģʽС��
#define GPS_CTRL_MODE_PC		 11//·������ģʽ���԰�
#define GPS_CTRL_MODE_CAR		 12//·������ģʽС����
#define MOTION_XY				 13//λ��̨
#define BEZIERMODE				 14//���������߲���
#define HONEY_ROBOT				 15//С��������
#define FREQUENCY				 16//�ٶ�����frequency Spectrogram
#define EARS_TWO				 17//˫��ЧӦ����
#define FREQUENCY2				 18//���л���
#define HONEY_CLOSE_LOOP		 19//С���ջ�����
#define TOTALLY_CTRL			 20//��������(������·���,���¼���1234���Զ���·���в��)
#define CHECK_COMMUNICATE		 21//����Э�鹦��(�����ƶ�\��������\����������ⶨ)
#define CALCULATE_POS			 22//һ����ͼ(��������)���ƻ����������Ŀ�������λ��
#define TWOSIDE_ONEORDER		 23//˫·����һ������(�°涨λ)
#define DARLING_CTRL_GPS		 24//����С�������˲��ҽ���gps��λ����
#define DARLING_GPS_PC			 25//����С�������˰���gps���������˶�
#define DARLING_GPS_CAR			 26//�����˽��������ķ������(���ƺ����˶�)
#define DARLING_TEST_ANGLE_PC	 27//�ⶨת��
#define DARLING_TEST_ANGLE_CAR	 28//�ⶨת�ǳ����
#define DARLING_GPSGO_ANGLE_PC	 29//��׼gps����
#define DARLING_GPSGO_ANGLE_CAR	 30//��׼gps����
#define NewUltrasonic_8Out		 31//8·����ź�
#define DoubleRoll_Running_CAR	 32//����ʽת�ǿ���
#define GET_ONE_ORDER			 33//��λ�����ճ��������Ϣpad��ȡ��ǰ�����Ϣ��TWOSIDE_ONEORDER����ƥ��
#define Ctrl_MotorDish			 34//�ϲ˵��
#define TestTCPIP_Opera			 35//����ͨѶ
#define Leading_PC				 36//�����°�
#define Leading_Pad				 37//������λ��
#define Calculate_RollTime		 38//����ת��ʱ��//����ģʽ
#define Leading_Pad2			 39//������λ���°����һ
#define SpeakLoud				 40//��������
#define AUTO_Dish				 41//�Զ����Ͳ�ѭ��
#define Mapping_Details			 42//���������Զ�ת��
#define DrawSurroundings		 43//������Χ����
#define GoAgain					 44//�ظ�֮ǰ�˶��켣
#define CompareWith				 45//�������������ݲɼ��Ա�
#define SendTCP_SER				 46//tcp  
#define SendTCP_CLI				 47//tcp  
#define Compare5Line			 48// �������ݱȶ�
#define RunDeltaStep			 49//�ƶ��ݶȻ�ȡ(��һ���ݶȵ���ʱֹͣ�˶�)����������Զ���
#define SetTestPlatform			 50//������Ʒ�ڷ�����
#define OutputOrderAndGetDis	 51//�������һ�ȡ����
#define OutputOrderAndGetDiscar	 52//�������һ�ȡ����
#define ORDER_TO_GO_WAY			 53//�趨����·����ʻ�������ó���������ͨ���Ծ�����Ϣ���н���
#define ORDER_TO_GIVEBACK		 54//�趨����·����ʻ�������ó���������ͨ���Ծ�����Ϣ���н���
#define TCP_CLI_RUN				 55//��ǰͨѶ��������  
#define Gyroscope_Give			 56//��ȡ��������Ϣ  
#define MicroWave				 57//���¯����ѡ����  
#define SendTest_Ul				 58//���Ե�ǰ̽ͷ����ź�,�����ܻظ�  
#define go_surroundings			 59//��ʻ��̽ͷλ��(�೵��)
#define HanNuo					 60
#define SendGoUltra				 61//�°湦�ܶ�λ
#define SendPathGo				 62//����λ�������˶�����//ͨѶ���̼�ص�ǰ����̽ͷ����
#define Communicate_SetUl		 63//����λ�������˶�����
#define Communicate_GetUl		 64//����λ�������˶�����
#define Communicate_GetUl2		 65//����λ�������˶�����
#define Robot_byMrWangAndMrHuang 66//������Ѱ·
#define RobSend					 67//������Ѱ·
#define RobotHeadIcon			 68//������Ѱ·
#define GoTheMostMessagebox		 69//��ʾ�����˴��������ʻ��������
#define TcpAll_demo				 70//��ʾ�����˴��������ʻ��������
#define SendGoStraight			 71//����o���������ǰ��
#define GoAndout				 72//����źŲ����������ź�
#define Tcp_Send_Map			 73//������
#define Tcp_Get_Map				 74//�ͻ���
#define OutputInfo				 75//�ͻ���
#define CGoStraight				 76//�ͻ���




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



typedef int (CALLBACK* PLCIDECALLBACK)(int *pInfo);//��������PLCIDECALLBACK


struct call_LASERDRAWLINE{
	UINT Flag;//1
	float fAngle;       //�Ƕ�
	float fLength;		//����
	UINT EndPag;
};//���ݽǶȳ��Ƚ��л���


struct call_GYROSCOPE{
	UINT Flag;//2
	float x, y, z;
	float Mag_x, Mag_y, Mag_z;
	UINT nCheckType;//ѡȡ����
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
	float fLength[10], fEnd;//����
	COLORREF Color_Each[10];//��ɫ
	UINT nCount;//Ŀǰ���ϵ������ɶ��������

};//��ͬ���ȵ��������Զ�Ӧ��Ӧ����ɫ

struct Gap_Linear{//���Բ���

	float fJumpSpace ;//����ռ䣬�����趨��һ�����������ڲ��ҵ��Ͽ���ʱ�ݴ�Χ
	UINT   nBreakMax ;//����ݴ����
	float  fLinear   ;//���Զ�
};

struct GPS_POS_A//��վ 
{
	BYTE Type;//1
	WCHAR ID;//���
	WCHAR Distance01;
	WCHAR Distance02;
	WCHAR Distance12;
};



struct GPS_POS_T//��ǩ
{
	BYTE Type;//2
	BYTE TagID;//��ǩid
	WCHAR ID;//���
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


struct call_MOTION_XY{//����λ��̨�˶�
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


struct call_Receive_From//����λ����ȡ����
{
	UINT Flag;//CTRL_RECEIVE
	BYTE * bt;
	UINT nLen;
};


struct call_TestAngleForRun//���Գ�����ת�ǶȺ���תʱ��
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
	int dis, factor, delta;//�߶�Զ,�ع���, ��ֵ

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
	WCHAR wcOrder[255];//ָ��
	WCHAR wcFileName[255];//�ļ�����  
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


