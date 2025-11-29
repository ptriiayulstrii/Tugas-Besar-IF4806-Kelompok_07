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

        // ----- 1. TAMBAH MOBIL -----
        if (menu == 1) {
            string id, nama;
            cout << "ID Mobil : ";
            cin >> id;
            cout << "Nama Mobil : ";
            cin >> nama;

            insertLastParent(LP, createElemenParent(id, nama));
            cout << "Mobil berhasil ditambahkan!\n";
        }

        // ----- 2. TAMBAH SALES -----
        else if (menu == 2) {
            string id, nama;
            cout << "ID Sales : ";
            cin >> id;
            cout << "Nama Sales : ";
            cin >> nama;

            insertLastChild(LC, createElemenChild(id, nama));
            cout << "Sales berhasil ditambahkan!\n";
        }

        // ----- 3. HUBUNGKAN SALES -> MOBIL -----
        else if (menu == 3) {
            string idS, idM;
            cout << "ID Sales : ";
            cin >> idS;
            cout << "ID Mobil : ";
            cin >> idM;

            adrSales S = findElemenChild(LC, idS);
            adrMobil M = findElemenParent(LP, idM);

            if (S != nullptr && M != nullptr) {

                // relasi Sales -> Mobil
                adrRelasiM RM = new RelasiM;
                RM->mobil = M;
                RM->next = S->child;
                S->child = RM;

                // relasi Mobil -> Sales
                adrRelasiS RS = new RelasiS;
                RS->sales = S;
                RS->next = M->child;
                M->child = RS;

                cout << "Relasi Sales - Mobil berhasil dibuat!\n";
            } else {
                cout << "Data tidak ditemukan!\n";
            }
        }

        // ----- 4. LIST MOBIL -----
        else if (menu == 4) {
            cout << "\nDaftar Mobil:\n";
            viewParent(LP);
        }

        // ----- 5. LIST SALES -----
        else if (menu == 5) {
            cout << "\nDaftar Sales:\n";
            viewChild(LC);
        }

        // ----- 6. LIHAT SALES YG PROMOSIKAN MOBIL -----
        else if (menu == 6) {
            string id;
            cout << "ID Mobil: ";
            cin >> id;

            adrMobil M = findElemenParent(LP, id);
            if (M != nullptr) {
                cout << "Sales yang mempromosikan " << M->namaMobil << ":\n";
                adrRelasiS R = M->child;

                if (R == nullptr) cout << "(Belum ada sales)\n";

                while (R != nullptr) {
                    cout << "- " << R->sales->namaSales << endl;
                    R = R->next;
                }
            }
        }

        // ----- 7. LIHAT MOBIL YANG DIPROMOSIKAN SALES -----
        else if (menu == 7) {
            string id;
            cout << "ID Sales: ";
            cin >> id;

            adrSales S = findElemenChild(LC, id);
            if (S != nullptr) {
                cout << "Mobil yang dipromosikan oleh " << S->namaSales << ":\n";
                adrRelasiM R = S->child;

                if (R == nullptr) cout << "(Belum ada mobil)\n";

                while (R != nullptr) {
                    cout << "- " << R->mobil->namaMobil << endl;
                    R = R->next;
                }
            }
        }

    } while (menu != 0);
}
