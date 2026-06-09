#include <iostream>
#include <string>
using namespace std;

struct pasien
{
    /* data */
};

class dataLengkap{
    protected:
    double berat, tinggi, imt;
    
    public:
    double tinggiM = tinggi / 100;
    imt = berat / (tinggiM*tinggiM);

    void hasilIMT(){
    if (imt < 18.5){ 
            cout << "Kategori: Kekurangan berat badan\n";
        }else if (imt < 25){
            cout << "Kategori: Normal\n";
        }else if (imt < 30){
            cout << "Kategori: Kelebihan berat badan\n";
        }else{
            cout << "Kategori: Obesitas\n";
        } 
    }
};

class menuBMR : public menuIMT {
    public:
    double bmr;
    void hasilBMR(){
        if (imt < 18.5){ 
            bmr = 655 + (9.6 * berat) + (1.8 * tinggi) - (4.7 * 20);
        }else if (imt < 25){
            bmr = 655 + (9.6 * berat) + (1.8 * tinggi) - (4.7 * 20);
        }else if (imt < 30){
            bmr = 655 + (9.6 * berat) + (1.8 * tinggi) - (4.7 * 20);
        }else{
            bmr = 655 + (9.6 * berat) + (1.8 * tinggi) - (4.7 * 20);
        }
    }
};

int main(){
    
}