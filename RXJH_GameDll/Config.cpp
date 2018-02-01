#include "stdafx.h"
#include "Config.h"


Config::Config()
{
	hpDrugs.push_back("��ҩ(С)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("���ƽ�ҩ");
	hpDrugs.push_back("ҩ�ɽ�ҩ");

	mpDrugs.push_back("�˲�");
	mpDrugs.push_back("Ұɽ��");
	mpDrugs.push_back("ѩԭ��");
	mpDrugs.push_back("��Ԫ��");
	mpDrugs.push_back("Ѫ��");
	mpDrugs.push_back("�����˲�");
	mpDrugs.push_back("������Ԫ��");
	mpDrugs.push_back("ҩ����Ԫ��");

	maps.push_back({ "������", "�سǷ�(������)", "ƽʮָ", {742, 1958} });
	// 9ȪNPC ����ͤ 55, 1861
	maps.push_back({ "��а��", "�سǷ�(��а��)", "½С��",{ 6599, 746 } });
	maps.push_back({ "���Ƹ�", "�سǷ�(���Ƹ�)", "������",{ 735, 1856 } });
	maps.push_back({ "������", "�سǷ�(������)", "½С��",{ 735, 1856 } });
}


Config::~Config()
{
}

Config& Config::GetConfig()
{
	static Config sInstance;
	return sInstance;
}

bool Config::GetMapInfoByName(const CString& a_mapName, MapInfo& a_info)
{
	for (int i = 0; i < maps.size(); i++)
	{
		if (a_mapName == maps[i].szName)
		{
			a_info = maps[i];
			return true;
		}
	}
	return false;
}