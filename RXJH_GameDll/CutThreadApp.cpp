// CutThreadApp.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RXJH_GameDll.h"
#include "CutThreadApp.h"


// CutThreadApp

IMPLEMENT_DYNCREATE(CutThreadApp, CWinThread)

CutThreadApp::CutThreadApp()
{
	pDlg = nullptr;
}

CutThreadApp::~CutThreadApp()
{
}

BOOL CutThreadApp::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	if (nullptr == pDlg)
	{
		pDlg = new CCDialg_Main;
		pDlg->Create(IDD_DIALOG_MAIN);
		pDlg->ShowWindow(SW_SHOW);
		pDlg->UpdateData();
	}
	return TRUE;
}

int CutThreadApp::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	delete pDlg;
	pDlg = nullptr;
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CutThreadApp, CWinThread)
END_MESSAGE_MAP()


// CutThreadApp ��Ϣ�������
