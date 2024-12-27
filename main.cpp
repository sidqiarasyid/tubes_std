#include <iostream>
#include "Sosmed.h"
using namespace std;

int main()
{
    int menuInput;
    infoUser user;
    graph G;
    createGraph(G);

    cout << "Selamat datang di fesbuk" << endl;
    cout << "1. Tambah User" << endl;
    cout << "2. Tambah teman user" << endl;
    cout << "3. Hapus User" << endl;
    cout << "4. Hapus Pertemanan User" << endl;
    cout << "5. Print List User" << endl;
    cout << "6. Print Teman User" << endl;
    cout << "7. Cari User" << endl;
    cout << "8. Tambah Komunitas" << endl;
    cout << "9. Tambah User ke Komunitas" << endl;
    cout << "10. Hapus User dari Komunitas" << endl;
    cout << "11. Print User dalam Komunitas" << endl;
    cout << "Input: ";
    cin >> menuInput;
    cout << endl;

    while(menuInput != 0) {
        if(menuInput == 1) {
            cout << "Masukkan ID User: " << endl;
            cin >> user.userId;
            cout << "Masukkan Nama User: " << endl;
            cin >> user.username;
            cout << "Masukkan Umur User: " << endl;
            cin >> user.userAge;
            adrNode p = createUser(user);
            addUsertoGraph(G, p);

        } else if(menuInput == 2) {
            string user1, user2;
            cout << "Masukkan nama user yang ingin ditambah temannya: " << endl;
            cin >> user1;
            cout << "Masukkan nama dari teman yang ingin ditambahkan: " << endl;
            cin >> user2;
            addFriend(G, user1, user2);
            cout << endl;

        } else if(menuInput == 3) {
            string username;
            cout << "Masukkan nama user yang ingin dihapus: ";
            cin >> username;
            deleteUser(G, username);

        } else if(menuInput == 4) {
            string user1, user2;
            cout << "Masukkan nama user pertama: ";
            cin >> user1;
            cout << "Masukkan nama user kedua (teman yang ingin dihapus): ";
            cin >> user2;
            deleteFriend(G, user1, user2);

        } else if(menuInput == 5) {
            printUser(G);

        } else if(menuInput == 6) {
            string username;
            cout << "Masukkan nama user untuk mengetahui friendlistnya: ";
            cin >> username;
            printUserFriend(username, G);
            cout << endl;

        } else if(menuInput == 7) {
            string username;
            cout << "Masukkan nama user yang ingin dicari: ";
            cin >> username;
            adrNode userNode = findUser(username, G);
            if (userNode != nullptr) {
                cout << "User ditemukan:\n";
                cout << "ID: " << userNode->info.userId << endl;
                cout << "Nama: " << userNode->info.username << endl;
                cout << "Umur: " << userNode->info.userAge << endl;
            } else {
                cout << "User tidak ditemukan.\n";
            }

        } else if(menuInput == 8) {
            string communityName;
            cout << "Masukkan nama komunitas yang ingin dibuat: ";
            cin >> communityName;
            addCommunity(G, communityName);

        } else if(menuInput == 9) {
            string username, communityName;
            cout << "Masukkan nama user yang ingin ditambahkan ke komunitas: ";
            cin >> username;
            cout << "Masukkan nama komunitas: ";
            cin >> communityName;
            addUserToCommunity(G, username, communityName);

        } else if(menuInput == 10) {
            string username, communityName;
            cout << "Masukkan nama user yang ingin dihapus dari komunitas: ";
            cin >> username;
            cout << "Masukkan nama komunitas: ";
            cin >> communityName;
            deleteUserFromCommunity(G, username, communityName);

        } else if(menuInput == 11) {
            string communityName;
            cout << "Masukkan nama komunitas untuk melihat anggotanya: ";
            cin >> communityName;
            printUserInCommunity(communityName, G);

        } else {
            cout << "Input Salah" << endl;
        }
        cout << endl;
        cout << "Selamat datang di fesbuk" << endl;
        cout << "1. Tambah User" << endl;
        cout << "2. Tambah teman user" << endl;
        cout << "3. Hapus User" << endl;
        cout << "4. Hapus Pertemanan User" << endl;
        cout << "5. Print List User" << endl;
        cout << "6. Print Teman User" << endl;
        cout << "7. Cari User" << endl;
        cout << "8. Tambah Komunitas" << endl;
        cout << "9. Tambah User ke Komunitas" << endl;
        cout << "10. Hapus User dari Komunitas" << endl;
        cout << "11. Print User dalam Komunitas" << endl;
        cout << "Input: ";
        cin >> menuInput;
        cout << endl;
    }

    return 0;
}
