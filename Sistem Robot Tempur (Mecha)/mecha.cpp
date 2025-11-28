#include <iostream>
#include <string>
using namespace std;

class Robot {
  private:
    string nama;
    int energi;      // Energi saat ini
    int peluru;      // Jumlah peluru saat ini
    int maxEnergi;   // Batas kapasitas energi
    int maxPeluru;   // Batas kapasitas peluru

  public:
    // 1. CONSTRUCTOR
    // Set nama, dan isi energi & peluru sampai PENUH (sesuai max)
    Robot(string n, int mEnergi, int mPeluru) {
        nama = n;
        maxEnergi = mEnergi;
        maxPeluru = mPeluru;
        
        // TUGAS A: Saat lahir, energi dan peluru langsung diisi PENUH
        energi = maxEnergi; 
        peluru = maxPeluru;
    }

    // 2. METHOD TEMBAK BIASA
    // Syarat: Butuh 10 Energi dan 1 Peluru
    void tembakBiasa() {
        // TUGAS B: Cek apakah energi >= 10 DAN peluru >= 1?
        // Gunakan operator logika DAN ( && )
        if (energi >= 10 && peluru >= 1) {
            
            // Kurangi sumber daya
            energi = energi - 10;
            peluru = peluru - 1;
            cout << "Duarr! Tembakan biasa diluncurkan." << endl;
        } else {
            cout << "Gagal! Energi atau Peluru habis." << endl;
        }
    }

    // 3. METHOD ULTIMATE (Serangan Besar)
    // Syarat: Butuh 50 Energi dan 5 Peluru
    void ultimate() {
        // TUGAS C: Cek apakah energi cukup 50 DAN peluru cukup 5?
         if (energi >= 50 && peluru >= 5 ) {
            
            energi = energi - 50;
            peluru = peluru - 5;
            cout << "BOOOM! ULTIMATE DILUNCURKAN! Hancur semua!" << endl;
        } else {
            cout << "Gagal Ultimate! Periksa energi/peluru." << endl;
        }
    }

    // 4. METHOD RECHARGE (Isi Ulang) -- LEVEL EXPERT
    // Robot istirahat. Energi nambah 30, Peluru nambah 3.
    // TAPI: Tidak boleh melebihi batas maksimum (maxEnergi / maxPeluru).
    void recharge() {
        cout << "Sedang recharge..." << endl;

        // --- LOGIKA PENGISIAN ENERGI ---
        // Tambah dulu energinya
        energi = energi + 30;

        // TUGAS D: Cek jika energi melebihi maxEnergi, potong kelebihannya!
        if (energi > maxEnergi) {
            energi = maxEnergi ; // Kembalikan ke batas max
        }

        // --- LOGIKA PENGISIAN PELURU ---
        // Tambah dulu pelurunya
        peluru = peluru + 3;

        // TUGAS E: Cek jika peluru melebihi maxPeluru, potong kelebihannya!
        if (peluru > maxPeluru) {
            peluru = maxPeluru ; // Kembalikan ke batas max
        }
    }

    void cekStatus() {
        cout << "[" << nama << "] Energi: " << energi << "/" << maxEnergi 
             << " | Peluru: " << peluru << "/" << maxPeluru << endl;
    }
};

int main() {
    // Robot "Gundam", Max Energi 100, Max Peluru 10
    Robot robotku("Gundam", 100, 10);
    robotku.cekStatus(); // Harus penuh (100/100, 10/10)

    cout << "\n--- PERTEMPURAN DIMULAI ---" << endl;
    robotku.ultimate(); // Pake 50 energi, 5 peluru
    robotku.tembakBiasa(); // Pake 10 energi, 1 peluru
    robotku.cekStatus(); // Sisa: 40 energi, 4 peluru

    cout << "\n--- COBA ULTIMATE LAGI (Harusnya Gagal) ---" << endl;
    robotku.ultimate(); // Gak cukup peluru (butuh 5, sisa 4)

    cout << "\n--- FASE RECHARGE ---" << endl;
    robotku.recharge(); // Nambah 30 energi, 3 peluru
    robotku.cekStatus(); // Sisa: 70 energi, 7 peluru

    robotku.recharge(); // Isi lagi... (Hati-hati over capacity!)
    robotku.cekStatus(); // Energi harus mentok di 100, Peluru mentok di 10. Gak boleh 105/100.

    return 0;
}