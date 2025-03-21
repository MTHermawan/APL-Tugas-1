#include <iostream>
#include <cmath> 

using namespace std;

void jenisSegitiga(float sisi1, float sisi2, float sisi3) {
    if ((sisi1 + sisi2 > sisi3) && (sisi1 + sisi3 > sisi2) && (sisi2 + sisi3 > sisi1)) {
        //cek segitiga sama kaki
        if ((sisi1 == sisi2) || (sisi1 == sisi3) || (sisi2 == sisi3)) {
            cout << "Segitiga Sama Kaki" << endl;
        }
        //cek segitiga siku-siku 
        else if (fabs(pow(sisi1, 2) + pow(sisi2, 2) - pow(sisi3, 2)) < 0.0001 ||
                 fabs(pow(sisi1, 2) + pow(sisi3, 2) - pow(sisi2, 2)) < 0.0001 ||
                 fabs(pow(sisi2, 2) + pow(sisi3, 2) - pow(sisi1, 2)) < 0.0001) {
            cout << "Segitiga Siku-Siku" << endl;
        }
        else {
            cout << "Segitiga Sembarang" << endl;
        }
    } else {
        cout << "Tidak bisa membentuk segitiga" << endl;
    }
}

int main() {
    float sisi1, sisi2, sisi3;
    
    cout << "Masukkan sisi 1: ";
    cin >> sisi1;
    cout << "Masukkan sisi 2: ";
    cin >> sisi2;
    cout << "Masukkan sisi 3: ";
    cin >> sisi3;

    jenisSegitiga(sisi1, sisi2, sisi3);

    return 0;
}
