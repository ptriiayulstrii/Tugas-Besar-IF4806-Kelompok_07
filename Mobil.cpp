#include "mobil.h"

// membuat list mobil
void createListParent(ListParent &L) {
    L.first = nullptr;
}

// membuat elemen mobil
Mobil* createElemenParent(string id, string nama) {
    Mobil *P = new Mobil;
    P->idMobil = id;
    P->namaMobil = nama;
    P->next = nullptr;
    P->child = nullptr;
    return P;
}

void insertFirstParent(ListParent &L, Mobil *P) {
    P->next = L.first;
    L.first = P;
}

void insertLastParent(ListParent &L, Mobil *P) {
    if (L.first == nullptr) insertFirstParent(L, P);
    else {
        Mobil *Q = L.first;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
    }
}

void insertAfterParent(Mobil *prec, Mobil *P) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteFirstParent(ListParent &L, Mobil *&P) {
    if (L.first != nullptr) {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastParent(ListParent &L, Mobil *&P) {
    if (L.first == nullptr) return;
    else if (L.first->next == nullptr) deleteFirstParent(L, P);
    else {
        Mobil *Q = L.first;
        while (Q->next->next != nullptr) Q = Q->next;
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterParent(Mobil *prec, Mobil *&P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

Mobil* findElemenParent(ListParent L, string id) {
    Mobil *P = L.first;
    while (P != nullptr) {
        if (P->idMobil == id) return P;
        P = P->next;
    }
    return nullptr;
}

void viewParent(ListParent L) {
    Mobil *P = L.first;
    while (P != nullptr) {
        cout << "- " << P->idMobil << " | " << P->namaMobil << endl;
        P = P->next;
    }
}
