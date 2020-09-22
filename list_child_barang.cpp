#include "list_child_barang.h"


void createList_Brg(List_Barang &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createElmn_Brg(addrBarang &P, infotype_barang newBrg){
    P = new elmlist_barang;
    info(P).id_barang = newBrg.id_barang;
    info(P).nama_barang = newBrg.nama_barang;
    info(P).harga_barang = newBrg.harga_barang;
    info(P).stok_barang = newBrg.stok_barang;
    info(P).totalTerjual = 0;
    next(P) = NULL;
    prev(P) = NULL;
}

void insertFirst_Brg(List_Barang &L, addrBarang P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast_Brg(List_Barang &L, addrBarang P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter_Brg(List_Barang &L,addrBarang prec, addrBarang P){
    if (prec != NULL){
        if(first(L) == NULL){
            insertFirst_Brg(L,P);
        }else if (prec == last(L)){
            insertLast_Brg(L,P);
        }else{
            next(P) = next(prec);
            prev(P) = prec;
            prev(next(prec)) = P;
            next(prec) = P;
        }
    }else{
        cout << "Elemen tidak ada" << endl;
    }

}

void deleteFirst_Brg(List_Barang &L, addrBarang &P){
    P = first(L);
    if(first(L) == NULL){
        cout << "List Kosong" << endl;
    }else if (next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        prev(next(P)) = NULL;
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast_Brg(List_Barang &L, addrBarang &P){
    if(first(L) == NULL){
        cout<<"List Kosong"<<endl;
    } else if(next(first(L)) == NULL) {
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = last(L);
        last(L) = prev(P);
        next(prev(P)) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfter_Brg(List_Barang &L,addrBarang prec, addrBarang &P){
    if(prec != NULL){
        if(first(L) == NULL){
            cout<<"List Kosong"<<endl;
        }else if(prec == last(L)){
            cout<<"prec elemen terakhir"<<endl;
        }else{
            if(next(prec) == last(L)){
                deleteLast_Brg(L,P);
            }else{
                P = next(prec);
                next(prec) = next(P);
                prev(next(P)) = prec;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }else{
        cout << "Elemen tidak ada" << endl;
    }
}

addrBarang findElmn_Brg(List_Barang L, infotype_barang brg){
    addrBarang P = first(L);
    while(P != NULL){
        if(info(P).id_barang == brg.id_barang){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printInfo_Brg(List_Barang L){
    addrBarang P = last(L);
    if(P == NULL){
        cout << "List Kosong" << endl;
    }else{
        cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
        cout << left << setw(2)<< " "<<setw(3) << "ID" << setw(5) << "|" << setw(25)<< "Nama Barang" << setw(12)<< "|"
        << setw(20) << "Harga Barang" << setw(12) << "|" << setw(20) << "Stok Barang" << setw(12) << "|" << endl;
        cout << "-----+-----------------------------+-------------------------------+-------------------------------+" << endl;
        while(P != NULL){
            if(info(P).stok_barang > 0){
                cout << left << setw(2)<< " "<<setw(3) << info(P).id_barang << setw(5) << "|" << setw(25)  << info(P).nama_barang << setw(12)<< "|"
                << setw(20) << info(P).harga_barang << setw(12) << "|" << setw(20) << info(P).stok_barang << setw(12) << "|" << endl;
            }
            P = prev(P);
        }
        cout << "-----+-----------------------------+-------------------------------+-------------------------------+\n" << endl;
    }
}

void palingTerjual(List_Barang L){
    addrBarang Pmaks;
    addrBarang P = first(L);

    int maks = 0;

    while(P != NULL){
        if(info(P).totalTerjual > maks){
            maks = info(P).totalTerjual;
            Pmaks = P;
        }
        P = next(P);
    }

    int i = 1;
    if(maks != 0){
        //DATA BARANG YANG PALING BANYAK TERJUAL
        cout << setw(30)<< " " << "DATA PENJUALAN" << endl;
        cout << setw(20)<< " " << "BARANG YANG TERJUAL PALING BANYAK" << endl;
        cout << "-----+------+------------------------------------------+----------------------+" << endl;
        cout << left << setw(2)<< " "<<setw(3) << "NO" << setw(3) << "|" << "ID" << setw(2)<< " " << "|" << setw(12)<< " " << setw(30)  << "NAMA BARANG"<< setw(5)<< "|" << setw(10)
        << "Total Terjual" << setw(5)<< " " << "|" << endl;
        cout << "-----+------+------------------------------------------+----------------------+" << endl;
        P = last(L);
        while(P != NULL){
            if(info(P).totalTerjual == maks){
                maks = info(P).totalTerjual;
                Pmaks = P;
                cout << left << setw(2)<< " "<<setw(3) << i << setw(4) << "|" << info(Pmaks).id_barang << setw(2)<< " " << "|" << setw(12)<< " " << setw(30)  << info(Pmaks).nama_barang<< setw(10)<< "|" << setw(13)
                << info(Pmaks).totalTerjual << setw(10) << "|" << endl;
                i++;
            }
            P = prev(P);
        }
        cout << "-----+------+------------------------------------------+----------------------+" << endl;


        // DATA BARANG YANG PALING SEDIKIT TERJUAL
        P = first(L);
        addrBarang Pmins;
        int mins = maks;

        while(P != NULL){

            if(info(P).totalTerjual < mins && info(P).totalTerjual > 0){
                mins = info(P).totalTerjual;
                Pmins = P;
            }
            P = next(P);
        }
        if(mins > 0 && mins != maks){
            cout << endl;
            cout << setw(30)<< " " << "DATA PENJUALAN" << endl;
            cout << setw(20)<< " " << "BARANG YANG TERJUAL PALING SEDIKIT" << endl;
            cout << "-----+------+------------------------------------------+----------------------+" << endl;
            cout << left << setw(2)<< " "<<setw(3) << "NO" << setw(3) << "|" << "ID" << setw(2)<< " " << "|" << setw(12)<< " " << setw(30)  << "NAMA BARANG"<< setw(5)<< "|" << setw(10)
            << "Total Terjual" << setw(5)<< " " << "|" << endl;
            cout << "-----+------+------------------------------------------+----------------------+" << endl;
            P = last(L);
            while(P != NULL){
                if(info(P).totalTerjual == mins){
                    mins = info(P).totalTerjual;
                    Pmins = P;
                    cout << left << setw(2)<< " "<<setw(3) << i << setw(4) << "|" << info(Pmins).id_barang << setw(2)<< " " << "|" << setw(12)<< " " << setw(30)  << info(Pmins).nama_barang<< setw(10)<< "|" << setw(13)
                    << info(Pmins).totalTerjual << setw(10) << "|" << endl;
                    i++;
                }
                P = prev(P);
            }
            cout << "-----+------+------------------------------------------+----------------------+\n" << endl;
        }else{
            cout << endl;
        }

        // DATA BARANG YANG BELUM TERJUAL

        P = last(L);

        cout << setw(30)<< " " << "DATA PENJUALAN" << endl;
        cout << setw(24)<< " " << "BARANG YANG BELUM TERJUAL" << endl;
        cout << "-----+------+------------------------------------------+----------------------+" << endl;
        cout << left << setw(2)<< " "<<setw(3) << "NO" << setw(3) << "|" << "ID" << setw(2)<< " " << "|" << setw(12)<< " " << setw(30)  << "NAMA BARANG"<< setw(5)<< "|" << setw(10)
        << "Total Terjual" << setw(5)<< " " << "|" << endl;
        cout << "-----+------+------------------------------------------+----------------------+" << endl;

        int i = 1;
        while(P != NULL){
            if(info(P).totalTerjual == 0){
                cout << left << setw(2)<< " "<<setw(3) << i << setw(4) << "|" << info(P).id_barang << setw(2)<< " " << "|" << setw(12)<< " " << setw(30)  << info(P).nama_barang<< setw(10)<< "|" << setw(13)
                << info(P).totalTerjual << setw(10) << "|" << endl;
                i++;
            }
            P = prev(P);

        }
        cout << "-----+------+------------------------------------------+----------------------+" << endl;
    }else{
        cout << "*Belum ada barang yang terjual.\n";
    }
}


