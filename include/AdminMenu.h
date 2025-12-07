#ifndef ADMINMENU_H_INCLUDED
#define ADMINMENU_H_INCLUDED

#include "SongLibrary.h"
#include "Playlist.h"

void showAdminMenu(SongLibrary &lib, Playlist &userPL);
//I.S: Library lib dan Playlist userPL terdefinisi
//F.S: Menu admin ditampilkan dan pilihan user diproses; library dan playlist mungkin berubah sesuai operasi yang dipilih (tambah/hapus lagu, dll)
#endif // ADMINMENU_H_INCLUDED
