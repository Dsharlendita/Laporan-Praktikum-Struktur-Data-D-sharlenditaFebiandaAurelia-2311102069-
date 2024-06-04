// D'sharlendita Febianda Aurelia
// 2311102069

#include <iostream>
#include <string>

using namespace std;

struct IndexedChar {
    char character;
    int index;
};

void selection_sort(IndexedChar* indexed_kalimat, int n) {
    int min, i, j;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (indexed_kalimat[j].character < indexed_kalimat[min].character) {
                min = j;
            }
        }
        swap(indexed_kalimat[i], indexed_kalimat[min]);
    }
}


void binarysearch(IndexedChar* indexed_kalimat, int n, char cari) {
    int awal = 0, akhir = n - 1, tengah;
    int found_indices[100]; 
    int found_count = 0; 
    bool found = false;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (indexed_kalimat[tengah].character == cari) {
            found = true;
            found_indices[found_count++] = indexed_kalimat[tengah].index;
            int left = tengah - 1;
            while (left >= awal && indexed_kalimat[left].character == cari) {
                found_indices[found_count++] = indexed_kalimat[left].index;
                left--;
            }
            int right = tengah + 1;
            while (right <= akhir && indexed_kalimat[right].character == cari) {
                found_indices[found_count++] = indexed_kalimat[right].index;
                right++;
            }
            break; 
        } else if (indexed_kalimat[tengah].character < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (found) {
        for (int i = 0; i < found_count - 1; ++i) {
            for (int j = 0; j < found_count - i - 1; ++j) {
                if (found_indices[j] > found_indices[j + 1]) {
                    swap(found_indices[j], found_indices[j + 1]);
                }
            }
        }

        cout << "\nHuruf ditemukan pada index ke- ";
        for (int i = 0; i < found_count; i++) {
            cout << found_indices[i];
            if (i < found_count - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "\nHuruf tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH FOR SEARCHING ALPHABET" << endl;
    cout << "\nMasukkan sebuah kalimat: ";
    string kalimat;
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin anda cari: ";
    char cari;
    cin >> cari;

    int n = kalimat.length();
    IndexedChar indexed_kalimat[100]; 

    for (int i = 0; i < n; ++i) {
        indexed_kalimat[i].character = kalimat[i];
        indexed_kalimat[i].index = i;
    }

    selection_sort(indexed_kalimat, n);

    binarysearch(indexed_kalimat, n, cari);

    return EXIT_SUCCESS;
}
