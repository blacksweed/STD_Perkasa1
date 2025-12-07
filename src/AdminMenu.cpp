#include "../include/AdminMenu.h"
#include "../include/Utils.h"
#include <iostream>

using namespace std;

void showAdminMenu(SongLibrary &lib, Playlist &userPL) {
    int choice;
    string id, title, artist, genre, path;
    int year;

    do {
        cout << "\n===================================" << endl;
        cout << "        ADMIN DASHBOARD            " << endl;
        cout << "===================================" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Lihat Library" << endl;
        cout << "3. Hapus Lagu" << endl;
        cout << "4. Cari Lagu (Judul)" << endl;
        cout << "0. Kembali" << endl;
        cout << ">> Pilih: ";
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
        case 1:
            cout << "ID Lagu (Unik): ";
            getline(cin, id);

            if (findSongByID(lib, id) != nullptr) {
                cout << "ID sudah digunakan!" << endl;
            } else {
                cout << "Judul  : "; getline(cin, title);
                cout << "Artis  : "; getline(cin, artist);
                cout << "Genre  : "; getline(cin, genre);
                cout << "Tahun  : "; cin >> year;
                clearInputBuffer();
                cout << "Path File (contoh: C:\\Musik\\lagu.mp3): ";
                getline(cin, path);

                addSongToLibrary(lib, allocateSong(id, title, artist, genre, year, path));
                cout << "Lagu berhasil ditambahkan ke Library!" << endl;
            }
            pressEnterToContinue();
            break;

        case 2:
            showLibrary(lib);
            pressEnterToContinue();
            break;

        case 3:
            cout << "Masukkan ID yang akan dihapus: ";
            getline(cin, id);
            {
                addressSong target = findSongByID(lib, id);
                if (target != nullptr) {
                    deleteSongFromPlaylist(userPL, target);
                    deleteSongFromLibrary(lib, id);
                } else {
                    cout << "ID tidak ditemukan." << endl;
                }
            }
            pressEnterToContinue();
            break;

        case 4:
            cout << "Cari Judul: ";
            getline(cin, title);
            {
                addressSong res = findSongByTitle(lib, title);
                if (res) {
                    cout << "Ditemukan: " << res->info.title
                         << " - " << res->info.artist << endl;
                } else {
                    cout << "Tidak ditemukan." << endl;
                }
            }
            pressEnterToContinue();
            break;
        }
    } while (choice != 0);
}
