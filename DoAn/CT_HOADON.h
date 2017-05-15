#pragma once
#include <iostream>
#include <string>
#include "HOADON.h"
using namespace std;
class CT_HOADON
{
	HOADON *XuLy_CTHD;
	int DonGia[200], VAT[200];
	int Tong;
public:
	/*string MaVT;
	int SoLuong, DonGia;
	float VAT;*/
	/*int Tong();*/
	void NhapCTHD(HOADON &hoadon);
	CT_HOADON();
	~CT_HOADON();
};