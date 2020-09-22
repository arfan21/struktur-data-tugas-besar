#ifndef LIST_PARENT_PEMBELI_H_INCLUDED
#define LIST_PARENT_PEMBELI_H_INCLUDED

//MENGGUNAKAN LIST CIRCULAR

#include <iostream>
#include "list_relasi.h"
#include <iomanip>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info
#define listR(P) P->relasi

struct user {
    int id_user;
    string nama;
};

typedef user infotype_user;
typedef struct elmlist_user *addrUser;

struct elmlist_user{
    infotype_user info;
    List_relasi relasi;
    addrUser next;
};

struct List_user{
    addrUser first;
};

void createList_user(List_user &L);
void createElmn_user(addrUser &P, infotype_user newUser);
void insertFirst_user(List_user &L, addrUser P);
void insertAfter_user(List_user &L, addrUser prec, addrUser P);
void insertLast_user(List_user &L, addrUser P);
void deleteFirst_user(List_user &L, addrUser &P);
void deleteLast_user(List_user &L, addrUser &P);
void deleteAfter_user(List_user &L, addrUser prec, addrUser &P);

addrUser findElmn_User(List_user &L, infotype_user namaUser);
void printInfo_User(List_user L);
void printinfo_brg_ygdibeli(List_Barang LB, List_user LU);

#endif // LIST_PARENT_PEMBELI_H_INCLUDED
