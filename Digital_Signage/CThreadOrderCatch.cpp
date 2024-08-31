#include "stdafx.h"
#include "CThreadOrderCatch.h"
#include "JekoAutoMachineServer.h"


char bufferFromServer[10000]; 

int CThreadOrderCatch::_GetStringFrom_clientSocket(char* string)
{
	int match;
	int whichKeyWord = -1;
	//_KeepAnalyzing()
	for (int i = 0; i < strlen(string); i++)
		_KeepAnalyzing(&whichKeyWord, seek, CountKeyWord, string[i]);
	if(0)
	for (int i = 0; i < strlen(string); i++)
	{
		match = 0;
		for (int k = 0; k < CountKeyWord; k++)
		{
			for (int j = 0; j < strlen(seek[k].keyword); j++)
			{
				if (string[i + j] != seek[k].keyword[j])
				{
					match = 0;
					break;
				}
				match++;
			}
			if (match)
			{ 
				whichKeyWord = k;
				break;
			}
		}
		if (match)
		{ 
			break;
		}
	}
	
	switch (whichKeyWord)
	{
	case 0://normal
		return whichKeyWord;
		///::MessageBox(0, L"key exchange", 0, 0);
		break;
	case 1://with order
		return whichKeyWord;
		///::MessageBox(0, L"print info on terminal", 0, 0);
		break;
	}
	return -1;
}


void CThreadOrderCatch::_KeepAnalyzing(int* returnKeyFound, _SeekKeyWord* keysheet, int countkeyword, char data)
{
	static int state, place, tempKey;
	static char recordKey[256];
	static int recordKeyCount = 0;
	static const BYTE
		_STATE_INIT = 0
		, _STATE_CHECKREST = 1
		, _STATE_SUCC = 2
		, _STATE_FAIL = 3;

	switch (state)
	{
	case _STATE_INIT:
	{
		recordKeyCount = 0;
		place = 0;
		for (int i = 0; i < countkeyword; i++)
		{
			if (data == keysheet[i].keyword[place++])
			{
				state = _STATE_CHECKREST;
				tempKey = i;
				break;
			}
		}
	}
	break;
	case _STATE_CHECKREST:
	{
		if (data == keysheet[tempKey].keyword[place++])
		{
			state = _STATE_CHECKREST;
		}
		else
		{
			place = 0;
			state = _STATE_FAIL;
			break;

		}
		if(place == strlen(keysheet[tempKey].keyword))
		{
			state = _STATE_INIT;
			*returnKeyFound = tempKey;
		}
	}

	break;
	case _STATE_FAIL:
	{
		
	}
		break;
	}

		recordKey[recordKeyCount++] = data;
	if (_STATE_FAIL == state)
	{

		//recheck jump gap 
		for (int i = 0; i < recordKeyCount; i++)
		{
			place = 0;
			for (int k = 0; k < countkeyword; k++)
			{
				for (int j = 0; j < strlen(keysheet[k].keyword); j++)
				{
					if (i + j >= recordKeyCount)
					{
						tempKey = k;
						state = _STATE_CHECKREST;
						place = j;
						recordKeyCount = 0;
						for (int a = 0; a < j; a++)
							recordKey[recordKeyCount++] = keysheet[k].keyword[a];
						return;
					}
					if (recordKey[i + j] != keysheet[k].keyword[j])
					{
						place = 0;
						break;
					}
					place++;
				}
				if (place)
				{
					*returnKeyFound = k;
					state = _STATE_INIT;
					break;
				}
			}
		}
	}

}


char _FONTSEL___FONTB[] =  "FB>"			;
char _FONTSEL__DFONTB[] =  "/FB>"			;
char _FONTSEL__CENTER[] =  "center>"		;
char _FONTSEL_DCENTER[] =  "/center>"		;
char _FONTSEL__FONTS2[] =  "FS2>"			;
char _FONTSEL_DFONTS2[] =  "/FS2>"			;
char _FONTSEL__FONTW2[] =  "FW2>"			;
char _FONTSEL_DFONTW2[] =  "/FW2>"			;
char _FONTSEL__FONTH2[] =  "FH2>"			;
char _FONTSEL_DFONTH2[] =  "/FH2>"			;
char _FONTSEL___FONTH[] =  "FH>"			;
char _FONTSEL__DFONTH[] =  "/FH>"			;
char _FONTSEL___RIGHT[] =  "right>"		;
char _FONTSEL__DRIGHT[] =  "/right>"		;


void CThreadOrderCatch::_initThreadOrder()
{
	pBuffer.buf = bufferFromServer;//save order information 
	pBuffer.len = 0;
	CountKeyWord = 0;
	seek[CountKeyWord++].keyword = KEYWORD_EXCHG_KEY;
	seek[CountKeyWord++].keyword = KEYWORD__MENU_KEY;
	countKeyWordFont = 0; 
		_FONTKEY[countKeyWordFont++].string = _FONTSEL___FONTB;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL__DFONTB;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL__CENTER;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL_DCENTER;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL__FONTS2;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL_DFONTS2;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL__FONTW2;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL_DFONTW2;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL__FONTH2;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL_DFONTH2;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL___FONTH;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL__DFONTH;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL___RIGHT;
		_FONTKEY[countKeyWordFont++].string = _FONTSEL__DRIGHT;



}

#include <afx.h>  // Include MFC core and standard components
#include <windows.h>  // For MultiByteToWideChar and WideCharToMultiByte functions


int CThreadOrderCatch::ConvertStringTohex(char* hexExp, char* asciiExp, int len)
{
	int local;
	int count = 0;
	int state = 0;
	for (int i = 0; i < len; i++)
	{
		switch (state)
		{
		case 0:
			if ('%' == asciiExp[i])
			{
				state = 1;
				local = 0;
			}
			else
			{
				hexExp[count++] = asciiExp[i];
			}
			break;
		case 1:
			if (asciiExp[i] >= '0' && asciiExp[i] <= '9')
				local = (asciiExp[i] - '0') << 4;
			else if (asciiExp[i] >= 'A' && asciiExp[i] <= 'F')
				local = (asciiExp[i] - 'A' + 10) << 4;
			else if (asciiExp[i] >= 'a' && asciiExp[i] <= 'f')
				local = (asciiExp[i] - 'a' + 10) << 4;
			else
			{
				// Invalid percent-encoding, copy '%' and this character
				hexExp[count++] = '%';
				hexExp[count++] = asciiExp[i];
				state = 0;
				break;
			}
			state = 2;
			break;
		case 2:
			if (asciiExp[i] >= '0' && asciiExp[i] <= '9')
				local |= (asciiExp[i] - '0');
			else if (asciiExp[i] >= 'A' && asciiExp[i] <= 'F')
				local |= (asciiExp[i] - 'A' + 10);
			else if (asciiExp[i] >= 'a' && asciiExp[i] <= 'f')
				local |= (asciiExp[i] - 'a' + 10);
			else
			{
				// Invalid encoding, copy '%' and the first character, continue with the current
				hexExp[count++] = '%';
				hexExp[count++] = (local >> 4) & 0xF;
				hexExp[count++] = asciiExp[i];
				state = 0;
				break;
			}
			hexExp[count++] = local & 0xff;
			state = 0;
			break;
		}
	}
	return count;

}


void CThreadOrderCatch::ConvertURLToGB2312( char* url, char* gb2312Url, int bufferSize)
{
	// Step 1: Convert the original URL to a wide string (UTF-16)
	int wideCharLength = MultiByteToWideChar(CP_UTF8, 0, url, -1, NULL, 0);
	wchar_t* wideString = new wchar_t[wideCharLength];
	MultiByteToWideChar(CP_UTF8, 0, url, -1, wideString, wideCharLength);

	// Step 2: Convert the wide string to GB2312
	int gb2312Length = WideCharToMultiByte(936, 0, wideString, -1, gb2312Url, bufferSize, NULL, NULL);

	// Clean up the wide string buffer
	delete[] wideString;
}


int CThreadOrderCatch::_ConvertToScreen(char* output, char* gb2312, int nLen)
{
	int count = 0;
	char* beginPlace = gb2312;
	int nLineCount = 0;
	_String_Convert_ReturnNewline(gb2312, nLen);
	for (int i = 0; i < nLen; i++)
	{
		if (gb2312[i] != 0x0d && i != nLen - 1)
			nLineCount;
		else
		{
			_ConvertFont(output, beginPlace, nLineCount);
			nLineCount = 0;
			beginPlace = gb2312 + i + 2;
		}
		
	}
	return count;
}


void CThreadOrderCatch::_String_Convert_ReturnNewline(char* string, int nLen)
{
	
	for (int i = 0; i < nLen - 1; i++)
	{
		if (string[i] == '\\' && string[i + 1] == 'r')
		{
			string[i] = 0x0d;
			string[i + 1] = 0x0a;
		}
	}
}


int CThreadOrderCatch::_ConvertFont(char* change, char* particalLine, int nLen)
{
	char get;
	int state = 0;
	char* nextPos;
	for (int i = 0; i < nLen; i++)
	{
		switch (state)
		{
		case 0:
			if (particalLine[i] == '<')
			{
				state = 1;
				get = -1;
			}
			break;
		case 1:
		{	
			int returnPos = 0;
			for (int j = 0; j < countKeyWordFont; j++)
			{
				for(int k = 0; k < _FONTKEY[i].len; k++)
					if (particalLine[i + k], _FONTKEY[j].string)
				if (strstr(particalLine + i, _FONTKEY[j].string))
				{
					i += _FONTKEY[j].len - 1;//avoid next i++
					get = j;
					break;
				}
			}
			if (-1 != get)
			{

			}
		}
		break;
		}
	}
	return 0;
}