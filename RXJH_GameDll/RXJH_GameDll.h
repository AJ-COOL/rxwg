// RXJH_GameDll.h : RXJH_GameDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "CutThreadApp.h"
#include "Config.h"
#include "PlayHelper.h"

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

	// ���ص���Ϸ
	void AttachToGame();

	// ��Ϣ����
	LRESULT ProcessMessage(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:
	// ��ʼ��
	void OnMsgInitialize();
	// ��������
	void OnMsgUpdateSetting(bool a_bProtect);
	// ��ʼ/ֹͣ�һ�
	void OnMsgAutoWork(bool a_bWork);
	// ��ȡ��ɫ��ǰ����
	void OnMsgGetPoint();

	// ��ʱ����Ϣ����
	void OnTimer(DWORD a_timerID);

	// ֹͣ����
	void StopWork();

private:

	// ��Ϸ������
	PlayHelper m_playHelper;

	// ���ô����߳�
	CutThreadApp* m_pThread;
	// ��Ϸ���ھ��
	HWND m_hGameWnd;
	// ���ڹ��̺�����ַ
	WNDPROC m_pGameWndProc;

	// 
	bool m_bInitialize;
};
