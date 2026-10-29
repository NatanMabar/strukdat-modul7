#include "stack.h"

int main() {
    Stack S;
    createStack(S);

    int pilihan;
    do {
        cout << "\n=== MENU STACK POINTER (TERURUT) ===" << endl;
        cout << "1. Tambah Terurut" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Keluar" << endl;
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
            pushAscending(S, x);
            cout << x << " berhasil ditambahkan secara terurut." << endl;
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
            clearStack(S);
            cout << "Semua node dilepas. Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
