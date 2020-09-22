#include "list_relasi.h"

void createList(List_relasi &L){
    first(L) = NULL;
}

void createElmn_relasi(addrRelasi &P, infotype_barang brg){
    P = new elmlist_relasi;
    info(P).id_barang = brg.id_barang;
    info(P).nama_barang = brg.nama_barang;
    info(P).harga_barang = brg.harga_barang;
    info(P).stok_barang = brg.stok_barang;
    info(P).totalTerjual = brg.totalTerjual;
    next(P) = NULL;
}

void insertFirst(List_relasi &L, addrRelasi P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List_relasi &L, addrRelasi P){
    addrRelasi Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(addrRelasi prec, addrRelasi P){
    if(prec != NULL){
        next(P) = next(prec);
        next(prec) = P;
    }
}

void deleteFirst(List_relasi &L, addrRelasi &P){
    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(List_relasi &L, addrRelasi &P){
    addrRelasi Q = first(L);
    while(next(next(Q)) != NULL){
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = NULL;
    next(P) = NULL;
}

void deleteAfter(addrRelasi prec, addrRelasi &P){
    if(prec != NULL){
        P = next(prec);
        next(prec) = next(P);
        next(P) = NULL;
    }
}

addrRelasi findElmn_Relasi(List_relasi L, string namaBrg){
    addrRelasi P = first(L);
    while(P != NULL){
        if(info(P).nama_barang == namaBrg){
            return P;
        }
    }
    return NULL;
}
void printInfo_Relasi(List_relasi L){
    int totalHarga = 0;
    addrRelasi P = first(L);
    if(first(L) == NULL){
        cout << "List Kosong" << endl;
    }else{
        cout << "LIST BARANG YANG DIBELI : \n";
        cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
        cout << left << setw(2)<< " "<<setw(3) << "ID" << setw(5) << "|" << setw(25)<< "Nama Barang" << setw(12)<< "|"
        << setw(20) << "Harga Barang" << setw(12) << "|" << setw(20) << "Jumlah Barang" << setw(12) << "|" << endl;
        cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
        while(P != NULL){
            cout << left << setw(2)<< " "<<setw(3) << info(P).id_barang << setw(5) << "|" << setw(25)  << info(P).nama_barang << setw(12)<< "|"
            << setw(20) << info(P).harga_barang << setw(12) << "|" << setw(20) << info(P).stok_barang << setw(12) << "|" << endl;
            totalHarga = totalHarga + info(P).harga_barang;
            P = next(P);
        }
        cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
        cout << left << setw(10) << " " << setw(25)  << "Total Harga"<< setw(12)<< "|"<< setw(15) << " " << setw(37)
        << totalHarga << setw(12) << "|" << endl;
        cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl << endl;
    }
}

addrRelasi cekInfo_Relasi(List_relasi L){
    addrRelasi P = first(L);
    if(first(L) == NULL){
        return NULL;
    }
}
