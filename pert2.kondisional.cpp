#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string menu[] = {"Ayam Geprek", "Ayam Goreng", "Udang Goreng", "Cumi Goreng", "Ayam Bakar"};
    int harga[] = {21000, 17000, 19000, 20000, 25000};
    int jumlah[5] = {0}; // untuk menyimpan jumlah tiap menu yang dibeli
    int totalBelanja = 0;
    int jarak;

    cout << "=== DAFTAR MENU ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << menu[i] << " : Rp " << harga[i] << endl;
    }

    // Input jumlah pesanan
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan jumlah " << menu[i] << " yang dibeli: ";
        cin >> jumlah[i];
        totalBelanja += harga[i] * jumlah[i];
    }

    // Input jarak untuk menghitung ongkir
    cout << "Masukkan jarak rumah Anda (dalam KM): ";
    cin >> jarak;

    int ongkir = (jarak < 3) ? 15000 : 25000;
    int potonganOngkir = 0;
    double diskon = 0.0;

    if (totalBelanja > 150000) {
        potonganOngkir = 8000;
        diskon = 0.35;
    } else if (totalBelanja > 50000) {
        potonganOngkir = 5000;
        diskon = 0.15;
    } else if (totalBelanja > 25000) {
        potonganOngkir = 3000;
    }

    int ongkirSetelahPotongan = ongkir - potonganOngkir;
    double totalDiskon = totalBelanja * diskon;
    double totalAkhir = (totalBelanja - totalDiskon) + ongkirSetelahPotongan;

    // Output Slip Pembayaran
    cout << fixed << setprecision(0);
    cout << "\n=== SLIP PEMBAYARAN ===" << endl;
    for (int i = 0; i < 5; i++) {
        if (jumlah[i] > 0) {
            cout << menu[i] << " x " << jumlah[i] << " = Rp " << harga[i] * jumlah[i] << endl;
        }
    }
    cout << "Total Belanja         : Rp " << totalBelanja << endl;
    cout << "Diskon                : Rp " << totalDiskon << endl;
    cout << "Ongkir                : Rp " << ongkir << endl;
    cout << "Potongan Ongkir       : Rp " << potonganOngkir << endl;
    cout << "Ongkir Setelah Potongan: Rp " << ongkirSetelahPotongan << endl;
    cout << "Total Pembayaran      : Rp " << totalAkhir << endl;

    return 0;
}

// versi class

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class MenuItem {
public:
    string nama;
    int harga;
    int jumlah;

    MenuItem(string n, int h) {
        nama = n;
        harga = h;
        jumlah = 0;
    }

    int subtotal() {
        return harga * jumlah;
    }
};

class Pembayaran {
private:
    MenuItem* menu[5];
    int jarak;
    int totalBelanja;
    int ongkir;
    int potonganOngkir;
    double diskon;

public:
    Pembayaran() {
        menu[0] = new MenuItem("Ayam Geprek", 21000);
        menu[1] = new MenuItem("Ayam Goreng", 17000);
        menu[2] = new MenuItem("Udang Goreng", 19000);
        menu[3] = new MenuItem("Cumi Goreng", 20000);
        menu[4] = new MenuItem("Ayam Bakar", 25000);
        totalBelanja = 0;
        ongkir = 0;
        potonganOngkir = 0;
        diskon = 0.0;
    }

    ~Pembayaran() {
        for (int i = 0; i < 5; i++) {
            delete menu[i];
        }
    }

    void inputPesanan() {
        cout << "=== DAFTAR MENU ===" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << menu[i]->nama << " : Rp " << menu[i]->harga << endl;
        }

        for (int i = 0; i < 5; i++) {
            cout << "Masukkan jumlah " << menu[i]->nama << ": ";
            cin >> menu[i]->jumlah;
            totalBelanja += menu[i]->subtotal();
        }
    }

    void inputJarak() {
        cout << "Masukkan jarak rumah Anda (dalam KM): ";
        cin >> jarak;
        ongkir = (jarak < 3) ? 15000 : 25000;
    }

    void hitungDiskonDanOngkir() {
        if (totalBelanja > 150000) {
            potonganOngkir = 8000;
            diskon = 0.35;
        } else if (totalBelanja > 50000) {
            potonganOngkir = 5000;
            diskon = 0.15;
        } else if (totalBelanja > 25000) {
            potonganOngkir = 3000;
        }
    }

    void cetakSlip() {
        cout << fixed << setprecision(0);
        cout << "\n=== SLIP PEMBAYARAN ===" << endl;
        for (int i = 0; i < 5; i++) {
            if (menu[i]->jumlah > 0) {
                cout << menu[i]->nama << " x " << menu[i]->jumlah 
                     << " = Rp " << menu[i]->subtotal() << endl;
            }
        }

        int ongkirSetelahPotongan = ongkir - potonganOngkir;
        double totalDiskon = totalBelanja * diskon;
        double totalAkhir = (totalBelanja - totalDiskon) + ongkirSetelahPotongan;

        cout << "----------------------------" << endl;
        cout << "Total Belanja         : Rp " << totalBelanja << endl;
        cout << "Diskon                : Rp " << totalDiskon << endl;
        cout << "Ongkir                : Rp " << ongkir << endl;
        cout << "Potongan Ongkir       : Rp " << potonganOngkir << endl;
        cout << "Ongkir Setelah Potongan: Rp " << ongkirSetelahPotongan << endl;
        cout << "TOTAL BAYAR           : Rp " << totalAkhir << endl;
    }
};

int main() {
    Pembayaran transaksi;
    transaksi.inputPesanan();
    transaksi.inputJarak();
    transaksi.hitungDiskonDanOngkir();
    transaksi.cetakSlip();
    return 0;
}



