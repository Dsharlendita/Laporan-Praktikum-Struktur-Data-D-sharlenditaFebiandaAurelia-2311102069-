#include <iostream>
using namespace std;
float r_2311102069;

float hitung_luaslingkaran (float r_2311102069) {
    return 3.14 * r_2311102069 * r_2311102069;
}

float hitung_kelilinglingkaran (float r_2311102069) {
    return 2 * 3.14 * r_2311102069;
}

int main()
{
    cout << " LUAS LINGKARAN DAN KELILING LINGKARAN " << endl;
    cout << "Masukkan jari-jari : ";
    cin >> r_2311102069;
    cout << "luas lingkaran dari jari jari yang telah anda inputkan adalah : " << hitung_luaslingkaran(r_2311102069) << endl;
    cout << "keliling lingkaran dari jari jari yang telah anda inputkan adalah : " << hitung_kelilinglingkaran(r_2311102069) << endl;
    return 0;
}
