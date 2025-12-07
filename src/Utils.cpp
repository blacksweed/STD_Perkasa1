#include "../include/Utils.h"
#include <iostream>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pressEnterToContinue() {
    cout << "\nTekan Enter untuk lanjut...";
    cin.get();
}
