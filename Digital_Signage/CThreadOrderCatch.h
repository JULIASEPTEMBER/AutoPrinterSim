#pragma once
class CThreadOrderCatch
{
public:
	//analyze api from client and control printing hardware to 
	int _GetStringFrom_clientSocket(char* string);
	

	struct _SeekKeyWord {
		char* keyword;
	};
	void _KeepAnalyzing(int* returnKeyFound, _SeekKeyWord* keysheet, int countkeyword, char data);
	struct _BufferFromServer {
		char* buf;
		int len;
	} pBuffer;
	void _initThreadOrder();
	_SeekKeyWord seek[2];
	int CountKeyWord;
	int ConvertStringTohex(char* hexExp, char* asciiExp, int len);
	void ConvertURLToGB2312( char* url, char* gb2312Url, int bufferSize);
	int _ConvertToScreen(char* output, char* gb2312, int nLen);
	void _String_Convert_ReturnNewline(char* string, int nLen);
	int _ConvertFont(char* change, char* particalLine, int nLen);
	struct _KeyWordSeries {
		char* string;
		int len;
	} _FONTKEY[100];
	int countKeyWordFont;
};
