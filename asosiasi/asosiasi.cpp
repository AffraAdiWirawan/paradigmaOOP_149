#include <iostream>
#include <vector>

using namespace std;

class dokter;

class pasien {
public:
	string nama;
	vector<dokter*> daftar_dokter;
	pasien(string pNama) : nama(pNama) {
		cout << " Pasien \"" << nama << "\" ada\n";
	}
	~pasien() {
		cout << "pasien \"" << nama << "\" tidak \n";
	}
	void tambahDokter(dokter*);
	void cetakdokter();
};

class dokter {
public:
	string nama;
	vector<pasien*> daftar_pasien;

	dokter(string pNama) : nama(pNama) {
		cout << "Dokter \"" << nama << "\" ada \n";
	}
	~dokter() {
		cout << "dokter \"" << nama << "\" tidak ada \n";
	}
	void tambahPasien(pasien*);
	void cetakPasien();
};