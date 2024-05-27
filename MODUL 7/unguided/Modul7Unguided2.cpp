// D'sharlendita Febianda Aurelia
// 2311102069

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    long long NIM;
    Node* next;
};

class QUEUE {
private:
    Node* head;
    Node* tail;
    int maksimalQueue;
    int count;

public:
    QUEUE(int maxQueue) : head(nullptr), tail(nullptr), maksimalQueue(maxQueue), count(0) {}

    // Fungsi untuk memeriksa apakah antrian penuh 
    bool isFull() { 
        return count >= maksimalQueue;
    }

    // Fungsi untuk memeriksa apakah antrian kosong 
    bool isEmpty() { 
        return count == 0;
    }

    // Fungsi untuk menambahkan elemen ke antrian
    void enqueueAntrian(string nama, long long NIM) { 
        if (isFull()) {
            cout << "Antrian penuh" << endl;
            return;
        }
        Node* newNode = new Node{nama, NIM, nullptr};
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
        cout << "Data dengan nama (" << nama << ") ditambahkan" << endl << endl;
    }

    // Fungsi untuk menghapus elemen dari antrian berdasarkan nama
    void dequeueAntrian() {
        cout << "---------------------------------------------------------------" << endl << endl;
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        string namaHapus;
        cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
        cin.ignore();
        getline(cin, namaHapus);

        Node* temp = head;
        Node* prev = nullptr;
        bool found = false;

        while (temp != nullptr) {
            if (temp->nama == namaHapus) {
                found = true;
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                if (temp == tail) {
                    tail = prev;
                }
                delete temp;
                count--;
                cout << "Mahasiswa dengan nama (" << namaHapus << ") telah dihapus" << endl << endl;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!found) {
            cout << "Mahasiswa dengan nama '" << namaHapus << "' tidak ditemukan" << endl << endl;
        }
        cout << "---------------------------------------------------------------" << endl << endl;
    }

    // Fungsi untuk menghitung jumlah elemen dalam antrian
    int countQueue() { 
        return count;
    }

    // Fungsi untuk mengosongkan semua elemen dalam antrian
    void clearQueue() { 
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
        cout << "Semua data di Queue telah dihapus" << endl << endl;
    }

    // Fungsi untuk menampilkan semua elemen dalam antrian
    void viewQueue() {
        cout << "---------------------------------------------------------------" << endl << endl;
        cout << "Data Mahasiswa:" << endl << endl;
        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->nama << " | NIM: " << current->NIM << endl;
            current = current->next;
            index++;
        }
        for (int i = index; i <= maksimalQueue; i++) {
            cout << i << ". (kosong)"<< endl;
        }
        cout << endl;
        cout << "Jumlah antrian = " << countQueue() << endl;
        cout << endl;
        cout << "---------------------------------------------------------------" << endl << endl;
    }
};

int main() {
    const int maksimalQueue = 5; // Batas maksimal antrian
    QUEUE dita(maksimalQueue);
    int pilih;
    string nama;
    long long NIM;

    do {
        cout << endl;
        cout << "Menu:" << endl << endl;
        cout << "---------------------------------------------------------------" << endl << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Lihat Data Mahasiswa Yang Terdaftar Di Queue" << endl;
        cout << "3. Hapus Data Mahasiswa berdasarkan nama" << endl;
        cout << "4. Hapus Seluruh Data Mahasiswa dari Queue" << endl;
        cout << "5. Keluar dari program\n" << endl << endl;
        cout << "---------------------------------------------------------------" << endl << endl;
        cout << "Pilih menu: ";
        cin >> pilih;
        cout << endl;

        switch (pilih) {
            case 1:
                cout << "---------------------------------------------------------------" << endl << endl;
                cout << "Masukan nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukan NIM: ";
                cin >> NIM;
                dita.enqueueAntrian(nama, NIM);
                cout << "---------------------------------------------------------------" << endl << endl;
                break;
            case 2:
                dita.viewQueue();
                break;
            case 3:
                dita.dequeueAntrian();
                break;
            case 4:
                cout << "---------------------------------------------------------------" << endl << endl;
                dita.clearQueue();
                cout << "---------------------------------------------------------------" << endl << endl;
                break;
            case 5:
                cout << "---------------------------------------------------------------" << endl << endl;
                cout << "Terimakasih" << endl << endl; // keluar dari program
                cout << "---------------------------------------------------------------" << endl << endl;
                break;
            default:
                cout << "---------------------------------------------------------------" << endl << endl;
                cout << "Pilihan anda tidak tersedia!" << endl << endl; // jika pilihan tidak valid
                cout << "---------------------------------------------------------------" << endl << endl;
        }
    } while (pilih != 5); // ulangi sampai pengguna memilih untuk keluar

    return 0;
}
