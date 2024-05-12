#include <iostream>

using namespace std;

int i;
char pil;


int main(){
    cout << "Masukkan jumlah angka yang ingin di inputkan : ";
    cin >> i;
    int arrayJmlhData [i];
    for ( int d = 0; d < i; d++){
             cout << "Masukkan angka ke " << d + 1<< ": ";
            cin >> arrayJmlhData[d];
        }
        cout << "Data Array : ";
        for ( int d = 0; d < i; d++){
            cout << arrayJmlhData[d] << " ";
        }
        cout << endl;
        cout << "\n";
        cout << "| M E N U |\n";
        cout << "\n";
        cout << "a. Cari Nilai Maksimum\n";
        cout << "b. Cari Nilai Minimum\n";
        cout << "c. Cari Nilai Rata-rata\n";
        cout << "\n";

        cout << "Masukkan Pilihan : ";
        cin >> pil;

        switch (pil){
            case 'a':
                {
                    int maksimum = arrayJmlhData[0];
                    for (int d = 0; d < i; d++){
                        if (arrayJmlhData[d] > maksimum){
                            maksimum = arrayJmlhData[d];
                        }
                    }
                    cout << "Nilai Maksimum : "<< maksimum << endl;
                    break;
                }
                
            case 'b':
                {
                    int minimal = arrayJmlhData[0];
                    for ( int d = 0; d < i; d++){
                        if (arrayJmlhData[d] < minimal){
                            minimal = arrayJmlhData[d];
                        }
                    }
                    cout << "Nilai Minimum : " << minimal << endl;
                    break;
                }

            case 'c':
                {
                    float total, rata2;
                    total = 0;
                    for ( int d = 0; d < i; d++){
                        total = total + arrayJmlhData[d];
                    }
                    rata2 = (total/i);
                    cout << "Nilai rata-rata dari " << i << " adalah sebagai berikut : " << rata2;
                    cout << endl;
                    break;
                }
                 default:
                 cout << "Menu tidak tersedia"<< endl;
        }
        return 0;
}




    