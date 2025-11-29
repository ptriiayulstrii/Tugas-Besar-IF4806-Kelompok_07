#ifndef MOBIL_H
#define MOBIL_H

#include <iostream>
#include <string>
using namespace std;

typedef struct Sales *adrSales;
typedef struct RelasiS *adrRelasiS;
typedef struct Mobil *adrMobil;

struct Mobil {
    string idMobil;
    string namaMobil;
    adrMobil next;
    adrRelasiS child;    // daftar sales yang mempromosikan mobil ini
};

struct RelasiS {
    adrSales sales;
    adrRelasiS next;
};

struct ListParent {
    adrMobil first;
};

// --- FUNCTION & PROCEDURE PARENT (DARI SLIDE) ---
void createListParent(ListParent &L);
adrMobil createElemenParent(string id, string nama);
void insertFirstParent(ListParent &L, adrMobil P);
void insertLastParent(ListParent &L, adrMobil P);
void insertAfterParent(adrMobil prec, adrMobil P);

void deleteFirstParent(ListParent &L, adrMobil &P);
void deleteLastParent(ListParent &L, adrMobil &P);
void deleteAfterParent(adrMobil prec, adrMobil &P);

adrMobil findElemenParent(ListParent L, string id);
void viewParent(ListParent L);

#endif
