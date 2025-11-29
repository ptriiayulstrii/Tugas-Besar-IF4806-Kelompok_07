#ifndef SALES_H
#define SALES_H

#include <iostream>
#include <string>
#include "mobil.h"
using namespace std;

typedef struct Sales *adrSales;
typedef struct RelasiM *adrRelasiM;

struct Sales {
    string idSales;
    string namaSales;
    adrSales next;
    adrRelasiM child;   // daftar mobil yang dipromosikan sales ini
};

struct RelasiM {
    adrMobil mobil;
    adrRelasiM next;
};

struct ListChild {
    adrSales first;
};

// --- FUNCTION & PROCEDURE CHILD ---
void createListChild(ListChild &L);
adrSales createElemenChild(string id, string nama);
void insertFirstChild(ListChild &L, adrSales C);
void insertLastChild(ListChild &L, adrSales C);
void insertAfterChild(adrSales prec, adrSales C);

void deleteFirstChild(ListChild &L, adrSales &C);
void deleteLastChild(ListChild &L, adrSales &C);
void deleteAfterChild(adrSales prec, adrSales &C);

adrSales findElemenChild(ListChild L, string id);
void viewChild(ListChild L);

#endif
