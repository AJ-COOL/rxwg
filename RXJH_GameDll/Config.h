#pragma once
#include <map>
#include <vector>



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
	BOOL bPickUp;

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
};

