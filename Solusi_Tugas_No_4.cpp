#include <iostream>
using namespace std;


int main(){
    int angka = 20;
    int *PointerAngka;

    PointerAngka = &angka;

    cout << "Nilai dari variabel angka : " << angka << endl;
    cout << "Alamat dari variabel angka : " << &angka << endl;
    cout << "Nilai yang ditunjuk oleh pointer : " << *PointerAngka << endl;
    cout << "Alamat yang disimpan oleh pointer :  " << PointerAngka << endl;
    
    return 0;
}
