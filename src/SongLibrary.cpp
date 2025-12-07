#include "../include/SongLibrary.h"

void createLibrary(SongLibrary& L)
{
    L.first = nullptr;
    L.last  = nullptr;
}

addressSong allocateSong(string id, string title, string artist,
                         string genre, int year, string path)
{
    addressSong P = new ElmSong;
    P->info.id = id;
    P->info.title = title;
    P->info.artist = artist;
    P->info.genre = genre;
    P->info.year = year;
    P->info.filePath = path;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void addSongToLibrary(SongLibrary& L, addressSong P)
{
    if (L.first == nullptr){
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void showLibrary(SongLibrary L)
{
    if (L.first == nullptr) {
        cout << "Library kosong." << endl;
        return;
    }

    addressSong P = L.first;
    cout << "\n=== SONG LIBRARY ===" << endl;
    cout << "ID\t | Judul\t\t\t| Artist" << endl;
    cout << "----------------------------------------------" << endl;

    while (P != nullptr){
        cout << P->info.id << "\t | "
             << P->info.title << "\t | "
             << P->info.artist << endl;
        P = P->next;
    }
    cout << endl;
}

addressSong findSongByID(SongLibrary L, string id)
{
    addressSong P = L.first;
    while (P != nullptr){
        if (P->info.id == id) return P;
        P = P->next;
    }
    return nullptr;
}

addressSong findSongByTitle(SongLibrary L, string title)
{
    addressSong P = L.first;
    while (P != nullptr){
        if (P->info.title == title) return P;
        P = P->next;
    }
    return nullptr;
}

void deleteSongFromLibrary(SongLibrary& L, string id)
{
    addressSong P = findSongByID(L, id);
    if (P == nullptr){
        cout << "ID tidak ditemukan" << endl;
        return;
    }

    if (P == L.first && P == L.last){
        L.first = nullptr;
        L.last = nullptr;
    } else if (P == L.first){
        L.first = P->next;
        L.first->prev = nullptr;
    } else if (P == L.last){
        L.last = P->prev;
        L.last->next = nullptr;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    delete P;
    cout << "Lagu dihapus dari Library" << endl;
}
