#include "../include/Playlist.h"

void createPlaylist(Playlist &P, string name){
    P.head = nullptr;
    P.tail = nullptr;
    P.name = name;
}

void addSongToPlaylist(Playlist &P, addressSong songPtr){
    if (songPtr == nullptr) return;

    addressPlaylist newNode = new ElmPlaylist;
    newNode->songRef = songPtr;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (P.head == nullptr){
        P.head = newNode;
        P.tail = newNode;
    } else {
        newNode->prev = P.tail;
        P.tail->next = newNode;
        P.tail = newNode;
    }
    cout << "Sukses ditambahkan ke Playlist: " << P.name << endl;
}

void showPlaylist(Playlist P){
    if (P.head == nullptr){
        cout << "Playlist '" << P.name << "' Kosong" << endl;
        return;
    }

    addressPlaylist Q = P.head;
    int i = 1;
    cout << "\n=== PLAYLIST: " << P.name << " ===" << endl;

    while (Q != nullptr){
        if (Q->songRef != nullptr){
            cout << i << ". " << Q->songRef->info.title
                 << " - " << Q->songRef->info.artist << endl;
        }
        Q = Q->next;
        i++;
    }
}

void deleteSongFromPlaylist(Playlist &P, addressSong songRef){
    addressPlaylist Q = P.head;

    while (Q != nullptr){
        if (Q->songRef == songRef){
            addressPlaylist temp = Q;
            Q = Q->next;

            if (temp == P.head && temp == P.tail) {
                P.head = nullptr;
                P.tail = nullptr;
            } else if (temp == P.head) {
                P.head = temp->next;
                P.head->prev = nullptr;
            } else if (temp == P.tail) {
                P.tail = temp->prev;
                P.tail->next = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
        } else {
            Q = Q->next;
        }
    }
}
