#include "VATTU.h"
void VATTU::gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
bool VATTU::Nhap() {
	char temp;
	bool flag = true;
	bool co = true;
	while (flag) 
	{
		cout << "\nNhap vao ten vat tu: ";
		while (co)
		{
			temp = _getch();
			if (temp != 27 && temp != 13) {
				TenVT += temp;
				cout << temp;
			}
			else {
				if (temp == 27) {
					flag = false;
					break;
				}
				else {
					if (temp == 13) {
						if (TenVT == "") {
							co = true;
						}
						else {
						
							co = false;
						}
					}
				}
			}
		}
		if (flag == false) break;
		co = true;
		cout << "\nNhap vao don vi tinh: ";
		while (co) {
			temp = _getch();
			if (temp != 27 && temp != 13) {
				DVT += temp;
				cout << temp;
			}
			else {
				if (temp == 27) {
					flag = false;
					break;
				}
				else {
					if (temp == 13) {
						if (DVT == "") {
							co = true;
						}
						else {
							
							co = false;
						}
					}
				}
			}
		}
		if (flag == false) break;
		co = true;
		cout << "\nNhap vao so luong ton: ";
		string SLT_String;
		while (co) {
			temp = _getch();
			if (temp != 27 && temp != 13) {
				SLT_String += temp;
				cout << temp;
			}
			else {
				if (temp == 27) {
					flag = false;
					break;
				}
				else {
					if (temp == 13) {
						if (SLT_String == "") {
							co = true;
						}
						else {
							
							SoLuongTon = atoi(SLT_String.c_str());
							break;
						}
					}
				}
			}
		}

		flag = false;
		return true;
	}

	return false;

}

void VATTU::Xuat() {
	/*gotoxy(61, 12);
	cout << MaVT;
	gotoxy(75 + 2, 12);
	cout << TenVT;
	gotoxy(60 + 90 - 1 - 10 - 10 - 1, 12);
	cout << DVT;
	gotoxy(60 + 90 - 1 - 10, 12);
	cout << SoLuongTon;*/
	cout << MaVT << "\t";
	cout << TenVT << "\t";
	cout << DVT << "\t";
	cout << SoLuongTon << endl;
}

//get
string VATTU::getMAVT() {
	return MaVT;
}

string VATTU::getTENVT() {
	return TenVT;
}

string VATTU::getDVT() {
	return DVT;
}

int VATTU::getSLT() {
	return SoLuongTon;
}

//set
void VATTU::setMAVT(string x) {
	MaVT = x;
}

void VATTU::setTENVT(string x) {
	TenVT = x;
}

//truyen x de thay doi, cap nhat (+, -) so luong ton, de tao thanh so luong ton moi.

void VATTU::setSLT(int x) {
	SoLuongTon = x;
}

void VATTU::setDVT(string x) {
	DVT = x;
}

VATTU::VATTU()
{
}


VATTU::~VATTU()
{

}

//them ham search de xu ly nhap vao vat tu, đối với mã vật tư
//vi du nhapp vao 5, trong luc do tim vao kho co 4, no se hien len bang thong bao, con 4, co muon lay khong.