#include "list_parent_pembeli.h"

void createList_user(List_user &L){
    first(L) = NULL;
}

void createElmn_user(addrUser &P, infotype_user newUser){
    P = new elmlist_user;
    info(P).id_user = newUser.id_user;
    info(P).nama = newUser.nama;
    createList(listR(P));
    next(P) = NULL;
}

void insertFirst_user(List_user &L, addrUser P){
    addrUser Q = first(L);

    if(Q == NULL){
        first(L) = P;
        next(P) = P;
    }else{
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
void insertAfter_user(List_user &L, addrUser prec, addrUser P){
    if(prec != NULL){
        next(P) = next(prec);
        next(prec) = P;
    }else{
        cout<<"Prec tidak ada"<<endl;
    }
}
void insertLast_user(List_user &L, addrUser P){
    addrUser Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }else{
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }

}

void deleteFirst_user(List_user &L, addrUser &P){
    addrUser Q = first(L);
    if(next(first(L)) == first(L)){
        first(L) = NULL;
    }else if(Q != NULL){
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        P = first(L);
        next(Q) = next(P);
        first(L) = next(P);
        next(P) = NULL;
    }else{
        cout << "List KOSONG\n";
    }
}
void deleteLast_user(List_user &L, addrUser &P){
    addrUser Q = first(L);
    if(next(Q) == first(L)){
        first(L) = NULL;
    }else if(Q != NULL){
        while(next(next(Q) != first(L))){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = first(L);
        next(P) = NULL;
    }else{
        cout << "List KOSONG\n";
    }
}
void deleteAfter_user(List_user &L, addrUser prec, addrUser &P){
    if(prec != NULL){
        if(first(L) == NULL){
            cout << "List KOSONG\n";
        }else{
            P = next(prec);
            next(prec) = next(P);
            next(P) = NULL;
        }

    }else{
        cout << "prec tidak ada\n";
    }
}

addrUser findElmn_User(List_user &L, infotype_user namaUser){
    addrUser P = first(L);
    for(bool end = false;!(end);){
        if(info(P).nama == namaUser.nama){
            return P;
        }
        P = next(P);
        if(next(P) == first(L)){
            if(info(P).nama == namaUser.nama){
                return P;
            }else{
                end = true;
            }
        }
    }
    return NULL;
}

void printInfo_User(List_user L){
    addrUser P = first(L);
    if(first(L) == NULL){
        cout << "======================================================================================================================" << endl;
        cout << "*List pembeli kosong." << endl;
    }else{
        int n = 1;
        do{
            cout << "======================================================================================================================\n" << endl;
            cout << "IDENTITAS PEMBELI KE-" << n << "\n";
            cout << "-----+------------------------+" << endl;
            cout << left << setw(2)<< " "<<setw(3) << "ID" << setw(5) << "|" << setw(20)<< "Nama" << setw(12)<< "|"<< endl;
            cout << "-----+------------------------+" << endl;
            cout << left << setw(2)<< " "<<setw(3) << info(P).id_user << setw(5) << "|" << setw(20)<< info(P).nama << setw(12)<< "|"<< endl;
            cout << "-----+------------------------+" << endl;
            printInfo_Relasi(listR(P));
            P = next(P);
            n++;
        }while(P!= first(L));
    }
    cout << "======================================================================================================================\n" << endl;

}

void printinfo_brg_ygdibeli(List_Barang LB, List_user LU){
    addrUser PU = first(LU);
    addrBarang PB = last(LB);
    addrRelasi PR;

    if(PU == NULL){
        cout << "\n======================================================================================================================" << endl;
        cout << "*Belum ada barang yang terjual." << endl;
    }else{
        while(PB != NULL){
            if(info(PB).totalTerjual != 0){
                cout << "\n======================================================================================================================\n" << endl;
                cout << "NAMA BARANG\n";
                cout << "-----+------------------------+" << endl;
                cout << left << setw(2) << " " << setw(3) << "ID" << setw(5) << "|" << setw(20)<< "Nama" << setw(12)<< "|"<< endl;
                cout << "-----+------------------------+" << endl;
                cout << left << setw(2) << " " << setw(3) << info(PB).id_barang << setw(5) << "|" << setw(20)<< info(PB).nama_barang << setw(12)<< "|"<< endl;
                cout << "-----+------------------------+" << endl;

                cout << "LIST PEMBELI : \n";
                cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
                cout << left << setw(2)<< " " << setw(3) << "ID" << setw(5) << "|" << setw(25)<< "Nama Pembeli" << setw(10)<< "|"
                << setw(22) << "Jumlah Barang" << setw(8) << "|" << setw(24) << "Sisa Stok Barang" << setw(12) << "|" << endl;
                cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
                do{
                    PR = first(listR(PU));

                    while(PR != NULL){
                       if(info(PB).nama_barang == info(PR).nama_barang){
                            cout << left << setw(2) << " " << setw(3) << info(PU).id_user << setw(5) << "|" << setw(25)<< info(PU).nama << setw(16)<< "|"
                            << setw(16) <<  info(PR).stok_barang << setw(15) << "|" << setw(17) <<  info(PB).stok_barang << setw(12) << "|" << endl;
                       }
                       PR = next(PR);
                    }
                    PU = next(PU);

                }while(PU != first(LU));
                cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
            }
            PB = prev(PB);
        }
    }
    cout << "\n======================================================================================================================\n" << endl;
}
