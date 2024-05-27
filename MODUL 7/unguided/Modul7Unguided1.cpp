// D'sharlendita Febianda Aurelia
// 2311102069

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;
    int maksimalQueue;
    int count;

public:
    Queue(int maxQueue) : head(nullptr), tail(nullptr), maksimalQueue(maxQueue), count(0) {}

    // Fungsi untuk memeriksa apakah antrian penuh 
    bool isFull() { 
        return count >= maksimalQueue;
    }

    // Fungsi untuk memeriksa apakah antrian kosong 
    bool isEmpty() { 
        return count == 0;
    }

    // Fungsi untuk menambahkan elemen ke antrian
    void enqueueAntrian(string data) { 
        if (isFull()) {
            cout << "Antrian penuh" << endl;
            return;
        }
        Node* newNode = new Node{data, nullptr};
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Fungsi untuk menghapus elemen dari antrian
    void dequeueAntrian() { 
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        if (isEmpty()) {
            tail = nullptr;
        }
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
        cout << "Semua data di Queue telah dihapus" << endl;
    }

    // Fungsi untuk menampilkan semua elemen dalam antrian
    void viewQueue() {
        cout << "Data antrian teller:" << endl;
        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". " << current->data << endl;
            current = current->next;
            index++;
        }
        for (int i = index; i <= maksimalQueue; i++) {
            cout << i << ". (kosong)" << endl;
        }
    }
};

int main() {
    const int maksimalQueue = 5; // Batas maksimal antrian
    Queue antrian(maksimalQueue);

    antrian.enqueueAntrian("Andi");
    antrian.enqueueAntrian("Maya");
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;

    antrian.dequeueAntrian();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;

    antrian.clearQueue();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;

    return 0;
}
