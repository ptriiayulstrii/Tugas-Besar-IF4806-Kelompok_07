#include <iostream>
#include "mobil.h"
#include "sales.h"
using namespace std;

void userMenu(ListParent &LP, ListChild &LC) {
    int menu;
    do {
        cout << "\n=== MENU USER ===\n";
        cout << "1. Lihat Semua Mobil\n";
        cout << "2. Lihat Semua Sales\n";
        cout << "3. Lihat Sales yang mempromosikan Mobil\n";
        cout << "4. Lihat Mobil yang dipromosikan Sales\n";
        cout << "0. Kembali ke Main Menu\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            viewParent(LP);
        }

        else if (menu == 2) {
            viewChild(LC);
        }

        else if (menu == 3) {
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
            } else {
                cout << "Mobil tidak ditemukan!\n";
            }
        }

        else if (menu == 4) {
            string id;
            cout << "ID Sales: ";
            cin >> id;

            Sales *S = findElemenChild(LC, id);
            if (S != nullptr) {
                cout << "Mobil yang dipromosikan " << S->namaSales << ":\n";
                RelasiM *R = S->child;
                while (R != nullptr) {
                    cout << "- " << R->mobil->namaMobil << endl;
                    R = R->next;
                }
            } else {
                cout << "Sales tidak ditemukan!\n";
            }
        }

    } while (menu != 0);
}
