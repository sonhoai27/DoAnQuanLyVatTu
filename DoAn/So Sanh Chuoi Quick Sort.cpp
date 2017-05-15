#include <iostream>
#include <string>
#include <math.h>
using namespace std;


//so sacnh chuoi su dung quick sort
void Sort(string A[11], int q, int r) {
	string temp;
	int i = q;
	int j = r;
	string x = A[ (q + r) / 2];
	
	do{
		while(A[i] < x) i++;
		while(A[j] > x) j--;
		if(i <= j) {
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++; j--;
		}
	}while(i <= j);
	if(q<j) Sort(A, q, j);
	if(i>r) Sort(A, i, r);
}

void Quick_Sort(string A[11], int n){
	Sort(A, 0, n - 1);
}
//so sacnh chuoi su dung quick sort


