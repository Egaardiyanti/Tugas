#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // untuk std::numeric_limits

using namespace std; // Menghindari penulisan std::

struct ArrayData {
    vector<int> values;
};

// Fungsi untuk mencari nilai yang habis dibagi 2 dan 3
vector<int> searchDivisibleBy2And3(const ArrayData& data) {
    vector<int> result;
    for (size_t i = 0; i < data.values.size(); ++i) {
        int value = data.values[i];
        if (value % 2 == 0 && value % 3 == 0) {
            result.push_back(value);
        }
    }
    return result;
}

// Fungsi untuk memisahkan array menjadi array positif dan negatif
void separateArray(const ArrayData& data, vector<int>& positive, vector<int>& negative) {
    for (size_t i = 0; i < data.values.size(); ++i) {
        int value = data.values[i];
        if (value >= 0) {
            positive.push_back(value);
        } else {
            negative.push_back(value);
        }
    }
}

// Fungsi untuk mencetak isi vector
void printArray(const vector<int>& arr, const string& name) {
    cout << name << ": ";
    if (arr.empty()) {
        cout << "Tidak ada data.";
    } else {
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    ArrayData data;
    int n;

    cout << "Masukkan jumlah elemen (minimal 15): ";
    cin >> n;

    // Validasi input jumlah elemen
    if (cin.fail() || n < 15) {
        cerr << "Input tidak valid atau jumlah elemen kurang dari 15." << endl;
        return 1;
    }

    cout << "Masukkan " << n << " elemen array (boleh positif dan negatif):" << endl;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;

        // Validasi input elemen
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Input tidak valid. Harus berupa angka." << endl;
            return 1;
        }

        data.values.push_back(value);
    }

    // Mencari nilai yang habis dibagi 2 dan 3
    vector<int> divisibleBy2And3 = searchDivisibleBy2And3(data);
    
    // Memisahkan array menjadi positif dan negatif
    vector<int> positive, negative;
    separateArray(data, positive, negative);

    // Mengurutkan array positif dan negatif
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end(), greater<int>());

    cout << endl;
    printArray(data.values, "Array asli");
    printArray(divisibleBy2And3, "Nilai yang habis dibagi 2 dan 3");
    printArray(positive, "Array positif (ascending)");
    printArray(negative, "Array negatif (descending)");

    return 0;
}


