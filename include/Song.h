#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#include <string>
using namespace std;

struct Song {
    string id;
    string title;
    string artist;
    string genre;
    int year;
    string filePath; // Perbaikan: Nama variabel harus "filePath", bukan link folder
};

typedef struct ElmSong *addressSong;

// Node lagu buat DLL
struct ElmSong {
    Song info;       // Perbaikan: Pakai "Song" (S besar) sesuai nama struct di atas
    addressSong next;
    addressSong prev;
};

#endif // SONG_H_INCLUDED
