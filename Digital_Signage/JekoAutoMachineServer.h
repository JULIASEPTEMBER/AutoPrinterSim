#pragma once
#define _LEN_DESIGN 200
#define _STATE_______________INIT    0
#define _STATE__________CONNECTED    1
#define _STATE___________CHECK_ID    2
#define _STATE_RECEIVE_HEART_BEAT    3
#define _STATE_BACKSEND_HEAT_BEAT    4
#define _STATE_____WANT_CHECK_BAG    5
#define _STATE_________RETURN_BAG    6
#define _STATE_________WANT_START    7
#define _STATE________________END    8
class CClientSocket;
#include "BasicData.h"

#define MAX_BUFFERLEN	1024

#define KEYWORD__REGISTER   "JKMY"//machine register
#define KEYWORD_______BAG   "BAG"
#define KEYWORD_______USE   "USE"
#define KEYWORD_HEARTBEAT   "HB"
#define KEYWORD____NEWBAG   "NEWBAG"
#define KEYWORD_____PRINT	"PRINTER"
#define KEYWORD_EXCHG_KEY	"\r\nkey="
#define KEYWORD__MENU_KEY	"&sign="
#define KEYWORD__GET_POST	"POST"
	


#define SENDWORD____HELLO   "HELLO"
#define SENDWORD____CKFAL   "CHECK FAIL"
#define SENDWORD__NOT_EXT   "NOT EXIST"
#define SENDWORD___EXPIRE   "EXPIRE"
#define SENDWORD_____FINE   "FINE"
#define SENDWORD_____USED   "USED"
#define SENDWORD______ACK   "ACK"
#define SENDWORD_BAG_SUCC   "BAG ADDED"
#define SENDWORD____ERROR   "ERROR"
#define SENDWORD______WHO   "WHO"
#define SENDWORD__PUBLISH   "PUBLISHED"


class COutputInfo;
class CJekoAutoMachineServer
{
public:
	
	COutputInfo* pOutputInfo;
	HWND m_hWnd;
	CJekoAutoMachineServer(void);
	~CJekoAutoMachineServer(void);
	static const int PAGELEN = 0X10000;
	static const int PAGELENW = 0X20000;
	struct _INFO_DISH{
		int nID, nSn, nPos, nTime[2], nOri[7];//id of each machine
		WCHAR wcName[256];
	};
	struct _INFO_MACHINE{
		int nID;
		WCHAR wcAddress[1024];
	};
	struct _FILEHEADER{
		int head, rear;
	}fileleader;
	CEdit* pEdit;
	_RUN_STORAGE st_TCPSer[_LEN_DESIGN];
	int nIndexSheet[_LEN_DESIGN];
	struct _local{
		int beg, rear;
	} m_Local;
	//init buffer 
	void _Init();
	//catch machine and put it in index sheet
	void _CatchMachine(int pointer);
	//heart beat check 
	void _CheckHeartBeat();
	//call controlling loop 
	void _ControlLogic();
	//dealwith each sentence
	void _DealWithOrder(_RUN_STORAGE* cur);
	//translate client
	void _TranslateClient(int place, BYTE* buffer, UINT nBfLen);
	//seek for storing space
	int _SeekForEmpty(CClientSocket* pClass);
	//new bag
	void _NewBag(int shopid, int addnum, WCHAR type);
	//clear client
	void _ClearClientTemp(int id);
	//operate id
	 void _OperateFile(int from, int len, WCHAR set);
	 //get filestate
	 BYTE _GetFileState(int id, WCHAR* get);
	//thread operation 
	 void _LOOPThread();
	int CALLBACK ExchangeData(int hhv, PLCIDECALLBACK pFC, void *pParam); 
	PLCIDECALLBACK Funname;//callback function name 
	//textout monitor
	void _InsertTextTodlg(CString cs);
	CString csOutput;
	//encry
	void _Encry_Code(char* result, UINT input, int rand);
	//decry
	int _Decrypt(UINT* result, char* from);
	//char for bag check 
	char bagcheck[100];
	//add day past
	void _PlusOneDayOfEach();
};

