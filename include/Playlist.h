#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include "Song.h"
#include <iostream>

typedef struct ElmPlaylist *addressPlaylist;

struct ElmPlaylist {
    addressSong songRef; //Jadi fungsi ini tuh nunjuk Lagu ke Library
    addressPlaylist next;
    addressPlaylist prev;
};

struct Playlist{
    addressPlaylist head;
    addressPlaylist tail;
    string name;
};

void createPlaylist (Playlist &P, string name);
//I.S: Playlist P sembarang, name terdefinisi
//F.S: Playlist P terbentuk dengan nama sesuai parameter, head dan tail bernilai NULL
void addSongToPlaylist(Playlist &P, addressSong songPtr);
//I.S: Playlist P terdefinisi (mungkin kosong), songPtr adalah alamat lagu valid dari library
//F.S: Node playlist baru yang mereferensi songPtr ditambahkan ke akhir playlist P
void showPlaylist(Playlist P);
//I.S: Playlist P terdefinisi, mungkin kosong atau berisi referensi lagu
//F.S: Nama playlist dan semua lagu dalam playlist ditampilkan ke layar, atau pesan "Playlist kosong" jika tidak ada lagu
void deleteSongFromPlaylist(Playlist &P, addressSong songRef);
//I.S: Playlist P terdefinisi, songRef adalah alamat lagu yang mungkin ada di playlist
//F.S: Jika node playlist yang mereferensi songRef ditemukan, node tersebut dihapus dari playlist dan memori didealokasi; jika tidak ditemukan, playlist tetap
#endif // PLAYLIST_H_INCLUDED
