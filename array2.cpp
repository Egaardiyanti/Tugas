#include <iostream>
#include <vector>
#include <algorithm>

struct ArrayData {
    std::vector<int> values;
};

// Fungsi untuk mencari nilai yang habis dibagi 2 dan 3
std::vector<int> searchDivisibleBy2And3(const ArrayData& data) {
    std::vector<int> result;
    for (int value : data.values) {
        if (value % 2 == 0 && value % 3 == 0) {
            result.push_back(value);
        }
    }
    return result;
}

// Fungsi untuk memisahkan array menjadi array positif dan negatif
void separateArray(const ArrayData& data, std::vector<int>& positive, std::vector<int>& negative) {
    for (int value : data.values) {
        if (value >= 0) {
            positive.push_back(value);
        } else {
            negative.push_back(value);
        }
    }
}

// Fungsi untuk mencetak isi vector
void printArray(const std::vector<int>& arr, const std::string& name) {
    std::cout << name << ": ";
    if (arr.empty()) {
        std::cout << "Tidak ada data.";
    } else {
        for (int value : arr) {
            std::cout << value << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    ArrayData data;
    int n;

    std::cout << "Masukkan jumlah elemen (minimal 15): ";
    std::cin >> n;
    
    if (std::cin.fail() || n < 15) {
        std::cerr << "Input tidak valid atau jumlah elemen kurang dari 15." << std::endl;
        return 1;
    }

    std::cout << "Masukkan " << n << " elemen array (boleh positif dan negatif):" << std::endl;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;

        // Validasi input
        if (std::cin.fail()) {
            std::cerr << "Input tidak valid. Harus berupa angka." << std::endl;
            return 1;
        }

        data.values.push_back(value);
    }

    // Mencari nilai yang habis dibagi 2 dan 3
    std::vector<int> divisibleBy2And3 = searchDivisibleBy2And3(data);

    // Memisahkan array menjadi positif dan negatif
    std::vector<int> positive, negative;
    separateArray(data, positive, negative);

    // Mengurutkan array positif secara ascending
    std::sort(positive.begin(), positive.end());

    // Mengurutkan array negatif secara descending
    std::sort(negative.begin(), negative.end(), std::greater<int>());

    // Output poin a sampai c
    std::cout << std::endl;
    printArray(data.values, "Array asli");
    printArray(divisibleBy2And3, "Nilai yang habis dibagi 2 dan 3");
    printArray(positive, "Array positif (ascending)");
    printArray(negative, "Array negatif (descending)");

    return 0;
}
