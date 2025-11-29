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

        // 1. LIHAT MOBIL
        if (menu == 1) {
            viewParent(LP);
        }

        // 2. LIHAT SALES
        else if (menu == 2) {
            viewChild(LC);
        }

        // 3. LIHAT SALES YG PROMOSI MOBIL
        else if (menu == 3) {
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
            } else {
                cout << "Mobil tidak ditemukan!\n";
            }
        }

        // 4. LIHAT MOBIL YANG DIPROMOSI SALES
        else if (menu == 4) {
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
            } else {
                cout << "Sales tidak ditemukan!\n";
            }
        }

    } while (menu != 0);
}
