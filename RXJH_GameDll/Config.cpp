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
}


Config::~Config()
{
}

// �������
void Config::ResetData()
{

}

// ����/������������
bool Config::LoadConfig()
{
	return true;
}
bool Config::SaveConfig()
{
	return true;
}
