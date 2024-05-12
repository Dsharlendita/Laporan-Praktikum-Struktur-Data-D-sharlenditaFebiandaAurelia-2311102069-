#include <iostream>
#include <string>

using namespace std;

class TokoSkincarePurwokerto {
public:
    string nama_produk;
    int harga;
    TokoSkincarePurwokerto* prev;
    TokoSkincarePurwokerto* next;

    TokoSkincarePurwokerto(string nama_produk, int harga) {
        this->nama_produk = nama_produk;
        this->harga = harga;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
public:
    TokoSkincarePurwokerto* head;

    DoubleLinkedList() {
        head = nullptr;
    }

    void tambah_belakang(string nama_produk, int harga) {
        TokoSkincarePurwokerto* new_node = new TokoSkincarePurwokerto(nama_produk, harga);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        TokoSkincarePurwokerto* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }

    void tambah_posisi(string nama_produk, int harga, int posisi) {
        if (posisi < 1) {
            cout << "Posisi harus lebih besar dari 0." << endl;
            return;
        }
        TokoSkincarePurwokerto* new_node = new TokoSkincarePurwokerto(nama_produk, harga);
        if (posisi == 1 || head == nullptr) {
            new_node->next = head;
            if (head != nullptr) {
                head->prev = new_node;
            }
            head = new_node;
            return;
        }
        TokoSkincarePurwokerto* current = head;
        int count = 1;
        while (current != nullptr && count < posisi - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Posisi melebihi panjang linked list." << endl;
            return;
        }
        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != nullptr) {
            current->next->prev = new_node;
        }
        current->next = new_node;
    }

    void hapus(string nama_produk) {
        TokoSkincarePurwokerto* current = head;
        while (current != nullptr && current->nama_produk != nama_produk) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << nama_produk << " tidak ditemukan." << endl;
            return;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
    }

    void update(string nama_produk_lama, string nama_produk_baru, int harga_baru) {
        TokoSkincarePurwokerto* current = head;
        while (current != nullptr && current->nama_produk != nama_produk_lama) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << nama_produk_lama << " tidak ditemukan." << endl;
            return;
        }
        current->nama_produk = nama_produk_baru;
        current->harga = harga_baru;
        cout << "Produk " << nama_produk_lama << " berhasil diupdate menjadi " << nama_produk_baru << " dengan harga " << harga_baru << endl;
    }

    void tampilkan() {
        TokoSkincarePurwokerto* current = head;
        cout <<"_________________________________" <<endl;
        cout << "| Nama Produk\t|Harga\t\t|" << endl;
        while (current != nullptr) {
            cout <<"_________________________________" <<endl;
            cout <<"| " << current->nama_produk << "\t|" << current->harga << "\t\t" << "|" << endl;
            current = current->next;
        }
        cout <<"_________________________________" <<endl;
    }

    void hapus_seluruh_data() {
        TokoSkincarePurwokerto* current = head;
        while (current != nullptr) {
            TokoSkincarePurwokerto* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
    }
};

int main() {
    DoubleLinkedList linked_list;

    linked_list.tambah_belakang("Originote", 60000);
    linked_list.tambah_belakang("Somethinc", 150000);
    linked_list.tambah_belakang("Skintific", 100000);
    linked_list.tambah_belakang("Wardah", 50000);
    linked_list.tambah_belakang("Hanasui", 30000);

    int choice;
    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string nama_produk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                linked_list.tambah_belakang(nama_produk, harga);
                break;
            }
            case 2: {
                string nama_produk_hapus;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_produk_hapus;
                linked_list.hapus(nama_produk_hapus);
                break;
            }
            case 3: {
                string nama_produk_lama, nama_produk_baru;
                int harga_baru;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama_produk_lama;
                cout << "Masukkan nama produk baru: ";
                cin >> nama_produk_baru;
                cout << "Masukkan harga baru: ";
                cin >> harga_baru;
                linked_list.update(nama_produk_lama, nama_produk_baru, harga_baru);
                break;
            }
            case 4: {
                string nama_produk_tambah;
                int harga_tambah, posisi;
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> nama_produk_tambah;
                cout << "Masukkan harga: ";
                cin >> harga_tambah;
                cout << "Masukkan posisi untuk menambahkan data: ";
                cin >> posisi;
                linked_list.tambah_posisi(nama_produk_tambah, harga_tambah, posisi);
                break;
            }
            case 5: {

                break;
            }
            case 6: {
                linked_list.hapus_seluruh_data();
                cout << "Semua data telah dihapus." << endl;
                break;
            }
            case 7: {
                linked_list.tampilkan();
                break;
            }
            case 8: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 8);

    return 0;
}