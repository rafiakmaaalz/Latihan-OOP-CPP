#include <iostream>
#include <string>
using namespace std;

// --- CLASS INDUK ---
class Karyawan {
  // TUGAS 1: Gunakan akses yang AMAN tapi BISA DIWARISKAN ke anak
  protected : 
    string nama;
    int gajiPokok;

  public:
    // Constructor Induk
    Karyawan(string n, int gp) {
        nama = n;
        gajiPokok = gp;
    }

    void infoDasar() {
        cout << "Nama: " << nama << " | Gaji Pokok: Rp " << gajiPokok << endl;
    }
};

// --- CLASS ANAK 1: MANAGER ---
// TUGAS 2: Tulis sintaks agar Manager mewarisi Karyawan
class Manager : public Karyawan { 
  private:
    int tunjangan;

  public:
    // TUGAS 3: Lengkapi Constructor Manager.
    // Manager butuh input: nama, gajiPokok, dan tunjangan.
    // Kirim nama & gajiPokok ke Constructor Bapak (Karyawan).
    Manager(string n, int gp, int t) : Karyawan(n, gp) {
        tunjangan = t;
    }

    // Method Hitung Gaji Manager
    void cetakSlipGaji(bool targetTercapai) {
        cout << "\n=== SLIP GAJI MANAGER ===" << endl;
        infoDasar(); // Panggil info dari bapak

        // TUGAS 4: Hitung Total Gaji
        // Rumus Awal: GajiPokok + Tunjangan
        int total = gajiPokok + tunjangan ;

        // Jika target tercapai, tambah bonus 5.000.000
        if (targetTercapai == true) {
            cout << "+ Bonus Target: Rp 5.000.000" << endl;
            total = total + 5000000; // <--- Tambahkan nominal uangnya
        }

        cout << "TOTAL GAJI DITERIMA: Rp " << total << endl;
    }
};

// --- CLASS ANAK 2: SALES ---
// TUGAS 5: Sales juga mewarisi Karyawan
class Sales : public Karyawan {
  private:
    int komisiPerBarang; // Dapat duit per barang yg dijual

  public:
    // Constructor Sales
    // Butuh input: nama, gajiPokok, dan komisi.
    Sales(string n, int gp, int k) : Karyawan(n, gp) {
        komisiPerBarang = k;
    }

    // Method Hitung Gaji Sales
    void cetakSlipGaji(int jumlahBarangTerjual) {
        cout << "\n=== SLIP GAJI SALES ===" << endl;
        infoDasar();

        // TUGAS 6: Hitung Total Pendapatan Sales
        // Rumus: GajiPokok + (Komisi x JumlahBarang)
        int totalKomisi = komisiPerBarang * jumlahBarangTerjual ;
        int totalGaji = gajiPokok + totalKomisi;

        cout << "Penjualan: " << jumlahBarangTerjual << " unit" << endl;
        cout << "Total Komisi: Rp " << totalKomisi << endl;
        cout << "TOTAL GAJI DITERIMA: Rp " << totalGaji << endl;
    }
};

int main() {
    int pilihanMenu;
    char kembali; 

    do {
    cout << "--- SISTEM PENGGAJIAN PT. MAJU MUNDUR ---" << endl;
    cout << "1. Hitung Gaji Manager" << endl;
    cout << "2. Hitung Gaji Sales" << endl;
    cout << "Pilih (1/2): ";
    cin >> pilihanMenu;

    // --- LOGIKA UTAMA ---
    if (pilihanMenu == 1) {
        // --- KASUS MANAGER ---
        string n;
        int gp, tunj;
        bool isSuccess; // Input 1 (True) atau 0 (False)

        cout << "Masukkan Nama: "; cin >> n;
        cout << "Gaji Pokok: "; cin >> gp;
        cout << "Besar Tunjangan: "; cin >> tunj;
        cout << "Target Project Tercapai? (1=Ya, 0=Tidak): "; cin >> isSuccess;

        // TUGAS 7: Buat Objek Manager (panggil constructor dengan variabel input)
        // Lalu panggil method cetakSlipGaji
        Manager pakBos( n , gp , tunj );
        pakBos.cetakSlipGaji( isSuccess );

    } else if (pilihanMenu == 2) {
        // --- KASUS SALES ---
        string n;
        int gp, komisi, jumlahJual;

        cout << "Masukkan Nama: "; cin >> n;
        cout << "Gaji Pokok: "; cin >> gp;
        cout << "Komisi Per Barang: "; cin >> komisi;
        cout << "Jumlah Barang Terjual: "; cin >> jumlahJual;

        // TUGAS 8: Buat Objek Sales
        // Lalu panggil method cetakSlipGaji
        Sales masSales( n , gp , komisi );
        masSales.cetakSlipGaji( jumlahJual );
        
    } else {
        cout << "Menu tidak valid!" << endl;
    }
    // TUGAS 9 : Buat Pertanyaan untuk mengulang
        cout << "\n-----------------------------------" << endl;
        cout << "Apakah ingin kembali ke menu utama? (y/n): ";
        cin >> kembali;

    } while (kembali == 'y' || kembali == 'Y');

    cout << "\nTerima kasih telah menggunakan aplikasi ini!" << endl;
    return 0;
}