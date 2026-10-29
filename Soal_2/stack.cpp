#include "stack.h"

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

Address alokasi(int x) {
    Address P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(Address P) {
    delete P;
}

// Menambah elemen baru pada TOP
void push(Stack &S, int x) {
    Address P = alokasi(x);
    P->next = S.Top;
    S.Top = P;
}

// Mengambil nilai TOP, lalu node dilepas (delete).
// Jika kosong: return false, stack tidak berubah.
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    Address P = S.Top;
    x = P->info;
    S.Top = P->next;
    dealokasi(P);
    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "TOP: (kosong)" << endl;
        return;
    }
    cout << "TOP: ";
    Address P = S.Top;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Urutan menaik dari bawah ke TOP (nilai terbesar di TOP).
// Elemen yang lebih besar dari x dipindah sementara ke stack bantu,
// x di-push, lalu elemen tadi dikembalikan. Nilai sama (duplikat) tidak
// dipindah, sehingga tersimpan sebagai elemen terpisah.
void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);

    int temp;
    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, temp);
        push(bantu, temp);
    }

    push(S, x);

    while (pop(bantu, temp)) {
        push(S, temp);
    }
}

// Melepas seluruh node dan mengembalikan Top ke nullptr
void clearStack(Stack &S) {
    int temp;
    while (pop(S, temp)) {
    }
}
