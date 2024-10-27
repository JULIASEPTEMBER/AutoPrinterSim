#pragma once

struct stateString_FORMAT {
	char param[3], data;
};
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
	int _ConvertFont(char* change, int *count, char* particalLine, int nLen);
	struct _KeyWordSeries {
		static const int FLAG_PUSH = 1, FLAG__POP = 0;
		char* string;
		int len;
		int flag_push;//1:push 0:pop
	} _FONTKEY[100];
	int countKeyWordFont;
	void find_key_word(char* target_string, int* pos, char* string, int len);
	void output_text(char* target_string, int* pos, char* content, int len, int type);
	char* output_string;
	int _stack[10];
	int stack_top;
	void push_stack(int type);
	int pop_stack();
	
	void monitor(char* string, int* i = 0);

	struct format_display {
		int paper_width, ascii_width;

	};
	format_display obj_format_display;


	//gb2312 cn Start = 280
	//char0 = posl
	//char1[0:1] = posh
	//char1[2:7] = lettercount
	//char2[0:3] = width / 8
	//char2[4:7] = height / 8
	//string:

	struct currentStringState {
		char series0[60];
		char series1[60];
		char series2[60];
		  
		int count;
	};

	void SetFontSate(stateString_FORMAT* fontStruct, int textX, int lettercount, int width, int height);
};
