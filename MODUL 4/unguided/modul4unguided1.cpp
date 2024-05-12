#include <iostream>
using namespace std;

class Node {
public :
    string nama;
    int nim;
    Node *next;
};

class LinkedListNonCircular {
public :
    Node *head;
    Node *tail;
    Node *current;
    Node *next;


    bool isEmpty() {
        head == nullptr;
        tail == nullptr;
    }

    void insertDepan(string nama, int nim) {
        Node *baru = new Node;
        baru->nama = nama;
        baru -> nim = nim;
        baru->next = nullptr;
        if (isEmpty()) {
            head = tail = baru;
        } else {
            baru->next = head;
            head = baru;
        }
    }

    void insertBelakang(string nama, int nim) {
        Node *baru = new Node;
        baru->nama = nama;
        baru->nim = nim;
        baru->next = nullptr;
        if (isEmpty()) {
            head = tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }

    int hitungList() {
        Node *hitung = head;
        int jumlah = 0;
        while (hitung != NULL) {
            jumlah++;
            hitung = hitung->next;
        }
        return jumlah;
    }

    void insertTengah(string nama, int nim, int posisi) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi diluar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *baru = new Node();
            baru->nama = nama;
            baru -> nim = nim;
            Node *bantu = head;
            int nomor = 1;
            while (nomor < posisi - 1) {
                bantu = bantu->next;
                nomor++;
            }
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }

    void hapusDepan() {
        if (!isEmpty()) {
            Node *hapus = head;
            if (head->next != NULL) {
                head = head->next;
            } else {
                head = tail = NULL;
            }
            delete hapus;
        } else {
            cout << "List kosong!" << endl;
        }
    }

    void hapusBelakang() {
        if (!isEmpty()) {
            Node *hapus = tail;
            if (head != tail) {
                Node *bantu = head;
                while (bantu->next != tail) {
                    bantu = bantu->next;
                }
                tail = bantu;
                tail->next = NULL;
            } else {
                head = tail = NULL;
            }
            delete hapus;
        } else {
            cout << "List kosong!" << endl;
        }
    }

    void hapusTengah(int posisi) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            Node *hapus;
            Node *sebelum = NULL;
            int nomor = 1;
            while (nomor < posisi) {
                sebelum = bantu;
                bantu = bantu->next;
                nomor++;
            }
            hapus = bantu;
            if (sebelum != NULL) {
                sebelum->next = bantu->next;
            } else {
                head = bantu->next;
            }
            delete hapus;
        }
    }

    void ubahDepan(string nama, int nim) {
        if (!isEmpty()) {
            head->nama = nama;
            head -> nim = nim;
        } else {
            cout << "List masih kosong!" << endl;
        }
    }

    void ubahTengah(string nama, int nim, int posisi) {
        if (!isEmpty()) {
            if (posisi < 1 || posisi > hitungList()) {
                cout << "Posisi di luar jangkauan" << endl;
            } else if (posisi == 1) {
                cout << "Posisi bukan posisi tengah" << endl;
            } else {
                Node *bantu = head;
                int nomor = 1;
                while (nomor < posisi) {
                    bantu = bantu->next;
                    nomor++;
                }
                bantu->nama = nama;
                bantu -> nim = nim;
            }
        } else {
            cout << "List masih kosong!" << endl;
        }
    }

    void ubahBelakang(string nama, int nim) {
        if (!isEmpty()) {
            tail->nama = nama;
            tail ->nim = nim;
        } else {
            cout << "List masih kosong!" << endl;
        }
    }

    void clearList() {
        Node *bantu = head;
        Node *hapus;
        while (bantu != NULL) {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = tail = NULL;
        cout << "List berhasil terhapus!" << endl;
    }

     void tampilkan() {
        Node* current = head;
        cout <<"_____" <<endl;
        cout << "|\t" << " DATA MAHASISWA " <<"\t|" << endl;
        cout <<"_____" <<endl;
        cout << "|NAMA \t\t | NIM\t\t|" << endl;
        while (current != nullptr) {
            cout <<"_____" <<endl;
            cout <<"|" << current-> nama << "\t\t" << " | " << current-> nim << "\t" << "|" << endl;
            current = current->next;
        }
        cout <<"_____" << endl;
    }
};


int main() {
    LinkedListNonCircular linked_list;

    
    linked_list.insertDepan("Jawad", 23300001);
    linked_list.insertBelakang("Budi", 23300099);
    linked_list.insertTengah("Dita", 2311102069, 2);
    linked_list.insertTengah("Farrel", 23300003, 3);
    linked_list.insertTengah("Denis", 23300005, 4);
    linked_list.insertTengah("Anis", 23300008, 5);
    linked_list.insertTengah("Bowo", 23300015, 6);
    linked_list.insertTengah("Gahar", 23300040, 7);
    linked_list.insertTengah("Udin", 23300048, 8);
    linked_list.insertTengah("Ucok", 23300050, 9);

    int choice;
    do {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                string nama;
                int nim;
                cout <<"_____" << endl;
                cout << "- Tambah Depan" << endl;
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;   
                linked_list.insertDepan(nama, nim);
                cout << "Data anda telah ditambahkan" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 2: {
                string nama;
                int nim;
                cout <<"_____" << endl;
                cout << "- Tambah Belakang" << endl;
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;   
                linked_list.insertBelakang(nama, nim);
                cout << "Data anda telah ditambahkan" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 3: {
                string nama;
                int nim;
                int posisi;
                cout <<"_____" << endl;
                cout << "- Tambah Tengah" << endl;
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linked_list.insertTengah(nama, nim, posisi);
                cout << "Data anda telah ditambahkan pada posisi ke-" << posisi << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 4: {
                string nama;
                int nim;
                cout <<"_____" << endl;
                cout << "- Ubah Depan" << endl;
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linked_list.ubahDepan(nama, nim);
                cout << "Data anda telah diubah" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 5: {
                string nama;
                int nim;
                cout <<"_____" << endl;
                cout << "- Ubah Belakang" << endl;
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linked_list.ubahBelakang(nama, nim);
                cout << "Data anda telah diubah" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 6: {
                string nama;
                int nim; 
                int posisi;
                cout <<"_____" << endl;
                cout << "- Ubah Tengah" << endl;
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout <<"Masukkan Posisi : ";
                cin >> posisi;
                linked_list.ubahTengah(nama, nim, posisi);
                cout << "Data anda pada posisi ke-" << posisi << " telah diubah" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 7: {
                cout <<"_____" << endl;
                cout << "- Hapus Depan" << endl;
                cout << endl;
                linked_list.hapusDepan();
                cout << "Data anda telah dihapus!" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 8: {
                cout <<"_____" << endl;
                cout << "- Hapus Belakang" << endl;
                cout << endl;
                linked_list.hapusBelakang();
                cout << "Data anda telah dihapus!" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 9: {
                int posisi;
                cout <<"_____" << endl;
                cout << "- Hapus Tengah" << endl;
                cout << endl;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linked_list.hapusTengah(posisi);
                cout << "Data anda pada posisi ke-" <<posisi << "telah diubah" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 10: {
                cout <<"_____" << endl;
                cout << "- Hapus List" << endl;
                cout << endl;
                linked_list.clearList();
                cout << "List data anda telah dihapus!" << endl;
                cout << endl;
                cout <<"_____" << endl;
                break;
            }
            case 11: {
                cout << "- Tampilkan List" << endl;
                cout << endl;
                linked_list.tampilkan();
                break;
            }
            case 0: {
                cout << endl;
                cout << "---Anda telah keluar dari program---" << endl;
                cout << endl;
                break;
            }
            default:
                cout << endl;
                cout << "!Pilihan Anda Tidak Valid!" << endl;
                cout << endl;
        }
    } while (choice != 0);
    return 0;
}
