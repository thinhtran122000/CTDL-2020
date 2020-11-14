#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class SanPham
{
private:
	string tenSp;
	double donGia;
public:
	SanPham() {}
	SanPham(string tenSp, double donGia)
	{
		this->tenSp = tenSp;
		this->donGia = donGia;
	}
	string getTenSp() { return this->tenSp; }
	void setTenSp(string tenSp) { this->tenSp = tenSp; }
	double getDonGia() { return this->donGia; }
	void setDonGia(double donGia) { this->donGia = donGia; }
	void Nhap()
	{
		cout << "Nhap ten san pham: ";
		cin.ignore();
		getline(cin, tenSp);
		cout << "Nhap don gia: ";
		cin >> donGia;
	}
	void Xuat()
	{
		cout << "Ten san pham: " << tenSp << "/n";
		cout << "Don gia: " << donGia << "/n";
	}
};
void menu();
vector<SanPham> nhap();
void xuat(vector<SanPham> dsSanPham);
double giaTB(vector<SanPham> dsSanPham);
void sortTang(vector<SanPham> dsSanPham);
void sortGiam(vector<SanPham> dsSanPham);
void xoa(vector<SanPham>& dsSanPham, string tenSP);
bool tang(SanPham sanpham1, SanPham sanpham2);
bool giam(SanPham sanpham1, SanPham sanpham2);

int main()
{
	int n;
	vector <SanPham> dsSanPham;
	while (true) {
		menu();
		cin >> n;
		string ten;
		switch (n) {
		case 1:
			dsSanPham = nhap();
			break;
		case 2:
			sortTang(dsSanPham);
			break;
		case 3:
			sortGiam(dsSanPham);
			break;
		case 4:
			cout << "Nhap ten ban muon xoa: ";
			cin.ignore();
			getline(cin, ten);
			xoa(dsSanPham, ten);
			break;
		case 5:
			cout << "Gia TB cua san pham la: ";
			cout << giaTB(dsSanPham);
			break;
		case 6:
			cout << "Danh sach san pham vua nhap la:" << endl;
			xuat(dsSanPham);
			break;
		}
		if (n == 7) break;
	}
	return 0;
}
void menu()
{
	cout << "\n==========MENU==========" << endl;
	cout << "1. Nhap danh sach san pham" << endl;
	cout << "2. Sap xep tang dan theo gia va xuat ra man hinh" << endl;
	cout << "3. Sap xep giam dan theo gia va xuat ra man hinh" << endl;
	cout << "4. Tim va xoa san pham theo ten nhap tu ban phim" << endl;
	cout << "5. Xuat gia trung binh cua cac san pham" << endl;
	cout << "6. Xuat danh sach" << endl;
	cout << "7. Ket thuc" << endl;
	cout << "Ban chon: ";
}
vector<SanPham> nhap()
{
	vector<SanPham> dsSanPham;
	while (true)
	{
		SanPham sp;
		sp.Nhap();
		dsSanPham.push_back(sp);
		cout << "Nhap them (Y/N)?: ";
		string s;
		cin >> s;
		if (s == "N")
		{
			break;
		}
	}
	return dsSanPham;
}
void xuat(vector<SanPham> dsSanPham)
{
	cout << "\nDanh sach san pham: ";
	for (int i = 0; i < dsSanPham.size(); i++) {
		cout << "\nTen san pham: " << dsSanPham[i].getTenSp() << endl;
		cout << "\nGia: " << dsSanPham[i].getDonGia() << endl;
	}
}
double giaTB(vector<SanPham> dsSanPham)
{
	double kq = 0.0;
	for (int i = 0; i < dsSanPham.size(); i++) {
		kq += dsSanPham[i].getDonGia();
	}
	return kq / dsSanPham.size();
	cout << endl;
}
void sortTang(vector<SanPham> dsSanPham)
{
	vector<SanPham> dsSanPham2 = dsSanPham;
	sort(dsSanPham2.rbegin(), dsSanPham2.rend(), tang);
	cout << "danh sach sau khi sap xep giam dan la: " << endl;
	for (int i = 0; i < dsSanPham2.size(); i++) {
		cout << "\nTen san pham: " << dsSanPham2[i].getTenSp() << endl;
		cout << "\Gia: " << dsSanPham2[i].getDonGia() << endl;
	}
}
void sortGiam(vector<SanPham> dsSanPham)
{
	vector<SanPham> dsSanPham2 = dsSanPham;
	sort(dsSanPham2.rbegin(), dsSanPham2.rend(), giam);
	cout << "danh sach sau khi sap xep giam dan la: " << endl;
	for (int i = 0; i < dsSanPham2.size(); i++) {
		cout << "\nTen san pham: " << dsSanPham2[i].getTenSp() << endl;
		cout << "\Gia: " << dsSanPham2[i].getDonGia() << endl;
	}
}
void xoa(vector<SanPham>& dsSanPham, string tenSP)
{
	for (int i = 0; i < dsSanPham.size(); i++)
	{
		if (dsSanPham[i].getTenSp() == tenSP) {
			dsSanPham.erase(dsSanPham.begin() + i);;
			break;
		}
	}
}
bool tang(SanPham sanpham1, SanPham sanpham2) {
	return sanpham1.getDonGia() < sanpham2.getDonGia();
}
bool giam(SanPham sanpham1, SanPham sanpham2) {
	return sanpham1.getDonGia() > sanpham2.getDonGia();
}

