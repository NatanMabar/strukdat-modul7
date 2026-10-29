#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAX_STACK;
}

// Gagal (false) jika penuh; isi dan Top tidak berubah
bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

// Gagal (false) jika kosong; isi, Top, dan x tidak berubah
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

// Menampilkan isi mulai dari TOP
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "TOP: (kosong)" << endl;
        return;
    }
    cout << "TOP: ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

// Membalik isi stack memakai satu stack bantu (lewat push & pop)
void balikStack(Stack &S) {
    Stack bantu;
    createStack(bantu);

    int x;
    // Pindahkan semua elemen: urutan di stack bantu menjadi terbalik
    while (pop(S, x)) {
        push(bantu, x);
    }
    // Stack bantu (sudah terbalik) menjadi isi stack utama
    S = bantu;
}
