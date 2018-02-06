#pragma once
#include <map>
#include <vector>


struct MapInfo
{
	CString szName; // ��ͼ����
	CString szHCFName;// �سǷ�����
	CString szDepotNpc; // �ֿ�NPC����
	POINT depotPt; // �ֿ�NPC����
	CString szSupplyNpc; // ����NPC����
	POINT supplyPt; // ����NPC����
};

class Config
{
public:
	Config();
	~Config();
	// �������
	void ResetData();

	// ����/������������
	bool LoadConfig();
	bool SaveConfig();

	bool GetMapInfoByName(const CString& a_mapName, MapInfo& a_info) const;

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

};

