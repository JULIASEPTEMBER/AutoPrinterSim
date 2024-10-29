#pragma once

struct stateString_FORMAT {
	char param[3];
};
struct _UnCompiled {
	static const int default_TextX = 0
		, default_lettercount = 0
		, default_width = 24
		, default_height = 24
		, default_Regular = 0
		, default_font_df = 0
		, default_font_ct = 1
		, default_font_lf = 2
		, default_font_rt = 3
		, default_font_lr = 4
		;

	int TextX;
	int lettercount;
	int width;
	int height;
	int bold;
	int font;
};

#define _DOT_PER_ROW   301
#define _STRINGFONTBOLD   0X80
#define _STRINGFONTASCI   0X40
class CThreadOrderCatch
{
public:
	CThreadOrderCatch();
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
	void find_key_word_FillStruct(char* target_string, int* pos, char* string, int len);
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
	//occor 3*'\0' on the end of each row 
	_UnCompiled m_FontGlobal;
	void SetFontSate(stateString_FORMAT* fontStruct, int textX, int lettercount, int width, int height);
	void FormatInfo_Compiled(char* outputStr, int* endpos, char* string, int len, _UnCompiled* state);
	//change global font by current font key
	void _formatAccord(int id);
	void _FormatFontInGb2312Lib(char* output, int* len, char* input, int lenOri, int bold = 0);
	void _OutputTranslating(char* stringFormatResult, int count);
	void _TranslateFormatInGb2312(_UnCompiled* rslt, stateString_FORMAT* ori);
	void SaveFile_InPath(CString csPath, BYTE* bt, UINT nLen);
};

