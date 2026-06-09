// File: Monitoring.h
#ifndef MONITORING_H
#define MONITORING_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <ctime>
#include "Kalkulator.h" // Menghubungkan file Rahmawati

using namespace std;

class Monitoring : public dataKesehatan {
private:
    stack<Riwayat> history;

public:
    void tambahRiwayat(string fitur, float nilai, string status) {
        Riwayat r;
        r.fitur = fitur; r.nilai = nilai; r.status = status;
        history.push(r);
    }

    string statusIMT(float imt) {
        if(imt < 18.5) return "Kurus";
        else if(imt < 25) return "Normal";
        else if(imt < 30) return "Overweight";
        else return "Obesitas";
    }

    string statusAir(float air) {
        if(air < 2000) return "Kurang";
        else if(air <= 3000) return "Cukup";
        else return "Tinggi";
    }

    string statusLemak(float lemak) {
        if(pasien.jk == 'L' || pasien.jk == 'l') {
            if(lemak < 6) return "Lemak Esensial";
            else if(lemak <= 13) return "Atlet";
            else if(lemak <= 17) return "Fit";
            else if(lemak <= 24) return "Ideal";
            else return "Obesitas";
        } else {
            if(lemak < 14) return "Lemak Esensial";
            else if(lemak <= 20) return "Atlet";
            else if(lemak <= 24) return "Fit";
            else if(lemak <= 31) return "Ideal";
            else return "Obesitas";
        }
    }

    string statusTekananDarah(int sistol, int diastol) {
        if(sistol < 120 && diastol < 80) return "Normal";
        else if(sistol >= 120 && sistol <= 129 && diastol < 80) return "Elevated";
        else if((sistol >= 130 && sistol <= 139) || (diastol >= 80 && diastol <= 89)) return "Hipertensi Tahap 1";
        else return "Hipertensi Tahap 2";
    }
    
    void tampilRiwayat() {
        if(history.empty()) { cout << "\nBelum ada riwayat.\n"; return; }
        stack<Riwayat> temp = history;
        cout << "\n===== RIWAYAT KESEHATAN =====\n";
        while(!temp.empty()) {
            Riwayat r = temp.top();
            cout << "\nFitur  : " << r.fitur << "\nNilai  : " << fixed << setprecision(2) << r.nilai << "\nStatus : " << r.status << "\n----------------------";
            temp.pop();
        }
        cout << endl;
    }

    void simpanLaporanTXT(string fitur, float nilai, string status) {
        char pilih;
        cout << "\nSimpan ke file TXT? (Y/N) : ";
        cin >> pilih;
        if(pilih == 'Y' || pilih == 'y') {
            ofstream file("laporan_kesehatan.txt", ios::app);
            time_t sekarang = time(0);
            file << "\n================================\nTanggal : " << ctime(&sekarang)
                 << "ID      : " << pasien.id << "\nNama    : " << pasien.nama << "\nUmur    : " << pasien.umur
                 << "\nJK      : " << pasien.jk << "\nFitur   : " << fitur << "\nNilai   : " << nilai
                 << "\nStatus  : " << status << "\n================================\n";
            file.close();
            cout << "\nData berhasil disimpan.\n";
        }
    }

    void cekIMT() { float imt = hitungIMT(); string status = statusIMT(imt); cout << "\n===== HASIL IMT =====\nIMT     : " << fixed << setprecision(2) << imt << "\nStatus  : " << status << endl; tambahRiwayat("IMT", imt, status); simpanLaporanTXT("IMT", imt, status); }
    void cekBMR() { float bmr = hitungBMR(); cout << "\n===== HASIL BMR =====\nBMR : " << fixed << setprecision(2) << bmr << " kkal/hari\n"; tambahRiwayat("BMR", bmr, "Kebutuhan Kalori"); simpanLaporanTXT("BMR", bmr, "Kebutuhan Kalori"); }
    void cekAir() { float air = hitungAir(); string status = statusAir(air); cout << "\n===== KEBUTUHAN AIR =====\nAir : " << fixed << setprecision(2) << air << " ml/hari\nStatus : " << status << endl; tambahRiwayat("Air", air, status); simpanLaporanTXT("Air", air, status); }
    void cekLemakTubuh() { float lemak = hitungLemakTubuh(); string status = statusLemak(lemak); cout << "\n===== BODY FAT =====\nPersentase Lemak : " << fixed << setprecision(2) << lemak << "%\nStatus : " << status << endl; tambahRiwayat("Body Fat", lemak, status); simpanLaporanTXT("Body Fat", lemak, status); }
    void cekTekananDarah() {
        int sistol, diastol; cout << "\nMasukkan Sistol   : "; cin >> sistol; cout << "Masukkan Diastol : "; cin >> diastol;
        string status = statusTekananDarah(sistol, diastol); cout << "TEKANAN DARAH\nHasil : " << sistol << "/" << diastol << " mmHg\nStatus : " << status << endl;
        tambahRiwayat("Tekanan Darah", sistol, status); simpanLaporanTXT("Tekanan Darah", sistol, status);
    }
};

#endif
