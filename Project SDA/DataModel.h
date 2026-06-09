#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <string>

using namespace std;

struct dataPasien {
    int id;
    string nama;
    int umur;
    char jk;
    float berat;
    float tinggi;
};

struct Riwayat {
    string fitur;
    float nilai;
    string status;
};

#endif