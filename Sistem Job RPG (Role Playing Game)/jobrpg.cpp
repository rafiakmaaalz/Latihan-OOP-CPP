#include <iostream>
#include <string>
using namespace std;

// --- CLASS INDUK ---
class Karakter {
  protected:
    string nama;
    int hp;
    int mana;

  public:
    Karakter(string n, int h, int m) {
        nama = n;
        hp = h; // [FIX] Isi hp dengan nilai dari 'h'
        mana = m;
    }

    void info() {
        cout << "Stats [" << nama << "] HP: " << hp << " | Mana: " << mana << endl;
    }
};

// --- CLASS ANAK 1: KSATRIA ---
class Ksatria : public Karakter {
  public:
    Ksatria(string n) : Karakter(n, 200, 50) {}

    void seranganKuat() {
        if (mana >= 10) {
            mana = mana - 10; // [FIX] Jangan lupa titik koma!
            cout << nama << " menggunakan Tebasan Maut! Hyaa!" << endl;
        } else {
            cout << "Mana tidak cukup!" << endl;
        }
    }
};

// --- CLASS ANAK 2: PENYIHIR ---
class Penyihir : public Karakter {
  public:
    Penyihir(string n) : Karakter(n, 100, 150) {}

    void bolaApi() {
        if (mana >= 20) { 
            mana = mana - 20; // [FIX] Jangan lupa titik koma!
            cout << nama << " menggunakan Bola Apii! BOOMM!" << endl;
        } else {
            cout << "Mana tidak cukup!" << endl;
        }
    }
};

int main() {
    cout << "--- ARENA PERTARUNGAN ---" << endl;

    // [FIX] Masukkan nama ke dalam kurung saat bikin objek
    Ksatria arthur("Arthur");
    Penyihir merlin("Merlin");
    
    // Cek info awal
    arthur.info();
    merlin.info();

    cout << "\n--- ACTION ---" << endl;

    // [FIX] Panggil method pakai titik (.) dan kurung ();
    arthur.seranganKuat();
    merlin.bolaApi();

    cout << "\n--- STATUS AKHIR ---" << endl;
    arthur.info();
    merlin.info();

    return 0;
}