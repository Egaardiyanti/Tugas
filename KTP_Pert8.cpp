// 2400018222 - Ega Ardiyanti

#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;   // Maksimum jumlah penduduk
const int KOLOM = 15;  // Jumlah atribut per penduduk

string kolom[KOLOM] = {
    "NIK", "Nama", "Tempat Lahir", "Tanggal Lahir", "Jenis Kelamin",
    "Golongan Darah", "Alamat", "RT/RW", "Kelurahan/Desa", "Kecamatan",
    "Agama", "Status Perkawinan", "Pekerjaan", "Kewarganegaraan", "Berlaku Hingga"
};

string data[MAX][KOLOM];  // Array 2 dimensi untuk menyimpan data KTP
int jumlahPenduduk;

// Fungsi memilih jenis kelamin
void pilihKelamin(int i) {
    int pilihJK;
    do {
        cout << "Pilih Jenis Kelamin:\n";
        cout << "1. Laki-laki\n";
        cout << "2. Perempuan\n";
        cout << "Pilihan Anda: ";
        cin >> pilihJK;
        cin.ignore();

        if (pilihJK == 1)
            data[i][4] = "Laki-laki";
        else if (pilihJK == 2)
            data[i][4] = "Perempuan";
        else
            cout << "Pilihan tidak valid!\n";

    } while (data[i][4] != "Laki-laki" && data[i][4] != "Perempuan");
}

// Fungsi memilih agama
void pilihAgama(int i) {
    int pilih;
    do {
        cout << "Pilih Agama:\n";
        cout << "1. Islam\n2. Kristen\n3. Katolik\n4. Hindu\n5. Buddha\n6. Konghucu\n";
        cout << "Pilihan Anda: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1: data[i][10] = "Islam"; break;
            case 2: data[i][10] = "Kristen"; break;
            case 3: data[i][10] = "Katolik"; break;
            case 4: data[i][10] = "Hindu"; break;
            case 5: data[i][10] = "Buddha"; break;
            case 6: data[i][10] = "Konghucu"; break;
            default:
                cout << "Pilihan tidak valid!\n";
                data[i][10] = "";
        }
    } while (data[i][10] == "");
}

void inputData() {
    for (int i = 0; i < jumlahPenduduk; i++) {
        cout << "\n=== Input Data KTP ke-" << i + 1 << " ===\n";

        cout << "Masukkan " << kolom[0] << ": ";
        getline(cin, data[i][0]);
        cout << "Masukkan " << kolom[1] << ": ";
        getline(cin, data[i][1]);
        cout << "Masukkan " << kolom[2] << ": ";
        getline(cin, data[i][2]);
        cout << "Masukkan " << kolom[3] << " (DD-MM-YYYY): ";
        getline(cin, data[i][3]);

        pilihKelamin(i);

        cout << "Masukkan " << kolom[5] << " (A/B/AB/O): ";
        getline(cin, data[i][5]);
        cout << "Masukkan " << kolom[6] << ": ";
        getline(cin, data[i][6]);
        cout << "Masukkan " << kolom[7] << ": ";
        getline(cin, data[i][7]);
        cout << "Masukkan " << kolom[8] << ": ";
        getline(cin, data[i][8]);
        cout << "Masukkan " << kolom[9] << ": ";
        getline(cin, data[i][9]);

        pilihAgama(i);

        cout << "Masukkan " << kolom[11] << ": ";
        getline(cin, data[i][11]);
        cout << "Masukkan " << kolom[12] << ": ";
        getline(cin, data[i][12]);
        cout << "Masukkan " << kolom[13] << ": ";
        getline(cin, data[i][13]);
        cout << "Masukkan " << kolom[14] << ": ";
        getline(cin, data[i][14]);
    }
}

void tampilkanData() {
    for (int i = 0; i < jumlahPenduduk; i++) {
        cout << "\n=========== KARTU TANDA PENDUDUK ===========\n";
        cout << "NIK                : " << data[i][0] << endl;
        cout << "Nama               : " << data[i][1] << endl;
        cout << "Tempat Lahir       : " << data[i][2] << endl;
        cout << "Tanggal Lahir      : " << data[i][3] << endl;
        cout << "Jenis Kelamin      : " << data[i][4] << "       Gol. Darah : " << data[i][5] << endl;
        cout << "Alamat             : " << data[i][6] << endl;
        cout << "  RT/RW            : " << data[i][7] << endl;
        cout << "  Kel/Desa         : " << data[i][8] << endl;
        cout << "  Kecamatan        : " << data[i][9] << endl;
        cout << "Agama              : " << data[i][10] << endl;
        cout << "Status Perkawinan  : " << data[i][11] << endl;
        cout << "Pekerjaan          : " << data[i][12] << endl;
        cout << "Kewarganegaraan    : " << data[i][13] << endl;
        cout << "Berlaku Hingga     : " << data[i][14] << endl;
        cout << "=============================================\n";
    }
}

void editKTP(int i) {
    int edit;
    do {
        cout << "\n=== MENU EDIT DATA KTP ===\n";
        for (int j = 1; j < KOLOM; j++) {
            cout << j << ". " << kolom[j] << endl;
        }
        cout << "15. Selesai Edit\n";
        cout << "Pilih data yang ingin diedit: ";
        cin >> edit;
        cin.ignore();

        if (edit >= 1 && edit <= 14) {
            if (edit == 4) { // Jenis Kelamin
                pilihKelamin(i);
            } else if (edit == 10) { // Agama
                pilihAgama(i);
            } else {
                cout << "Masukkan " << kolom[edit] << " baru: ";
                getline(cin, data[i][edit]);
            }
        }
    } while (edit != 15);
}

int main() {
    cout << "Masukkan jumlah penduduk : ";
    cin >> jumlahPenduduk;
    cin.ignore();

    inputData();
    tampilkanData();
    
    char editData;
    for (int i = 0; i < jumlahPenduduk; i++) {
        cout << "\nIngin mengedit data penduduk ke-" << i + 1 << "? (y/n): ";
        cin >> editData;
        cin.ignore();
        
        if (editData == 'y' || editData == 'Y') {
            editKTP(i);
        }
    }

    cout << "\n=== Data Setelah Diedit ===";
    tampilkanData();

    return 0;
}

