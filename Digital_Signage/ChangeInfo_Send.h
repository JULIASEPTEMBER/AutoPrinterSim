#pragma once
#include "afxwin.h"
#include "BasicData.h"


// CChangeInfo_Send 对话框
struct CChangeInfo_Send_fileinfo{
	WCHAR wc[2000][255];
};
class CChangeInfo_Send : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeInfo_Send)

public:
	CChangeInfo_Send(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeInfo_Send();

	// 对话框数据
	enum { IDD = IDD_DIALOG_SENDMAP_GETINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit_id_Send;
	CEdit m_Edit_id_Call;
	CEdit m_Edit_Type;
	afx_msg void OnBnClickedButtonAddpic();
	afx_msg void OnBnClickedButtonKnown();
	void Create();
	CChangeInfo_Send_fileinfo m_CChangeInfo_Send_fileinfo;
	int GetIntFromEidt(CEdit* edit);
	void SaveFile_InPath(CString csPath, BYTE* bt, UINT nLen);
	void ReadFile_InPath(CString csPath, BYTE* bt, UINT &nLen);
	CEdit m_Call_Logic;
	CEdit m_Edit_List;
	CEdit m_Edit_Identif;
	CEdit m_Edit_Output;
	afx_msg void OnBnClickedButtonAdd();

	BYTE btSaveItemGet[1000000]; 
	UINT* nCountpSaveID;
	UINT nCurrentId;//id必须不能是0
	CEdit m_Edit_Delete;
	afx_msg void OnBnClickedButtonDelete(); 
	void  GetInfoFromCombo(CComboBox* edit, WCHAR* wc, UINT& nLen);
	void  GetInfoFromEdit(CEdit* edit, WCHAR* wc, UINT& nLen);
	CEdit m_Edit_Row;
	CEdit m_Edit_Column; 
	OrderWantMenu backStack[1000];//save all informations of want-return stack
	UINT nCountBackStack;//the stack of receieving not jumping to next step unless there exis a 'end'
	CEdit m_Edit_Jason;
	afx_msg void OnBnClickedButtonSavejason();
	CEdit m_Edit_Replace;
	afx_msg void OnBnClickedButtonSaveReplace();//
	void Out_replaceCode(WCHAR* wc, UINT nLen);//this function is to get the replace edit info and translate all the info from client while there needs call to sql
	int CheckLoginInfo(WCHAR *wcLogin, UINT nLen);//to check if the login buff is correctly signed in file make sure each code was began with a \n and the id must be bigger than 0
	WCHAR wcCheckLoginInfo[1000000];
	UINT nCheckLoginInfo;
	void c2w(wchar_t *pwstr,size_t &len,const char *str);
	void FillStackInf(
		UINT IP,//for the pointer which need to be recall
		ItemGet* CurrentItem, //save the current step that need to get
		UINT nCurrentRow,//need this value to stand for the count of getting rows
		UINT nFound,//make this to stand for if there exists the needed information

		//the following function will only be used in large amount get
		UINT Total,//if There wants to get several Words There will be a total that stands for all the details has finished,
		UINT nThis,//Stands for the page of total that describe the getting proc
		ItemGet* begItem,
		UINT nTypeChange//This Want Change
		);//to fill a stack
	afx_msg void OnBnClickedButtonSetmultiple();//to give all the subset to have the same guiding map

	WCHAR wcListSave[100][255];//save the current 100 lists name buffer
	UINT nCountwcListSave;//Stands for the amount of list name 
	WCHAR ListSave_Buffer[100][100000];//save the lists into buffer 

	void OrderList_SendAll(UINT* nListIdHead, UINT nCountList);//to output all those read list into the analyzing system;
	UINT GetListIdFromBuffer(WCHAR* name, UINT nLen);//to get the current list id from its list name  return list id + 1
	//Attention!: The reply will no longer call the ayalyzing system. instead, Our program will call it.
	void Init_SetListInfo();//this function will run to fill the listsave buffer while the whole system  is begin the file will use the first UINT to tell Length
	void Refresh_buffer_Get();//to let all list settled, and ask for the list if we don't have
	UINT GetList_fromSQL(WCHAR* wcListname, UINT nCount);//when we were calling the list this function will receive the informations for each list and judge out 
	// where the list belong to

};
