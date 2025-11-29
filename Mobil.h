#ifndef MOBIL_H
#define MOBIL_H

#include <iostream>
#include <string>
using namespace std;

struct Sales;      // forward declaration
struct RelasiS;    // relasi Sales pada Mobil

struct Mobil {
    string idMobil;
    string namaMobil;
    Mobil *next;
    RelasiS *child;    // daftar sales yang mempromosikan mobil ini
};

struct RelasiS {
    Sales *sales;
    RelasiS *next;
};

struct ListParent {
    Mobil *first;
};

// --- FUNCTION & PROCEDURE PARENT (DARI SLIDE) ---
void createListParent(ListParent &L);
Mobil* createElemenParent(string id, string nama);
void insertFirstParent(ListParent &L, Mobil *P);
void insertLastParent(ListParent &L, Mobil *P);
void insertAfterParent(Mobil *prec, Mobil *P);

void deleteFirstParent(ListParent &L, Mobil *&P);
void deleteLastParent(ListParent &L, Mobil *&P);
void deleteAfterParent(Mobil *prec, Mobil *&P);

Mobil* findElemenParent(ListParent L, string id);
void viewParent(ListParent L);

#endif
