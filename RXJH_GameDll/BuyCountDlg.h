#pragma once


// CBuyCountDlg �Ի���

class CBuyCountDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBuyCountDlg)

public:
	CBuyCountDlg(DWORD nBuy, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBuyCountDlg();


	DWORD GetBuyCount();
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_nBuy;
	afx_msg void OnBnClickedOk();
};
