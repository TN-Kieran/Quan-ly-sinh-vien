#include <iostream>
using namespace std;

struct SV {
	int id;
	char ten[20];
	float diemcc;
	float diemthigk;
	float diemthick;
	float tongdiem;
};

void menu() {
	cout << endl;
	cout << "---------------------------/./------------------------------\n";
	cout << "1. Them ban ghi sinh vien\n";
	cout << "2. Xoa ban ghi sinh vien\n";
	cout << "3. Cap nhat ban ghi sinh vien\n";
	cout << "4. Quan sat tat ca ban ghi sinh vien\n";
	cout << "5. Tinh diem trung binh cua mot sinh vien da chon\n";
	cout << "6. Hien thi sinh vien co tong diem cao nhat\n";
	cout << "7. Hien thi sinh vien co tong diem thap nhat\n";
	cout << "8. Tim sinh vien boi ID\n";
	cout << "9. Sap xep cac ban ghi boi tong diem thi cua sinh vien\n";
	cout << "---------------------------/./------------------------------\n";
}

bool checkID(SV sinhvien[], int id, int n, int index) {
	for (int i = 0; i < n; i++) {
		if (sinhvien[i].id == id && i != index) return true;
	}
	return false;
}

bool checkID(int id, int n, SV sinhvien[]) {
	for (int i = 0; i < n; i++) {
		if (sinhvien[i].id == id) return true;
	}
	return false;
}

void nhap_thong_tin(SV sinhvien[], int n) {
	for (int i = 0; i < n; i++) {
		do {
			cout << "ID: ";
			cin >> sinhvien[i].id;
			if (checkID(sinhvien, sinhvien[i].id, n, i) == true) cout << "!!! MOI BAN NHAP LAI (ID khong duoc giong nhau) !!!\n";
		} while (checkID(sinhvien, sinhvien[i].id, n, i) == true);
		cout << "Ten: ";
		cin.ignore();
		cin.getline(sinhvien[i].ten, 20);

		do {
			cout << "Diem chuyen can: ";
			cin >> sinhvien[i].diemcc;
			if (sinhvien[i].diemcc > 10 || sinhvien[i].diemcc < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
		} while (sinhvien[i].diemcc > 10 || sinhvien[i].diemcc < 0);

		do {
			cout << "Diem thi giua ky: ";
			cin >> sinhvien[i].diemthigk;
			if (sinhvien[i].diemthigk > 10 || sinhvien[i].diemthigk < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
		} while (sinhvien[i].diemthigk > 10 || sinhvien[i].diemthigk < 0);

		do {
			cout << "Diem thi cuoi ky: ";
			cin >> sinhvien[i].diemthick;
			if (sinhvien[i].diemthick > 10 || sinhvien[i].diemthick < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
		} while (sinhvien[i].diemthick > 10 || sinhvien[i].diemthick < 0);

		sinhvien[i].tongdiem = sinhvien[i].diemcc + sinhvien[i].diemthigk + sinhvien[i].diemthick;
		cout << "Tong diem: " << sinhvien[i].tongdiem;
		cout << endl << endl;
	}
}
void nhap_thong_tin_don(SV& sinhvien, int n, SV sinhvien_arr[]) {
	do {
		cout << "ID: ";
		cin >> sinhvien.id;
		if (checkID(sinhvien.id, n, sinhvien_arr) == true) cout << "!!! MOI BAN NHAP LAI (ID khong duoc giong nhau) !!!\n";
	} while (checkID(sinhvien.id, n, sinhvien_arr) == true);
	cout << "Ten: ";
	cin.ignore();
	cin.getline(sinhvien.ten, 20);

	do {
		cout << "Diem chuyen can: ";
		cin >> sinhvien.diemcc;
		if (sinhvien.diemcc > 10 || sinhvien.diemcc < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
	} while (sinhvien.diemcc > 10 || sinhvien.diemcc < 0);

	do {
		cout << "Diem thi giua ky: ";
		cin >> sinhvien.diemthigk;
		if (sinhvien.diemthigk > 10 || sinhvien.diemthigk < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
	} while (sinhvien.diemthigk > 10 || sinhvien.diemthigk < 0);

	do {
		cout << "Diem thi cuoi ky: ";
		cin >> sinhvien.diemthick;
		if (sinhvien.diemthick > 10 || sinhvien.diemthick < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
	} while (sinhvien.diemthick > 10 || sinhvien.diemthick < 0);

	sinhvien.tongdiem = sinhvien.diemcc + sinhvien.diemthigk + sinhvien.diemthick;
	cout << "Tong diem: " << sinhvien.tongdiem;
	cout << endl << endl;
}

void them_ban_ghi(SV sinhvien[], int& n) {
	nhap_thong_tin_don(sinhvien[n], n, sinhvien);
	cout << "!!! Da them ban ghi vi tri " << n << " !!!\n";
	n++;
}

void in_ban_ghi(SV sinhvien[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "----------------/-/------------------\n";
		cout << "    Thong tin sinh vien co ID: " << sinhvien[i].id;
		cout << "\n----------------/-/------------------";
		cout << "\nID: " << sinhvien[i].id;
		cout << "\nTen: " << sinhvien[i].ten;
		cout << "\nDiem chuyen can: " << sinhvien[i].diemcc;
		cout << "\nDiem thi giua ky: " << sinhvien[i].diemthigk;
		cout << "\nDIem thi cuoi ky: " << sinhvien[i].diemthick;
		cout << "\nTong diem: " << sinhvien[i].tongdiem;
		cout << endl << endl;
	}
}

void in_ban_ghi_don(SV sinhvien) {
	cout << "\n          ID: " << sinhvien.id;
	cout << "\n          Ten: " << sinhvien.ten;
	cout << "\n          Diem chuyen can: " << sinhvien.diemcc;
	cout << "\n          Diem thi giua ky: " << sinhvien.diemthigk;
	cout << "\n          DIem thi cuoi ky: " << sinhvien.diemthick;
	cout << "\n          Tong diem: " << sinhvien.tongdiem;
	cout << endl;
}

void cap_nhat_ban_ghi(SV sinhvien[], int n) {
	int index;
	cout << "Nhap vi tri sinh vien ban muon cap nhat: ";
	cin >> index;
	if (index > n - 1 || index < 0) {
		cout << "\n!!! DANH SACH CHI CO " << n << " SINH VIEN (bat dau tu '0') !!!\n";
	}
	else {
		cout << endl;
		int opt;
		char a;
		cout << "------------/*/-----------\n";
		cout << "1.ID\n";
		cout << "2.Ten\n";
		cout << "3.Diem chuyen can\n";
		cout << "4.Diem thi giua ky\n";
		cout << "5.Diem thi cuoi ky\n";
		cout << "------------/*/-----------\n";
		do {
			cout << "Nhap lua chon cap nhat: ";
			cin >> opt;
			switch (opt) {
			case 1:
				do {
					cout << "(new) ID: ";
					cin >> sinhvien[index].id;
					if (checkID(sinhvien, sinhvien[index].id, n, index) == true) cout << "!!! MOI BAN NHAP LAI (ID khong duoc giong nhau) !!!\n";
				} while (checkID(sinhvien, sinhvien[index].id, n, index) == true);
				cout << "\n*** DA CAP NHAT ***\n";
				break;
			case 2:
				cout << "(new) Ten: ";
				cin.ignore();
				cin.getline(sinhvien[index].ten, 20);
				cout << "\n*** DA CAP NHAT ***\n";
				break;
			case 3:
				do {
					cout << "(new) Diem chuyen can: ";
					cin >> sinhvien[index].diemcc;
					if (sinhvien[index].diemcc > 10 || sinhvien[index].diemcc < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
				} while (sinhvien[index].diemcc > 10 || sinhvien[index].diemcc < 0);
				cout << "\n*** DA CAP NHAT ***\n";
				break;
			case 4:
				do {
					cout << "(new) Diem thi giua ky: ";
					cin >> sinhvien[index].diemthigk;
					if (sinhvien[index].diemthigk > 10 || sinhvien[index].diemthigk < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
				} while (sinhvien[index].diemthigk > 10 || sinhvien[index].diemthigk < 0);
				cout << "\n*** DA CAP NHAT ***\n";
				break;
			case 5:
				do {
					cout << "(new) Diem thi cuoi ky: ";
					cin >> sinhvien[index].diemthick;
					if (sinhvien[index].diemthick > 10 || sinhvien[index].diemthick < 0) cout << "***Nhap Lai (0 <= Diem <= 10)***\n";
				} while (sinhvien[index].diemthick > 10 || sinhvien[index].diemthick < 0);
				cout << "\n*** DA CAP NHAT ***\n";
				break;
			default:
				cout << "\n*** LUA CHON KHONG NAM TRONG MENU ***\n";
				break;
			}
			cout << endl;
			cout << "Ban co muon tiep tuc cap nhat khong: (Y: YES || N: NO): ";
			cin >> a;
		} while (a == 'y' || a == 'Y');
		sinhvien[index].tongdiem = sinhvien[index].diemcc + sinhvien[index].diemthigk + sinhvien[index].diemthick;
		cout << endl;
	}
}
void xoa_ban_ghi(SV sinhvien[], int& n) {
	int vitri;
	cout << "Nhap vi tri xoa: ";
	cin >> vitri;
	if (vitri > n - 1 || vitri < 0) {
		cout << "\n!!! DANH SACH CHI CO " << n << " SINH VIEN (bat dau tu '0') !!!";
	}
	else {
		for (int i = vitri; i < n; i++) {
			sinhvien[i] = sinhvien[i + 1];
		}
		cout << "\n!!! Da xoa sinh vien vi tri thu " << vitri << " !!!";
		n--;
	}
}

void dtb_mot_sv(SV sinhvien[], int n) {
	int index;
	float dtb = 0;
	cout << "Nhap vi tri sinh vien de xem diem trung binh: ";
	cin >> index;
	if (index > n - 1 || index < 0) {
		cout << "\n!!! DANH SACH CHI CO " << n << " SINH VIEN (bat dau tu '0') !!!\n";
	}
	else {
		dtb = (sinhvien[index].diemcc + sinhvien[index].diemthigk + sinhvien[index].diemthick) / 3;
		cout << "\n*-* DTB sinh vien co ID " << sinhvien[index].id << ": " << dtb << " *-*\n";
	}
}

void hien_thi_tong_diem_cao_nhat(SV sinhvien[], int n) {
	float temp = sinhvien[0].tongdiem;
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (temp < sinhvien[i].tongdiem) {
			temp = sinhvien[i].tongdiem;
			index = i;
		}
	}
	cout << "******** TONG DIEM CAO NHAT **********\n";
	in_ban_ghi_don(sinhvien[index]);
	cout << "\n**************************************\n";
}

void hien_thi_tong_diem_thap_nhat(SV sinhvien[], int n) {
	float temp = sinhvien[0].tongdiem;
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (temp > sinhvien[i].tongdiem) {
			temp = sinhvien[i].tongdiem;
			index = i;
		}
	}
	cout << "******** TONG DIEM THAP NHAT **********\n";
	in_ban_ghi_don(sinhvien[index]);
	cout << "\n**************************************\n";
}

void tim_kiem_id(SV sinhvien[], int n) {
	int id;
	cout << "Nhap ID can tim: ";
	cin >> id;
	cout << endl;
	bool is = false;
	int index;
	for (int i = 0; i < n; i++) {
		if (sinhvien[i].id == id) {
			index = i;
			is = true;
		}
	}
	if (is == true) {
		cout << "************* ID: " << id << " ***************\n";
		in_ban_ghi_don(sinhvien[index]);
		cout << "\n**************************************\n";
	}
	else {
		cout << "\n!!! KHONG TIM THAY SINH VIEN CO ID: " << id << " !!!\n";
	}
}

void sap_xep_ban_ghi_tongdiem(SV sinhvien[], int n) {
	cout << "******************\n";
	cout << "1. Tang dan\n";
	cout << "2. Giam dan\n";
	cout << "******************\n";
	cout << "Nhap lua chon: ";
	int opt;
	cin >> opt;
	if (opt == 1) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (sinhvien[i].tongdiem > sinhvien[j].tongdiem) {
					SV temp = sinhvien[i];
					sinhvien[i] = sinhvien[j];
					sinhvien[j] = temp;

				}
			}
		}
		cout << "\n*** DA SAP XEP TANG DAN ***\n";
	}
	else if (opt == 2) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (sinhvien[i].tongdiem < sinhvien[j].tongdiem) {
					SV temp = sinhvien[i];
					sinhvien[i] = sinhvien[j];
					sinhvien[j] = temp;
				}
			}
		}
		cout << "\n*** DA SAP XEP GIAM DAN ***\n";
	}
	else {
		cout << "\n!!! LUA CHON KHONG CO TRONG MENU !!!\n";
	}
}

int main() {
	SV sinhvien[100];
	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	cout << endl;
	nhap_thong_tin(sinhvien, n);
	int opt;
	char back;
	do {
		menu();
		cout << "Nhap lua chon: ";
		cin >> opt;
		cout << endl;
		switch (opt) {
		case 1:
			them_ban_ghi(sinhvien, n);
			break;
		case 2:
			if (n > 0) {
				xoa_ban_ghi(sinhvien, n);
				cout << endl;
			}
			else {
				cout << "!! KHONG CO SINH VIEN DE XOA !!\n";
			}
			break;
		case 3:
			if (n > 0) {
				cap_nhat_ban_ghi(sinhvien, n);
			}
			else {
				cout << "!! KHONG CO SINH VIEN DE CAP NHAT !!\n";
			}
			break;
		case 4:
			if (n > 0) {
				in_ban_ghi(sinhvien, n);
			}
			else {
				cout << "!!! EMPTY !!!\n";
			}
			break;
		case 5:
			if (n > 0) {
				dtb_mot_sv(sinhvien, n);
			}
			else {
				cout << "!! KHONG CO SINH VIEN DE HIEN THI DTB !!\n";
			}
			break;
		case 6:
			if (n > 0) {
				hien_thi_tong_diem_cao_nhat(sinhvien, n);
			}
			else {
				cout << "!! KHONG CO SINH VIEN DE HIEN THI !!\n";
			}
			break;
		case 7:
			if (n > 0) {
				hien_thi_tong_diem_thap_nhat(sinhvien, n);
			}
			else {
				cout << "!! KHONG CO SINH VIEN DE HIEN THI !!\n";
			}
			break;
		case 8:
			if (n > 0) {
				tim_kiem_id(sinhvien, n);
			}
			else {
				cout << "!! KHONG CO SINH VIEN DE TIM !!\n";
			}
			break;
		case 9:
			if (n > 0) {
				sap_xep_ban_ghi_tongdiem(sinhvien, n);
			}
			else {
				cout << "!! KHONG CO SINH VIEN DE SAP XEP !!\n";
			}
			break;
		default:
			cout << "*** LUA CHON KHONG NAM TRONG MENU ***\n";
			break;
		}
		cout << "\nBan co muon tiep tuc khong (Y: Yes || N: NO): ";
		cin >> back;
	} while (back == 'Y' || back == 'y');
	cout << endl;
	return 0;
}

