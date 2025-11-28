#include <iostream>
#include <string>
using namespace std;

// 1. TULIS CLASS 'Tiket'
class Tiket{
    protected:
        string namaFilm;
        int hargaDasar;
    
    public :
        Tiket(string n, int h){
            namaFilm = n;
            hargaDasar = h;
        }
        
    virtual void cetak(){
            cout << "Tiket " << namaFilm << " - Harga: Rp " << hargaDasar << endl;
        }
};


// 2. TULIS CLASS 'Regular'
class Reguler : public Tiket{
    public :
        // [FIX] Terima input 'n' (nama film), lalu oper ke Tiket bersama harga 50000
        Reguler(string n) : Tiket(n, 50000) {
        }
    
    void cetak(){
        cout << "Tiket REGULAR: " << namaFilm << " | Kursi Standar | Total: Rp 50.000" << endl;
    }
};

// 3. TULIS CLASS 'Premiere'
class Premiere : public Tiket{
    public :
        // [FIX] Terima input 'n', oper ke Tiket bersama harga 150000
        Premiere(string n) : Tiket(n, 150000) {
        }
    
    void cetak(){
        cout << "Tiket PREMIERE: " << namaFilm << " | Sofa + Selimut | Total: Rp 150.000" << endl;
    }
};

int main() {
    cout << "--- BIOSKOP XXI SELF SERVICE ---" << endl;
    
    // a. Siapkan Array Pointer (Size 2)
    Tiket* Film[2];
    int pilihan;

    // [FIX] Butuh variabel buat nampung judul film sementara
    string inputJudul;

    char kembali;

    do{
    // b. Loop Input (0 sampai 1)
       // Minta Judul Film
       // Minta Tipe Tiket
       // Logika IF: Kalau 1 -> new Regular(...), Kalau 2 -> new Premiere(...)
    for (int i = 0; i < 2; i++) {
            cout << "\n--- Pesanan Tiket ke-" << i+1 << " ---" << endl;
            
            // [FIX] Tanya Judul Film dulu!
            cout << "Mau nonton film apa? (1 Kata): ";
            cin >> inputJudul;

            cout << "Pilih Tipe (1. Regular, 2. Premiere): ";
            cin >> pilihan;

            if (pilihan == 1) {
                // [FIX] Masukkan 'inputJudul' ke dalam constructor
                Film[i] = new Reguler(inputJudul); 
            } else {
                Film[i] = new Premiere(inputJudul);
            }
        }

    cout << "\n--- CETAK TIKET ---" << endl;
    
    // c. Loop Output (Polymorphism)
       // Panggil method cetak()
    for (int i = 0; i < 2; i++) {
            cout << "Tiket " << i+1 << ": ";
        
        // Karena pointer, pakai tanda panah (->)
        // Output akan beda tergantung benda apa yang kamu pasang tadi
        Film[i]->cetak(); 
    }
        cout << "\n-----------------------------------" << endl;
        cout << "Apakah ingin kembali ke menu utama? (y/n): ";
        cin >> kembali;
    
    }while (kembali == 'y' || kembali == 'Y');
    cout << "\nTerima kasih, selamat menonton!" << endl;

    return 0;
}