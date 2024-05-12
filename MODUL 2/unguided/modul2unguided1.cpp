#include <iostream>

using namespace std;

int dataAngka[10];

int jmlhAngka;
int angka;

int main() {
    cout << "Masukkan jumlah angka yang ingin anda masukkan : ";
    cin >> jmlhAngka;
    if (jmlhAngka > 10){
        cout << "ERROR!! MELEBIHI BATAS MAKSIMUM!!"<<endl;
    }else{
        for ( int i = 0; i < jmlhAngka; i++){
            cout << "Masukkan angka ke " << i + 1<< ": ";
            cin >> angka;
            dataAngka[i] = angka;
        }
        cout << "Data Array : ";
        for ( int i = 0; i < jmlhAngka; i++){
            cout << dataAngka[i] << " ";
        }
        cout << endl;
        cout << "Nomor Genap : ";
        for (int i = 0; i < jmlhAngka; i++){
            if (dataAngka[i] % 2 == 0){
                cout << dataAngka[i] << " ";
            }
        }
        cout << endl;
        cout << "Nomor Ganjil : ";
        for (int i = 0; i < jmlhAngka; i++){
            if ( dataAngka[i] % 2 != 0){
                cout << dataAngka[i] << " ";
            }
        }
    }
    return 0;
}

   
    

