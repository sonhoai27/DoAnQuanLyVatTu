#pragma once
#include "VATTU.h"
#include "DS_VATTU.h"
class HOADON
{
private:
	int NgHienTai();
	void SetBGColor(WORD color);
	void gotoxy(short x, short y);
	void VeMau();
	void coutChar(int code);
	void SetColor(WORD color);
	
public:
	int SoHD, NgLapHD;
	char Loai;
	DS_VATTU DsCon;
	int static AutoNumber;
	void Nhap(); //truyen vao ds kho, kho 
	void Xuat(); //xuat to hoa don ra
	HOADON();
	~HOADON();
};

