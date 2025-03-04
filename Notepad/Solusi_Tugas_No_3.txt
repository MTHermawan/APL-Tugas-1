#include <iostream>
using namespace std;

int main(){
    int nomor [2][3] = {{5, 4, 3},
                        {2, 6, 8}};
    for(int a=0; a<2; a++){
        for(int b=0; b<3; b++){
            cout<<nomor[a][b]<<" ";
        }
        cout<<endl;
    }


int sum = 0;
for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 3; b++) {
        sum = sum + nomor[a][b];
    }
}

int n = 6; 
double mean = (double)sum / n;

cout << "5+4+3+2+6+8(jumlah) = " << sum << endl;
cout << "n = " << n << endl;
cout << "Mean = jumlah/n" << endl;
cout << "Mean = " << mean << endl;
return 0;
}
