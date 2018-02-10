#include "stdafx.h"
#include "MapManager.h"


MapManager::MapManager()
{
	InitMaps();
}


MapManager::~MapManager()
{
}


MapManager& MapManager::GetMgr()
{
	static MapManager s_instance;
	return s_instance;
}

const std::vector<MapInfo>& MapManager::GetAllMaps()
{
	return m_maps;
}

bool MapManager::GetMapInfoByName(const CString& a_szName, MapInfo& a_info)
{
	for (int i = 0; i < m_maps.size(); i++)
	{
		if (a_szName == m_maps[i].szName)
		{
			a_info = m_maps[i];
			return true;
		}
	}
	return false;
}

void MapManager::InitMaps()
{
	// ������
	//MapInfo xbp("������", "�سǷ�(������)", "Τ��", { 155, 1780 }, "ƽʮָ", { 742, 1958 });
	MapInfo xbp("������", "�سǷ�(������)", "", { 155, 1780 }, "����Ц", { 1155, 2227 });
	m_maps.push_back(xbp);

	MapInfo jq("��Ȫ֮��1��", "", "", { 0, 0 }, "����ͤ", { 0, -264 });
	m_maps.push_back(jq);

	MapInfo sxg("��а��", "�سǷ�(��а��)", "����ͨ",{ 6610, 176 }, "½С��",{ 6599, 746 });
	m_maps.push_back(sxg);
	MapInfo lzg("������", "�سǷ�(������)", "����",{ -6832, 297 }, "����ˮ",{ -6639, 203 });
	m_maps.push_back(lzg);
	MapInfo nmh("������", "", "", { 0, 0 }, "", { 0, 0 });
	m_maps.push_back(nmh);
	// ��Ȫ�ͱ�����������ʹ��������ͼ�ĻسǷ�
	//  �������������� ������� xbp:649 1071 bhbg:1578 1185 nl:-1063 265

	MapInfo lsf("�����ᶽ��", "�سǷ�(�����ᶽ��)", "��ԯ����",{ 1176, 239 }, "������",{ 1142, 979 });
	m_maps.push_back(lsf);
	MapInfo swm("������", "�سǷ�(������)", "ƽʮָ", { 742, 1958 }, "½С��", { 735, 1856 });
	m_maps.push_back(swm);
}