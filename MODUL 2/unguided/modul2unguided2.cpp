#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main(){
    // Deklarasi array
    int blok, baris, kolom;
    cout << "Masukkan jumlah blok : ";
    cin >> blok;

    cout << "Masukkan jumlah baris : ";
    cin >> baris;

    cout << "Masukkan jumlah kolom : ";
    cin >> kolom;
    
    int arr[blok][baris][kolom];
    // Input elemen
    for (int x = 0; x < blok; x++){
        for (int y = 0; y < baris; y++){
            for (int z = 0; z < kolom; z++){
                cout << "Input Array[" << x << "][" << y << "][" << z <<"] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
 // Output Array
 for (int x = 0; x < blok; x++){
    for (int y = 0; y < baris; y++){
        for (int z = 0; z < kolom; z++){
            cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
         }
    }
 }
 cout << endl;

 // Tampilan array
 for (int x = 0; x < blok; x++){
    for (int y = 0; y < kolom; y++){
        for (int z = 0; z < baris; z++){
            cout << arr[x][y][z] << ends;
        }
        cout << endl;
    }
    cout << endl;
 }
}