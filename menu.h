#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "list_parent_pembeli.h"
#include "list_child_barang.h"
#include "list_relasi.h"
#include <unistd.h>
#include <stdio.h>
#include <string>

void menu_tambah_barang(List_Barang &LB, addrBarang &PB, infotype_barang &brg);
void menu_beli(List_Barang &LB, addrBarang &PB, infotype_barang &brg ,List_user &LU, addrUser &PU, infotype_user &pembeli, addrRelasi &PR, int jumlahBrg);
void menu_hapus_barang(List_Barang &LB, addrBarang &PB, infotype_barang &brg);
void menu_hapus_pembeli(List_user &LU, addrUser &PU, infotype_user &pembeli);
void list_menu(List_Barang &LB, addrBarang &PB, infotype_barang &brg ,List_user &LU, addrUser &PU, infotype_user &pembeli, addrRelasi &PR, int jumlahBrg);

#endif // MENU_H_INCLUDED
