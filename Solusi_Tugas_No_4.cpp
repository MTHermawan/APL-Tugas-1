#include <iostream>
using namespace std;
int main() {
    int angka = 10; 
    int *PointerAngka = &angka; 

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;
    cout << "Nilai yang ditunjuk oleh pointer: " << *PointerAngka << endl;
    return 0;
}
