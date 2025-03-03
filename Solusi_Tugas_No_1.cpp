#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

// Fungsi untuk menghitung minimum
int calculateMin(const std::vector<int>& values) {
    return *std::min_element(values.begin(), values.end());
}

// Fungsi untuk menghitung maksimum
int calculateMax(const std::vector<int>& values) {
    return *std::max_element(values.begin(), values.end());
}

// Fungsi untuk menghitung mean
double calculateMean(const std::vector<int>& values) {
    return std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}

// Prosedur untuk menangani pesan dari jendela
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static std::vector<int> values = {10, 20, 30, 40, 50}; // Contoh data

    switch (uMsg) {
        case WM_CREATE: {
            // Membuat tombol untuk menghitung minimum
            CreateWindow(TEXT("BUTTON"), TEXT("Hitung MIN"), WS_VISIBLE | WS_CHILD, 10, 10, 100, 30, hwnd, (HMENU)1, NULL, NULL);
            // Membuat tombol untuk menghitung maksimum
            CreateWindow(TEXT("BUTTON"), TEXT("Hitung MAX"), WS_VISIBLE | WS_CHILD, 120, 10, 100, 30, hwnd, (HMENU)2, NULL, NULL);
            // Membuat tombol untuk menghitung mean
            CreateWindow(TEXT("BUTTON"), TEXT("Hitung MEAN"), WS_VISIBLE | WS_CHILD, 230, 10, 100, 30, hwnd, (HMENU)3, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == 1) { // Tombol MIN ditekan
                int minVal = calculateMin(values);
                std::wstring message = L"Nilai MIN: " + std::to_wstring(minVal);
                MessageBoxW(hwnd, message.c_str(), L"Hasil", MB_OK);
            } else if (LOWORD(wParam) == 2) { // Tombol MAX ditekan
                int maxVal = calculateMax(values);
                std::wstring message = L"Nilai MAX: " + std::to_wstring(maxVal);
                MessageBoxW(hwnd, message.c_str(), L"Hasil", MB_OK);
            } else if (LOWORD(wParam) == 3) { // Tombol MEAN ditekan
                double meanVal = calculateMean(values);
                std::wstring message = L"Nilai MEAN: " + std::to_wstring(meanVal);
                MessageBoxW(hwnd, message.c_str(), L"Hasil", MB_OK);
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Fungsi utama
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Mendaftarkan kelas jendela
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("KalkulatorMatrixClass");

    RegisterClass(&wc);

    // Membuat jendela
    HWND hwnd = CreateWindowEx(0, TEXT("KalkulatorMatrixClass"), TEXT("Kalkulator Matrix"), WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 400, 200, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        return 0;
    }

    // Menampilkan jendela
    ShowWindow(hwnd, nCmdShow);

    // Loop pesan
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}