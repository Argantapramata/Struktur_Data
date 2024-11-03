#include <iostream>
#include <string>
using namespace std;

// Definisi node untuk linked list
struct Node {
    string name;       // Nama mahasiswa
    char gender;       // Jenis kelamin: 'L' (laki-laki), 'P' (perempuan)
    Node* next;        // Pointer ke node berikutnya
    Node* prev;        // Pointer ke node sebelumnya

    // Constructor untuk membuat node baru
    Node(string n, char g) : name(n), gender(g), next(nullptr), prev(nullptr) {}
};

// Kelas LinkedList untuk merepresentasikan lingkaran mahasiswa
class LinkedList {
private:
    Node* head;      // Pointer ke node pertama
    int size;        // Ukuran lingkaran
    const int MAX_SIZE = 20;  // Batas maksimal mahasiswa dalam lingkaran

public:
    // Constructor untuk inisialisasi linked list
    LinkedList() : head(nullptr), size(0) {}

    // Fungsi untuk menambahkan mahasiswa ke lingkaran
    void addStudent(string name, char gender) {
        if (size >= MAX_SIZE) {
            cout << "Lingkaran sudah penuh!" << endl;
            return;
        }
        
        Node* newNode = new Node(name, gender);
        if (!head) {
            head = newNode;
            head->next = head; // Membentuk lingkaran
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        size++;
        cout << name << " telah bergabung dalam lingkaran." << endl;
    }

    // Fungsi untuk menghapus mahasiswa dari lingkaran
    void removeStudent(string name) {
        if (!head) {
            cout << "Lingkaran kosong!" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->name == name) {
                if (temp == head && size == 1) { // Jika hanya ada satu node
                    head = nullptr;
                } else {
                    Node* prevNode = temp->prev;
                    Node* nextNode = temp->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    if (temp == head) head = nextNode;
                }
                delete temp;
                size--;
                cout << name << " telah keluar dari lingkaran." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Mahasiswa dengan nama " << name << " tidak ditemukan!" << endl;
    }

    // Fungsi untuk memisahkan lingkaran berdasarkan jenis kelamin
    void splitCircles() {
        LinkedList maleCircle, femaleCircle;

        Node* temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->gender == 'L') {
                maleCircle.addStudent(temp->name, temp->gender);
            } else if (temp->gender == 'P') {
                femaleCircle.addStudent(temp->name, temp->gender);
            }
            temp = temp->next;
        }

        cout << "Lingkaran Laki-laki: ";
        maleCircle.display();
        cout << "Lingkaran Perempuan: ";
        femaleCircle.display();
    }

    // Fungsi untuk menampilkan mahasiswa dalam lingkaran
    void display() {
        if (!head) {
            cout << "Lingkaran kosong!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->name << " (" << temp->gender << ") -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "Kembali ke awal." << endl;
    }

    // Fungsi untuk menambahkan aturan khusus
    void handleSpecialRules() {
        // Cindy tidak mau bergandengan dengan laki-laki
        removeStudent("Cindy");
        cout << "Cindy tidak ikut bergandengan karena ada laki-laki." << endl;

        // Irsyad dan Arsya selalu bersama, tidak dipisahkan
        addStudent("Irsyad", 'L');
        addStudent("Arsya", 'L');
        cout << "Irsyad dan Arsya selalu bersama dalam lingkaran." << endl;
    }
};

int main() {
    LinkedList circle;

    // Menambahkan beberapa mahasiswa
    circle.addStudent("Alice", 'P');
    circle.addStudent("Bob", 'L');
    circle.addStudent("Cindy", 'P');  // Cindy tidak ingin bergandengan dengan laki-laki
    circle.addStudent("Diana", 'P');
    circle.addStudent("Evan", 'L');

    cout << "\nLingkaran awal:" << endl;
    circle.display();

    // Menghapus Cindy karena tidak ingin bergandengan dengan laki-laki
    circle.handleSpecialRules();

    cout << "\nLingkaran setelah aturan khusus diterapkan:" << endl;
    circle.display();

    // Pisahkan lingkaran menjadi dua
    cout << "\nPisahkan lingkaran berdasarkan jenis kelamin:" << endl;
    circle.splitCircles();

    return 0;
}
