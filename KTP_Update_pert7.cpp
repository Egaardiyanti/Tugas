//2400018222-Ega Ardiyanti

#include <iostream>
#include <string>
using namespace std;

class KTP {
private:
    char nik[20];
    string nama;
    string tempat_lahir;
    string tgl_lahir;
    string jenis_kelamin;
    string gol_darah;
    string alamat;
    string rt_rw;
    string kel_desa;
    string kecamatan;
    string agama;
    string status_perkawinan;
    string pekerjaan;
    string kewarganegaraan;
    string berlaku_hingga;
    
public:
	void pilihKelamin();
	void pilihAgama();
	void inputKTP();
	void tampil();
	void editKTP();
	
	string getNama(){ 
	return nama; 
	}
    string getNIK(){ 
	return nik; 
	}
    string getTglLahir(){
	return tgl_lahir; 
	}
	
};

void KTP::pilihKelamin(){
	int pilihan;
        do {
            cout << "Pilih Kelamin :\n";
            cout << "1. Laki Laki\n";
            cout << "2. Perempuan\n";
            cout << "Pilihan Anda: ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan) {
                case 1: 
					jenis_kelamin = "Laki laki"; 
					break;
                case 2: 
					jenis_kelamin = "Perempuan"; 
					break;
                default:
                    cout << "Pilihan jenis kelamin tidak valid. Ulangi\n";
                    jenis_kelamin = "Tidak Valid";
                    break;
            }
        } while (jenis_kelamin == "Tidak Valid");
    }
    
void KTP::pilihAgama(){
	int pilihan;
        do {
            cout << "Pilih Agama :\n";
            cout << "1. Islam\n2. Kristen\n3. Katolik\n4. Hindu\n5. Buddha\n6. Konghucu\n";
            cout << "Pilihan Anda: ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan) {
                case 1: 
					agama = "Islam"; 
					break;
                case 2: 
					agama = "Kristen"; 
					break;
                case 3: 
					agama = "Katolik"; 
					break;
                case 4: 
					agama = "Hindu"; 
					break;
                case 5: 
					agama = "Buddha"; 
					break;
                case 6: 
					agama = "Konghucu"; 
					break;
                default:
                    cout << "Pilihan agama tidak valid. Ulangi\n";
                    agama = "Tidak Valid";
                    break;
            }
        } while (agama == "Tidak Valid");
    }

void KTP::inputKTP(){
        cout << "Masukkan NIK: ";
        cin >> nik; cin.ignore();
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan Tempat Lahir: ";
        getline(cin, tempat_lahir);
        cout << "Masukkan Tanggal Lahir (DD-MM-YYYY): ";
        getline(cin, tgl_lahir);
        pilihKelamin();
        cout << "Masukkan Golongan Darah (A/B/AB/O): ";
        cin >> gol_darah; cin.ignore();
        cout << "Masukkan Alamat: ";
        getline(cin, alamat);
        cout << "Masukkan RT/RW: ";
        getline(cin, rt_rw);
        cout << "Masukkan Kelurahan/Desa: ";
        getline(cin, kel_desa);
        cout << "Masukkan Kecamatan: ";
        getline(cin, kecamatan);
        pilihAgama();
        cout << "Masukkan Status Perkawinan: ";
        getline(cin, status_perkawinan);
        cout << "Masukkan Pekerjaan: ";
        getline(cin, pekerjaan);
        cout << "Masukkan Kewarganegaraan: ";
        getline(cin, kewarganegaraan);
        cout << "Masukkan Berlaku Hingga: ";
        getline(cin, berlaku_hingga);
}

void KTP::tampil(){
	cout << "\n================= KARTU TANDA PENDUDUK =================" << endl;
    cout << "NIK                : " << nik << endl;
    cout << "Nama               : " << nama << endl;
    cout << "Tempat Lahir       : " << tempat_lahir << endl;
    cout << "Tanggal Lahir      : " << tgl_lahir << endl;
    cout << "Jenis Kelamin      : " << jenis_kelamin << "        Gol. Darah : " << gol_darah << endl;
    cout << "Alamat             : " << alamat << endl;
    cout << "   RT/RW           : " << rt_rw << endl;
    cout << "   Kel/Desa        : " << kel_desa << endl;
    cout << "   Kecamatan       : " << kecamatan << endl;
    cout << "Agama              : " << agama << endl;
    cout << "Status Perkawinan  : " << status_perkawinan << endl;
    cout << "Pekerjaan          : " << pekerjaan << endl;
    cout << "Kewarganegaraan    : " << kewarganegaraan << endl;
    cout << "Berlaku Hingga     : " << berlaku_hingga << endl;
    cout << "=========================================================" << endl;
}

void KTP::editKTP(){
	int pilihan;
    do {
        cout << "\n=== MENU EDIT DATA KTP ===\n";
        cout << "1. Nama" << endl;
        cout << "2. Tempat Lahir" << endl;
        cout << "3. Tanggal Lahir" << endl;
        cout << "4. Jenis Kelamin" << endl;
        cout << "5. Golongan Darah" << endl;
        cout << "6. Alamat" << endl;
        cout << "7. RT/RW" << endl;
        cout << "8. Kelurahan/Desa" << endl;
        cout << "9. Kecamatan" << endl;
        cout << "10. Agama" << endl;
        cout << "11. Status Perkawinan" << endl;
        cout << "12. Pekerjaan" << endl;
        cout << "13. Kewarganegaraan" << endl;
        cout << "14. Berlaku Hingga" << endl;
        cout << "15. Selesai Edit" << endl;
        cout << "Masukkan Pilihan Anda : " << endl;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: 
				cout << "Nama baru : "; 
				getline(cin, nama); 
				break;
            case 2: 
				cout << "Tempat Lahir: "; 
				getline(cin, tempat_lahir); 
				break;
            case 3: 
				cout << "Tanggal Lahir baru: "; 
				cin >> tgl_lahir; 
				break;
            case 4: 
				pilihKelamin(); 
				break;
            case 5: 
				cout << "Golongan Darah baru (A/B/AB/O): "; 
				getline(cin, gol_darah); 
				break;
            case 6: 
				cout << "Alamat baru: "; 
				getline(cin, alamat); 
				break;
            case 7: 
				cout << "RT/RW baru: "; 
				getline(cin, rt_rw); 
				break;
            case 8: 
				cout << "Kelurahan/Desa baru: "; 
				getline(cin, kel_desa); 
				break;
            case 9: 
				cout << "Kecamatan baru: "; 
				getline(cin, kecamatan); 
				break;
            case 10: 
				pilihAgama(); 
				break;
            case 11: 
				cout << "Status Perkawinan baru: "; 
				getline(cin, status_perkawinan); 
				break;
            case 12: 
				cout << "Pekerjaan baru: "; 
				getline(cin, pekerjaan); 
				break;
            case 13: 
				cout << "Kewarganegaraan baru: "; 
				getline(cin, kewarganegaraan); 
				break;
            case 14: 
				cout << "Berlaku Hingga baru: "; 
				getline(cin, berlaku_hingga); 
				break;
			case 15:
				cout << "Terimakasih!!\n";
				break;
            default: 
				cout << "Pilihan data tidak valid.\n"; 
				break;
        }
    } while (pilihan != 15);
}

bool mintaEdit() {
    char edit;
    cout << "\nApakah Anda ingin mengedit data? (y/n) : ";
    cin >> edit;
    cin.ignore();
    return (edit == 'y' || edit == 'Y');
}

class KTPManager{
private:
	KTP* data;
	int jumlah;
public:
	KTPManager(int n){
		jumlah = n;
		data = new KTP[jumlah];
	}
	
	void inputSemua();
    void tampilkanSemua();
   	void urutkanNama(bool ascending);
   	void urutkanNIK(bool ascending);
	void urutkanTglLahir(bool ascending);
    void cariNIK();
    void cariNama();
    void menuTambahan();
};

void KTPManager::inputSemua(){
 for (int i = 0; i < jumlah; i++) {
        cout << "\n=== Input Data KTP ke-" << i + 1 << " ===\n";
        data[i].inputKTP();
        data[i].tampil();
        if (mintaEdit()) {
            data[i].editKTP();
        }
	}
}

void KTPManager::tampilkanSemua(){
	for (int i = 0; i < jumlah; i++) {
        cout << "\n-----Data ke- " << i + 1 << " -----" << endl;
        data[i].tampil();
    }
}

void KTPManager::urutkanNama(bool ascending) {
    for (int i = 0; i < jumlah - 1; ++i) {
        for (int j = 0; j < jumlah - 1 - i; ++j) {
            if ((ascending && data[j].getNama() > data[j + 1].getNama()) ||
                (!ascending && data[j].getNama() < data[j + 1].getNama())) {
                KTP temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void KTPManager::urutkanNIK(bool ascending) {
    for (int i = 0; i < jumlah - 1; ++i) {
        for (int j = 0; j < jumlah - 1 - i; ++j) {
            string nik1 = data[j].getNIK();
            string nik2 = data[j + 1].getNIK();
            if ((ascending && nik1 > nik2) ||
                (!ascending && nik1 < nik2)) {
                KTP temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void KTPManager::urutkanTglLahir(bool ascending) {
    for (int i = 0; i < jumlah - 1; ++i) {
        for (int j = 0; j < jumlah - 1 - i; ++j) {
            string tgl1 = data[j].getTglLahir();
            string tgl2 = data[j + 1].getTglLahir();

            // Bagian tahun, bulan, tanggal
            string tahun1 = tgl1.substr(6, 4);
            string bulan1 = tgl1.substr(3, 2);
            string hari1 = tgl1.substr(0, 2);
            string total1 = tahun1 + bulan1 + hari1;

            string tahun2 = tgl2.substr(6, 4);
            string bulan2 = tgl2.substr(3, 2);
            string hari2 = tgl2.substr(0, 2);
            string total2 = tahun2 + bulan2 + hari2;

            // Urutkan berdasarkan hasil gabungan tahun+bulan+tanggal
            if ((ascending && total1 > total2) || (!ascending && total1 < total2)) {
                KTP temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void KTPManager::cariNIK() {
    string nik;
    cout << "Masukkan NIK yang dicari: ";
    getline(cin, nik);
    bool ketemu = false;
    for (int i = 0; i < jumlah; ++i) {
        if (data[i].getNIK() == nik) {
            data[i].tampil();
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Data tidak ditemukan.\n";
}

void KTPManager::cariNama() {
    string nama;
    cout << "Masukkan Nama yang dicari: ";
    getline(cin, nama);
    bool ketemu = false;
    for (int i = 0; i < jumlah; ++i) {
        if (data[i].getNama() == nama) {
            data[i].tampil();
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Data tidak ditemukan.\n";
}

void KTPManager::menuTambahan() {
    int menu;
    
    do {
        cout << "\n=========== MENU SORTING & SEARCHING =============\n";
        cout << "1. Tampilkan Semua Data\n";
        cout << "2. Urutkan Data Berdasarkan Nama\n";
        cout << "3. Urutkan Data Berdasarkan NIK\n";
        cout << "4. Urutkan Data Berdasarkan Tanggal, Bulan & Tahun Lahir\n";
        cout << "5. Cari Data Berdasarkan Nama\n";
        cout << "6. Cari Data Berdasarkan NIK\n";
        cout << "7. Keluar\n";
        cout << "====================================================\n";
        cout << "Masukkan Pilihan: ";
        cin >> menu;
        cin.ignore();

        switch (menu) {
        case 1:
            tampilkanSemua();
            break;
        case 2:
            int urutan;
   			cout << "Urutkan Nama secara :" << endl;
			cout << "1. Ascending (A-Z)" << endl;
			cout << "2. Descending (Z-A)" << endl;
			cout << "Masukkan Pilihan: ";
    		cin >> urutan;
    		cin.ignore();
    		
			urutkanNama(urutan == 1);
    		cout << "\nData berhasil diurutkan berdasarkan Nama.\n";
    		tampilkanSemua();
    		break;
        case 3:
            int urutNIK;
            cout << "Urutkan NIK secara :" << endl;
			cout << "1. Ascending (terkecil ke terbesar)" << endl;
			cout << "2. Descending (terbesar ke terkecil)" <<endl;
			cout << "Masukkan Pilihan : ";
            cin >> urutNIK;
            cin.ignore();

            urutkanNIK(urutNIK == 1);
            cout << "\nData berhasil diurutkan berdasarkan NIK.\n";
            tampilkanSemua();
            break;
        case 4:
            int uruttgl;
    		cout << "Urutkan Tanggal Lahir secara :" << endl; 
			cout << "1. Ascending (tua ke muda)" << endl;
			cout << "2. Descending (muda ke tua)" << endl;
			cout << "Masukkan Pilihan: ";
    		cin >> uruttgl;
    		cin.ignore();
    
			urutkanTglLahir(uruttgl == 1);
    		cout << "\nData berhasil diurutkan berdasarkan tanggal dan bulan lahir.\n";
    		tampilkanSemua();
    		break;
        case 5:
            cariNama();
            break;
        case 6:
            cariNIK();
            break;
        case 7:
            cout << "Terima kasih Telah menggunkan Program ini!\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (menu != 7);
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah penduduk : ";
    cin >> jumlah;
    cin.ignore();

	KTPManager manager(jumlah);
    manager.inputSemua();
    manager.menuTambahan();
    
    return 0;
}
