#include <iostream>
#include <cmath> // pow buat pangkat

using namespace std;

void jenisSegitiga(int sisi1, int sisi2, int sisi3) {
    //cek apakah segitiga
    if ((sisi1 + sisi2 > sisi3) && (sisi1 + sisi3 > sisi2) && (sisi2 + sisi3 > sisi1)) {
        //segitiga sama kaki
        if ((sisi1 == sisi2) || (sisi1 == sisi3) || (sisi2 == sisi3)) {
            cout << "Segitiga Sama Kaki" << endl;
        }
        //segitiga siku siku
        else if ((pow(sisi1, 2) + pow(sisi2, 2) == pow(sisi3, 2)) ||
                (pow(sisi1, 2) + pow(sisi3, 2) == pow(sisi2, 2)) ||
                (pow(sisi2, 2) + pow(sisi3, 2) == pow(sisi1, 2))) {
            cout << "Segitiga Siku-Siku" << endl;
        }
        //jika bukan sama kaki atau siku siku
        else {
            cout << "Segitiga Sembarang" << endl;
        }
    } else {
        cout << "Tidak dapat membentuk segitiga" << endl;
    }
}

int main() {
    int sisi1, sisi2, sisi3;
    
    //input dari user
    cout << "Masukkan sisi 1: ";
    cin >> sisi1;
    cout << "Masukkan sisi 2: ";
    cin >> sisi2;
    cout << "Masukkan sisi 3: ";
    cin >> sisi3;

    jenisSegitiga(sisi1, sisi2, sisi3);

    return 0;
}
