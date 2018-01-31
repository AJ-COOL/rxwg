#pragma once
#include <map>
#include <vector>


struct MapInfo
{
	CString szName;
	CString szSupplyNpc;
	POINT supplyPt;
};

class Config
{
public:
	static Config& GetConfig();

	// ��������
	int nProtectHP;
	int nProtentMP;
	CString szPriorHPDrug;
	CString szPriorMPDrug;

	// �һ�����
	POINT pt;
	CString szWorkMap;
	int nAttackType;
	int nAttackRange;
	BOOL bNearestPrior;

	// �س�����
	BOOL bCheckHPDrugs;
	int nMinHPDrugs;
	BOOL bCheckMPDrugs;
	int nMinMPDrugs;
	BOOL bCheckArrows;
	int nMinArrows;
	BOOL bCheckPackage;
	CString szSupplyMap;

	// ��������: ��Ʒ���ƣ�����
	std::map<CString, DWORD> buys;


	std::vector<CString> hpDrugs;
	std::vector<CString> mpDrugs;

	std::vector<MapInfo> maps;
private:
	Config();
	~Config();
};

