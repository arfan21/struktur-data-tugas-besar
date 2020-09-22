#ifndef LIST_CHILD_BARANG_H_INCLUDED
#define LIST_CHILD_BARANG_H_INCLUDED

//MENGGUNAKAN DOUBLE LINKED LIST

#include <iostream>
#include <iomanip>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct Barang {
    int id_barang;
    string nama_barang;
    int harga_barang;
    int stok_barang;
    int totalTerjual;
};

typedef Barang infotype_barang;
typedef struct elmlist_barang *addrBarang;

struct elmlist_barang{
    infotype_barang info;
    addrBarang next;
    addrBarang prev;
};

struct List_Barang{
    addrBarang first;
    addrBarang last;
};

void createList_Brg(List_Barang &L);
void createElmn_Brg(addrBarang &P, infotype_barang newBrg);
void insertFirst_Brg(List_Barang &L, addrBarang P);
void insertLast_Brg(List_Barang &L, addrBarang P);
void insertAfter_Brg(List_Barang &L, addrBarang prec, addrBarang P);
void deleteFirst_Brg(List_Barang &L, addrBarang &P);
void deleteLast_Brg(List_Barang &L, addrBarang &P);
void deleteAfter_Brg(List_Barang &L, addrBarang prec, addrBarang &P);

addrBarang findElmn_Brg(List_Barang L, infotype_barang namaBrg);
void printInfo_Brg(List_Barang L);
void palingTerjual(List_Barang L);

#endif // LIST_CHILD_BARANG_H_INCLUDED
