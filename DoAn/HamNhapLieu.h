#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include "mylib.h"
using namespace std;

// cac ham nhap ngay/thang/nam

void nhangiatri(int &x, int&y, string &ketqua, char batkitu)
{
	ketqua += batkitu;
	cout << batkitu;
	x++;
	gotoxy(x, y);
}

void nhapnam(int x, int y, string &nam, char &lenh)
{
	string ketqua = nam;
	int toadogocX = x;
	x += ketqua.length();
	gotoxy(x, y);

	string namNhoNhat = "2000";
	while (true)
	{
		char batkitu = _getch();

		// truong hop nhap so
		if ((batkitu >= '0') && (batkitu <= '9') && (ketqua.length() < namNhoNhat.length()) && (batkitu >= namNhoNhat.at(ketqua.length())))
		{
			nhangiatri(x, y, ketqua, batkitu);
		}

		// truong hop nhap phim Backspace
		if (batkitu == 8)
		{
			if (x > toadogocX)
			{
				int kichThuocChuoi = ketqua.length();
				ketqua.resize(kichThuocChuoi - 1); // giam 1 ki tu cua chuoi
				x--;
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y);
			}
		}

		// truong hop nhap phim nut mui ten DE DUNG
		if ((batkitu < 0) && (ketqua.length() >= namNhoNhat.length()))
		{
			batkitu = _getch();
			if (batkitu == 72 || batkitu == 75 || batkitu == 77 || batkitu == 80)
			{
				lenh = batkitu;
				break;
			}
		}
	}

	nam = ketqua;
}

void nhapthang(int x, int y, string &thang, char &lenh)
{
	string ketqua = thang;
	int toadogocX = x;
	x += ketqua.length();
	gotoxy(x, y);

	while (true)
	{
		char batkitu = _getch();

		// truong hop nhap so
		if ((batkitu >= '0') && (batkitu <= '9') && (ketqua.length() < 2))
		{
			if ((ketqua.length() == 0) || (((ketqua.at(0) == '0') && (batkitu >= '1') && (batkitu <= '9')) || ((ketqua.at(0) == '1') && (batkitu >= '0') && (batkitu <= '2'))))
			{
				nhangiatri(x, y, ketqua, batkitu);
			}
		}

		// truong hop nhap phim Backspace
		if (batkitu == 8)
		{
			if (x > toadogocX)
			{
				int kichThuocChuoi = ketqua.length();
				ketqua.resize(kichThuocChuoi - 1); // giam 1 ki tu cua chuoi
				x--;
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y);
			}
		}

		// truong hop nhap phim nut mui ten DE DUNG
		if (batkitu < 0)
		{
			batkitu = _getch();
			if (batkitu == 72 || batkitu == 75 || batkitu == 77 || batkitu == 80)
			{
				if ((ketqua == "") || ((ketqua.at(0) == '0') && (ketqua.length() == 2)) || (ketqua.at(0) != '0'))
				{
					lenh = batkitu;
					break;
				}
			}
		}
	}

	if ((ketqua.length() < 2) && (ketqua != ""))
		ketqua = "0" + ketqua;
	thang = ketqua;
}

void nhapngay(int x, int y, string &ngay, char &lenh)
{
	string ketqua = ngay;
	int toadogocX = x;
	x += ketqua.length();
	gotoxy(x, y);

	while (true)
	{
		char batkitu = _getch();

		// truong hop nhap so
		if ((batkitu >= '0') && (batkitu <= '9') && (ketqua.length() < 2))
		{
			if (ketqua.length() == 0)
				nhangiatri(x, y, ketqua, batkitu);
			else
			{
				if ((ketqua.at(0) == '0') && (batkitu >= '1') && (batkitu <= '9'))
					nhangiatri(x, y, ketqua, batkitu);
				else
				{
					if ((ketqua.at(0) == '1') || (ketqua.at(0) == '2'))
						nhangiatri(x, y, ketqua, batkitu);
					if ((ketqua.at(0) == '3') && (batkitu >= '0') && (batkitu <= '1'))
						nhangiatri(x, y, ketqua, batkitu);
				}
				
			}
		}

		// truong hop nhap phim Backspace
		if (batkitu == 8)
		{
			if (x > toadogocX)
			{
				int kichThuocChuoi = ketqua.length();
				ketqua.resize(kichThuocChuoi - 1); // giam 1 ki tu cua chuoi
				x--;
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y);
			}
		}

		// truong hop nhap phim nut mui ten DE DUNG
		if (batkitu < 0)
		{
			batkitu = _getch();
			if (batkitu == 72 || batkitu == 75 || batkitu == 77 || batkitu == 80)
			{
				if ((ketqua == "") || ((ketqua.at(0) == '0') && (ketqua.length() == 2)) || (ketqua.at(0) != '0'))
				{
					lenh = batkitu;
					break;
				}
			}
		}
	}

	if ((ketqua.length() < 2) && (ketqua != ""))
		ketqua = "0" + ketqua;
	ngay = ketqua;
}



// cac ham nhap chuoi

void H_T(char &kitu)
{
	if (kitu >= 'A' && kitu <= 'Z')
		kitu += 32;
}

void T_H(char &kitu)
{
	if (kitu >= 'a' && kitu <= 'z')
		kitu -= 32;
}

void XuLyTenRieng(string &ten) // chi sd khi da xu ly dau cach
{
	string ketqua = "";
	for (int i = 0; i < ten.length(); i++)
	{
		char kiTuHienTai = ten.at(i);
		if ((i != 0) && (kiTuHienTai != ' '))
		{
			H_T(kiTuHienTai);
			if (ten.at(i - 1) == ' ')
				T_H(kiTuHienTai);
		}
		ketqua += kiTuHienTai;
	}
	ten = ketqua;
}

void NhapTen(int x, int y, string &giatri, char &lenh)
{
	string ketqua = giatri;
	int toadogocX = x;
	x += ketqua.length();
	gotoxy(x, y);

	// thuc hien viec nhap lien tuc
	while (true)
	{
		char batkitu = _getch();
		// truong hop nhap chu & so binh thuong
		if (((batkitu >= 'a') && (batkitu <= 'z')) || ((batkitu >= 'A') && (batkitu <= 'Z')) || ((batkitu >= '0') && (batkitu <= '9')))
		{
			if (ketqua.length() == 0)
				T_H(batkitu);
			ketqua += batkitu;
			cout << batkitu;
			x++;
			gotoxy(x, y);
		}

		// truong hop nhap dau _
		if ((batkitu == ' ') && (ketqua.length() != 0) && (ketqua.at(ketqua.length() - 1) != ' '))
		{
			ketqua += batkitu;
			cout << batkitu;
			x++;
			gotoxy(x, y);
		}

		// truong hop nhap phim Backspace
		if (batkitu == 8)
		{
			if (x > toadogocX)
			{
				int kichThuocChuoi = ketqua.length();
				ketqua.resize(kichThuocChuoi - 1); // giam 1 ki tu cua chuoi
				x--;
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y);
			}
		}

		// truong hop nhap phim ENTER
		if (batkitu < 0)//(batkitu == 13)
		{
			batkitu = _getch();
			if (batkitu == 72 || batkitu == 75 || batkitu == 77 || batkitu == 80)
			{
				lenh = batkitu;
				if (ketqua.at(ketqua.length() - 1) == ' ')
				{
					int kichThuocChuoi = ketqua.length();
					ketqua.resize(kichThuocChuoi - 1); // giam 1 ki tu cua chuoi
				}
				XuLyTenRieng(ketqua);
				break;
			}
		}
	}

	giatri = ketqua;
}

void NhapMa(int x, int y, string &giatri, int doDaiChuoi, char &lenh)
{
	string ketqua = giatri;
	int toadogocX = x;
	x += ketqua.length();
	gotoxy(x, y);

	// thuc hien viec nhap lien tuc
	while (true)
	{
		char batkitu = _getch();
		// truong hop nhap chu & so binh thuong
		if (((batkitu >= 'a') && (batkitu <= 'z')) || ((batkitu >= 'A') && (batkitu <= 'Z')) || ((batkitu >= '0') && (batkitu <= '9')))
		{
			T_H(batkitu);
			ketqua += batkitu;
			cout << batkitu;
			x++;
			gotoxy(x, y);
		}

		// truong hop nhap dau _
		if ((batkitu == ' ') && (ketqua.length() != 0) && (ketqua.at(ketqua.length() - 1) != ' '))
		{

		}

		// truong hop nhap phim Backspace
		if (batkitu == 8)
		{
			if (x > toadogocX)
			{
				int kichThuocChuoi = ketqua.length();
				ketqua.resize(kichThuocChuoi - 1); // giam 1 ki tu cua chuoi
				x--;
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y);
			}
		}

		// truong hop nhap phim ENTER
		if (batkitu < 0)//(batkitu == 13)
		{
			batkitu = _getch();
			lenh = batkitu;
			if (ketqua.at(ketqua.length() - 1) == ' ')
			{
				int kichThuocChuoi = ketqua.length();
				ketqua.resize(kichThuocChuoi - 1); // giam 1 ki tu cua chuoi
			}
			//XuLyTenRieng(ketqua);
			break;
		}

		// Khong the nhap vi gioi han do dai chuoi
		if (ketqua.length() >= doDaiChuoi)
			break;
	}

	giatri = ketqua;
}