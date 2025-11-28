#include <iostream>
#include <string>
using namespace std;

class Player {
  public:
    string nickname;
    string role;
    int level;

    // CONSTRUCTOR
    // Menerima data dari luar untuk mengisi atribut
    Player(string n, string r, int l) {
        nickname = n;
        role = r;
        level = l;
    }

    // Method untuk menampilkan Kartu Identitas
    void tampilkanKartu() {
        cout << "\n=== PLAYER CARD ===" << endl;
        cout << "Name  : " << nickname << endl;
        cout << "Class : " << role << endl;
        cout << "Level : " << level << endl;
        cout << "===================" << endl;
    }
};

int main() {
    // 1. SIAPKAN WADAH (VARIABEL)
    // Variabel ini kosong, tugasnya cuma buat menampung ketikan user sementara
    string inputNama;
    string inputRole;
    int inputLevel;

    cout << "--- SELAMAT DATANG DI GAME CREATE ---" << endl;

    // 2. MINTA INPUT USER
    // TUGAS A: Gunakan 'cin' untuk mengisi variabel-variabel di atas
    
    cout << "Masukkan Nickname (1 kata): ";
    cin >> inputNama ; // Masukkan ke variabel nama

    cout << "Pilih Role (Mage/Tank/Archer): ";
    cin >> inputRole ; // Masukkan ke variabel role

    cout << "Tentukan Level Awal (1-99): ";
    cin >> inputLevel ; // Masukkan ke variabel level

    // 3. BUAT OBJEK DARI HASIL INPUT
    // TUGAS B: Buat objek bernama 'pemain1' dari class Player.
    // PENTING: Isi dalam kurungnya BUKAN tulisan manual ("Budi"), 
    // tapi masukkan variabel yang sudah diisi user di atas tadi.
    
    Player pemain1( inputNama , inputRole , inputLevel );

    // 4. BUKTIKAN HASILNYA
    cout << "\nSedang mencetak kartu..." << endl;
    
    // TUGAS C: Panggil method tampilkanKartu punya 'pemain1'
    pemain1.tampilkanKartu() ;

    return 0;
}