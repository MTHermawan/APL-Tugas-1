#include <iostream>
using namespace std;

int pangkat(int a, int b) {
    if (b == 0) 
        return 1; 
    else 
        return a * pangkat(a, b - 1); 
}

int main() {
    int a, b;
    cout << "Masukkan bilangan (a): ";
    cin >> a;
    cout << "Masukkan pangkat (b): ";
    cin >> b;

    int hasil = pangkat(a, b);
    cout << a << "^" << b << " = " << hasil << endl;

    return 0;
}
