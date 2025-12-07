#include <windows.h>
#include <mmsystem.h>
#include <iostream>

#include "include/SongLibrary.h"
#include "include/Playlist.h"
#include "include/PlayQueue.h"
#include "include/AdminMenu.h"
#include "include/UserMenu.h"
#include "include/Utils.h"

using namespace std;

SongLibrary myLib;
Playlist userPlaylist;
PlayQueue myQueue;

int main() {
    createLibrary(myLib);
    createPlaylist(userPlaylist, "My Daily Mix");
    createQueue(myQueue);


    addSongToLibrary(myLib, allocateSong(
        "S01", "Die On This Hill", "Sienna Spiro", "Pop", 2024,
        "C:\\Users\\LEGION\\Downloads\\ListLagu\\sienna.mp3"
    ));

    addSongToLibrary(myLib, allocateSong(
        "S02", "Goodness Of God", "Jenn Johnson", "Gospel", 2019,
        "C:\\Users\\LEGION\\Downloads\\ListLagu\\goodness.mp3"
    ));

    addSongToLibrary(myLib, allocateSong(
        "S03", "Merry Christmas", "Bleachers", "Holiday", 2023,
        "C:\\Users\\LEGION\\Downloads\\ListLagu\\bleachers.mp3"
    ));

    addSongToLibrary(myLib, allocateSong(
        "S04", "Satu Kali", "Tulus", "Pop Indo", 2022,
        "C:\\Users\\LEGION\\Downloads\\ListLagu\\tulus_satukali.mp3"
    ));

    addSongToLibrary(myLib, allocateSong(
        "S05", "Remedi", "Tulus", "Pop Indo", 2022,
        "C:\\Users\\LEGION\\Downloads\\ListLagu\\tulus_remedi.mp3"
    ));

    addSongToLibrary(myLib, allocateSong(
        "S06", "Jatuh Suka", "Tulus", "Pop Indo", 2022,
        "C:\\Users\\LEGION\\Downloads\\ListLagu\\tulus_jatuhsuka.mp3"
    ));

    addSongToLibrary(myLib, allocateSong(
        "S07", "Interaksi", "Tulus", "Pop Indo", 2022,
        "C:\\Users\\LEGION\\Downloads\\ListLagu\\tulus_interaksi.mp3"
    ));

    int mainChoice;
    do {
        cout << "\n===================================" << endl;
        cout << "   APLIKASI PEMUTAR MUSIK DIGITAL  " << endl;
        cout << "===================================" << endl;
        cout << "1. Masuk sebagai ADMIN" << endl;
        cout << "2. Masuk sebagai USER bisa (Play Music)" << endl;
        cout << "0. KELUAR" << endl;
        cout << ">> Pilih: ";

        if (!(cin >> mainChoice)) {
            cout << "Input error!" << endl;
            cin.clear();
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (mainChoice) {
            case 1: showAdminMenu(myLib, userPlaylist); break;
            case 2: showUserMenu(myLib, userPlaylist, myQueue); break;
            case 0: cout << "Bye!" << endl; break;
            default: cout << "Pilihan salah." << endl;
        }
    } while (mainChoice != 0);

    return 0;
}
