#include <iostream>
#include "mobil.h"
#include "sales.h"
using namespace std;

void adminMenu(ListParent&, ListChild&);
void userMenu(ListParent&, ListChild&);

int main() {
    ListParent LP;
    ListChild LC;

    createListParent(LP);
    createListChild(LC);

    int menu;

    do {
        cout << "\n=== SISTEM SHOWROOM ===\n";
        cout << "1. Masuk sebagai Admin\n";
        cout << "2. Masuk sebagai User\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1){
            adminMenu(LP, LC);
        }else if (menu == 2){
            userMenu(LP, LC);
        }
    } while (menu != 0);

    return 0;
}
