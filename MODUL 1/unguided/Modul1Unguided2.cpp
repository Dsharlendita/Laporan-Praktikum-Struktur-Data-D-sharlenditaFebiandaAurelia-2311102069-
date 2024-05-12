//Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
struct Kontak {
    const char *name;
    const char *telpnumber;
};
class Alamatperson1 {
private :
    string alamatkomplek;
    int blokkomplek;

public :
    Alamatperson1(string alamatkomplek, int blokkomplek){
        this -> alamatkomplek = alamatkomplek;
        this -> blokkomplek = blokkomplek;
    }

void tampilkanInfo(){
    cout << "Alamat : " << alamatkomplek << endl;
    cout << "No Blok Komplek : " << blokkomplek << endl;
}
};

int main (){
    struct Kontak person1;
    person1.name = "Dita";
    person1.telpnumber = "082151925262";
    printf ("--- data contact person 1 ---\n");
    printf ("Nama: %s\n", person1.name);
    printf ("Alamat: %s\n", person1.telpnumber);
    Alamatperson1 alamat ("Komplek Taman Bunga Asri", 3);
    alamat.tampilkanInfo();
    return 0;
}
