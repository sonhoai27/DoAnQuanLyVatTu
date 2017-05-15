#include "NHANVIEN.h"

void NHANVIEN::NhapMoi()
{
	while (true)
	{
		cout << "Nhap HO: ";
		fflush(stdin);
		getline(cin, Ho);
		if (Ho != "")
			break;
	}

	while (true)
	{
		cout << "Nhap TEN: ";
		fflush(stdin);
		getline(cin, Ten);
		if (Ten != "")
			break;
	}

	cout << "Phai ('0' - Nam / '1' - Nu / ENTER - Trong): ";
	while (true)
	{
		fflush(stdin);
		char c = _getch();
		if (c == '1')
		{
			cout << c << endl;
			SetPhai(true);
			break;
		}
		else if (c == '0')
		{
			cout << c << endl;
			SetPhai(false);
			break;
		}
		else if (c == 13)
		{
			cout << endl;
			break;
		}
	}
}

//int NHANVIEN::GetMaNV()
//{
//	return MaNV;
//}
string NHANVIEN::GetHo()
{
	return Ho;
}
string NHANVIEN::GetTen()
{
	return Ten;
}
string NHANVIEN::GetPhai()
{
	return Phai;
}
void NHANVIEN::SetHo(string ho)
{
	Ho = ho;
}
void NHANVIEN::SetTen(string ten)
{
	Ten = ten;
}
void NHANVIEN::SetPhai(bool phai)
{
	(phai == true) ? Phai = "Nu" : Phai = "Nam";
}
NHANVIEN::NHANVIEN()
{

}

NHANVIEN::~NHANVIEN()
{

}
