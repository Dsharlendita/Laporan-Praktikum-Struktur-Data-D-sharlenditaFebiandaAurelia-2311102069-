#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string nama;
    int usia;
    Node* next;
    Node(string nama, int usia) {
        this->nama = nama;
        this->usia = usia;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

void tambah_depan(string nama, int usia) {
    Node* new_node = new Node(nama, usia);
    new_node->next = head;
    head = new_node;
}

void tambah_belakang(string nama, int usia) {
    Node* new_node = new Node(nama, usia);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

void tambah_tengah(string nama, int usia, int posisi) {
    if (posisi < 1) {
        cout << "Posisi harus lebih besar dari 0." << endl;
        return;
    }
    if (posisi == 1) {
        tambah_depan(nama, usia);
        return;
    }
    Node* new_node = new Node(nama, usia);
    Node* current = head;
    int count = 1;
    while (current != nullptr && count < posisi - 1) {
        current = current->next;
        count++;
    }
    if (current == nullptr) {
        cout << "Posisi melebihi panjang linked list." <<
        endl;
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void hapus(string nama) {
    Node* current = head;
    if (current != nullptr && current->nama == nama) {
        head = current->next;
        delete current;
        return;
    }
    Node* prev = nullptr;
    while (current != nullptr && current->nama != nama) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << nama << " tidak ditemukan dalam linked list."
        << endl;
        return;
    }
    prev->next = current->next;
    delete current;
}

void tampilkan() {
    Node* current = head;
    cout << "Data dalam linked list:" << endl;
    while (current != nullptr) {
        cout << current->nama << "\t" << current->usia <<
        endl;
        current = current->next;
    }
}
};

int main() {
LinkedList linked_list;
char choice;
do {
cout << "\nPilih operasi yang ingin dilakukan:" << endl;
cout << "a. Tambahkan data" << endl;
cout << "b. Hapus data" << endl;
cout << "c. Tambahkan data di tengah" << endl;
cout << "d. Tambahkan data di awal" << endl;
cout << "e. Ubah data" << endl;
cout << "f. Tampilkan seluruh data" << endl;
cout << "g. keluar" << endl;
cout << "Pilihan: ";
cin >> choice;
switch (choice) {
        case 'a': {
            string nama_list[8]; 
            int usia_list[8]; 
            for (int i = 0; i < 8; ++i) {
                cout << "Masukkan nama data ke-" << i + 1 << " : ";
                cin >> nama_list[i];
                cout << "Masukkan umur data ke-" << i + 1 << " : ";
                cin >> usia_list[i];
                linked_list.tambah_belakang(nama_list[i], usia_list[i]);
            }
            break;
        }
        case 'b': {
            string nama_hapus;
            cout << "Masukkan nama yang ingin dihapus: ";
            cin >> nama_hapus;
            linked_list.hapus(nama_hapus);
            break;
        }
        case 'c': {
            string nama_tambah;
            int usia_tambah, posisi;
            cout << "Masukkan nama yang ingin ditambahkan: ";
            cin >> nama_tambah;
            cout << "Masukkan usia yang ingin ditambahkan: ";
            cin >> usia_tambah;
            cout << "Masukkan posisi (indeks) tempat penambahan: ";
            cin >> posisi;
            linked_list.tambah_tengah(nama_tambah, 
            usia_tambah, posisi);
            break;
        }
        case 'd': {
        string nama_tambah_awal;
        int usia_tambah_awal;
        cout << "Masukkan nama yang ingin ditambahkan di awal: ";
        cin >> nama_tambah_awal;
        cout << "Masukkan usia yang ingin ditambahkan di awal: ";
        cin >> usia_tambah_awal;
        linked_list.tambah_depan(nama_tambah_awal, 
        usia_tambah_awal);
        break;
        }
        case 'e':
        {
            string nama_lama, nama_baru;
            int usia_baru;
            cout << "Masukkan nama yang ingin diubah: ";
            cin >> nama_lama;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru;
            cout << "Masukkan usia baru: ";
            cin >> usia_baru;
            linked_list.hapus(nama_lama);
            linked_list.tambah_belakang(nama_baru, usia_baru);
            break;
        }
        case 'f':
        {
            linked_list.tampilkan();
            break;
        }
        case 'g': {
            cout << "Keluar dari program." << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while(choice != 'g');
return 0;
}
