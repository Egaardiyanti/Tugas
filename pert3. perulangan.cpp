#include <iostream>
#include <string>
using namespace std;

const int JUMLAH_MENU = 5;

class MenuItem {
public:
    string nama;
    int harga;

    MenuItem() {}
    MenuItem(string n, int h) {
        nama = n;
        harga = h;
    }
};

class Order {
private:
    MenuItem menu[JUMLAH_MENU] = {
        MenuItem("Ayam Geprek", 21000),
        MenuItem("Ayam Goreng", 17000),
        MenuItem("Udang Goreng", 19000),
        MenuItem("Cumi Goreng", 20000),
        MenuItem("Ayam Bakar", 25000)
    };
    int jumlah[JUMLAH_MENU]{};
    double jarak;
    int ongkir;

public:
    void inputPesanan() {
        cout << "===== MENU RUMAH MAKAN =====\n";
        for (int i = 0; i < JUMLAH_MENU; i++) {
            cout << i + 1 << ". " << menu[i].nama << " : Rp " << menu[i].harga << endl;
        }

        cout << "\nMasukkan jumlah pesanan untuk setiap menu:\n";
        for (int i = 0; i < JUMLAH_MENU; i++) {
            cout << menu[i].nama << " = ";
            cin >> jumlah[i];
        }

        cout << "\nMasukkan jarak rumah Anda dari rumah makan (dalam KM): ";
        cin >> jarak;
    }

    int hitungTotalMenu() {
        int total = 0;
        for (int i = 0; i < JUMLAH_MENU; i++) {
            total += jumlah[i] * menu[i].harga;
        }
        return total;
    }

    int hitungOngkir() {
        ongkir = (jarak < 3.0) ? 15000 : 25000;
        return ongkir;
    }

    void cetakSlip() {
        cout << "\n\n===== SLIP PEMBAYARAN =====\n";
        cout << "Menu\t\tJumlah\tHarga Total\n";
        cout << "-----------------------------------------\n";

        for (int i = 0; i < JUMLAH_MENU; i++) {
            if (jumlah[i] > 0) {
                cout << menu[i].nama;
                if (menu[i].nama.length() < 8) cout << "\t\t";
                else if (menu[i].nama.length() < 16) cout << "\t";
                else cout << " ";
                cout << jumlah[i] << "\tRp " << jumlah[i] * menu[i].harga << endl;
            }
        }

        int totalMenu = hitungTotalMenu();
        int totalOngkir = hitungOngkir();
        int totalBayar = totalMenu + totalOngkir;

        cout << "-----------------------------------------\n";
        cout << "Total Harga Makanan\t: Rp " << totalMenu << endl;
        cout << "Biaya Ongkir\t\t: Rp " << totalOngkir << endl;
        cout << "TOTAL BAYAR\t\t: Rp " << totalBayar << endl;
        cout << "=========================================\n";
    }
};

int main() {
    Order pesanan;
    pesanan.inputPesanan();
    pesanan.cetakSlip();
    return 0;
}

