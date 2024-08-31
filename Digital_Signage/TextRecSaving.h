#pragma once
class CTextRecSaving
{
public:
	CTextRecSaving(void);
	~CTextRecSaving(void);
	//Get buffer from 
	void _RecBufferAndSave(WCHAR* wc);
	//buffer length
	int nLength;
};