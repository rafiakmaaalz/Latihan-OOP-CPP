#include <iostream>
#include <string>
using namespace std;

class TokoBuku {
  private:
    string judulBuku;
    int stok;
    int hargaSatuan;
    int totalPendapatan; 

  public:
    TokoBuku(string j, int s, int h) {
        judulBuku = j;
        stok = s;
        hargaSatuan = h;
        totalPendapatan = 0; // BAGUS! Ini sudah benar.
    }

    int hitungTotalHarga(int jumlahBeli) {
        // [FIX 1] Kalikan dengan 'jumlahBeli', bukan 'stok'
        return jumlahBeli * hargaSatuan;
    }

    void prosesJualBeli(int jumlahBeli, int uangPelanggan) {
        
        // [FIX 2] Panggil method tanpa menulis 'int' di dalam kurung
        // Dan kita cuma butuh kirim 'jumlahBeli' saja
        int hargaHarusDibayar = hitungTotalHarga(jumlahBeli); 

        // VALIDASI

        // [FIX 3] Gunakan '>' (Jika jumlah beli LEBIH BESAR dari stok)
        if (jumlahBeli > stok) { 
            cout << "Transaksi Gagal: Stok habis / tidak cukup!" << endl;
        }
        // [FIX 4] Gunakan '<' (Jika uang KURANG dari harga)
        // Kalau uangnya PAS (==), itu boleh, jadi jangan pakai '<='
        else if (uangPelanggan < hargaHarusDibayar) {
            cout << "Transaksi Gagal: Uang Anda kurang!" << endl;
        } 
        else {
            // LOGIKA SUKSES
            
            // 1. Kurangi Stok (SUDAH BENAR)
            stok = stok - jumlahBeli;

            // 2. Update Kas Toko
            // [FIX 5] Tambahkan dengan variabel harga yg sudah dihitung tadi
            totalPendapatan = totalPendapatan + hargaHarusDibayar;

            // 3. Hitung Kembalian
            // [FIX 6] Rumus: Uang Pelanggan dikurangi Harga
            int kembalian = uangPelanggan - hargaHarusDibayar;

            cout << "--- STRUK BELANJA ---" << endl;
            cout << "Buku: " << judulBuku << endl;
            cout << "Total Bayar: " << hargaHarusDibayar << endl;
            cout << "Kembalian: " << kembalian << endl;
            cout << "Terima kasih!" << endl;
        }
    }

    void cekStatusToko() {
        cout << "[INFO] Stok: " << stok << " | Kas Toko: Rp " << totalPendapatan << endl;
    }
};

int main() {
    TokoBuku tokoku("C++ Mastery", 10, 50000);

    // Skenario 1: Beli 2 buku (Total 100.000), Uang 150.000
    cout << "Pembeli 1 Datang..." << endl;
    tokoku.prosesJualBeli(2, 150000); 
    tokoku.cekStatusToko(); 

    cout << "\n Pembeli 2 Datang (Uang Kurang)..." << endl;
    // Beli 1 buku (Total 50.000), Uang cuma 5.000
    tokoku.prosesJualBeli(1, 5000);
    
    cout << "\n Pembeli 3 Datang (Borong)..." << endl;
    // Beli 5 buku (Total 250.000), Uang 300.000
    tokoku.prosesJualBeli(5, 300000);
    
    tokoku.cekStatusToko(); // Stok sisa 3, Uang kas 350.000

    return 0;
}