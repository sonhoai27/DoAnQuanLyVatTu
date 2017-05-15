#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include <dos.h>
#include <math.h>
using namespace std;
const int MaxSize = 200;

class VATTU
{
private:
	string DVT, TenVT, MaVT;
	int SoLuongTon;
	void gotoxy(short x, short y);
public:
	bool Nhap();
	void Xuat();
	string getMAVT();
	string getTENVT();
	string getDVT();
	int getSLT();
	void setMAVT(string x);
	void setTENVT(string x);
	void setDVT(string x);
	void setSLT(int x);
	VATTU();
	~VATTU();

};

