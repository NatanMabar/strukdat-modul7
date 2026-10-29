#include "stack.h"

int main() {
    Stack S;
    createStack(S);

    int pilihan;
    do {
        cout << "\n=== MENU STACK ARRAY ===" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = 0;
        }

        switch (pilihan) {
        case 1: {
            int x;
            cout << "Masukkan bilangan bulat: ";
            if (!(cin >> x)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Input tidak valid." << endl;
                break;
            }
            if (push(S, x)) {
                cout << x << " berhasil di-Push." << endl;
            } else {
                cout << "Push ditolak: stack penuh (kapasitas "
                     << MAX_STACK << ")." << endl;
            }
            break;
        }
        case 2: {
            int x;
            if (pop(S, x)) {
                cout << "Nilai yang di-Pop: " << x << endl;
            } else {
                cout << "Pop ditolak: stack kosong." << endl;
            }
            break;
        }
        case 3:
            printInfo(S);
            break;
        case 4:
            balikStack(S);
            cout << "Stack berhasil dibalik." << endl;
            printInfo(S);
            break;
        case 5:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
