#include "DS_NHANVIEN.h"



DS_NHANVIEN::DS_NHANVIEN()
{
	root = NULL;
}

DS_NHANVIEN::~DS_NHANVIEN()
{
	while (root != NULL)
	{
		int delKey = root->MaNV;
		Remove(delKey, root);
	}
}

void DS_NHANVIEN::InsertNode(NODES_DSNHANVIEN *&p, int MaMoi, NHANVIEN info)
{
	if (p == NULL)
	{
		p = new NODES_DSNHANVIEN;
		p->MaNV = MaMoi;
		p->info.SetHo(info.GetHo());
		p->info.SetTen(info.GetTen());
		(info.GetPhai() == "Nu") ? p->info.SetPhai(true) : p->info.SetPhai(false);
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (MaMoi < p->MaNV)
			InsertNode(p->left, MaMoi, info);
		else if (MaMoi > p->MaNV)
			InsertNode(p->right, MaMoi, info);
	}
}

void DS_NHANVIEN::CreateTree()
{
	NHANVIEN nv;
	nv.NhapMoi();
	srand(time(NULL));
	while (true)
	{
		int a = rand() % 50 + 1;
		if (Search(a) == NULL)
		{
			cout << " " << a << " ";
			InsertNode(root, a, nv);
			break;
		}
	}
}

bool DS_NHANVIEN::isEmpty()
{
	if (root == NULL)
		return true;
	return false;
}

void DS_NHANVIEN::RemoveCase3(NODES_DSNHANVIEN *&p)
{
	if (p->left == NULL)
	{
		r->MaNV = p->MaNV;
		r->info = p->info;
		r = p;
		p = r->right;
	}
	else
		RemoveCase3(p->left);
}

void DS_NHANVIEN::Remove(int MaXoa, NODES_DSNHANVIEN *&p)
{
	if (p == NULL)
		cout << "Khong tim thay" << endl;
	else
	{
		if (MaXoa < p->MaNV)
			Remove(MaXoa, p->left);
		else if (MaXoa > p->MaNV)
			Remove(MaXoa, p->right);
		else // truong hop tim thay key can xoa
		{
			r = p;
			if (r->right == NULL)
				p = r->left;
			else if (r->left == NULL)
				p = r->right;
			else
				RemoveCase3(r->right);
			delete r;
		}
	}
}

void DS_NHANVIEN::Preorder(NODES_DSNHANVIEN *p)
{
	if (p != NULL)
	{
		Preorder(p->left);
		cout << p->MaNV << " -> ";
		Preorder(p->right);
	}
}

void DS_NHANVIEN::DuyetCay()
{
	Preorder(root);
}

NODES_DSNHANVIEN* DS_NHANVIEN::Search(int MaTim)
{
	NODES_DSNHANVIEN *p = root;
	while (p != NULL && p->MaNV != MaTim)
	{
		if (MaTim < p->MaNV)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}

void DS_NHANVIEN::clearTree()
{
	while (root != NULL)
	{
		int delKey = root->MaNV;
		Remove(delKey, root);
	}
}

void DS_NHANVIEN::SuaTT()
{
	int editKey;
	char suatiep;
	do
	{
		cout << "Nhap ma nhan vien can sua: ";
		cin >> editKey;
		NODES_DSNHANVIEN *temp = Search(editKey);

		if (temp != NULL)
		{
			cout << "1. Sua HO nhan vien" << endl;
			cout << "2. Sua TEN nhan vien" << endl;
			cout << "3. Thoat" << endl;
			cout << "Chon: ";
			while (true)
			{
				char c = _getch();
				if (c == '1')
				{
					cout << c << endl;
					string editHo;
					getline(cin, editHo);
					temp->info.SetHo(editHo);
				}
				if (c == '2')
				{
					cout << c << endl;
					string editTen;
					getline(cin, editTen);
					temp->info.SetTen(editTen);
				}
				if (c == '3')
				{
					cout << c << endl;
					break;
				}
			}
		}
		else
		{
			cout << "Khong ton tai ma nhan vien " << editKey << endl;
		}

		cout << "Ban muon sua nua khong (Y/N): ";
		while (true)
		{
			suatiep = _getch();
			if (suatiep == 'n' || suatiep == 'N' || suatiep == 'y' || suatiep == 'Y')
			{
				cout << suatiep << endl;
				break;
			}
		}
	} while (suatiep == 'y' || suatiep == 'Y');
	
}