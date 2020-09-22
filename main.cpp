#include "menu.h"

int main(){

    // DEKLARASI PEMBELI
    List_user LU;
    createList_user(LU);
    infotype_user pembeli;
    pembeli.id_user = 0;
    addrUser PU;

    // DEKLARASI RELASI
    addrRelasi PR;
    int jumlahBrg;

    // MEMBUAT LIST BARANG
    List_Barang LB;
    createList_Brg(LB);
    addrBarang PB;
    infotype_barang brg;

    brg.id_barang = 1; brg.nama_barang = "Mie Instan"; brg.harga_barang = 3000; brg.stok_barang = 100;
    createElmn_Brg(PB, brg);
    insertFirst_Brg(LB,PB);
    brg.id_barang = 2; brg.nama_barang = "Kecap Asin"; brg.harga_barang = 16500; brg.stok_barang = 100;
    createElmn_Brg(PB, brg);
    insertFirst_Brg(LB,PB);
    brg.id_barang = 3; brg.nama_barang = "Saus Sambal"; brg.harga_barang = 12500; brg.stok_barang = 100;
    createElmn_Brg(PB, brg);
    insertFirst_Brg(LB,PB);
    brg.id_barang = 4; brg.nama_barang = "Ikan Makarel"; brg.harga_barang = 25000; brg.stok_barang = 100;
    createElmn_Brg(PB, brg);
    insertFirst_Brg(LB,PB);
    brg.id_barang = 5; brg.nama_barang = "Susu"; brg.harga_barang = 2000; brg.stok_barang = 100;
    createElmn_Brg(PB, brg);
    insertFirst_Brg(LB,PB);


    // MENAMPILKAN MENU
    list_menu(LB,PB,brg,LU,PU,pembeli,PR, jumlahBrg);

}
