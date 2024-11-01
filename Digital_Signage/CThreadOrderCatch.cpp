#include "stdafx.h"
#include "CThreadOrderCatch.h"
#include "JekoAutoMachineServer.h" 

char bufferFromServer[10000];
char _string_monitor[10000];


CThreadOrderCatch::CThreadOrderCatch()
{
	int total = sizeof(_UnCompiled);
	for (int i = 0; i < total; i++)
		((char*)&m_FontGlobal)[i] = 0;
	m_FontGlobal.width = _UnCompiled::default_width;
	m_FontGlobal.height = _UnCompiled::default_height;
	m_FontGlobal.TextX = 0;
	m_FontGlobal.lettercount = _UnCompiled::default_lettercount;
	m_FontGlobal.bold = _UnCompiled::default_Regular;
	m_FontGlobal.font = _UnCompiled::default_font_df;
}

int CThreadOrderCatch::_GetStringFrom_clientSocket(char* string)
{
	int match;
	int whichKeyWord = -1;
	//_KeepAnalyzing()
	for (int i = 0; i < strlen(string); i++)
		_KeepAnalyzing(&whichKeyWord, seek, CountKeyWord, string[i]);
	if (0)
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
		if (place == strlen(keysheet[tempKey].keyword))
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


void CThreadOrderCatch::push_stack(int type)
{
	_stack[stack_top++] = type;
}


int CThreadOrderCatch::pop_stack()
{
	if (stack_top)
		stack_top--;
	else
		return -1;
	return _stack[stack_top];
}


char _FONTSEL___FONTB[] = "FB>";//
char _FONTSEL__DFONTB[] = "/FB>";
char _FONTSEL__CENTER[] = "center>";
char _FONTSEL_DCENTER[] = "/center>";
char _FONTSEL__FONTS2[] = "FS2>";//48*48
char _FONTSEL_DFONTS2[] = "/FS2>";
char _FONTSEL__FONTW2[] = "FW2>";//24*48
char _FONTSEL_DFONTW2[] = "/FW2>";
char _FONTSEL__FONTH2[] = "FH2>";//48*24
char _FONTSEL_DFONTH2[] = "/FH2>";
char _FONTSEL___FONTH[] = "FH>";//32*24
char _FONTSEL__DFONTH[] = "/FH>";
char _FONTSEL___RIGHT[] = "right>";
char _FONTSEL__DRIGHT[] = "/right>";
char _FONTSEL______FS[] = "FS>";//32*32
char _FONTSEL_____DFS[] = "/FS>";
char _FONTSEL______LR[] = "LR>";
char _FONTSEL_____DLR[] = "/LR>";


#define _FONTSEL___FONTB_TYPE 0
#define _FONTSEL__DFONTB_TYPE 1
#define _FONTSEL__CENTER_TYPE 2
#define _FONTSEL_DCENTER_TYPE 3
#define _FONTSEL__FONTS2_TYPE 4
#define _FONTSEL_DFONTS2_TYPE 5
#define _FONTSEL__FONTW2_TYPE 6
#define _FONTSEL_DFONTW2_TYPE 7
#define _FONTSEL__FONTH2_TYPE 8
#define _FONTSEL_DFONTH2_TYPE 9
#define _FONTSEL___FONTH_TYPE 10
#define _FONTSEL__DFONTH_TYPE 11
#define _FONTSEL___RIGHT_TYPE 12
#define _FONTSEL__DRIGHT_TYPE 13
#define _FONTSEL______FS_TYPE 14
#define _FONTSEL_____DFS_TYPE 15
#define _FONTSEL______LR_TYPE 16
#define _FONTSEL_____DLR_TYPE 17












void CThreadOrderCatch::_initThreadOrder()
{
	_string_monitor[0] = 0;
	pBuffer.buf = bufferFromServer;//save order information 
	pBuffer.len = 0;
	CountKeyWord = 0;
	seek[CountKeyWord++].keyword = KEYWORD_EXCHG_KEY;
	seek[CountKeyWord++].keyword = KEYWORD__MENU_KEY;
	countKeyWordFont = 0;
	stack_top = 0;
	obj_format_display.ascii_width = 8;
	obj_format_display.paper_width = 300;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL___FONTB;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL__DFONTB;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL__CENTER;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL_DCENTER;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL__FONTS2;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL_DFONTS2;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL__FONTW2;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL_DFONTW2;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL__FONTH2;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL_DFONTH2;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL___FONTH;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL__DFONTH;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL___RIGHT;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL__DRIGHT;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL______FS;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL_____DFS;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG_PUSH; _FONTKEY[countKeyWordFont++].string = _FONTSEL______LR;
	_FONTKEY[countKeyWordFont].flag_push = _KeyWordSeries::FLAG__POP; _FONTKEY[countKeyWordFont++].string = _FONTSEL_____DLR;



	for (int i = 0; i < countKeyWordFont; i++)
	{
		_FONTKEY[i].len = strlen(_FONTKEY[i].string);
	}


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


void CThreadOrderCatch::ConvertURLToGB2312(char* url, char* gb2312Url, int bufferSize)
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
	//gb2312 = testbuffer;


	for (int i = 0; i < nLen; i++)
	{
		 if (gb2312[i] == 0x0d || i >= nLen - 1)
		{
			//strcat(output, "\r\n");
			output[count++] = 0;
			output[count++] = 0;
			output[count++] = 0;
			beginPlace = gb2312 + i + 2;
			i ++;
		}
		else if(gb2312[i + 1] == 0x0d)
		{
			int pos = 0;
			m_FontGlobal.RowBeg = 1;
			find_key_word_FillStruct(output + count, &pos, beginPlace, nLineCount);
			//find_key_word(output + count, &pos, beginPlace, nLineCount);
			count += pos;
			//strcat(output, "\r\n");
			//_ConvertFont(output, &count, beginPlace, nLineCount);
			beginPlace = gb2312 + i + 3;//means on[i + 1] exists 0x0d or reach file end
			nLineCount = 0;
			i += 2;
			int k = gb2312[i];
		}
		else//(i != nLen - 1 && gb2312[i + 1] != 0x0d && gb2312[i] != 0x0d)//len
		{
			nLineCount++;
		}
		
	} 
	SaveFile_InPath(L"C:\\cloud\\BaiduSyncdisk\\simo2\\AutoPrinter\\AutoPrinter\\path.ojulia", (BYTE*)output, count);
	_OutputTranslating(output, count);
	return count;
}


void CThreadOrderCatch::monitor(char* string, int* i)
{
	char local[256];
	if (i)
	{
		sprintf(local, string, i);
		strcat(_string_monitor, local);
		return;
	}

	{
		strcat(_string_monitor, string);
	}
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


void CThreadOrderCatch::output_text(char* target_string, int* pos, char* content, int len, int type)
{
	int space_count = 0;
	switch (type)
	{
	case _FONTSEL___FONTB_TYPE: break;
	case _FONTSEL__DFONTB_TYPE: break;
	case _FONTSEL__CENTER_TYPE:
	{
		int current_width = len * obj_format_display.ascii_width;

		if (current_width > obj_format_display.paper_width) {
			MessageBox(0, L"error: overflow", 0, 0);
			return;
		}
		space_count = (obj_format_display.paper_width / 2 - current_width / 2) / obj_format_display.ascii_width;

	}
	break;
	case _FONTSEL_DCENTER_TYPE: break;
	case _FONTSEL__FONTS2_TYPE: break;
	case _FONTSEL_DFONTS2_TYPE: break;
	case _FONTSEL__FONTW2_TYPE: break;
	case _FONTSEL_DFONTW2_TYPE: break;
	case _FONTSEL__FONTH2_TYPE: break;
	case _FONTSEL_DFONTH2_TYPE: break;
	case _FONTSEL___FONTH_TYPE: break;
	case _FONTSEL__DFONTH_TYPE: break;
	case _FONTSEL___RIGHT_TYPE:
	{
		int current_width = len * obj_format_display.ascii_width;

		if (current_width > obj_format_display.paper_width) {
			MessageBox(0, L"error: overflow", 0, 0);
			return;
		}
		space_count = (obj_format_display.paper_width - current_width) / obj_format_display.ascii_width;

	}
	break;
	case _FONTSEL__DRIGHT_TYPE: break;



	}
	if (space_count) {


		if (space_count < *pos && len) {
			MessageBox(0, L"error: overlap", 0, 0);
			return;
		}
		for (int i = 0; i < space_count - *pos; i++)
		{
			target_string[(*pos)++] = ' ';
		}
	}
	target_string[(*pos)] = 0;
	strcat(target_string, content);
	(*pos) += len;
}


//set font in each row
void CThreadOrderCatch::find_key_word(char* target_string, int* pos, char* string, int len)
{
	int found = 0;
	int foundID = 0;
	char content[100];
	int contentlen = 0;

	for (int i = 0; i < len; i++)
	{
		char* current;
		current = string + i;
		if (string[i] == '<')
		{
			found = 0;
			i++;
			for (int j = 0; j < countKeyWordFont; j++)
			{
				found = 0;
				foundID = -1;
				for (int k = 0; k < _FONTKEY[j].len; k++)
				{
					if (string[i + k] == _FONTKEY[j].string[k])
					{
						found++;
					}
					else
					{
						found = 0;
						break;
					}
				}
				if (found)
				{
					foundID = j;
					i += _FONTKEY[j].len - 1;
					if (_FONTKEY[j].flag_push == _KeyWordSeries::FLAG_PUSH)
					{
						content[contentlen] = 0;
						//FormatInfo_Compiled("");

						output_text(target_string, pos, content, contentlen, stack_top ? _stack[stack_top - 1] : -1);
						push_stack(foundID);
						contentlen = 0;

					}
					else if (_FONTKEY[j].flag_push == _KeyWordSeries::FLAG__POP)
					{
						content[contentlen] = 0;
						output_text(target_string, pos, content, contentlen, pop_stack());
						contentlen = 0;

					}
					break;
				}
			}
		}
		if (!found)
		{
			content[contentlen++] = string[i];
		}
		else
		{
			found = 0;
		}
	}
	content[contentlen] = 0;
	output_text(target_string, pos, content, contentlen, pop_stack());
	contentlen = 0;
}


//set font in each row
void CThreadOrderCatch::find_key_word_FillStruct(char* target_string, int* pos, char* string, int len)
{
	int found = 0;
	int foundID = 0;
	char content[100];
	int contentlen = 0;
	
	for (int i = 0; i < len + 1; i++)
	{
		char* current;
		current = string + i;
		if (string[i] == '<')
		{
			found = 0;
			i++;
			for (int j = 0; j < countKeyWordFont; j++)
			{
				found = 0;
				foundID = -1;
				for (int k = 0; k < _FONTKEY[j].len; k++)
				{
					if (string[i + k] == _FONTKEY[j].string[k])
					{
						found++;
					}
					else
					{
						found = 0;
						break;
					}
				}
				if (found)
				{
					foundID = j;
					i += _FONTKEY[j].len - 1;
					if (contentlen)
					{
						content[contentlen] = 0; 
						FormatInfo_Compiled(target_string, pos, content, contentlen, &m_FontGlobal);
						contentlen = 0;
					}
					_formatAccord(foundID);
					break;
				}
			}
		}
		if (!found)
		{
			content[contentlen++] = string[i];
		}
		else
		{
			found = 0;
		}
	}
	content[contentlen] = 0;
	if(contentlen)
	{
		FormatInfo_Compiled(target_string, pos, content, contentlen, &m_FontGlobal);

	contentlen = 0;
	}
}


int CThreadOrderCatch::_ConvertFont(char* change, int* count, char* particalLine, int nLen)
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

				//for(int k = 0; k < _FONTKEY[i].len; k++)
				//	if (particalLine[i + k], _FONTKEY[j].string)
				//if (strstr(particalLine + i, _FONTKEY[j].string))
				//{
				//	i += _FONTKEY[j].len - 1;//avoid next i++
				//	get = j;
				//	break;
				//}

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


void CThreadOrderCatch::SetFontSate(stateString_FORMAT* fontStruct, int textX, int lettercount, int width, int height)
{
	((stateString_FORMAT*)fontStruct)->param[0] = textX & 0xff;
	((stateString_FORMAT*)fontStruct)->param[1] = (textX >> 8) & 0x03;
	((stateString_FORMAT*)fontStruct)->param[1] += (lettercount << 2) & 0xfc;
	((stateString_FORMAT*)fontStruct)->param[2] = (width / 8) & 0xf;
	((stateString_FORMAT*)fontStruct)->param[2] += ((height / 8) << 4) & 0xf0;

}


void CThreadOrderCatch::FormatInfo_Compiled(char* outputStr, int* endpos, char* string, int len, _UnCompiled* state)
{
	int begPos;

	switch (m_FontGlobal.font)
	{
	case _UnCompiled::default_font_df:
	case _UnCompiled::default_font_lf:
		m_FontGlobal.TextX = 0;
		break;
	case _UnCompiled::default_font_ct:
	{
		int nCountLetter = len * m_FontGlobal.width / 2;
		int centerPos = _DOT_PER_ROW / 2;
		int lettercenter = nCountLetter / 2;
		int displace = centerPos - lettercenter;
		m_FontGlobal.TextX = displace > 0 ? displace : 0;


	}
	break;
	case _UnCompiled::default_font_rt:
	{
		int nCountLetter = len * m_FontGlobal.width / 2;
		int displace = _DOT_PER_ROW - nCountLetter;
		m_FontGlobal.TextX = displace > 0 ? displace : 0;


	}
	break;
	case _UnCompiled::default_font_lr:
	{
		char localstr[100];
		int findComa = (int)strstr(string, ",");
		if (!findComa)
		{
			m_FontGlobal.font = _UnCompiled::default_font_df;
			FormatInfo_Compiled(outputStr, endpos, string, len, state); return;
		}
		int lenBefore = findComa - (int)string;
		string[lenBefore] = 0;
		m_FontGlobal.font = _UnCompiled::default_font_lf;
		FormatInfo_Compiled(outputStr, endpos, string, lenBefore, state);
		string = &string[lenBefore + 1];
		len -= lenBefore + 1;
		m_FontGlobal.font = _UnCompiled::default_font_rt;
		FormatInfo_Compiled(outputStr, endpos, string, len, state); return;
	}
	break;
	}

	//m_FontGlobal.lettercount = len;
	begPos = (*endpos);

	_FormatFontInGb2312Lib(outputStr + sizeof(stateString_FORMAT), endpos, string, len, m_FontGlobal.bold, &m_FontGlobal.RowBeg);
	m_FontGlobal.lettercount = (((int)*endpos) - begPos) / 2;

	SetFontSate((stateString_FORMAT*)&outputStr[begPos]
		, m_FontGlobal.TextX
		, m_FontGlobal.lettercount
		, m_FontGlobal.width
		, m_FontGlobal.height);

	(*endpos) += sizeof(stateString_FORMAT);
}


void CThreadOrderCatch::_formatAccord(int id)
{
	switch (id)
	{
	case _FONTSEL___FONTB_TYPE:
		m_FontGlobal.bold = 1;
		break;
	case _FONTSEL__DFONTB_TYPE:
		m_FontGlobal.bold = m_FontGlobal.default_Regular;
		break;
	case _FONTSEL__CENTER_TYPE:
		m_FontGlobal.font = m_FontGlobal.default_font_ct;
		break;
	case _FONTSEL_DCENTER_TYPE:
	case _FONTSEL__DRIGHT_TYPE:
	case _FONTSEL_____DLR_TYPE:
		m_FontGlobal.font = m_FontGlobal.default_font_df;
		break;
	case _FONTSEL__FONTS2_TYPE:
		m_FontGlobal.width = 48;
		m_FontGlobal.height = 48;
		break;
	case _FONTSEL_DFONTS2_TYPE:
	case _FONTSEL_DFONTW2_TYPE:
	case _FONTSEL_DFONTH2_TYPE:
	case _FONTSEL__DFONTH_TYPE:
	case _FONTSEL_____DFS_TYPE:
		m_FontGlobal.width = m_FontGlobal.default_width;
		m_FontGlobal.height = m_FontGlobal.default_height;
		break;
	case _FONTSEL__FONTW2_TYPE:

		m_FontGlobal.width = 48;
		m_FontGlobal.height = 16;
		break;
	case _FONTSEL__FONTH2_TYPE:
		m_FontGlobal.width = 16;
		m_FontGlobal.height = 48;
		break;
	case _FONTSEL___FONTH_TYPE:
		m_FontGlobal.width = 16;
		m_FontGlobal.height = 32;
		break;
	case _FONTSEL___RIGHT_TYPE:
		m_FontGlobal.font = m_FontGlobal.default_font_rt;
		break;
	case _FONTSEL______FS_TYPE:
		m_FontGlobal.width = 32;
		m_FontGlobal.height = 32;
		break;
	case _FONTSEL______LR_TYPE:
		m_FontGlobal.font = m_FontGlobal.default_font_lr;
		break;
	}
}


void CThreadOrderCatch::_FormatFontInGb2312Lib(char* output, int* len, char* input, int lenOri, int bold, int* endFlag)
{

	for (int i = 0; i < lenOri; i++)
	{

		if (input[i] & 0x80)
		{
			UINT Get = (input[i + 0] & 0xff) << 8 | (input[i + 1] & 0xff);
			UINT high = (Get >> 8) - 0xA1;
			UINT low = (Get & 0xff) - 0xA1;
			UINT delta = 6 * 16 - 2;
			UINT resultCal = high * delta + low;
			output[(*len)++] = (resultCal >> 8) & 0x1f | (bold ? _STRINGFONTBOLD : 0) | (*endFlag ? _STRINGFONT_BEG : 0);
			output[(*len)++] = resultCal & 0xff;
			*endFlag = 0;
			i += 1;
		}
		else
		{
			UINT startAscii = input[i + 0] - 0x20;
			UINT Get = 0xa3a0;
			UINT high = (Get >> 8) - 0xA1;
			UINT low = (Get & 0xff) - 0xA1;
			UINT delta = 6 * 16 - 2;
			UINT resultCal = high * delta + low;
			resultCal += startAscii;
			if(input[i + 0] == '.' || input[i + 0] == ':' || input[i + 0] == '：')
				output[(*len)++] = (resultCal >> 8) & 0x1f
				| (bold ? _STRINGFONTBOLD : 0) | (*endFlag ? _STRINGFONT_BEG : 0);
			else
			output[(*len)++] = (resultCal >> 8) & 0x1f
				| (bold ? _STRINGFONTBOLD : 0) | _STRINGFONTASCI | (*endFlag ? _STRINGFONT_BEG : 0);
			output[(*len)++] = resultCal & 0xff;
			*endFlag = 0;
		}
	}
}



void CThreadOrderCatch::_OutputTranslating(char* stringFormatResult, int count)
{
	char* monitor, * piece, * get;
	get = stringFormatResult;
	monitor = new char[10000];
	monitor[0] = 0;
	piece = new char[2560];
	int state = 0;
	stateString_FORMAT getHead;
	
	for (int i = 0; i < count; )
	{
		switch (state)
		{
		case 0:
			_TranslateFormatInGb2312(&m_FontGlobal, (stateString_FORMAT*)(get + i));
			sprintf(piece, "\r\ntxtX:%d, lettercount:%d, width:%d, height:%d\r\n"
				, m_FontGlobal.TextX
				, m_FontGlobal.lettercount
				, m_FontGlobal.width
				, m_FontGlobal.height
			);
			strcat(monitor, piece);
			state++;
			i += 3;
			break;
		case 1:
		{
			for (int j = 0; j < m_FontGlobal.lettercount; j++)
			{
				sprintf(piece, "%02x, %02x, ", *(get + i + j * 2 + 0) & 0xff, *(get + i + j * 2 + 1) & 0xff);
				strcat(monitor, piece);
			}
			i += m_FontGlobal.lettercount * 2;
			
		}
		state = 0;
		break;

		}
	}
	monitor;

	monitor[0] = 0;
	sprintf(piece, "const char buf[%d] = {", count);
	strcat(monitor, piece);
	for (int i = 0; i < count - 1; i++)
	{
		sprintf(piece, "0x%02x, ", 0xff & get[i]);
		strcat(monitor, piece);
		if (i % 50 == 49)
			strcat(monitor, "\r\n");
		
	}
	sprintf(piece, "0x%02x};", 0xff & get[count - 1]);
	strcat(monitor, piece);
	monitor;

	delete piece;
	delete monitor;
}


void CThreadOrderCatch::_TranslateFormatInGb2312(_UnCompiled* rslt, stateString_FORMAT* ori)
{


	rslt->TextX = (ori->param[0] & 0xff) + ((ori->param[1] << 8) & 0x300);
	rslt->lettercount = (ori->param[1] >> 2) & 0x3f;
	rslt->width = ori->param[2] & 0xf;
	rslt->height = (ori->param[2] >> 4) & 0xf;
	rslt->width *= 8;
	rslt->height *= 8;

	if (*((char*)(ori + 1)) & _STRINGFONT_BEG && rslt->lettercount)rslt->RowBeg = 1;
}


void CThreadOrderCatch::SaveFile_InPath(CString csPath, BYTE* bt, UINT nLen)
{

	DWORD dw;
	HANDLE hFile;
	::DeleteFile(csPath);
	hFile = ::CreateFile(csPath, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);

	::WriteFile(hFile, bt, nLen, &dw, 0);
	::CloseHandle(hFile);
	//	csoutput += L"存储文件成功" ;
	//	m_output.SetWindowTextW(csoutput);

}