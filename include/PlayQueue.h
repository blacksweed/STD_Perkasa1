#ifndef PLAYQUEUE_H_INCLUDED
#define PLAYQUEUE_H_INCLUDED
#include "Song.h"
#include <iostream>

typedef struct ElmQueue *addressQueue;

struct ElmQueue {
    addressSong songRef;
    addressQueue next;
};

struct PlayQueue {
    addressQueue head;
    addressQueue tail;
};

void createQueue(PlayQueue &Q);
//I.S: Queue Q sembarang
//F.S: Queue Q terbentuk dan kosong, head dan tail bernilai NULL
bool isQueueEmpty(PlayQueue Q);
//I.S: Queue Q terdefinisi
//F.S: Mengembalikan true jika queue kosong (head == NULL), false jika tidak kosong
void enqueue(PlayQueue &Q, addressSong songPtr);
//I.S: Queue Q terdefinisi (mungkin kosong), songPtr adalah alamat lagu valid
//F.S: Node queue baru yang mereferensi songPtr ditambahkan ke belakang queue (tail)
void dequeue(PlayQueue &Q);
//I.S: Queue Q terdefinisi, mungkin kosong atau berisi elemen
//F.S: Jika queue tidak kosong, elemen terdepan (head) dihapus dari queue dan memori didealokasi; jika kosong, queue tetap
void showQueue(PlayQueue Q);
//I.S: Queue Q terdefinisi, mungkin kosong atau berisi referensi lagu
//F.S: Semua lagu dalam queue ditampilkan ke layar secara berurutan dari head ke tail, atau pesan "Queue kosong" jika tidak ada lagu
#endif // PLAYQUEUE_H_INCLUDED
