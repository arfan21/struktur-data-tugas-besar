#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

//MENGGUNAKAN SINGLE LINKED LIST

#include "list_child_barang.h"
#include <iostream>
#include <iomanip>
using namespace std;

//LIST RELASI ANTARA PEMBELI DAN BARANG

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef struct elmlist_relasi *addrRelasi;

struct elmlist_relasi{
    infotype_barang info;
    addrRelasi next;
};

struct List_relasi{
    addrRelasi first;
};


void createList(List_relasi &L);
void createElmn_relasi(addrRelasi &P,infotype_barang brg);
void insertFirst(List_relasi &L, addrRelasi P);
void insertLast(List_relasi &L, addrRelasi P);
void insertAfter(addrRelasi prec, addrRelasi P);
void deleteFirst(List_relasi &L, addrRelasi &P);
void deleteLast(List_relasi &L, addrRelasi &P);
void deleteAfter(addrRelasi prec, addrRelasi &P);

addrRelasi findElmn_Relasi(List_relasi L, string namaBrg);
void printInfo_Relasi(List_relasi L);
addrRelasi cekInfo_Relasi(List_relasi L);
#endif // LIST_RELASI_H_INCLUDED
