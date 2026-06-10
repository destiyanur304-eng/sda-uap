#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include "Monitoring.h" 

using namespace std;

class DatabasePasien {
public:
    Monitoring daftarPasien[100];
    int jumlahPasien = 0;

    int cariPasienByID(int id) {
        for(int i = 0; i < jumlahPasien; i++) {
            if(daftarPasien[i].getData().id == id) return i;
        }
        return -1;
    }

    void tambahPasien() {
        dataPasien p;
        cout << "\n===== TAMBAH PASIEN =====\nID            : "; cin >> p.id;
        if(cariPasienByID(p.id) != -1) { cout << "\nID sudah digunakan!\n"; return; }
        cin.ignore();
        cout << "Nama          : "; getline(cin, p.nama);
        cout << "Umur          : "; cin >> p.umur;
        cout << "Jenis Kelamin (L/P) : "; cin >> p.jk;
        cout << "Berat (kg)    : "; cin >> p.berat;
        cout << "Tinggi (m)    : "; cin >> p.tinggi;
        
        daftarPasien[jumlahPasien].setData(p);
        jumlahPasien++;
        cout << "\nData pasien berhasil ditambahkan.\n";
    }

    void tampilSemuaPasien() {
        if(jumlahPasien == 0) { cout << "\nBelum ada data pasien.\n"; return; }
        cout << "\n===== DAFTAR PASIEN =====\n";
        for(int i = 0; i < jumlahPasien; i++) { daftarPasien[i].tampilData(); }
    }

    void ubahPasien() {
        int id; cout << "\nMasukkan ID Pasien : "; cin >> id;
        int index = cariPasienByID(id);
        if(index == -1) { cout << "\nPasien tidak ditemukan.\n"; return; }
        
        dataPasien p; p.id = id; cin.ignore();
        cout << "Nama Baru          : "; getline(cin, p.nama);
        cout << "Umur Baru          : "; cin >> p.umur;
        cout << "Jenis Kelamin(L/P) : "; cin >> p.jk;
        cout << "Berat Baru (kg)    : "; cin >> p.berat;
        cout << "Tinggi Baru (m)    : "; cin >> p.tinggi;
        
        daftarPasien[index].setData(p);
        cout << "\nData berhasil diubah.\n";
    }

    void hapusPasien() {
        int id; cout << "\nMasukkan ID Pasien : "; cin >> id;
        int index = cariPasienByID(id);
        if(index == -1) { cout << "\nPasien tidak ditemukan.\n"; return; }
        
        for(int i = index; i < jumlahPasien - 1; i++) { daftarPasien[i] = daftarPasien[i + 1]; }
        jumlahPasien--;
        cout << "\nData berhasil dihapus.\n";
    }
};

#endif
