#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "mylib.h"
#include <time.h>
using namespace std;

const int so_item = 4;
const int dong = 2;
const int cot = 20;
const int Up = 72;
const int Down = 80;
char thucdon[so_item][50] = { "1. Tao day so ngau nhien    ",
"2. Nhap day tu file         ",
"3. Them ve dau danh sach    ",
"4.Ket thuc chuong trinh     " };




void Normal() {
	/*SetColor(15);
	SetBGColor(0);*/
}
void HighLight() {
	/*SetColor(15);
	SetBGColor(2);*/
}
int MenuDong(char td[so_item][50]) {
	Normal();
	system("cls");   int chon = 0;
	int i;
	for (i = 0; i< so_item; i++)
	{
		gotoxy(cot, dong + i);
		cout << td[i];
	}
	HighLight();
	gotoxy(cot, dong + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case Up:if (chon + 1 >1)
		{
			Normal();
			gotoxy(cot, dong + chon); cout << td[chon];
			chon--;
			HighLight();
			gotoxy(cot, dong + chon); 	cout << td[chon];
		}
				break;
		case Down:if (chon + 1 <so_item)
		{
			Normal();
			gotoxy(cot, dong + chon);	cout << td[chon];
			chon++;
			HighLight();
			gotoxy(cot, dong + chon); 	cout << td[chon];

		}
				  break;
		case 13: return chon + 1;
		}  // end switch
	} while (1);
}

int Menu(char td[so_item][50]) {

	system("cls");   int chon = 0;
	int i;
	for (i = 0; i< so_item; i++)
	{
		gotoxy(cot, dong + i);
		cout << td[i];
	}
Nhaplai:
	gotoxy(cot, dong + so_item);
	cout << "Ban chon 1 so (1..10) :    ";
	gotoxy(wherex() - 4, wherey());
	cin >> chon;
	if (chon <1 || chon >so_item) goto Nhaplai;
	return chon;

}

int main() {

	int chon;
	while (1) {
		chon = MenuDong(thucdon);
		switch (chon) {

		case 1: gotoxy(10, 20);
			cout << "Vua chon chuc nang " << chon;
			break;
		case 2:gotoxy(10, 20);
			cout << "Vua chon chuc nang " << chon;
			break;
		case 3: gotoxy(10, 20);
			cout << "Vua chon chuc nang " << chon;
			break;
		case so_item: return 0;
		}
		Sleep(1000);
	}
	return 0;
}