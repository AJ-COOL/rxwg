#include "stdafx.h"
#include "ListBoxEx.h"
#include "resource.h"


CListBoxEx::CListBoxEx()
{
}


CListBoxEx::~CListBoxEx()
{
}
BEGIN_MESSAGE_MAP(CListBoxEx, CListBox)
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


void CListBoxEx::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	POINT   pt;
	GetCursorPos(&pt);
	int nCount = GetCount();
	ScreenToClient(&pt);
	int nSel = -1;
	//ʵ���Ҽ����ѡ��Ŀ��
	for (int i = 0; i < nCount; i++)
	{
		CRect rc;

		GetItemRect(i, &rc);
		if (rc.PtInRect(pt))
		{
			nSel = i;
			SetCurSel(i);

			break;
		}
	}
	if (nSel >= 0)
	{
		CMenu temp, *ptr;
		temp.LoadMenu(IDR_MENU1);
		ptr = temp.GetSubMenu(0);
		ClientToScreen(&pt);
		ptr->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, GetParent());
	}
}
