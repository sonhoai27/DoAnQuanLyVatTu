#include "Nodes_DSNHANVIEN.h"
class DS_NHANVIEN
{
	NODES_DSNHANVIEN *root;
	NODES_DSNHANVIEN *r;
	void InsertNode(NODES_DSNHANVIEN *&p, int MaMoi, NHANVIEN info);
	void RemoveCase3(NODES_DSNHANVIEN *&p);
	void Preorder(NODES_DSNHANVIEN *p);
public:
	DS_NHANVIEN();
	~DS_NHANVIEN();
	void CreateTree();
	bool isEmpty();
	void Remove(int MaXoa, NODES_DSNHANVIEN *&p);
	void DuyetCay();
	NODES_DSNHANVIEN* Search(int MaTim);
	void clearTree();
	void SuaTT();
};

