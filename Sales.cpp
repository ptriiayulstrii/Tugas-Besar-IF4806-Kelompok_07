#include "sales.h"

// membuat list
void createListChild(ListChild &L) {
    L.first = nullptr;
}

Sales* createElemenChild(string id, string nama) {
    Sales *C = new Sales;
    C->idSales = id;
    C->namaSales = nama;
    C->next = nullptr;
    C->child = nullptr;
    return C;
}

void insertFirstChild(ListChild &L, Sales *C) {
    C->next = L.first;
    L.first = C;
}

void insertLastChild(ListChild &L, Sales *C) {
    if (L.first == nullptr) insertFirstChild(L, C);
    else {
        Sales *Q = L.first;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = C;
    }
}

void insertAfterChild(Sales *prec, Sales *C) {
    if (prec != nullptr) {
        C->next = prec->next;
        prec->next = C;
    }
}

void deleteFirstChild(ListChild &L, Sales *&C) {
    if (L.first != nullptr) {
        C = L.first;
        L.first = C->next;
        C->next = nullptr;
    }
}

void deleteLastChild(ListChild &L, Sales *&C) {
    if (L.first == nullptr) return;
    else if (L.first->next == nullptr) deleteFirstChild(L, C);
    else {
        Sales *Q = L.first;
        while (Q->next->next != nullptr) Q = Q->next;
        C = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterChild(Sales *prec, Sales *&C) {
    if (prec != nullptr && prec->next != nullptr) {
        C = prec->next;
        prec->next = C->next;
        C->next = nullptr;
    }
}

Sales* findElemenChild(ListChild L, string id) {
    Sales *C = L.first;
    while (C != nullptr) {
        if (C->idSales == id) return C;
        C = C->next;
    }
    return nullptr;
}

void viewChild(ListChild L) {
    Sales *C = L.first;
    while (C != nullptr) {
        cout << "- " << C->idSales << " | " << C->namaSales << endl;
        C = C->next;
    }
}
