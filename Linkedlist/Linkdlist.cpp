#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struct 'mahasiswa'
struct Mahasiswa
{
    string nama;
    string nrp;
    int umur;
    bool jenis_kelamin;
    Mahasiswa* next;
};

// Fungsi untuk menambahkan data mahasiswa ke linked list
void tambahData(Mahasiswa*& head, int& jumlah_data)
{
    if (jumlah_data < 10)
    {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        cout << "Masukkan data mahasiswa ke-" << jumlah_data + 1 << ":" << endl;
        cout << "Nama: ";
        cin >> newMahasiswa->nama;
        cout << "NRP: ";
        cin >> newMahasiswa->nrp;
        cout << "Umur: ";
        cin >> newMahasiswa->umur;
        cout << "Jenis Kelamin (0: Perempuan, 1: Laki-laki): ";
        cin >> newMahasiswa->jenis_kelamin;
        newMahasiswa->next = NULL;

        if (!head)
        {
            head = newMahasiswa;
        }
        else
        {
            Mahasiswa* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newMahasiswa;
        }

        jumlah_data++;
    }
    else
    {
        cout << "Maaf, Anda sudah mencapai batas maksimum (10 data mahasiswa)." << endl;
    }
}

// Fungsi untuk menghapus data mahasiswa dari linked list
void hapusData(Mahasiswa*& head, int& jumlah_data)
{
    if (!head)
    {
        cout << "Tidak ada data mahasiswa yang tersedia." << endl;
        return;
    }

    int indeks_hapus;
    cout << "Masukkan nomor data mahasiswa yang ingin dihapus (1-" << jumlah_data << "): ";
    cin >> indeks_hapus;

    if (indeks_hapus >= 1 && indeks_hapus <= jumlah_data)
    {
        Mahasiswa* toDelete = head;
        if (indeks_hapus == 1)
        {
            head = head->next;
        }
        else
        {
            Mahasiswa* prev = NULL;
            for (int i = 1; i < indeks_hapus; i++)
            {
                prev = toDelete;
                toDelete = toDelete->next;
            }
            prev->next = toDelete->next;
        }

        delete toDelete;
        jumlah_data--;
        cout << "Data mahasiswa telah dihapus." << endl;
    }
    else
    {
        cout << "Nomor data tidak valid." << endl;
    }
}

// Fungsi untuk menampilkan data mahasiswa dari linked list
void tampilkanData(Mahasiswa* head)
{
    if (!head)
    {
        cout << "Tidak ada data mahasiswa yang tersedia." << endl;
        return;
    }

    cout << "\nData Mahasiswa:" << endl;
    int i = 1;
    Mahasiswa* current = head;
    while (current)
    {
        cout << "Data ke-" << i << ":" << endl;
        cout << "Nama: " << current->nama << endl;
        cout << "NRP: " << current->nrp << endl;
        cout << "Umur: " << current->umur << endl;
        cout << "Jenis Kelamin: " << (current->jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
        current = current->next;
        i++;
    }
}

int main()
{
    Mahasiswa* head = NULL;
    int jumlah_data = 0; // Variabel untuk melacak jumlah data mahasiswa yang sudah dimasukkan

    while (true)
    {
        int input_user;

        cout << "\nMenu: " << endl;
        cout << "1. Menambah Data" << endl;
        cout << "2. Menghapus Data" << endl;
        cout << "3. Menampilkan Data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1/2/3/4): ";
        cin >> input_user;

        if (input_user == 1)
        {
            tambahData(head, jumlah_data);
        }
        else if (input_user == 2)
        {
            hapusData(head, jumlah_data);
        }
        else if (input_user == 3)
        {
            tampilkanData(head);
        }
        else if (input_user == 4)
        {
            // Hapus semua data sebelum keluar
            Mahasiswa* current = head;
            while (current)
            {
                Mahasiswa* toDelete = current;
                current = current->next;
                delete toDelete;
            }
            break; // Keluar dari program
        }
        else
        {
            cout << "Menu tidak valid. Silakan masukkan pilihan yang valid." << endl;
        }
    }

    return 0;
}

