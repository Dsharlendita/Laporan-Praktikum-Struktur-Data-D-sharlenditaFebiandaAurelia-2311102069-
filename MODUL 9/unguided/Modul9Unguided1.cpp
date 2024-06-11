//D'sharlendita Febianda Aurelia
//2311102069

// Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int jumlah_simpul;
    cout << "Silahkan masukkan jumlah simpul : ";
    cin >> jumlah_simpul;
    vector<string> DsharlenditaFebiandaAurelia_2311102069(jumlah_simpul);
    vector<vector<int>> bobot(jumlah_simpul, vector<int>(jumlah_simpul));
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << "Silahkan masukkan nama simpul " << i + 1 << " : ";
        cin >> DsharlenditaFebiandaAurelia_2311102069[i];
    }
    cout << "Silahkan masukkan bobot antar simpul\n";
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << DsharlenditaFebiandaAurelia_2311102069[i] << "-->" << DsharlenditaFebiandaAurelia_2311102069[j] << " : ";
            cin >> bobot[i][j];
        }
    }
    cout << "\n\t";
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << DsharlenditaFebiandaAurelia_2311102069[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << DsharlenditaFebiandaAurelia_2311102069[i] << "\t";
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << bobot[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
