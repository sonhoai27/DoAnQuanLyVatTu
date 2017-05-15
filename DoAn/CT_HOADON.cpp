#include "CT_HOADON.h"

//int CT_HOADON::Tong()
//{
//	return 0;
//}

void CT_HOADON::NhapCTHD(HOADON &hoadon)
{
	XuLy_CTHD = &hoadon;
	Tong = 0;
	int SLVT = XuLy_CTHD->DsCon.SoLuongVT(); //soluong vat tu
	/*XuLy_CTHD->DsCon.node[];*/ //biet dc so luong, chay tu 0 den < sl, thi dscon (DSVT).node[i].getMVT/.getSLT se lay dc mavt so luongton
	//dongia[i] //do nhap vao
	//vat[i] tuong tu, VAT
	//tinh tong( = 0) = tong + (dg[i] + dg[i]*vat[i])*.ds.node[i].getSLT;
	for (int i = 0; i < SLVT; i++) {
		cout << XuLy_CTHD->DsCon.node[i].getMAVT() << endl;
		cout << XuLy_CTHD->DsCon.node[i].getSLT() << endl;
		cout << "\nNHap Don Gia: ";
		cin >> DonGia[i];
		cout << "\nNhap VAT";
		cin >> VAT[i];
		Tong = Tong + (DonGia[i] + DonGia[i] * (VAT[i] / 100)*XuLy_CTHD->DsCon.node[i].getSLT());
	}
}

CT_HOADON::CT_HOADON()
{
	
}


CT_HOADON::~CT_HOADON()
{

}
