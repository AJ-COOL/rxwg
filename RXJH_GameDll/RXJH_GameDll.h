// RXJH_GameDll.h : RXJH_GameDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "CutThreadApp.h"

// CRXJH_GameDllApp
// �йش���ʵ�ֵ���Ϣ������� RXJH_GameDll.cpp
//

class CRXJH_GameDllApp : public CWinApp
{
public:
	CRXJH_GameDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
public:
	
};
