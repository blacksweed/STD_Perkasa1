#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

void clearInputBuffer();
//I.S: Input buffer mungkin berisi karakter sisa dari operasi input sebelumnya
//F.S: Input buffer dikosongkan hingga karakter newline atau EOF
void pressEnterToContinue();
//I.S: Program berjalan dan menunggu interaksi user
//F.S: Pesan "Press Enter to continue..." ditampilkan, program berhenti sementara hingga user menekan Enter
#endif // UTILS_H_INCLUDED
