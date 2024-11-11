#include "StdAfx.h"
#include "JekoAutoMachineServer.h"
#include "ClientSocket.h"
#include "resource.h"
#include "OutputInfo.h"
#include "CThreadOrderCatch.h"
#include "CSocketDecription.h"

#include "Digital_Signage.h"

CAsyncSocket Socket;
_SENDMSG _outsendformat;


CThreadOrderCatch* pOrderCatch;

CJekoAutoMachineServer::CJekoAutoMachineServer(void)
	: csOutput(L"")
{
	pOrderCatch = new CThreadOrderCatch;
	pOrderCatch->_initThreadOrder();
	pOutputInfo = new COutputInfo;
}


CJekoAutoMachineServer::~CJekoAutoMachineServer(void)
{

}


//init buffer 
void CJekoAutoMachineServer::_Init()
{
	for(int i = 0; i < _LEN_DESIGN; i ++)
	{
		for(int j = 0; j < sizeof(_RUN_STORAGE); j ++)
		{
			((BYTE*)&st_TCPSer[i])[j] = 0;
		}
		nIndexSheet[i] = 0;
	}

}


//catch machine and put it in index sheet
void CJekoAutoMachineServer::_CatchMachine(int pointer)
{
}


//heart beat check 
void CJekoAutoMachineServer::_CheckHeartBeat()
{
}


//call controlling loop 
void CJekoAutoMachineServer::_ControlLogic()
{
	for(int i = 0; i < _LEN_DESIGN; i ++)
	{
		_DealWithOrder((_RUN_STORAGE*)(&nIndexSheet[i]));
	}
}


//dealwith each sentence
void CJekoAutoMachineServer::_DealWithOrder(_RUN_STORAGE* cur)
{

}


//translate client
void CJekoAutoMachineServer::_TranslateClient(int place, BYTE* buffer, UINT nBfLen)
{

	char* found;
	CString cs;



	if((st_TCPSer[place].server.nMaskFin & MASK___PACKAGE) && 
		(st_TCPSer[place].client.nMask & MASK___PACKAGE))
	{
		st_TCPSer[place].client.nMask &= ~MASK___PACKAGE;
		_InsertTextTodlg(L"client clear client MASK___PACKAGE MASK___USEPACK\r\n");
	}
	if((st_TCPSer[place].server.nMaskFin & MASK___USEPACK) && 
		(st_TCPSer[place].client.nMask & MASK___USEPACK))
	{
		st_TCPSer[place].client.nMask &= ~MASK___USEPACK;
		_InsertTextTodlg(L"client clear client MASK___USEPACK MASK___USEPACK\r\n");
	}
	if((st_TCPSer[place].server.nMaskFin & MASK_HEARTBEAT) && 
		(st_TCPSer[place].client.nMask & MASK_HEARTBEAT))
	{
		st_TCPSer[place].client.nMask &= ~MASK_HEARTBEAT;
		_InsertTextTodlg(L"client clear MASK_HEARTBEAT\r\n");
	}
	if((st_TCPSer[place].server.nMaskFin & MASK____NEWBAG) && 
		(st_TCPSer[place].client.nMask & MASK____NEWBAG))
	{
		st_TCPSer[place].client.nMask &= ~MASK____NEWBAG;
		_InsertTextTodlg(L"client clear MASK_HEARTBEAT\r\n");
	}
	if((st_TCPSer[place].server.nMaskFin & MASK_ANONYMOUS) && 
		(st_TCPSer[place].client.nMask & MASK_ANONYMOUS))
	{
		st_TCPSer[place].client.nMask &= ~MASK_ANONYMOUS;
		_InsertTextTodlg(L"client clear MASK_ANONYMOUS\r\n");
	}
	if ((st_TCPSer[place].server.nMaskFin & MASK___PUBLISH) &&
		(st_TCPSer[place].client.nMask & MASK___PUBLISH))
	{
		st_TCPSer[place].client.nMask &= ~MASK___PUBLISH;
		_InsertTextTodlg(L"client clear MASK___PUBLISH\r\n");
	}
	if ((st_TCPSer[place].server.nMaskFin & MASK___WEB_KEY) &&
		(st_TCPSer[place].client.nMask & MASK___WEB_KEY))
	{
		st_TCPSer[place].client.nMask &= ~MASK___WEB_KEY;
		_InsertTextTodlg(L"client clear MASK___WEB_KEY\r\n");
	}
	if ((st_TCPSer[place].server.nMaskFin & MASK___WEB_PRT) &&
		(st_TCPSer[place].client.nMask & MASK___WEB_PRT))
	{
		st_TCPSer[place].client.nMask &= ~MASK___WEB_PRT;
		_InsertTextTodlg(L"client clear MASK___WEB_PRT\r\n");
	}
	st_TCPSer[place].client.irq = 1 - st_TCPSer[place].server.irq;
	st_TCPSer[place].client.current = 0;
	st_TCPSer[place].client.nTimeoutStamp = ::GetTickCount();
	{
		if(!(st_TCPSer[place].client.nMask & MASK__REGISTER))
		{
			found = strstr((char*)buffer, KEYWORD__REGISTER);
			if(found)
			{
				_InsertTextTodlg(L"client found KEYWORD__REGISTER\r\n");
				int total = strlen(found);
				found += strlen(KEYWORD__REGISTER);

				strcpy(st_TCPSer[place].client.machineidStirng, found);
				for(int j = 0; j < 5; j ++)
				{
					if(*found != '0')
					{
						st_TCPSer[place].client.ID_Machine = atoi(found);
						cs.Format(L"found machine:%d\r\n", st_TCPSer[place].client.ID_Machine);
						_InsertTextTodlg(cs);
						st_TCPSer[place].client.nMask |= MASK__REGISTER;
						st_TCPSer[place].client.nMask &= ~MASK_ANONYMOUS;
						return;
					}
					found ++;
				}
			}
			found = strstr((char*)buffer, KEYWORD__GET_POST);
			if (found)
			{
				for (int i = 0; i < nBfLen; i++)
					pOrderCatch->pBuffer.buf[i] = buffer[i];
				pOrderCatch->pBuffer.len = nBfLen;
				st_TCPSer[place].client.nTimeoutStamp = ::GetTickCount();
				st_TCPSer[place].client.nMask |= MASK___WEB_KEY;
				st_TCPSer[place].client.current = MASK___WEB_KEY;

				cs.Format(L"get web post keyword\r\n");
				_InsertTextTodlg(cs);
			}
			else if ((st_TCPSer[place].client.nMask | MASK___WEB_KEY) && (::GetTickCount() - st_TCPSer[place].client.nTimeoutStamp < 100))
			{
				for (int i = 0; i < nBfLen; i++)
					pOrderCatch->pBuffer.buf[pOrderCatch->pBuffer.len++] = buffer[i];
			}
			int getkey = pOrderCatch->_GetStringFrom_clientSocket((char*)buffer);
			if (-1 != getkey)
			{
				st_TCPSer[place].client.nMask |= MASK___WEB_PRT;
				st_TCPSer[place].client.current = MASK___WEB_PRT;
			}
			found = strstr((char*)buffer, KEYWORD_____PRINT);
			if (found)
			{
				found += strlen(KEYWORD_____PRINT);
				st_TCPSer[place].client.info = new char[1024];
				strcpy(st_TCPSer[place].client.info, found);

				st_TCPSer[place].client.nMask |= MASK___PUBLISH;
				st_TCPSer[place].client.current = MASK___PUBLISH;
				return;
			}
			found = strstr((char*)buffer, KEYWORD____NEWBAG);
			if(found)
			{
				_InsertTextTodlg(L"client found KEYWORD____NEWBAG\r\n");
				int total = strlen(found);
				int clientid = 0, addbagcount = 0;
				found += strlen(KEYWORD____NEWBAG);
				for(int j = 0; j < 5; j ++)
				{
					if(*found != '0')
					{
						clientid = atoi(found);
						break;
					}
					found ++;
				}
				for(int j = 0; j < 10; j ++)
				{
					if(*found == ',')
					{
						found ++;

						addbagcount = atoi(found);
						st_TCPSer[place].client.ID_Package = addbagcount;
					}
					if(*found == ' ')
					{
						found ++;
						addbagcount = atoi(found);
						cs.Format(L"client:%d, add:%d\r\n", clientid, addbagcount);
						_InsertTextTodlg(cs);
						st_TCPSer[place].client.nMask |= MASK____NEWBAG; 
						st_TCPSer[place].client.current = MASK____NEWBAG;
						st_TCPSer[place].client.ID_Machine = addbagcount;
						//_NewBag(clientid, addbagcount);
						//((CClientSocket*)st_TCPSer[place].client.pClass)->Close();
						//_ClearClientTemp(place);
					}
					found ++;
				}
			}
			else 
			{

				found = strstr((char*)buffer, KEYWORD_______BAG);
				if(found)
				{
					st_TCPSer[place].client.nMask |= MASK_ANONYMOUS;
					st_TCPSer[place].client.current = MASK_ANONYMOUS;
					_InsertTextTodlg(L"--NO BAG MASK_ANONYMOUS\r\n");
				}
				else
				{
					found = strstr((char*)buffer, KEYWORD_HEARTBEAT);
					if(found)
					{
						st_TCPSer[place].client.nMask |= MASK_ANONYMOUS;
						st_TCPSer[place].client.current = MASK_ANONYMOUS;
						_InsertTextTodlg(L"--NO BAG MASK_ANONYMOUS\r\n");
					}
				}
			}
		}
		else
		{

			found = strstr((char*)buffer, KEYWORD_______BAG);
			if(found)
			{
				_InsertTextTodlg(L"client found KEYWORD_______BAG\r\n");
				int total = strlen(found);
				UINT nBagGet;
				found += strlen(KEYWORD_______BAG);
				if(!_Decrypt(&nBagGet, found))
				{
					st_TCPSer[place].client.ID_Package = 0x80000000;
					//MessageBoxA(0, found - strlen(KEYWORD_______BAG), 0, 0);
					cs = L"check error bag!!\r\n";
				}
				else
				{
					st_TCPSer[place].client.ID_Package = nBagGet;
					cs.Format(L"client found machine:%d check bag:%d\r\n", st_TCPSer[place].client.ID_Machine, st_TCPSer[place].client.ID_Package);
				}
				_InsertTextTodlg(cs);
				st_TCPSer[place].client.nMask |= MASK___PACKAGE; 
				st_TCPSer[place].client.current = MASK___PACKAGE;

			}
			found = strstr((char*)buffer, KEYWORD_______USE);
			if(found)
			{
				_InsertTextTodlg(L"client found MASK___USEPACK\r\n");
				st_TCPSer[place].client.nMask |= MASK___USEPACK;
				st_TCPSer[place].client.current = MASK___USEPACK;
			}
		}
		found = strstr((char*)buffer, KEYWORD_HEARTBEAT);
		if(found)
		{
			_InsertTextTodlg(L"client found KEYWORD_HEARTBEAT\r\n");
			st_TCPSer[place].client.nMask |= MASK_HEARTBEAT;
			st_TCPSer[place].client.current = MASK_HEARTBEAT;
			cs.Format(L"[%d]heartbeat\r\n", st_TCPSer[place].client.ID_Machine);
			_InsertTextTodlg(cs);
		}
	}
}


//seek for storing space
int CJekoAutoMachineServer::_SeekForEmpty(CClientSocket* pClass)
{
	for(int i = 0; i < _LEN_DESIGN; i ++)
	{
		if(!(st_TCPSer[i].client.nMask & MASK___CORRUPT))
		{
			st_TCPSer[i].client.nTimeoutStamp = ::GetTickCount();
			st_TCPSer[i].client.nMask |= MASK___CORRUPT;
			st_TCPSer[i].client.pClass = (int) pClass;
			((CClientSocket*)st_TCPSer[i].client.pClass)->m_nTimeOut = MAXEXISTINGPERIOD;
			return i;
		}
	}
	return -1;
}


//new bag
void CJekoAutoMachineServer::_NewBag(int shopid, int addnum, WCHAR type)
{
	char info[1000];
	UINT nLen;
	pOutputInfo->ReadFile_InPath(L"filedesc.txt", (BYTE*)info, nLen);
	info[nLen] = 0;
	fileleader.head = atoi(info);
	char* crear = info;
	for(int i = 0; i < (int)nLen; i ++)
	{
		if(*crear == ' ')
			break;
		crear ++;
	}
	crear ++;
	fileleader.rear = atoi(crear);

	_OperateFile(fileleader.rear, addnum, type * 256 + PACKAGESTATE___FINE);
	fileleader.rear = (fileleader.rear + addnum) % MAXSAVE;


	sprintf(info, "%d %d", fileleader.head, fileleader.rear);
	nLen = strlen(info);


	pOutputInfo->SaveFile_InPath(L"filedesc.txt", (BYTE*)info, nLen);
}


//clear client
void CJekoAutoMachineServer::_ClearClientTemp(int id)
{
	for(int i = 0; i < sizeof(_RUN_CLIENT); i ++)
	{
		((BYTE*)&st_TCPSer[id].client)[i] = 0;
	}
}


//operate id
void CJekoAutoMachineServer::_OperateFile(int from, int len, WCHAR set)
{

	DWORD dw;	
	HANDLE hFile;	
	UINT nLen;
	WCHAR bt[2][PAGELEN];   				
	int page[2];
	CString csPath;
	if(!len)return;
	page[0] = from / PAGELEN;
	page[1] = ((from + len - 1) % MAXSAVE) / PAGELEN;
	for(int p = 0; p < 2; p++)
	{
		csPath.Format(L"saveinfo%d.iic", page[p]);
		hFile = ::CreateFile(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  

		nLen = ::GetFileSize(hFile, NULL) ;
		if(nLen == 0)
		{
			for(int i = 0 ;i < PAGELEN; i ++)
			{
				bt[p][i] = 0;
			}
			::WriteFile(hFile,  &bt[p][0], PAGELENW, &dw, 0);  
		}
		else
		{
			::ReadFile(hFile,  &bt[p][0], nLen , &dw, 0); 

		}
		::CloseHandle(hFile);
	}
	for(int i = 0; i < len; i ++)
	{
		if((from % PAGELEN) + i < PAGELEN)
			bt[0][(from % PAGELEN) + i] = set;
		else
			bt[1][((from % PAGELEN) + i) % PAGELEN] = set;
	}


	for(int p = 0; p < 2; p++)
	{
		csPath.Format(L"saveinfo%d.iic", page[p]);
		hFile = ::CreateFile(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  
		::WriteFile(hFile,  &bt[p][0], nLen, &dw, 0);  
		::CloseHandle(hFile);
		if(page[0] == page[1])break;
	}
}


//get filestate
BYTE CJekoAutoMachineServer::_GetFileState(int id, WCHAR* get)
{

	UINT nLen;
	WCHAR bt[PAGELEN];

	DWORD dw;
	HANDLE hFile;
	CString csPath;
	int page = id / PAGELEN;

	csPath.Format(L"saveinfo%d.iic", page);
	hFile = ::CreateFile(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL); 
	nLen = ::GetFileSize(hFile, NULL) ;
	if(!nLen)
	{
		::CloseHandle(hFile);
		return 0;
	}
	::ReadFile(hFile,  bt, nLen , &dw, 0); 
	*get = bt[id % PAGELEN];

	_InsertTextTodlg(L"getstate");
	::CloseHandle(hFile);
	return 1;
}


UINT Thread(LPVOID sock)
{
	Socket.Attach((SOCKET)sock);//如果在线程外close()，记得在离开时Detach().
	Socket.Close ();

	return 0;
} 


//thread operation 
void CJekoAutoMachineServer::_LOOPThread()
{
	int currenttick = ::GetTickCount();

	for(int i = 0; i < _LEN_DESIGN; i ++)
	{

		if((st_TCPSer[i].server.nMaskFin & MASK___CORRUPT) && 
			!(st_TCPSer[i].client.nMask & MASK___CORRUPT))
		{
			_InsertTextTodlg(L"server clear MASK___CORRUPT\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK___CORRUPT;
		}
		if((st_TCPSer[i].server.nMaskFin & MASK__REGISTER) && 
			!(st_TCPSer[i].client.nMask & MASK__REGISTER))
		{
			_InsertTextTodlg(L"server clear MASK__REGISTER\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK__REGISTER;
		}
		if((st_TCPSer[i].server.nMaskFin & MASK___PACKAGE) && 
			!(st_TCPSer[i].client.nMask & MASK___PACKAGE))
		{
			_InsertTextTodlg(L"server clear MASK___PACKAGE\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK___PACKAGE;
		}
		if((st_TCPSer[i].server.nMaskFin & MASK___USEPACK) && 
			!(st_TCPSer[i].client.nMask & MASK___USEPACK))
		{
			_InsertTextTodlg(L"server clear MASK___USEPACK\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK___USEPACK;
		}
		if((st_TCPSer[i].server.nMaskFin & MASK_HEARTBEAT) && 
			!(st_TCPSer[i].client.nMask & MASK_HEARTBEAT))
		{
			_InsertTextTodlg(L"server clear MASK_HEARTBEAT\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK_HEARTBEAT;
		}
		if((st_TCPSer[i].server.nMaskFin & MASK____NEWBAG) && 
			!(st_TCPSer[i].client.nMask & MASK____NEWBAG))
		{
			_InsertTextTodlg(L"server clear MASK____NEWBAG\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK____NEWBAG;
		}
		if((st_TCPSer[i].server.nMaskFin & MASK_ANONYMOUS) && 
			!(st_TCPSer[i].client.nMask & MASK_ANONYMOUS))
		{
			_InsertTextTodlg(L"server clear MASK_ANONYMOUS\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK_ANONYMOUS;
		}
		if ((st_TCPSer[i].server.nMaskFin & MASK___PUBLISH) &&
			!(st_TCPSer[i].client.nMask & MASK___PUBLISH))
		{
			_InsertTextTodlg(L"server clear MASK___PUBLISH\r\n");
			st_TCPSer[i].server.nMaskFin &= ~MASK___PUBLISH;
		}
		if(st_TCPSer[i].client.irq != st_TCPSer[i].server.irq)
		{
			st_TCPSer[i].server.irq = st_TCPSer[i].client.irq;
			_InsertTextTodlg(L"server pro\r\n");
			if((st_TCPSer[i].client.nMask & MASK_ANONYMOUS))
			{ 
				st_TCPSer[i].server.nMaskFin |= MASK_ANONYMOUS;
				_outsendformat.ID = i;
				_outsendformat.len = sizeof(SENDWORD______WHO);
				_outsendformat.info = SENDWORD______WHO;
				((CClientSocket*)st_TCPSer[i].client.pClass);
				::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);

			}
			else if(st_TCPSer[i].client.current & MASK_HEARTBEAT)
			{
				_InsertTextTodlg(L"server MASK_HEARTBEAT\r\n");
				st_TCPSer[i].server.nMaskFin |= MASK_HEARTBEAT;
				_outsendformat.ID = i;
				_outsendformat.len = sizeof(KEYWORD_HEARTBEAT);
				_outsendformat.info = KEYWORD_HEARTBEAT;
				((CClientSocket*)st_TCPSer[i].client.pClass);
				::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
			}
			if(!(st_TCPSer[i].server.nMaskFin & MASK___CORRUPT) && 
				(st_TCPSer[i].client.nMask & MASK___CORRUPT))
			{
				_InsertTextTodlg(L"server MASK___CORRUPT\r\n");
				st_TCPSer[i].server.nMaskFin |= MASK___CORRUPT;
			}
			if(!(st_TCPSer[i].server.nMaskFin & MASK__REGISTER) && 
				(st_TCPSer[i].client.nMask & MASK__REGISTER))
			{
				_InsertTextTodlg(L"server MASK__REGISTER\r\n");
				st_TCPSer[i].server.nMaskFin |= MASK__REGISTER;
				_outsendformat.ID = i;
				_outsendformat.len = sizeof(SENDWORD____HELLO);
				_outsendformat.info = SENDWORD____HELLO;
				((CClientSocket*)st_TCPSer[i].client.pClass);
				::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
			}
			if(st_TCPSer[i].client.current & MASK___PACKAGE)
			{
				_InsertTextTodlg(L"server MASK___PACKAGE\r\n");
				WCHAR get = 0, bag;
				if(st_TCPSer[i].client.ID_Package & 0x80000000)
				{
					get = PACKAGESTATE__UNCHK;
				}
				else if(!_GetFileState(st_TCPSer[i].client.ID_Package, &get))MessageBox(0, L"error:2305191536", 0, 0);
				bag = (get >> 8) & 0xff;
				get &= 0XFF;
				switch(get)
				{
				case PACKAGESTATE___NULL:
					{
						_outsendformat.ID = i;
						_outsendformat.len = sizeof(SENDWORD__NOT_EXT);
						_outsendformat.info = SENDWORD__NOT_EXT;
						((CClientSocket*)st_TCPSer[i].client.pClass);
						::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
					}
					break;
				case PACKAGESTATE__UNCHK: 
					{
						_outsendformat.ID = i;
						_outsendformat.len = sizeof(SENDWORD____CKFAL);
						_outsendformat.info = SENDWORD____CKFAL;
						((CClientSocket*)st_TCPSer[i].client.pClass);
						::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
					}
					break;
				case PACKAGESTATE___FINE: 
					{
						_outsendformat.ID = i;
						sprintf(bagcheck, "%s[%d]", SENDWORD_____FINE, bag);
						_outsendformat.len = sizeof(bagcheck);
						_outsendformat.info = bagcheck;
						((CClientSocket*)st_TCPSer[i].client.pClass);
						::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
					}
					break;
				case PACKAGESTATE_EXPIRE:
					{
						_outsendformat.ID = i;
						_outsendformat.len = sizeof(SENDWORD___EXPIRE);
						_outsendformat.info = SENDWORD___EXPIRE;
						((CClientSocket*)st_TCPSer[i].client.pClass);
						::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
					}
					break;
				case PACKAGESTATE___USED: 
					{
						_outsendformat.ID = i;
						_outsendformat.len = sizeof(SENDWORD_____USED);
						_outsendformat.info = SENDWORD_____USED;
						((CClientSocket*)st_TCPSer[i].client.pClass);
						::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
					}
					break;
				}
				st_TCPSer[i].server.nMaskFin |= MASK___PACKAGE;
			}

			if(!(st_TCPSer[i].server.nMaskFin & MASK___USEPACK) && 
				(st_TCPSer[i].client.nMask & MASK___USEPACK))
			{
				_InsertTextTodlg(L"server MASK___USEPACK\r\n");
				_outsendformat.ID = i;
				_OperateFile(st_TCPSer[i].client.ID_Package, 1, PACKAGESTATE___USED);
				_outsendformat.len = sizeof(SENDWORD______ACK);
				_outsendformat.info = SENDWORD______ACK;
				((CClientSocket*)st_TCPSer[i].client.pClass);
				::PostMessageW(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
				st_TCPSer[i].server.nMaskFin |= MASK___USEPACK;
			}

			if (!(st_TCPSer[i].server.nMaskFin & MASK___WEB_PRT) &&
				(st_TCPSer[i].client.nMask & MASK___WEB_PRT))
			{
					char machine[20];
					char* info = strstr(pOrderCatch->pBuffer.buf, "machine_code=");
					int ilen;
					for (int ilen = 0; ilen < 20; ilen++)
					{
						machine[ilen] = (info + strlen("machine_code="))[ilen];
						if (machine[ilen] == '&')
						{
							machine[ilen++] = 0;
							break;
						}
					}
					//info = (int)(strstr(pOrderCatch->pBuffer.buf, "&key=")) - (int)pOrderCatch->pBuffer.buf;
					//info[0] = 0;
					info = strstr(pOrderCatch->pBuffer.buf, "content=") + strlen("content=");
					int endlen = (int)(strstr(pOrderCatch->pBuffer.buf, KEYWORD__MENU_KEY)) - (int)info;
					char machinecode[200];
					sprintf(machinecode, "%d", machine);
					//::MessageBoxA(0, info, machinecode, 0);
					//::MessageBoxA(0, info + endlen, machinecode, 0);
					char* url;
					url = new char[endlen];

					endlen = pOrderCatch->ConvertStringTohex(url, info, strlen(info));
					//m_SocketDescription->md5_hash((char*)url, outputsss);
					//::MessageBoxA(0, outputsss, 0, 0);//////////////////////////////

					char* gb2312;
					gb2312 = new char[endlen];
					pOrderCatch->ConvertURLToGB2312(url, gb2312, endlen);
					endlen = (int)(strstr(gb2312, KEYWORD__MENU_KEY)) - (int)gb2312;
					gb2312[endlen] = 0;

					char outputsss[100];
					char outputtotal[256];
					outputtotal[0] = 0;

					m_SocketDescription->md5_hash((char*)info, outputsss);
					strcat(outputtotal, outputsss);
					strcat(outputtotal, "----info\r\n");

					m_SocketDescription->md5_hash((char*)url, outputsss);
					strcat(outputtotal, outputsss);
					strcat(outputtotal, "----url\r\n");

					m_SocketDescription->md5_hash((char*)gb2312, outputsss);
					strcat(outputtotal, outputsss);
					strcat(outputtotal, "----gb2312\r\n");
					::MessageBoxA(0, outputtotal, 0, 0);//////////////////////////////
					
					char* get_string;
					get_string = new char[strlen(gb2312)];
					get_string[0] = 0;
					//before
					//pOrderCatch->_ConvertToScreen(get_string, gb2312, strlen(gb2312));
					//new2024-10-30

					strcpy(gb2312, testbuffer2);
					int length_Format = pOrderCatch->_ConvertToScreen(get_string, gb2312, strlen(gb2312));

					//MessageBoxA(0, get_string, 0, 0);

					//::MessageBoxA(0, gb2312, 0, 0);

					for (int k = 0; k < _LEN_DESIGN; k++)
					{
						if(strcmp(machine, st_TCPSer[k].client.machineidStirng) == 0)
					//if (machine == st_TCPSer[k].client.ID_Machine)
					{
						_outsendformat.ID = k;
						_outsendformat.len = length_Format;
						_outsendformat.info = get_string;
						((CClientSocket*)st_TCPSer[k].client.pClass);
						::SendMessage(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
						
						break;
					}
					//	delete get_string;
					//delete url;
					//delete gb2312;
				}

					delete []get_string;
					delete []url;
					delete []gb2312;
				//target machine mentioned in http 
				st_TCPSer[i].server.nMaskFin |= MASK___WEB_PRT;

			}

			if (!(st_TCPSer[i].server.nMaskFin & MASK___PUBLISH) &&
				(st_TCPSer[i].client.nMask & MASK___PUBLISH))
			{
				char* local;
				int machine;
				_InsertTextTodlg(L"server MASK___PUBLISH\r\n");

				machine = atoi(st_TCPSer[i].client.info);
				local = strstr(st_TCPSer[i].client.info, ":") + 1;
				for (int k = 0; k < _LEN_DESIGN; k++)
				{
					 
					if (machine == st_TCPSer[k].client.ID_Machine)
					{

						_outsendformat.ID = k;
						_outsendformat.len = strlen(local);
						_outsendformat.info = local;
						((CClientSocket*)st_TCPSer[k].client.pClass);
						::SendMessage(m_hWnd, WM_MYMESSAGE, POST________SEND, 0);
						break;

					}
				}

				_outsendformat.ID = i;
				_outsendformat.len = sizeof(SENDWORD__PUBLISH);
				_outsendformat.info = SENDWORD__PUBLISH;
				((CClientSocket*)st_TCPSer[i].client.pClass);
				::PostMessageW(m_hWnd, WM_MYMESSAGE, POST__SEND_CLOSE, 0);
				st_TCPSer[i].server.nMaskFin |= MASK___PUBLISH;
			}

			if(!(st_TCPSer[i].server.nMaskFin & MASK____NEWBAG) && 
				(st_TCPSer[i].client.nMask & MASK____NEWBAG))
			{

				_InsertTextTodlg(L"server MASK____NEWBAG\r\n");
				_NewBag(i, st_TCPSer[i].client.ID_Machine, st_TCPSer[i].client.ID_Package);
				//((CClientSocket*)st_TCPSer[place].client.pClass)->Close();
				//_ClearClientTemp(place);

				_outsendformat.ID = i;
				_outsendformat.len = sizeof(SENDWORD_BAG_SUCC);
				_outsendformat.info = SENDWORD_BAG_SUCC;
				((CClientSocket*)st_TCPSer[i].client.pClass);
				::PostMessageW(m_hWnd, WM_MYMESSAGE, POST__SEND_CLOSE, 0);
				st_TCPSer[i].server.nMaskFin |= MASK____NEWBAG;
			}
		}

		if(st_TCPSer[i].client.nTimeoutStamp && currenttick - st_TCPSer[i].client.nTimeoutStamp > MAXEXISTINGPERIOD)
		{
			if(st_TCPSer[i].client.pClass && !(st_TCPSer[i].server.nMaskFin & MASK_____FAULT))
			{
				//st_TCPSer[i].server.nMaskFin &= ~MASK_HEARTBEAT;
				//CClientSocket* soc;
				//soc = new CClientSocket((C_ChatDlg*)this);
				//soc->Attach(((CClientSocket*)st_TCPSer[i].client.pClass)->m_hSocket);
				//soc->Close();
				////delete ((CClientSocket*)st_TCPSer[i].client.pClass);
				//delete soc;
				//keybd_event(65, KEYEVENTF_KEYUP, 0,0);
				CString cs;
				cs.Format(L"timeout: %d\r\n", st_TCPSer[i].client.ID_Machine);
				_InsertTextTodlg(cs);
				((CClientSocket*)st_TCPSer[i].client.pClass);
				::PostMessageW(m_hWnd, WM_MYMESSAGE, (WPARAM)POST__DISCONNECT, i);
				// SOCKET hSocket = ((CClientSocket*)st_TCPSer[i].client.pClass)->Detach ();
				//((CClientSocket*)st_TCPSer[i].client.pClass)->OnClose(0);

				///Socket.Create(0);
				///AfxBeginThread(Thread,(LPVOID)(((CClientSocket*)st_TCPSer[i].client.pClass)->m_hSocket),0,0,0,0);
				///st_TCPSer[i].server.nMaskFin |= MASK_____FAULT;
			}

		}
	}
}


int CALLBACK CJekoAutoMachineServer::ExchangeData(int hhv, PLCIDECALLBACK pFC, void *pParam)//
{

	Funname = pFC;                     // 
	return 0;
}


//textout monitor
void CJekoAutoMachineServer::_InsertTextTodlg(CString cs)
{




	if(!_enableMonitor)
	{

		int len = csOutput.GetLength();
		if(len > 60000)csOutput = L"";
		csOutput += cs;
		pEdit->SetWindowTextW(csOutput);
		pEdit->SetSel(len, len, 0);
	}
	else
	{
		wcscpy(cInfoMonitor, cs);
		::PostMessageW(m_hWnd, WM_MYMESSAGE, POST_____MONITOR, 0);
	}

}



//encry
void CJekoAutoMachineServer::_Encry_Code(char* result, UINT input, int rand)
{

	char cinfo[100];
	UINT temp[10];
	UINT Prime[3] = {1039, 1049, 1051};
	char* info = result;
	temp[0] = input ^ Prime[0];
	temp[2] = (rand % 10) ;
	sprintf(info, "%d", temp[0]);
	temp[4] = strlen(info);
	temp[5] = 1;
	for(UINT i = 0; i < temp[4] - 1; i ++)
	{
		temp[5] = temp[5] * 10;
	}
	for(UINT i = 0; i < temp[2]; i ++)
	{
		temp[3] = temp[0] % 10;
		temp[0] = temp[0] / 10;
		temp[0] += temp[3] * temp[5];
	}
	temp[0] += temp[5] * 10;
	temp[1] = temp[0] ^ Prime[1];
	sprintf(info, "%d", temp[1]);
	temp[5] = 1;
	for(UINT i = 0; i < strlen(info); i ++)
	{
		temp[5] = temp[5] * 10;
	}
	temp[6] = temp[1];
	//if(temp[2] == 0)
	sprintf(info, "%01d%d", temp[2], temp[6]);
	temp[0] = strlen(info);
	temp[1] = 0;
	for(int i = 0; i < temp[0]; i ++)
	{
		temp[1] = (temp[1] + info[i]) %100;
	}
	temp[1] = (temp[1] ^ Prime[2]) % 100;
	sprintf(info, "%02d%01d%d", temp[1], temp[2], temp[6]);

}


//decry
int CJekoAutoMachineServer::_Decrypt(UINT* result, char* from)
{
	UINT nResult;
	UINT temp[10];
	char info[32];
	UINT Prime[3] = {1039, 1049, 1051};
	//temp[1] = 1;
	//for(UINT i = 0; i < temp[0] - 1; i ++)
	//temp[1] *= 10;

	info[0] = from[0];
	info[1] = from[1];
	info[2] = 0;
	temp[3] = atoi(info);
	temp[0] = strlen(from + 2);
	temp[1] = 0;
	for(int i = 0; i < temp[0]; i ++)
	{
		temp[1] = (temp[1] + from[i + 2]) %100;
	}
	temp[1] = (temp[1] ^ Prime[2]) % 100;

	if(temp[3] != temp[1])return 0;

	info[0] = from[2];
	info[1] = 0;
	temp[3] = atoi(info);

	temp[4] = atoi(from + 3);
	//temp[3] = temp[2] / temp[1];//cycle
	//temp[4] = temp[2] % temp[1];//num
	temp[5] = temp[4] ^ Prime[1];//decode
	sprintf(info, "%d", temp[5]);//get len
	temp[2] = 1;
	temp[6] = strlen(info);
	for(UINT i = 0; i < temp[6] - 1; i ++)
		temp[2] *= 10;
	temp[6] = temp[6] % temp[2];

	temp[1] = temp[2] / 10;
	temp[5] = temp[5] % temp[2];
	for(UINT i = 0; i < temp[3]; i ++)
	{
		temp[7] = temp[5] / temp[1];
		temp[5] = (temp[5] - (temp[7] * temp[1])) * 10 + temp[7];
		temp[5] = temp[5] % temp[2];
	}
	temp[6] = temp[5] ^ Prime[0];

	*result = temp[6];

	return 1;
}


//add day past
void CJekoAutoMachineServer::_PlusOneDayOfEach()
{
	int from;
	int len;
	WCHAR set;


	DWORD dw;	
	HANDLE hFile;	
	UINT nLen;
	WCHAR bt[2][PAGELEN];   				
	int page[2];
	CString csPath;
	if(!len)return;
	page[0] = from / PAGELEN;
	page[1] = ((from + len - 1) % MAXSAVE) / PAGELEN;


	fileleader.head;
	fileleader.rear;

	for(int p = 0; p < 2; p++)
	{
		csPath.Format(L"saveinfo%d.iic", page[p]);
		hFile = ::CreateFile(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  

		nLen = ::GetFileSize(hFile, NULL) ;
		if(nLen == 0)
		{
			for(int i = 0 ;i < PAGELEN; i ++)
			{
				bt[p][i] = 0;
			}
			::WriteFile(hFile,  &bt[p][0], PAGELENW, &dw, 0);  
		}
		else
		{
			::ReadFile(hFile,  &bt[p][0], nLen , &dw, 0); 

		}
		::CloseHandle(hFile);
	}
	for(int i = 0; i < len; i ++)
	{
		if((from % PAGELEN) + i < PAGELEN)
			bt[0][(from % PAGELEN) + i] = set;
		else
			bt[1][((from % PAGELEN) + i) % PAGELEN] = set;
	}  

	for(int p = 0; p < 2; p++)
	{ 
		csPath.Format(L"saveinfo%d.iic", page[p]);
		hFile = ::CreateFile(csPath, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  
		::WriteFile(hFile,  &bt[p][0], nLen, &dw, 0);  
		::CloseHandle(hFile);
		if(page[0] == page[1])break;
	}
}