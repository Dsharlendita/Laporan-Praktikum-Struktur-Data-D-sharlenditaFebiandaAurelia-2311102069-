// D'sharlendita Febianda Aurelia
// 2311102069

#include <iostream>
#include <cstdlib> // Untuk menggunakan konstanta EXIT_SUCCESS untuk mengakhiri program
#include <iomanip>

using namespace std;

int sequential_search_count(int data[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int count = sequential_search_count(data, size, target);

    cout << "Data = ";
        for(int x = 0; x<10; x++)
        cout<<setw(3)<<data[x];
    cout << endl << endl;
    cout << "Jumlah angka " << target << " dalam array adalah: " << count << endl;

    return EXIT_SUCCESS; 
}
