#include <iostream>
#include <limits>
using namespace std;

void cls()
{
    system("cls"); // Membersihkan layar konsol
}

int main() {

    cls();

    float matrix[2][2];
    cout << "Silahkan masukkan nilai matriks 2x2" << endl;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            while (true) {
                cout << "Masukkan nilai baris " << i + 1 << ", kolom " << j + 1 << ": ";
                cin >> matrix[i][j];
                if (cin.fail()) {
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Input tidak valid. Silakan masukkan angka." << endl;
                } else {
                    break;
                }
            }
        }
    }

    cls();
    cout << "Matriks yang dimasukkan adalah: " << endl;
    cout << matrix[0][0] << " " << matrix[0][1] << endl;
    cout << matrix[1][0] << " " << matrix[1][1] << endl;
 
    int det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    if (det == 0) {
        cout << "Matriks tidak dapat di-invers, determinan adalah 0." << endl;
        return 1;
    }

    cout << "Matriks inversnya adalah: " << endl;
    matrix[0][0] = matrix[1][1] / (float)det;
    matrix[0][1] = -matrix[0][1] / (float)det;
    matrix[1][0] = -matrix[1][0] / (float)det;
    matrix[1][1] = matrix[0][0] / (float)det;
    
    cout << matrix[0][0] << "  " << matrix[0][1] << endl;
    cout << matrix[1][0] << "  " << matrix[1][1] << endl;
  
    return 0;
}
