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

	maps.push_back({ "������", "ƽʮָ", {735, 1856} });
	maps.push_back({ "���Ƹ�", "������",{ 735, 1856 } });
	maps.push_back({ "������", "½С��",{ 735, 1856 } });
}


Config::~Config()
{
}

Config& Config::GetConfig()
{
	static Config sInstance;
	return sInstance;
}
