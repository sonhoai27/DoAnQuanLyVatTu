#include "VATTU.h"
#include "DS_HOADON.h"
using namespace std;
class NHANVIEN
{
	string Ho, Ten, Phai;
	DS_HOADON DsHDCon;
public:
	NHANVIEN();
	~NHANVIEN();
	void NhapMoi();
	//int GetMaNV();
	string GetHo();
	string GetTen();
	string GetPhai();
	void SetHo(string ho);
	void SetTen(string ten);
	void SetPhai(bool phai);
};

