#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mahasiswa
{
    string nama;
    int nilai;
};

// Exchange Sort
void exchangeSort(vector<Mahasiswa> &data)
{
    int n = data.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Tukar elemen jika nilai pada indeks i lebih besar dari nilai pada indeks j
            if (data[i].nilai > data[j].nilai)
            {
                Mahasiswa temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

// Fibonacci Search
int fibonacciSearch(vector<Mahasiswa> &data, int x)
{
    int n = data.size();
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    // Mencari angka fibonacci terbesar yang kurang dari atau sama dengan n
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Proses pencarian nilai x
    int offset = -1;
    int i = -1;
    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);

        if (data[i].nilai < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (data[i].nilai > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            return i;
        }
    }

    if (fibMMm1 && data[offset + 1].nilai == x)
    {
        i = offset + 1;
    }
    else
    {
        return -1;
    }

    return i;
}

// Fungsi untuk membaca data dari file CSV
vector<Mahasiswa> ReadCSV(string &namaFile)
{
    vector<Mahasiswa> data;
    ifstream file(namaFile);
    string line;

    // Lewati baris header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        string nama, nilaiStr;
        getline(ss, nama, ',');
        getline(ss, nilaiStr, ',');
        int nilai = stoi(nilaiStr);
        data.push_back({nama, nilai});
    }

    file.close();
    return data;
}

int main()
{
    string namaFile = "data_nilai.csv";
    vector<Mahasiswa> data = ReadCSV(namaFile);

    // Mengurutkan data menggunakan Exchange Sort
    exchangeSort(data);

    // Menampilkan data setelah diurutkan
    cout << "Data setelah diurutkan:" << endl;
    for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i].nama << ": " << data[i].nilai << endl;
    }

    // Mencari nilai tertentu
    int x;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> x;

    int result = fibonacciSearch(data, x);

    if (result != -1)
    {
        cout << "Nilai ditemukan pada mahasiswa: " << data[result].nama << " (Dengan indeks: " << result << ")" << endl;
    }
    else
    {
        cout << "Nilai tidak ditemukan" << endl;
    }

    return 0;
}