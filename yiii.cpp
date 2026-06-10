#include <iostream>
using namespace std;

int main() {
    float berat, tinggi, imt;
    float sistolik, diastolik, map;

    // INPUT IMT
    cout << "=== Menghitung IMT ===" << endl;
    cout << "Masukkan berat badan (kg): ";
    cin >> berat;

    cout << "Masukkan tinggi badan (m): ";
    cin >> tinggi;

    // HITUNG IMT
    imt = berat / (tinggi * tinggi);

    cout << "Nilai IMT = " << imt << endl;

    //  IMT
    if (imt < 18.5) {
        cout << "Kategori: Kurus" << endl;
    }
    else if (imt >= 18.5 && imt < 25) {
        cout << "Kategori: Normal" << endl;
    }
    else if (imt >= 25 && imt < 30) {
        cout << "Kategori: Gemuk" << endl;
    }
    else {
        cout << "Kategori: Obesitas" << endl;
    }

    cout << endl;

    // INPUT MAP
    cout << "=== Menghitung MAP ===" << endl;
    cout << "Masukkan tekanan sistolik: ";
    cin >> sistolik;

    cout << "Masukkan tekanan diastolik: ";
    cin >> diastolik;

    // HITUNG MAP
    map = diastolik + (1.0 / 3.0 * (sistolik - diastolik));

    cout << "Nilai MAP = " << map << endl;

    // MAP
    if (map < 70) {
        cout << "Tekanan darah rendah" << endl;
    }
    else if (map >= 70 && map <= 100) {
        cout << "Tekanan darah normal" << endl;
    }
    else {
        cout << "Tekanan darah tinggi" << endl;
    }

    return 0;
}