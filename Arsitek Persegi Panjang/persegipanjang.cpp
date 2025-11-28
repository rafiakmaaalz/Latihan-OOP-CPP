#include <iostream>
using namespace std;

class PersegiPanjang {
  public:
    int panjang;
    int lebar;

    // --- INI CONSTRUCTOR ---
    // Namanya sama dengan Class. Menerima input (p, l).
    PersegiPanjang(int p, int l) {
        // Kita pindahkan data dari input (p) ke atribut class (panjang)
        panjang = p;
        lebar = l;
    }

    int hitungLuas() {
        return panjang * lebar;
    }
};

int main() {
    // CARA PAKAI DI MAIN:
    // Langsung masukkan angka di dalam kurung saat membuat objek
    PersegiPanjang kotak1(10, 5);
    PersegiPanjang kotak2(20, 3);

    cout << "Luas Kotak 1: " << kotak1.hitungLuas() << endl; // 50
    cout << "Luas Kotak 2: " << kotak2.hitungLuas() << endl; // 60

    return 0;
}