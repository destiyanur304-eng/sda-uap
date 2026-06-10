#include <iostream>
using namespace std;

int main() {
    double berat, tinggi, imt, bmr, kalori;
    int umur, aktivitas;
    char ulang, gender;

    do{
        cout << "~~ Welcome to Makronutrien Project ! ~~\n\n";
        cout << "~~ Mengukur IMT & Kalori Untuk Rekomendasi Kesehatan ~~\n\n";
        cout << "HASIL DARI REKOMENDASI KALORI HARIAN INI HANYA SEKEDAR PERKIRAAN\n";
        cout << "KONSULTASIKAN KE AHLI GIZI UNTUK REKOMENDASI YANG PASTI!\n\n";
        cout << "Masukkan berat badan (kg) : ";
        cin >> berat;
        cout << "Masukkan tinggi badan (cm) : ";
        cin >> tinggi;
        cout << "Masukkan umur (tahun) : ";
        cin >> umur;
        cout << "Jenis kelamin (L = pria, P = wanita) : ";
        cin >> gender;

        double tinggiMeter = tinggi / 100.0;
        imt = berat / (tinggiMeter * tinggiMeter);
        cout << "\nHasil IMT Anda: " << imt << endl;
       
        if (imt < 18.5){ 
            cout << "Kategori: Kekurangan berat badan\n";
        }else if (imt < 25){
            cout << "Kategori: Normal\n";
        }else if (imt < 30){
            cout << "Kategori: Kelebihan berat badan\n";
        }else{
            cout << "Kategori: Obesitas\n";
        }
        
        if (gender == 'L' || gender == 'l') {
            bmr = 10 * berat + 6.25 * tinggi - 5 * umur + 5;
        } else if(gender == 'P' || gender == 'p'){
            bmr = 10 * berat + 6.25 * tinggi - 5 * umur - 161;
        }else{
            cout << "Tidak Dikenali. Default: Wanita (P)\n";
            bmr = 10 * berat + 6.25 * tinggi - 5 * umur - 161;
        }
    cout << "\n Pilih tingkat aktivitas:\n";
        cout << "1. Sangat ringan (Hampir tidak beraktivitas, seperti duduk seharian)\n";
        cout << "2. Ringan (Aktivitas ringan 1–3 kali/minggu, seperti jalan santai)\n";
        cout << "3. Sedang (Aktivitas ringan 3–5 kali/minggu, seperti bersepada atau lari pagi)\n";
        cout << "4. Berat (Aktivitas berat setiap hari, seperti Olahraga berat atau latihan intensif)\n";
        cout << "5. Sangat berat (Aktivitas sangat berat 1-2 kali/hari, seperti Atlet atau pekerja lapangan berat)\n";
        cout << "Pilihan: ";
            cin >> aktivitas;

    double faktorAktivitas;
        switch (aktivitas){
            case 1: faktorAktivitas = 1.2; break;
            case 2: faktorAktivitas = 1.375; break;
            case 3: faktorAktivitas = 1.55; break;
            case 4: faktorAktivitas = 1.725; break;
            case 5: faktorAktivitas = 1.9; break;
            default: faktorAktivitas = 1.2; break;
        }
        
    kalori = bmr*faktorAktivitas;
        cout << "Kebutuhan Kalori Harian Anda: " << kalori << "kkal\n";

        cout << "\nRekomendasi: ";
        if (imt < 18.5) {
            cout << "Anda kekurangan berat badan. Tambahkan asupan kalori, perbanyak makanan bergizi";
        } else if (imt < 25){
            cout << "Berat badan anda normal. Pertahankan pola makan sehat dan olahraga teratur.\n";
        } else if (imt < 30) {
            cout << "Anda mengalami kelebihan berat badan. Kurangi asupan kalori (sekitar 300-500 kka)";
        } else {
            cout << "Anda obesitas. Disarankan konsultasi ke ahli gizi, kurangi kalori lebih banyak";
        } 
        
        cout << "\nApakah ingin menghitung lagi? (y/n): ";
            cin >> ulang;
        
    }while  (ulang == 'y' || ulang == 'Y');
        cout << "\nTerima kasih sudah menggunakan program ini!";
    
    return 0;
}