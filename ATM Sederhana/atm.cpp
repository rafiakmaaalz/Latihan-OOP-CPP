#include <iostream>
#include <string>
using namespace std;

class ATM {
  private:
    string pin;
    int saldo; // <--- Uangmu disimpan DI SINI selamanya

  public:
    ATM(string pinAwal, int saldoAwal) {
        pin = pinAwal;
        saldo = saldoAwal; // Memindahkan uang dari formulir ke brankas
    }

    bool cekPin(string inputPin) {
        if (inputPin == pin) return true;
        else return false;
    }

    void lihatSaldo() {
        cout << "Sisa Saldo Anda: Rp " << saldo << endl;
    }

    // --- PERBAIKAN ADA DI BAWAH SINI ---

    void setorUang(int jumlah) {
        // PERBAIKAN 1: Gunakan variabel 'saldo', bukan 'saldoAwal'
        saldo = saldo + jumlah; 
        cout << "Berhasil setor Rp " << jumlah << endl;
    }

    void tarikUang(int jumlah) {
        // PERBAIKAN 2: Cek apakah saldo cukup membayar 'jumlah' penarikan?
        if (saldo >= jumlah) { 
            
            // PERBAIKAN 3: Kurangi 'saldo' saat ini
            saldo = saldo - jumlah; 
            cout << "Berhasil tarik Rp " << jumlah << endl;
            
        } else {
            cout << "Saldo tidak cukup!" << endl;
        }
    }
};

int main() {
    ATM atmKu("1234", 100000); // Saldo awal 100.000

    cout << "--- SELAMAT DATANG DI BANK C++ ---" << endl;
    
    atmKu.lihatSaldo(); // 100.000

    cout << "\n>> Setor 50.000..." << endl;
    atmKu.setorUang(50000); 
    atmKu.lihatSaldo(); // Harusnya jadi 150.000

    cout << "\n>> Tarik 200.000 (Percobaan Gagal)..." << endl;
    atmKu.tarikUang(200000); // Harusnya Gagal (Saldo cuma 150rb)

    cout << "\n>> Tarik 20.000 (Percobaan Berhasil)..." << endl;
    atmKu.tarikUang(20000); // Harusnya Berhasil
    
    atmKu.lihatSaldo(); // Harusnya sisa 130.000

    return 0;
}