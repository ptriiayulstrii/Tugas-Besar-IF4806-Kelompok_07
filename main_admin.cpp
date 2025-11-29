#include <iostream>
#include "mobil.h"
#include "sales.h"
using namespace std;

void adminMenu(ListParent &LP, ListChild &LC) {
    int menu;
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Mobil\n";
        cout << "2. Tambah Sales\n";
        cout << "3. Hubungkan Sales ke Mobil\n";
        cout << "4. Lihat Semua Mobil\n";
        cout << "5. Lihat Semua Sales\n";
        cout << "6. Lihat Sales yang mempromosikan suatu Mobil\n";
        cout << "7. Lihat Mobil yang dipromosikan suatu Sales\n";
        cout << "0. Kembali ke Main Menu\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            string id, nama;
            cout << "ID Mobil : ";
            cin >> id;
            cout << "Nama Mobil : ";
            cin >> nama;
            insertLastParent(LP, createElemenParent(id, nama));
            cout << "Mobil berhasil ditambahkan!\n";
        }

        else if (menu == 2) {
            string id, nama;
            cout << "ID Sales : ";
            cin >> id;
            cout << "Nama Sales : ";
            cin >> nama;
            insertLastChild(LC, createElemenChild(id, nama));
            cout << "Sales berhasil ditambahkan!\n";
        }

        else if (menu == 3) {
            string idS, idM;
            cout << "ID Sales : ";
            cin >> idS;
            cout << "ID Mobil : ";
            cin >> idM;

            Sales *S = findElemenChild(LC, idS);
            Mobil *M = findElemenParent(LP, idM);

            if (S != nullptr && M != nullptr) {
                // tambah relasi sales → mobil
                RelasiM *RM = new RelasiM;
                RM->mobil = M;
                RM->next = S->child;
                S->child = RM;

                // tambah relasi mobil → sales
                RelasiS *RS = new RelasiS;
                RS->sales = S;
                RS->next = M->child;
                M->child = RS;

                cout << "Relasi Sales - Mobil berhasil dibuat!\n";
            } else {
                cout << "Data tidak ditemukan!\n";
            }
        }

        else if (menu == 4) {
            cout << "\nDaftar Mobil:\n";
            viewParent(LP);
        }

        else if (menu == 5) {
            cout << "\nDaftar Sales:\n";
            viewChild(LC);
        }

        else if (menu == 6) {
            string id;
            cout << "ID Mobil: ";
            cin >> id;

            Mobil *M = findElemenParent(LP, id);
            if (M != nullptr) {
                cout << "Sales yang mempromosikan " << M->namaMobil << ":\n";
                RelasiS *R = M->child;
                while (R != nullptr) {
                    cout << "- " << R->sales->namaSales << endl;
                    R = R->next;
                }
            }
        }

        else if (menu == 7) {
            string id;
            cout << "ID Sales: ";
            cin >> id;

            Sales *S = findElemenChild(LC, id);
            if (S != nullptr) {
                cout << "Mobil yang dipromosikan oleh " << S->namaSales << ":\n";
                RelasiM *R = S->child;
                while (R != nullptr) {
                    cout << "- " << R->mobil->namaMobil << endl;
                    R = R->next;
                }
            }
        }

    } while (menu != 0);
}
