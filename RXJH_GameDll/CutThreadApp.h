#pragma once



// CutThreadApp
#include "CDialg_Main.h"

class CutThreadApp : public CWinThread
{
	DECLARE_DYNCREATE(CutThreadApp)

protected:
	CutThreadApp();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CutThreadApp();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CCDialg_Main* pDlg;
};


