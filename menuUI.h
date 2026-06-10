#ifndef MENUUI_H
#define MENUUI_H
#include <iostream>
#include "Database.h" 

using namespace std;

class MenuAplikasi {
private:
    DatabasePasien db;

public:
    // Fungsi untuk menu bagian dalam (setelah pasien dipilih)
    void pilihPasien() {
        int id; 
        cout << "\nMasukkan ID Pasien : "; 
        cin >> id;
        
        int index = db.cariPasienByID(id);
        if(index == -1) { cout << "\nPasien tidak ditemukan.\n"; return; }

        int menu;
        do {
            cout << "\n==============================";
            cout << "\n MENU KESEHATAN PASIEN";
            cout << "\n==============================";
            cout << "\n1. Hitung IMT\n2. Hitung BMR\n3. Kebutuhan Air\n4. Tekanan Darah\n5. Persentase Lemak Tubuh\n6. Lihat Riwayat\n0. Kembali\nPilihan : ";
            cin >> menu;

            switch(menu) {
                case 1: db.daftarPasien[index].cekIMT(); break;
                case 2: db.daftarPasien[index].cekBMR(); break;
                case 3: db.daftarPasien[index].cekAir(); break;
                case 4: db.daftarPasien[index].cekTekananDarah(); break;
                case 5: db.daftarPasien[index].cekLemakTubuh(); break;
                case 6: db.daftarPasien[index].tampilRiwayat(); break;
                case 0: break;
                default: cout << "\nPilihan tidak valid.\n";
            }
        } while(menu != 0);
    }

    // Fungsi untuk menu utama yang pertama kali muncul
    void jalankanProgram() {
        int pilihan;
        do {
            cout << "\n SISTEM MONITORING KESEHATAN";
            cout << "\n1. Tambah Data Pasien\n2. Tampilkan Semua Pasien\n3. Pilih Pasien\n4. Ubah Data Pasien\n5. Hapus Data Pasien\n0. Keluar\nPilihan : ";
            cin >> pilihan;

            switch(pilihan) {
                case 1: db.tambahPasien(); break;
                case 2: db.tampilSemuaPasien(); break;
                case 3: pilihPasien(); break;
                case 4: db.ubahPasien(); break;
                case 5: db.hapusPasien(); break;
                case 0: cout << "\nTerima kasih telah menggunakan program.\n"; break;
                default: cout << "\nPilihan tidak valid.\n";
            }
        } while(pilihan != 0);
    }
};

#endif
