#include "HOADON.h"

int HOADON::AutoNumber = 0;

int HOADON::NgHienTai()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	return ((1900 + newtime.tm_year) * 10000 + (newtime.tm_mon + 1) * 100 + newtime.tm_mday);
}

void HOADON::coutChar(int code)
{
	cout << (char)code;
	return;
}

void HOADON::SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void HOADON::SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void HOADON::gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void HOADON::VeMau()
{
	int x = 60, y = 1, cn = 90, cd = 30;
	SetColor(14);
	int col1 = 20, col2 = 15, col3 = 10;

	for (int i = x; i <= x + cn - 1; i++) // chieu ngang
	{
		gotoxy(i, y);
		coutChar(205);
		gotoxy(i, y + 2);
		coutChar(205);
		gotoxy(i, y + 4);
		coutChar(205);
		gotoxy(i, y + 6);
		coutChar(205);
		gotoxy(i, y + 8);
		coutChar(205);
		gotoxy(i, y + 10);
		coutChar(196);

		gotoxy(i, y + cd - 1);
		coutChar(205);
		if (i == x)
		{
			gotoxy(i, y);
			coutChar(201);
			gotoxy(i, y + cd - 1);
			coutChar(200);
		}
		if (i == x + cn - 1)
		{
			gotoxy(i, y);
			coutChar(187);
			gotoxy(i, y + cd - 1);
			coutChar(188);
		}
	}

	for (int i = y + 1; i < y + cd - 1; i++)
	{
		gotoxy(x, i);
		coutChar(186);
		gotoxy(x + cn - 1, i);
		coutChar(186);

		if (i == y + 1)
		{
			gotoxy(x + col1 + 1, i - 1);
			coutChar(203);
			gotoxy(x + col1 + 1, i);
			coutChar(186);
		}
		else if ((i == y + 2) || (i == y + 4) || (i == y + 6) || (i == y + 8))
		{
			gotoxy(x, i);
			coutChar(204);
			gotoxy(x + cn - 1, i);
			coutChar(185);
			if ((i != y + 8) && (i != y + 6))
			{
				gotoxy(x + col1 + 1, i);
				coutChar(206);
			}
		}
		else if (i < y + 6)
		{
			gotoxy(x + col1 + 1, i);
			coutChar(186);
		}
		else if (i == y + 10)
		{
			gotoxy(x, i);
			coutChar(199);
			gotoxy(x + cn - 1, i);
			coutChar(182);
		}
		if (i == y + 6)
		{
			gotoxy(x + col1 + 1, i);
			coutChar(202);
		}
	}

	for (int i = y + 8; i <= y + cd - 1; i++)
	{
		if (i == y + 8)
		{
			gotoxy(x + col2 + 1, i);
			coutChar(209);
			gotoxy(x + cn - 1 - col3 - 1, i);
			coutChar(209);
			gotoxy(x + cn - 1 - col3 - 1 - col3 - 1, i);
			coutChar(209);
		}
		else if (i == y + 10)
		{
			gotoxy(x + col2 + 1, i);
			coutChar(197);
			gotoxy(x + cn - 1 - col3 - 1, i);
			coutChar(197);
			gotoxy(x + cn - 1 - col3 - 1 - col3 - 1, i);
			coutChar(197);
		}
		else if (i == y + cd - 1)
		{
			gotoxy(x + col2 + 1, i);
			coutChar(207);
			gotoxy(x + cn - 1 - col3 - 1, i);
			coutChar(207);
			gotoxy(x + cn - 1 - col3 - 1 - col3 - 1, i);
			coutChar(207);
		}
		else
		{
			gotoxy(x + col2 + 1, i);
			coutChar(179);
			gotoxy(x + cn - 1 - col3 - 1, i);
			coutChar(179);
			gotoxy(x + cn - 1 - col3 - 1 - col3 - 1, i);
			coutChar(179);
		}
	}

	
	gotoxy(x, y + cd);
	SetColor(15);
	
	gotoxy(x + 1, 2);
	cout << "So Hoa Don"; //cout << "Ngay Lap Hoa Don:\t " << "Loai Hoa Don:\t " << endl;
	
	gotoxy(x + 1, 4);
	cout << "Ngay Lap Hoa Don";
	
	gotoxy(x + 1, 6);
	cout << "Loai Hoa Don";
	
	gotoxy(100, 8);
	cout << "Danh Sach Vat Tu";
	
	gotoxy(x + 1, y + 9);
	cout << "Ma vat tu";
	gotoxy(x + col2 + 2, y + 9);
	cout << "Ten vat tu";
	gotoxy(x + cn - 1 - col3 - col3 - 1, y + 9);
	cout << "DVT";
	gotoxy(x + cn - 1 - col3, y + 9);
	cout << "SL ton";
}

void HOADON::Nhap()
{
	VeMau();
	AutoNumber++;
	SoHD = AutoNumber;
	cout << "\nSo Hoa Don: "<<SoHD;
	NgLapHD = NgHienTai();
	cout << "\nNgay Lap Hoa Don: " << NgLapHD;
	cout << "\nLoai Hoa Don: ";
	//bool kiemtra = true;
	do
	{
		char c = _getch();
		if (c == 'N' || c == 'n' || c == 'X' || c == 'x')
		{
			if (c == 'n' || c == 'x')
			{
				c -= 32;
			}
			Loai = c;
			break;
		}
	} while (true);
	cout << Loai << endl;
	DsCon.Them();
}

void HOADON::Xuat()
{
	//VeMau();
	gotoxy(60 + 20 + 2, 2);
	cout << SoHD;
	gotoxy(60 + 20 + 2, 4);
	cout << NgLapHD;
	gotoxy(60 + 20 + 2, 6);
	cout << Loai;
	//gotoxy(65, 11);
	DsCon.Xuat();
}

HOADON::HOADON()
{
}


HOADON::~HOADON()
{
}
