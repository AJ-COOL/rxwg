#include "stdafx.h"
#include "EntityNPC.h"


EntityNPC::EntityNPC(DWORD a_id)
:EntityBase(a_id)
{
	m_nSize = 60;
}

EntityNPC::EntityNPC(const CString& a_name)
	: EntityBase(EntityBase::ID_NULL)
{
	m_nSize = 60;
	// ����NPC���ƻ�ȡID
	for (DWORD dwID = 1; dwID < 0x2710; dwID++)
	{
		// ����ΪNPC
		if (ET_NPC == EntityBase::GetTypeWithID(dwID))
		{
			DWORD dwNation = Read_RD(EntityPropAddress + dwID * 4);
			CString szName = Read_RS(dwNation + EntityNameOffset);
			if (a_name == szName)
			{
				SetID(dwID);
				break;
			}
		}
	}
}


EntityNPC::~EntityNPC()
{
}

bool EntityNPC::IsTalkOpened()
{
	DWORD dwNPCBaseAddr = 0x02D37C7C; // 02D36518 + 5D9 * 4
	DWORD dwOpen = Read_RD((Read_RD(dwNPCBaseAddr) + 0x338) + 0x40);
	return dwOpen != 0;
}
bool EntityNPC::IsShopOpened()
{
	DWORD dwNPCBaseAddr = 0x02D37C7C; // 02D36518 + 5D9 * 4
	DWORD dwOpen = Read_RD((Read_RD(dwNPCBaseAddr) + 0x348) + 0x40);
	return dwOpen != 0;
}

void EntityNPC::OpenTalk()
{
	// ��ѡ��NPC
	Select();

	// �򿪶Ի�ѡ�
	DWORD dwNation = m_nation;
	_asm
	{
		mov ecx, dwNation
		mov edx, [ecx]
		mov eax, [edx + 4]
		push 0
		push 0
		push 0x401
		call eax
	}
	// �ȴ�ѡ��򿪲ŷ���
	/*bool bOpen = IsTalkOpened();
	int tryCount = 10;
	while (!bOpen && tryCount > 0)
	{
		::Sleep(50);
		bOpen = IsTalkOpened();
		tryCount--;
	}
	::Sleep(1000);*/
}
void EntityNPC::CloseTalk()
{
	DWORD NPCCloseTalkBaseAddress = 0x0109CF50;
	DoNPCOperation(NPCCloseTalkBaseAddress);
}

void EntityNPC::ChooseOption(DWORD a_index)
{
	DWORD NPCChooseBaseAddress = 0x0109CF5C + a_index * 4;
	DoNPCOperation(NPCChooseBaseAddress);
}

void EntityNPC::OpenShop()
{
	DWORD NPCCloseTalkBaseAddress = 0x0109CF5C;
	DoNPCOperation(NPCCloseTalkBaseAddress);
	// �ȴ����ڴ򿪲ŷ���
	/*bool bOpen = IsShopOpened();
	int tryCount = 10;
	while (!bOpen && tryCount > 0)
	{
		::Sleep(50);
		bOpen = IsShopOpened();
		tryCount--;
	}
	::Sleep(1000);*/
}

void EntityNPC::CloseShop()
{
	DWORD NPCCloseTalkBaseAddress = 0x0109CFB8;
	DoNPCOperation(NPCCloseTalkBaseAddress);
}

void EntityNPC::CloseDepot()
{
	DWORD NPCCloseTalkBaseAddress = 0x0109D080;
	DoNPCOperation(NPCCloseTalkBaseAddress);
}

void EntityNPC::DoNPCOperation(DWORD a_baseAddr)
{
	DWORD dwBaseAddress = a_baseAddr;
	_asm
	{
		mov eax, dwBaseAddress
		mov eax, [eax]
		add eax, 4
		mov esi, [eax]
		mov ecx, [esi + 4]
		mov eax, [esi + 0x254]
		mov edx, [ecx]
		mov edx, [edx + 4]
		push 0
		push eax
		push 0x3F4
		call edx
	}
}

bool EntityNPC::BuyGoodsByName(const CString& a_name, DWORD a_count)
{
	bool bRet = false;
	if (a_count > 0)
	{
		DWORD dwGoodsId = GetGoodsID(a_name);
		if (dwGoodsId > 0)
		{
			// ������Ʒ
			bRet = BuyGoodsByID(dwGoodsId, a_count);
		}
	}
	
	return bRet;
}

bool EntityNPC::BuyGoodsByID(DWORD a_id, DWORD a_count)
{
	BYTE* pDate = new BYTE[142];
	memset(pDate, 0, 142);
	_asm
	{
		mov eax, pDate
		mov dword ptr[eax + 2], 0x00880092
		mov dword ptr[eax + 6], 0x1
		mov dword ptr[eax + 0x0A], 0
		mov ebx, a_id
		mov dword ptr[eax + 0x0E], ebx
		mov dword ptr[eax + 0x12], 0
		mov ebx, a_count
		mov dword ptr[eax + 0x16], ebx
		mov ecx, dword ptr ds:[0x1097760]
		push 0x8E
		push eax
		mov edx, ShopCallAddress
		call edx
	}
	delete pDate;
	pDate = nullptr;
	return true;
}

DWORD EntityNPC::GetGoodsID(const CString& a_name)
{
	DWORD dwID = 0;
	for (int i = 0; i < m_nSize; i++)
	{
		DWORD dwNation = Read_RD(Read_RD(ShopBaseAddress) + i * 4 + ShopBaseOffset);
		if (0 == dwNation)
		{
			break;
		}
		CString szName = Read_RS(dwNation + ShopItemNameOffset);
		if (a_name == szName)
		{
			dwID = Read_RD(dwNation + ShopItemIDOffset);
			break;
		}
	}
	return dwID;
}