#pragma once
#include "Nodes_DSHOADON.h"
#include "KHOCHUA.h"
using namespace std;
class DS_HOADON
{
private:
	KHOCHUA khoChua;
	//DS_VATTU *KhoXuLy;
	NODES_DSHOADON *contro;
public:
	DS_HOADON();
	PTR newnode();
	void InsertLast();
	void XuatDSHOADON();
	void XuLyHOADON();
	int SoLuongHD();
	HOADON &ViTriHD(int Position);
	void TimTheoNgay(int NgayBatDau, int NgayKetThuc, string TenNV, string HoNV);
	void VeThongKeHD(int SoHD, int NgLapHD, char Loai, string HoNV, string TenNV);
	~DS_HOADON();
};
//a
//void nnnn(int &h)
//{
//	h = 6;
//	a = h;
//}


