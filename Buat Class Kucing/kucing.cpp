#include <iostream>
#include <string>
using namespace std;

class Kucing {
  // DATA RAHASIA (Private)
  private:
    string nama; 
    int umur;
   
  // PINTU AKSES (Public)
  public:
    // Constructor
    Kucing(string n, int u) {
        nama = n;
        umur = u;
    }

    // --- 1. GETTER (Cuma buat intip data) ---
    // Karena 'nama' itu string, maka tipe fungsinya string
    string ambilNama() {
        return nama; 
    }

    // --- 2. SETTER (Buat ubah data dengan aman) ---
    // Kita pasang satpam di sini!
    void aturUmur(int umurBaru) {
        if (umurBaru < 0) {
            cout << "Eits! Umur tidak boleh minus. Umur tidak diubah." << endl;
        } else {
            umur = umurBaru; // Kalau positif, baru boleh masuk brankas
            cout << "Umur berhasil diubah!" << endl;
        }
    }

    void mengeong() {
        cout << "Meong... Halo namaku: " << nama << ", umurku " << umur << " tahun." << endl;
    }
};

int main() {
   Kucing kucingku("Mochi", 2); 
   
   // cout << kucingku.nama; // <--- INI AKAN ERROR
   
   // CARA BENAR MENGAMBIL DATA (Pakai Getter)
   cout << "Nama kucing adalah: " << kucingku.ambilNama() << endl;

   // CARA BENAR MENGUBAH DATA (Pakai Setter)
   // Coba masukkan angka ngawur (minus)
   kucingku.aturUmur(-5); 
   
   // Coba masukkan angka benar
   kucingku.aturUmur(5);

   kucingku.mengeong();
   return 0;
}