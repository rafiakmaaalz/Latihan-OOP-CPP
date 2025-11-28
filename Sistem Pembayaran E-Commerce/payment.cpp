#include <iostream>
#include <string>
using namespace std;

// --- 1. CLASS INDUK ---
class MetodeBayar {
  public:
    // TUGAS A: Agar method ini bisa diubah oleh anak, 
    // tambahkan kata kunci 'ajaib' di depannya.
    virtual void bayar(int nominal) {
        cout << "Pembayaran standar: Rp " << nominal << endl;
    }
};

// --- 2. CLASS ANAK: TRANSFER BANK ---
// TUGAS B: Lakukan pewarisan (Inheritance) dari MetodeBayar
class TransferBank : public MetodeBayar {
  public:
    // TUGAS C: Timpa (Override) method bayar
    void bayar(int nominal) {
        cout << "Transfer ke VA BCA 12345 senilai Rp " << nominal << " [BERHASIL]" << endl;
    }
};

// --- 3. CLASS ANAK: E-WALLET ---
// TUGAS D: Lakukan pewarisan dari MetodeBayar
class EWallet : public MetodeBayar {
  public:
    // TUGAS E: Timpa (Override) method bayar
    void bayar(int nominal) {
        cout << "Scan QRIS senilai Rp " << nominal << " [LUNAS]" << endl;
    }
};

int main() {
    cout << "--- KASIR OTOMATIS ---" << endl;

    // TUGAS F: Kita butuh variable POINTER (Penunjuk).
    // Gunakan tanda bintang (*) setelah nama class induk.
    MetodeBayar* transaksi; 

    // --- SKENARIO 1: User pilih Transfer Bank ---
    cout << "\n>> User memilih Bank..." << endl;
    
    // TUGAS G: Isi pointer dengan objek baru (gunakan kata kunci 'new')
    transaksi = new TransferBank();
    
    // TUGAS H: Panggil method bayar.
    // KARENA INI POINTER, gunakan tanda panah (->) bukan titik (.)
    transaksi -> bayar(100000);

    // --- SKENARIO 2: User pilih E-Wallet ---
    cout << "\n>> User ganti memilih E-Wallet..." << endl;

    // TUGAS I: Isi pointer dengan objek EWallet baru ('new')
    transaksi = new EWallet();
    
    // TUGAS J: Panggil method bayar lagi (tetap pakai panah)
    transaksi -> bayar(50000);

    return 0;
}