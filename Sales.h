#ifndef SALES_H
#define SALES_H

#include <iostream>
#include <string>
using namespace std;

struct Mobil;
struct RelasiM;

struct Sales {
    string idSales;
    string namaSales;
    Sales *next;
    RelasiM *child;   // daftar mobil yang dipromosikan sales ini
};

struct RelasiM {
    Mobil *mobil;
    RelasiM *next;
};

struct ListChild {
    Sales *first;
};

// --- FUNCTION & PROCEDURE CHILD ---
void createListChild(ListChild &L);
Sales* createElemenChild(string id, string nama);
void insertFirstChild(ListChild &L, Sales *C);
void insertLastChild(ListChild &L, Sales *C);
void insertAfterChild(Sales *prec, Sales *C);

void deleteFirstChild(ListChild &L, Sales *&C);
void deleteLastChild(ListChild &L, Sales *&C);
void deleteAfterChild(Sales *prec, Sales *&C);

Sales* findElemenChild(ListChild L, string id);
void viewChild(ListChild L);

#endif
