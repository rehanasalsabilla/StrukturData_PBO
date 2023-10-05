#include <iostream>
#include <map>
#include <limits> // Untuk menggunakan numeric_limits

using namespace std;

map<int, map<string, string> > dataAkun; // Menggunakan map dengan kunci bertipe int

// Hash Function
int hashFunction(string username)
{
    int hash = 0;
    for (int i = 0; i < username.length(); ++i)
    {
        hash += static_cast<int>(username[i]);
    }
    return hash;
}

void registerAkun()
{
    string username, password, fullname;
    cout << "Masukkan Username: " << endl;
    cin >> username;
    cout << "Masukkan Password: " << endl;
    cin >> password;

    // Membersihkan newline dari buffer cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Masukkan Nama Lengkap: " << endl;
    getline(cin, fullname); // Menggunakan getline untuk membaca seluruh baris, termasuk spasi

    int hash_key = hashFunction(username); // Menggunakan username sebagai kunci

    map<string, string> dataDetail;
    dataDetail["password"] = password;
    dataDetail["fullname"] = fullname;

    // Masukkan ke map
    dataAkun[hash_key] = dataDetail;
}

void loginAkun()
{
    string username, password;
    cout << "Masukkan Username: " << endl;
    cin >> username;
    cout << "Masukkan Password: " << endl;
    cin >> password;

    int hash_key = hashFunction(username); // Menggunakan username sebagai kunci

    cout << endl;
    if (dataAkun.find(hash_key) != dataAkun.end())
    {
        if (dataAkun[hash_key]["password"] == password)
        {
            cout << "Login berhasil!" << endl
                 << endl;
            cout << "==== Account Details ====" << endl;
            cout << "Username: " << username << endl;
            cout << "Fullname: " << dataAkun[hash_key]["fullname"] << endl;
        }
        else
        {
            cout << "Login gagal! Password salah." << endl
                 << endl;
        }
    }
    else
    {
        cout << "Login gagal! Username tidak ditemukan." << endl
             << endl;
    }
}

void printAkun()
{
    cout << endl;
    for (map<int, map<string, string> >::iterator it = dataAkun.begin(); it != dataAkun.end(); ++it)
    {
        cout << "Username: " << it->first << "\t" << " Fullname: " << it->second["fullname"] << endl;
    }
}

// Menu
void menu()
{
    while (true)
    {
        int input_user;

        cout << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << endl;
        cout << "Pilih Menu: " << endl;
        cin >> input_user;

        if (input_user == 1)
        {
            registerAkun();
        }
        else if (input_user == 2)
        {
            loginAkun();
        }
        else if (input_user == 3)
        {
            printAkun();
            break;
        }
        else
        {
            cout << "Invalid!" << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}

