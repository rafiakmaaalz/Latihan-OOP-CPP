#include <iostream>
#include <string>
using namespace std;

class Peliharaan {
  private : 
    string nama;
    int lapar;   
    int bahagia; 
    int energi;  

  public :
    // CONSTRUCTOR
    Peliharaan(string n) {
        nama = n;
        lapar = 50;
        bahagia = 50;
        energi = 100;
    }

    // METHOD MAKAN
    void beriMakan() {
        cout << nama << " sedang makan... Nyam nyam!" << endl;
        
        lapar = lapar - 20; 
        energi = energi + 10;

        // [PERBAIKAN LOGIKA]
        // Jika lapar jadi minus, kembalikan ke 0
        if (lapar < 0) { 
            lapar = 0;
        }

        // Jika energi kelebihan, potong ke 100
        if (energi > 100) {
            energi = 100;
        }
    }

    // METHOD MAIN
    void ajakMain() {
        if (energi > 10) {
            cout << nama << " bermain bola! Seru banget!" << endl;

            bahagia = bahagia + 20;
            lapar = lapar + 10;
            energi = energi - 30;

            if (bahagia > 100) bahagia = 100;
            if (lapar > 100) lapar = 100;

        } else {
            cout << nama << " terlalu lelah untuk bermain..." << endl;
        }
    }

    // METHOD TIDUR
    void tidur() {
        cout << nama << " tidur pulas... Zzz..." << endl;
        energi = 100; 
        lapar = lapar + 20;
        
        if (lapar > 100) lapar = 100;
    }

    void cekStatus() {
        cout << "--- STATUS " << nama << " ---" << endl;
        cout << "Lapar   : " << lapar << "/100" << endl;
        cout << "Bahagia : " << bahagia << "/100" << endl;
        cout << "Energi  : " << energi << "/100" << endl;
        
        if (lapar >= 100) cout << "⚠️ PERINGATAN: " << nama << " KELAPARAN!" << endl;
        if (energi <= 0)  cout << "⚠️ PERINGATAN: " << nama << " PINGSAN!" << endl;
        cout << "-----------------------" << endl;
    }
}; 

int main() {
    // [PERBAIKAN SYNTAX]
    // TipeData NamaObjek("IsiString");
    Peliharaan kucingKu("Oyen");

    kucingKu.cekStatus();

    cout << "\n>> Ajak Main..." << endl;
    kucingKu.ajakMain();

    cout << "\n>> Ajak Main lagi..." << endl;
    kucingKu.ajakMain();

    cout << "\n>> Paksa Main..." << endl;
    kucingKu.ajakMain();

    cout << "\n>> Suruh Tidur..." << endl;
    kucingKu.tidur();

    cout << "\n>> Beri Makan..." << endl;
    kucingKu.beriMakan();

    kucingKu.cekStatus();

    return 0;
}