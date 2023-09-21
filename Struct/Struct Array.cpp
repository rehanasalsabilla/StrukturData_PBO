#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struct 'mahasiswa'
struct mahasiswa
{
    string nama;
    string nrp;
    int umur;
    bool jenis_kelamin;
};

int main()
{
    struct mahasiswa mhs[10];
    int jumlah_data = 0; // Variabel untuk melacak jumlah data mahasiswa yang sudah dimasukkan

    while (true)
    {
        int input_user;

        cout << "\nMenu: " << endl;
        cout << "1. Menambah Data" << endl;
        cout << "2. Menghapus Data" << endl;
        cout << "3. Mengubah Data" << endl;
        cout << "4. Menampilkan Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> input_user;

        if (input_user == 1)
        {
            if (jumlah_data < 10)
            {
                cout << "Masukkan data mahasiswa ke-" << jumlah_data + 1 << ":" << endl;
                cout << "Nama: ";
                cin >> mhs[jumlah_data].nama;
                cout << "NRP: ";
                cin >> mhs[jumlah_data].nrp;
                cout << "Umur: ";
                cin >> mhs[jumlah_data].umur;
                cout << "Jenis Kelamin (0: Perempuan, 1: Laki-laki): ";
                cin >> mhs[jumlah_data].jenis_kelamin;
                jumlah_data++;
            }
            else
            {
                cout << "Maaf, Anda sudah mencapai batas maksimum (10 data mahasiswa)." << endl;
            }
        }
        else if (input_user == 2)
        {
            int indeks_hapus;
            cout << "Masukkan nomor data mahasiswa yang ingin dihapus (1-" << jumlah_data << "): ";
            cin >> indeks_hapus;

            if (indeks_hapus >= 1 && indeks_hapus <= jumlah_data)
            {
                // Menggeser data ke atas untuk mengisi indeks yang dihapus
                for (int i = indeks_hapus - 1; i < jumlah_data - 1; i++)
                {
                    mhs[i] = mhs[i + 1];
                }
                jumlah_data--;
                cout << "Data mahasiswa telah dihapus." << endl;
            }
            else
            {
                cout << "Nomor data tidak valid." << endl;
            }
        }
        else if (input_user == 3)
        {
            int indeks_ubah;
            cout << "Masukkan nomor data mahasiswa yang ingin diubah (1-" << jumlah_data << "): ";
            cin >> indeks_ubah;

            if (indeks_ubah >= 1 && indeks_ubah <= jumlah_data)
            {
                cout << "Masukkan data mahasiswa baru untuk indeks " << indeks_ubah << ":" << endl;
                cout << "Nama: ";
                cin >> mhs[indeks_ubah - 1].nama;
                cout << "NRP: ";
                cin >> mhs[indeks_ubah - 1].nrp;
                cout << "Umur: ";
                cin >> mhs[indeks_ubah - 1].umur;
                cout << "Jenis Kelamin (0: Perempuan, 1: Laki-laki): ";
                cin >> mhs[indeks_ubah - 1].jenis_kelamin;
                cout << "Data mahasiswa telah diubah." << endl;
            }
            else
            {
                cout << "Nomor data tidak valid." << endl;
            }
        }
        else if (input_user == 4)
        {
            cout << "\nData Mahasiswa:" << endl;
            for (int i = 0; i < jumlah_data; i++)
            {
                cout << "Data ke-" << i + 1 << ":" << endl;
                cout << "Nama: " << mhs[i].nama << endl;
                cout << "NRP: " << mhs[i].nrp << endl;
                cout << "Umur: " << mhs[i].umur << endl;
                cout << "Jenis Kelamin: " << (mhs[i].jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
            }
        }
        else if (input_user == 5)
        {
            break; // Keluar dari program
        }
        else
        {
            cout << "Menu tidak valid. Silakan masukkan pilihan yang valid." << endl;
        }
    }

    return 0;
}

