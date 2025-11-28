#include <iostream>
#include <string>
using namespace std;

// --- 1. TULIS CLASS INDUK 'Perangkat' DI SINI ---
// (Ingat: protected nama, public constructor, virtual void hidupkan)
class Perangkat{
    protected:
        string nama;
    
    public:
        Perangkat(string n){
            nama = n;
        }
        
    virtual void hidupkan(){
        cout << "perangkat menyalaa" << endl;
        }
};



// --- 2. TULIS CLASS ANAK 'Lampu' DI SINI ---
// (Ingat: warisi Perangkat, constructor set nama, override hidupkan)
class Lampu : public Perangkat{
    public:
        Lampu() : Perangkat("Lampu Philips"){

        }

    void hidupkan(){
        cout << "Cahaya terang benderang!" << endl;
    }
};


// --- 3. TULIS CLASS ANAK 'Speaker' DI SINI ---
// (Ingat: warisi Perangkat, constructor set nama, override hidupkan)
class Speaker : public Perangkat{
    public:
        Speaker() : Perangkat("Speaker JBL"){

        }

    void hidupkan(){
        cout << "Musik diputar... Jedag Jedug!" << endl;
    }
};



int main() {
    cout << "--- SMART HOME DASHBOARD ---" << endl;

    // --- 4. TULIS LOGIKA MAIN DI SINI ---
    // a. Buat Array of Pointer 'Perangkat' (Size 2)
    Perangkat* Sistem[2];
    int pilihan;
    char kembali;
    // b. Isi array ke-0 dengan new Lampu()
    
    // c. Isi array ke-1 dengan new Speaker()
    
    // d. Lakukan Looping for (0 sampai < 2)
    //    Di dalam loop: Panggil method hidupkan() pakai tanda panah (->)
    // LOGIKA INPUT USER (Improvisasi Kerenmu!)
    do{
    for (int i = 0; i < 2; i++) {
        cout << "\nSlot Device ke-" << i+1 << endl;
        cout << "Pasang apa? (1. Lampu, 2. Speaker): ";
        cin >> pilihan;

        if (pilihan == 1) {
            Sistem[i] = new Lampu(); 
        } else {
            Sistem[i] = new Speaker();
        }
    }

    cout << "\n--- MENYALAKAN SEMUA PERANGKAT ---" << endl;

    // LOGIKA POLYMORPHISM
    for (int i = 0; i < 2; i++) {
        cout << "Device ke-" << i+1 << ": ";
        
        // Karena pointer, pakai tanda panah (->)
        // Output akan beda tergantung benda apa yang kamu pasang tadi
        Sistem[i]->hidupkan(); 
    }
        cout << "\n-----------------------------------" << endl;
        cout << "Apakah ingin kembali ke menu utama? (y/n): ";
        cin >> kembali;
    
    }while (kembali == 'y' || kembali == 'Y');
    cout << "\nTerima kasih telah menggunakan aplikasi ini!" << endl;
    return 0;
}