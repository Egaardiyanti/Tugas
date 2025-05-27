#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Daftar menu
    string menu[5] = {
        "Nasi Bakar Ayam", 
        "Nasi Bakar Tongkol", 
        "Nasi Bakar MIX", 
        "Nasi Bakar Cumi", 
        "Nasi Goreng Bakar"
    };
    int harga[5] = {18000, 20000, 25000, 30000, 25000};
    int jumlah[5] = {0};

    // Input jumlah masing-masing menu
    cout << "=== DAFTAR MENU RUMAH MAKAN ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << menu[i] << " : Rp " << harga[i] << endl;
    }

    cout << "\nMasukkan jumlah pembelian tiap menu:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << menu[i] << " : ";
        cin >> jumlah[i];
    }

    // Hitung total belanja
    int totalBelanja = 0;
    for (int i = 0; i < 5; i++) {
        totalBelanja += harga[i] * jumlah[i];
    }

    // Input jarak rumah
    int jarak, ongkir;
    cout << "\nMasukkan jarak rumah Anda (KM): ";
    cin >> jarak;

    if (jarak > 4) {
        ongkir = 20000;
    } else {
        ongkir = 8000;
    }

    // Potongan ongkir dan diskon
    int potonganOngkir = 0;
    double diskon = 0.0;

    if (totalBelanja > 150000) {
        potonganOngkir = 12000;
        diskon = 0.35;
    } else if (totalBelanja > 100000) {
        potonganOngkir = 9000;
        diskon = 0.25;
    } else if (totalBelanja > 40000) {
        potonganOngkir = 4000;
    }

    // Hitung nilai akhir
    int ongkirSetelahPotongan = ongkir - potonganOngkir;
    double totalDiskon = totalBelanja * diskon;
    double totalBayar = (totalBelanja - totalDiskon) + ongkirSetelahPotongan;

    // Tampilkan slip pembayaran
    cout << fixed << setprecision(0);
    cout << "\n=== SLIP PEMBAYARAN ===" << endl;
    for (int i = 0; i < 5; i++) {
        if (jumlah[i] > 0) {
            cout << menu[i] << " x " << jumlah[i]
                 << " = Rp " << harga[i] * jumlah[i] << endl;
        }
    }

    cout << "----------------------------" << endl;
    cout << "Total Belanja         : Rp " << totalBelanja << endl;
    cout << "Diskon                : Rp " << totalDiskon << endl;
    cout << "Ongkir                : Rp " << ongkir << endl;
    cout << "Potongan Ongkir       : Rp " << potonganOngkir << endl;
    cout << "Ongkir Setelah Potongan: Rp " << ongkirSetelahPotongan << endl;
    cout << "TOTAL BAYAR           : Rp " << totalBayar << endl;

    return 0;
}

//versi class

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Class MenuItem untuk data menu
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

// Class Transaksi untuk proses pesanan dan pembayaran
class Transaksi {
private:
    MenuItem* menu[5] = {
        new MenuItem("Nasi Bakar Ayam", 18000),
        new MenuItem("Nasi Bakar Tongkol", 20000),
        new MenuItem("Nasi Bakar MIX", 25000),
        new MenuItem("Nasi Bakar Cumi", 30000),
        new MenuItem("Nasi Goreng Bakar", 25000)
    };

    int jarak, ongkir = 0;
    int potonganOngkir = 0;
    double diskon = 0.0;
    int totalBelanja = 0;

public:
    void inputPesanan() {
        cout << "=== MENU RUMAH MAKAN ===" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << menu[i]->nama << " : Rp " << menu[i]->harga << endl;
        }

        cout << "\nMasukkan jumlah pesanan untuk masing-masing menu:\n";
        for (int i = 0; i < 5; i++) {
            cout << menu[i]->nama << ": ";
            cin >> menu[i]->jumlah;
            totalBelanja += menu[i]->subtotal();
        }
    }

    void inputJarak() {
        cout << "\nMasukkan jarak rumah Anda (dalam KM): ";
        cin >> jarak;

        if (jarak > 4)
            ongkir = 20000;
        else
            ongkir = 8000;
    }

    void hitungPotonganDanDiskon() {
        if (totalBelanja > 150000) {
            potonganOngkir = 12000;
            diskon = 0.35;
        } else if (totalBelanja > 100000) {
            potonganOngkir = 9000;
            diskon = 0.25;
        } else if (totalBelanja > 40000) {
            potonganOngkir = 4000;
        }
    }

    void cetakSlip() {
        int ongkirAkhir = ongkir - potonganOngkir;
        double totalDiskon = totalBelanja * diskon;
        double totalBayar = (totalBelanja - totalDiskon) + ongkirAkhir;

        cout << fixed << setprecision(0);
        cout << "\n=== SLIP PEMBAYARAN ===" << endl;
        for (int i = 0; i < 5; i++) {
            if (menu[i]->jumlah > 0) {
                cout << menu[i]->nama << " x " << menu[i]->jumlah
                     << " = Rp " << menu[i]->subtotal() << endl;
            }
        }

        cout << "------------------------------" << endl;
        cout << "Total Belanja          : Rp " << totalBelanja << endl;
        cout << "Diskon                 : Rp " << totalDiskon << endl;
        cout << "Ongkir                 : Rp " << ongkir << endl;
        cout << "Potongan Ongkir        : Rp " << potonganOngkir << endl;
        cout << "Ongkir Setelah Potongan: Rp " << ongkirAkhir << endl;
        cout << "TOTAL BAYAR            : Rp " << totalBayar << endl;
    }

    ~Transaksi() {
        for (int i = 0; i < 5; i++) {
            delete menu[i];
        }
    }
};

// Fungsi utama
int main() {
    Transaksi trx;
    trx.inputPesanan();
    trx.inputJarak();
    trx.hitungPotonganDanDiskon();
    trx.cetakSlip();
    return 0;
}

