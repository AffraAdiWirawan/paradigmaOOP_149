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

void pasien::tambahDokter(dokter* pDokter) {
	daftar_dokter.push_back(pDokter);
}

void pasien::cetakdokter() {
	cout << "Daftar Dokter yang menangani pasien \"" << this->nama << "\":\n";
	for (auto& a : daftar_dokter) {
		cout << a->nama << "\n";
	}
}

void dokter::tambahPasien(pasien* pPasien) {
	daftar_pasien.push_back(pPasien);
	pPasien->tambahDokter(this);
}

void dokter::cetakPasien() {
	cout << " Daftar Pasien dari dokter\"" << this->nama << "\":\n";
	for (auto& a : daftar_pasien) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	dokter* varDokter1 = new dokter("Dr.Budi");
	dokter* varDokter2 = new dokter("Dr.Tono");
	pasien* varPasien1 = new pasien("Andi");
	pasien* varPasien2 = new pasien("Lia");

	varDokter1->tambahPasien(varPasien1);
	varDokter1->tambahPasien(varPasien2);
	varDokter2->tambahPasien(varPasien2);

	varDokter1->cetakPasien();
	varDokter2->cetakPasien();
	varPasien1->cetakdokter();
	varPasien2->cetakdokter();

	return 0;

}