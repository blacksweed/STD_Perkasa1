#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include "../include/UserMenu.h"
#include "../include/Utils.h"

using namespace std;


bool fileExists(const string& path) {
    ifstream file(path);
    return file.good();
}

void showUserMenu(SongLibrary &lib, Playlist &userPL, PlayQueue &queue) {
    int choice;
    string title;

    do {
        cout << "\n===================================" << endl;
        cout << "        USER PLAYLIST MENU         " << endl;
        cout << "===================================" << endl;
        cout << "Playlist Aktif: " << userPL.name << endl;
        cout << "1. Tambah Lagu ke Playlist" << endl;
        cout << "2. Lihat Playlist" << endl;
        cout << "3. Masukkan Playlist ke Antrean" << endl;
        cout << "4. Lihat Antrean" << endl;
        cout << "5. Mainkan Antrean" << endl;
        cout << "0. Kembali" << endl;
        cout << ">> Pilih: ";
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
        case 1:
            showLibrary(lib);
            cout << "Masukkan Judul Lagu: ";
            getline(cin, title);
            {
                addressSong song = findSongByTitle(lib, title);
                if (song != nullptr) {
                    addSongToPlaylist(userPL, song);
                } else {
                    cout << "Lagu tidak ditemukan." << endl;
                }
            }
            pressEnterToContinue();
            break;

        case 2:
            showPlaylist(userPL);
            pressEnterToContinue();
            break;

        case 3:
            {
                addressPlaylist P = userPL.head;
                if (P == nullptr) {
                    cout << "Playlist kosong." << endl;
                } else {
                    while (P != nullptr) {
                        enqueue(queue, P->songRef);
                        P = P->next;
                    }
                    cout << "Semua lagu masuk antrean." << endl;
                }
            }
            pressEnterToContinue();
            break;

        case 4:
            showQueue(queue);
            pressEnterToContinue();
            break;

        case 5:
            if (isQueueEmpty(queue)) {
                cout << "Antrean kosong." << endl;
            } else {
                cout << "\n========================================" << endl;
                cout << "     NOW PLAYING (Lagunya enakkan?)  " << endl;
                cout << "========================================" << endl;

                while (!isQueueEmpty(queue)) {
                    string songTitle = queue.head->songRef->info.title;
                    string songArtist = queue.head->songRef->info.artist;
                    string songPath = queue.head->songRef->info.filePath;

                    cout << "\n>> Sedang memutar: " << songTitle
                         << " - " << songArtist << endl;


                    if (!fileExists(songPath)) {
                        cout << "  File tidak ditemukan!" << endl;
                        cout << "  Path: " << songPath << endl;
                        dequeue(queue);
                        pressEnterToContinue();
                        continue;
                    }

                    mciSendString("close audioPlayer", NULL, 0, NULL);

                    string openCmd = "open \"" + songPath + "\" alias audioPlayer";
                    MCIERROR err = mciSendString(openCmd.c_str(), NULL, 0, NULL);


                    if (err == 0) {
                        cout << "  File berhasil dibuka. Memutar..." << endl;

                        MCIERROR playErr = mciSendString("play audioPlayer wait", NULL, 0, NULL);

                        if (playErr == 0) {
                            cout << "   Lagu selesai diputar!" << endl;
                        } else {
                            char playErrorMsg[256];
                            mciGetErrorString(playErr, playErrorMsg, 256);
                            cout << "   [ERROR] " << playErrorMsg << endl;
                        }

                        // TUTUP PLAYER
                        mciSendString("close audioPlayer", NULL, 0, NULL);
                    } else {
                        char errorMsg[256];
                        mciGetErrorString(err, errorMsg, 256);

                        cout << "   Gagal membuka file!" << endl;
                        cout << "   Pesan: " << errorMsg << endl;
                        cout << "\n   CATATAN:" << endl;
                        cout << "   File mungkin belum diconvert dengan benar." << endl;
                        cout << "   Pastikan sudah convert dengan setting:" << endl;
                        cout << "   - Format: MP3" << endl;
                        cout << "   - Bitrate: 128 kbps" << endl;
                        cout << "   - Sample rate: 44100 Hz" << endl;
                    }

                    dequeue(queue);
                    cout << "\n--------------------------------------" << endl;
                }

                cout << "\n========================================" << endl;
                cout << "      PEMUTARAN SELESAI - QUEUE HABIS   " << endl;
                cout << "========================================" << endl;
            }
            pressEnterToContinue();
            break;
        }
    } while (choice != 0);
}
