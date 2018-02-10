#pragma once
#include <vector>

// �ڽ���ͼ��Ϣ
struct NearMap
{
	CString szName; // ��ͼ����
	CString szHCFName; // �سǷ�����
	bool bCanUseHCF; // �Ƿ����ʹ�ûسǷ�
	CString szTransferNpc; // ����NPC
	DWORD dwTransIndex; // �㿪�Ի��󣬵�ͼ����ѡ�������
	POINT transferPt; // ��������

	NearMap(){}
	NearMap(char* a_name, char* a_hcfName, bool a_bUseHCF, POINT a_pt, char* a_transferNpc = "", DWORD a_transIndex = 0)
	:szName(a_name), szHCFName(a_hcfName), bCanUseHCF(a_bUseHCF), transferPt(a_pt), szTransferNpc(a_transferNpc), dwTransIndex(a_transIndex)
	{

	}
	void SetTransferPt(POINT pt) { transferPt = pt; }
};
// ��ͼ��Ϣ
struct MapInfo
{
	CString szName; // ��ͼ����
	CString szHCFName;// �سǷ�����
	CString szDepotNpc; // �ֿ�NPC����
	POINT depotPt; // �ֿ�NPC����
	CString szSupplyNpc; // ����NPC����
	POINT supplyPt; // ����NPC����
	// ���ڵ�ͼ��Ϣ
	std::vector<NearMap> newarMaps;

	MapInfo(){}
	MapInfo(char* a_name, char* a_hcfName, char* a_depotNpc, POINT a_depotPt, char* a_supplyNpc, POINT a_supplyPt)
	:szName(a_name), szHCFName(a_hcfName), szDepotNpc(a_depotNpc), depotPt(a_depotPt), szSupplyNpc(a_supplyNpc), supplyPt(a_supplyPt)
	{

	}
};


class MapManager
{
public:
	static MapManager& GetMgr();

	const std::vector<MapInfo>& GetAllMaps();

	bool GetMapInfoByName(const CString& a_szName, MapInfo& a_info);

private:
	MapManager();
	~MapManager();

	void InitMaps();

private:
	std::vector<MapInfo> m_maps;
};

