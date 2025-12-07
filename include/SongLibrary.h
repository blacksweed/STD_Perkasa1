#ifndef SONGLIBRARY_H_INCLUDED
#define SONGLIBRARY_H_INCLUDED
#include "Song.h"
#include <iostream>

struct SongLibrary{
    addressSong first;
    addressSong last;
};

void createLibrary(SongLibrary &L);
//I.S: Library L sembarang (belum terinisialisasi)
//F.S: Library L terbentuk dan kosong, first dan last bernilai NULL
addressSong allocateSong(string id, string title,string artist, string genre, int year,string path);
//I.S: Parameter id, title, artist, genre, year, dan path terdefinisi
//F.S: Mengembalikan alamat node lagu baru dengan info sesuai parameter, next dan prev bernilai NULL, atau NULL jika alokasi gagal
void addSongToLibrary(SongLibrary &L, addressSong P);
//I.S: Library L mungkin kosong atau berisi data, P adalah alamat node lagu yang valid
//F.S: Node P ditambahkan ke library L di posisi akhir (tail/last)
void showLibrary(SongLibrary L);
//I.S: Library L terdefinisi, mungkin kosong atau berisi data
//F.S: Semua lagu dalam library ditampilkan ke layar (id, title, artist, genre, year, filePath), atau pesan "Library kosong" jika tidak ada lagu
addressSong findSongByID(SongLibrary L, string id);
//I.S: Library L terdefinisi, id terdefinisi
//F.S: Mengembalikan alamat node lagu dengan id yang sesuai, atau NULL jika tidak ditemukan
addressSong findSongByTitle(SongLibrary L, string title);
//I.S: Library L terdefinisi, title terdefinisi
//F.S: Mengembalikan alamat node lagu dengan title yang sesuai, atau NULL jika tidak ditemukan
void deleteSongFromLibrary(SongLibrary &L, string id);
//I.S: Library L terdefinisi dan mungkin berisi lagu dengan id tertentu
//F.S: Jika lagu dengan id ditemukan, node tersebut dihapus dari library dan memori didealokasi; jika tidak ditemukan, library tetap
#endif // SONGLIBRARY_H_INCLUDED
