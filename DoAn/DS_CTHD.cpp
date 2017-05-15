#include "DS_CTHD.h"



void DS_CTHD::InsertLast(HOADON &hoadon) {
	NODES_DSCTHOADON * p = new NODES_DSCTHOADON;
	p->next = NULL; //danh sach chua co gi nen phai tro p->next = null, vi tri cuoi.
	if (contro == NULL) {
		p->info.NhapCTHD(hoadon);
		contro = p; //neu first mà bang null thi gan p vao;
	}
	else
	{
		NODES_DSCTHOADON * last;
		for (last = contro; last->next != NULL; last = last->next);
		p->info.NhapCTHD(hoadon);
		last->next = p;
	}
	
}

DS_CTHD::DS_CTHD()
{
	contro = NULL;
}


DS_CTHD::~DS_CTHD()
{
	while (contro != NULL)
	{
		NODES_DSCTHOADON * p;
		p = contro;
		contro = p->next;
		delete p;
	}
}
