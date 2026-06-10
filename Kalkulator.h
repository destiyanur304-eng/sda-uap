#ifndef KALKULATOR_H
#define KALKULATOR_H
#include <iostream>
#include "DataModel.h" 

using namespace std;

class dataKesehatan {
protected:
    dataPasien pasien;

public:
    void setData(dataPasien p) { pasien = p; }
    dataPasien getData() { return pasien; }

    void tampilData() {
        cout << "\nID      : " << pasien.id;
        cout << "\nNama    : " << pasien.nama;
        cout << "\nUmur    : " << pasien.umur;
        cout << "\nJK      : " << pasien.jk;
        cout << "\nBerat   : " << pasien.berat << " kg";
        cout << "\nTinggi  : " << pasien.tinggi << " m";
    }

    float hitungIMT() { return pasien.berat / (pasien.tinggi * pasien.tinggi); }

    float hitungBMR() {
        float tinggiCM = pasien.tinggi * 100;
        if(pasien.jk == 'L' || pasien.jk == 'l') {
            return 88.36 + (13.4 * pasien.berat) + (4.8 * tinggiCM) - (5.7 * pasien.umur);
        } else {
            return 447.6 + (9.2 * pasien.berat) + (3.1 * tinggiCM) - (4.3 * pasien.umur);
        }
    }

    float hitungAir() { return pasien.berat * 35; }

    float hitungLemakTubuh() {
        float imt = hitungIMT();
        if(pasien.jk == 'L' || pasien.jk == 'l') {
            return (1.20 * imt) + (0.23 * pasien.umur) - 16.2;
        } else {
            return (1.20 * imt) + (0.23 * pasien.umur) - 5.4;
        }
    }
};

#endif
