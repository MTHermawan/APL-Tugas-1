#include <iostream>
using namespace std;

// Fungsi untuk mengubah nilai menggunakan pointer
void ubahNilai(int *ptr) {
    *ptr = 20; // Mengubah nilai yang ditunjuk oleh pointer
}

int main() {
    int Angka = 10;
    int *PointerAngka = &Angka;
    cout << "Sebelum perubahan: " << Angka << endl;
    ubahNilai(PointerAngka); // Memanggil fungsi dengan pointer
    cout << "Setelah perubahan: " << Angka << endl;
    return 0;
}
