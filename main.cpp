#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const string warna[] = {"Hati", "Wajik", "Sekop", "Keriting"};
const string angka[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

void pilihKartuAcak(string &randWarna, string &randAngka) {
    randWarna = warna[rand() % 4];
    randAngka = angka[rand() % 13];
}

bool cekTebakan(const string &InputWarna, const string &InputAngka, const string &randWarna, const string &randAngka) {
    return (InputWarna == randWarna && InputAngka == randAngka);
}

void tampilkanPesanSalah(const string &InputWarna, const string &InputAngka, const string &randWarna, const string &randAngka) {
    if (InputWarna != randWarna && InputAngka != randAngka) {
        cout << "Jenis kartu dan nilai kartu keduanya salah.";
    } else if (InputWarna != randWarna) {
        cout << "Jenis kartu salah.";
    } else {
        cout << "Nilai kartu salah.";
    }
    cout << " Coba lagi!\n";
}

void tampilkanPengantar() {
    cout << "Selamat datang di permainan Tebak Kartu!\n";
    cout << "Komputer telah memilih sebuah kartu dari tumpukan.\n";
    cout << "Tebak kartu tersebut!\n";
    cout << "Masukkan '0' pada jenis atau nilai kartu untuk keluar dari permainan.\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    string randWarna, randAngka;
    pilihKartuAcak(randWarna, randAngka);

    tampilkanPengantar();

    string InputWarna, InputAngka;
    int kesempatan = 0;
    bool berhasil = false;

    do {
        cout << "\nMasukkan tebakan jenis kartu (Hati, Wajik, Sekop, Keriting): ";
        cin >> InputWarna;
        if (InputWarna == "0") break;
        
        cout << "Masukkan tebakan nilai kartu (As, 2-10, Jack, Queen, King): ";
        cin >> InputAngka;
        if (InputAngka == "0") break; 

        kesempatan++;

        if (cekTebakan(InputWarna, InputAngka, randWarna, randAngka)) {
            cout << "\nSelamat! Anda berhasil menebak kartu dengan benar: " 
                 << randAngka << " " << randWarna << " dalam " 
                 << kesempatan << " percobaan.\n";
            berhasil = true;
            break;
        } else {
            tampilkanPesanSalah(InputWarna, InputAngka, randWarna, randAngka);
        }
    } while (true);

    if (!berhasil) {
        cout << "\nPermainan selesai. Kartu yang dipilih adalah: " 
             << randAngka << " " << randWarna << ".\n";
    }
    cout << "Terima kasih telah bermain!\n";

    return 0;
}
