#include "VATTU.h"
#include "DS_VATTU.h"

//tra ve vi tri cua 1 vat tu
int DS_VATTU::Search(string mavt)
{
	int i;
	for (i = 0; i < n; i++) {
		if(mavt == node[i].getMAVT())
			return i;
	}
	return -1;
}

int DS_VATTU::Full() {
	if (n == MaxSize) {
		return 0; //danh sach day
	}
	else {
		return 1; //danh sach chua day
	}
}

bool DS_VATTU::Them() 
{
	if (n < MaxSize)
	{
		while (true)
		{
			string MaVTTemp;
			cout << endl << "Nhap vao ma vat tu: ";
			while (true)
			{
				char temp = _getch();
				if (temp != 27 && temp != 13)
				{
					if (((temp >= 'a') && (temp <= 'z')) || ((temp >= 'A') && (temp <= 'Z')) || ((temp >= '0') && (temp <= '9')))
					{
						if ((temp >= 'a') && (temp <= 'z'))
							temp -= 32;
						MaVTTemp += temp;
						cout << temp;
					}
				}
				else
				{
					if (temp == 27)
						return false;
					if (temp == 13)
					{
						if (MaVTTemp != "")
							break;
					}
				}
			}
			if (Search(MaVTTemp) < 0)
			{
				if (node[n].Nhap() == true)
				{
					node[n].setMAVT(MaVTTemp);
					n++;
					return true;
				}
				else
					return false;
			}
		}	
	}
	else
		return false;
}

void DS_VATTU::Them(string mavt, string tenvt, int slt, string dvt)
{
	if (n < MaxSize) 
	{
		node[n].setTENVT(tenvt);
		node[n].setMAVT(mavt);
		node[n].setDVT(dvt);
		node[n].setSLT(slt);
		n++;
	}
	else {
		cout << "\nDanh Sach Day";
	}
}

void DS_VATTU::XoaVT(string mavt)
{
	for (int i = 0; i < n; i++) 
	{
		if (node[i].getMAVT() != mavt)
		{
			cout << "\nKhong co ma vat tu " << mavt;
		}
		else 
		{
			for (int j = i; j < n - 1; j++)
			{
				node[j] = node[j + 1];
			}
			n--;
		}
	}
}

void DS_VATTU::SuaVT(string ma_vt) {
	char LuaChon;
	string tenvt, mavt;
	for (int i = 0; i < n; i++) {
		if (node[i].getMAVT() == ma_vt) {
			bool KiemTraNhap = true;
			while (KiemTraNhap) {
				cout << "\n1. Sua MVT";
				cout << "\n2. Sua TENVT";
				cout << "\n0. Thoat";
				cout << "\nNhap vao lua chon: ";
				do {
					LuaChon = _getch();
					cout << LuaChon;
					if (LuaChon == '0' || LuaChon == '1' || LuaChon == '2') {
						switch (LuaChon) {
							case '1':
								cout << "\nNhap vao Ma Vat Tu moi: "; fflush(stdin); getline(cin, mavt); node[i].setMAVT(mavt); break;
							case '2':
								cout << "\nNhap vao Ten Vat Tu moi: "; fflush(stdin); getline(cin, tenvt); node[i].setTENVT(tenvt); break;
							case '0': KiemTraNhap = false;
						}
						break;
					}
				} while (true);
					
			}
		}
		else {
			cout << "\nKo co Vat tu do";
		}
	}
}

int DS_VATTU::SoLuongVT()
{
	return n;
}

void DS_VATTU::Xuat()
{
	string mangTenVT[MaxSize];
	for (int i = 0; i < n; i++)
	{
		mangTenVT[i] = node[i].getMAVT();
	}
	Quick_Sort(mangTenVT, n);
	for (int i = 0; i < n; i++)
	{
		node[Search(mangTenVT[i])].Xuat();
	}
}

DS_VATTU::DS_VATTU()
{

}

DS_VATTU::~DS_VATTU()
{

}

void DS_VATTU::Sort(string A[MaxSize], int q, int r)
{
	string temp;
	int i = q;
	int j = r;
	string x = A[(q + r) / 2];
	do
	{
		while (A[i] < x) 
			i++;
		while (A[j] > x)
			j--;
		if (i <= j) 
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++; 
			j--;
		}
	} while (i <= j);
	if (q < j)
		Sort(A, q, j);
	if (i > r)
		Sort(A, i, r);
}

void DS_VATTU::Quick_Sort(string A[MaxSize], int n)
{
	Sort(A, 0, n - 1);
}