#pragma once


// CShow_Informations

class CShow_Informations : public CWnd
{
	DECLARE_DYNAMIC(CShow_Informations)

public:
	CShow_Informations();
	virtual ~CShow_Informations();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void Create();
};


