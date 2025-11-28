#include <iostream>
#include <string>
using namespace std;

class Akun {
  // DATA RAHASIA (Private)
  // Ini ibarat "Database" yang menyimpan password asli
  private:
    string password; 
   
  public:
    // CONSTRUCTOR
    // Tugasnya cuma satu: Simpan password awal ke brankas
    Akun(string pass) {
        password = pass; 
        // Variabel 'pass' mati setelah kurung kurawal ini tutup.
        // Tapi isinya sudah kita selamatkan ke dalam variabel 'password'.
    }
    
    // METHOD LOGIN
    // Menerima input dari orang yang mau masuk
    void cobaLogin(string inputPassword) {
        // Logika: Apakah inputan orang ini SAMA DENGAN password di brankas?
        if (inputPassword == password) {
            cout << "Sukses! Anda berhasil login." << endl;
        } else {
            cout << "Gagal! Password salah." << endl;
        }
    }
};

int main() {
   // 1. Daftar akun baru dengan password "rahasia123"
   Akun akunSaya("rahasia123");

   cout << "Percobaan 1 (Password Ngawur):" << endl;
   akunSaya.cobaLogin("bukapintu"); // Pasti Gagal

   cout << "\nPercobaan 2 (Password Benar):" << endl;
   akunSaya.cobaLogin("rahasia123"); // Pasti Sukses

   return 0;
}