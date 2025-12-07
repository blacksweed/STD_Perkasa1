#include "../include/PlayQueue.h"

void createQueue(PlayQueue& Q)
{
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isQueueEmpty(PlayQueue Q)
{
    return (Q.head == nullptr);
}

void enqueue(PlayQueue& Q, addressSong songPtr)
{
    if (songPtr == nullptr) return;

    addressQueue newNode = new ElmQueue;
    newNode->songRef = songPtr;
    newNode->next = nullptr;

    if (Q.head == nullptr){
        Q.head = newNode;
        Q.tail = newNode;
    } else {
        Q.tail->next = newNode;
        Q.tail = newNode;
    }
}

void dequeue(PlayQueue& Q)
{
    if (isQueueEmpty(Q)) return;

    addressQueue temp = Q.head;
    if (Q.head == Q.tail){
        Q.head = nullptr;
        Q.tail = nullptr;
    } else {
        Q.head = Q.head->next;
    }
    delete temp;
}

void showQueue(PlayQueue Q)
{
    if (isQueueEmpty(Q)){
        cout << "Antrean Kosong" << endl;
        return;
    }

    addressQueue curr = Q.head;
    int i = 1;
    cout << "\n=== ANTREAN PUTAR ===" << endl;

    while (curr != nullptr) {
        if (curr->songRef != nullptr) {
            cout << i << ". " << curr->songRef->info.title
                 << " - " << curr->songRef->info.artist << endl;
        }
        curr = curr->next;
        i++;
    }
}
