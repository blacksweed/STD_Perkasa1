#ifndef USERMENU_H_INCLUDED
#define USERMENU_H_INCLUDED

#include "SongLibrary.h"
#include "Playlist.h"
#include "PlayQueue.h"

void showUserMenu(SongLibrary &lib, Playlist &userPL, PlayQueue &queue);
//I.S: Library lib, Playlist userPL, dan PlayQueue queue terdefinisi
//F.S: Menu user ditampilkan dan pilihan user diproses; playlist dan queue mungkin berubah sesuai operasi yang dipilih (tambah ke playlist/queue, play lagu, dll)
#endif // USERMENU_H_INCLUDED
