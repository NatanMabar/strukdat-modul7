#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct Node;
typedef Node *Address;

struct Node {
    int info;
    Address next;
};

// Stack hanya menyimpan pointer Top; kosong jika Top = nullptr
struct Stack {
    Address Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
Address alokasi(int x);
void dealokasi(Address P);
void push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif
