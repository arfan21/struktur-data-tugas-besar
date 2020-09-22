#include "menu.h"

void menu_tambah_barang(List_Barang &LB, addrBarang &PB, infotype_barang &brg){
     int jawab;
     do{// MENAMBAHKAN BARANG
        system("CLS");
        cout << "- Tambah Barang -\n" << endl;
        cout << "Isi keterangan barang:\nNama Barang  > ";
        cin.ignore();
        getline(cin, brg.nama_barang);
        cout << "Harga Barang > ";
        cin >> brg.harga_barang;
        while(brg.harga_barang <= 0){// JIKA INPUT HARGA BARANG <= 0
            system("CLS");
            cout << "- Tambah Barang -\n" << endl;
            cout << "Isi keterangan barang:\nNama Barang  > " << brg.nama_barang << endl;
            cout << "\n*Input harga barang tidak boleh kurang dari sama dengan 0. Silakan coba lagi.\n\nHarga Barang > ";
            cin >> brg.harga_barang;
        }
        cout << "Stok Barang  > ";
        cin >> brg.stok_barang;
        while(brg.stok_barang <= 0){// JIKA INPUT STOK BARANG <= 0
            system("CLS");
            cout << "- Tambah Barang -\n" << endl;
            cout << "Isi keterangan barang:\nNama Barang  > " << brg.nama_barang << endl;
            cout << "Harga Barang > " << brg.harga_barang << endl;
            cout << "\n*Input stok barang tidak boleh kurang dari sama dengan 0. Silakan coba lagi.\n\nStok Barang  > ";
            cin >> brg.stok_barang;
        }

        // KONFIRMASI TAMBAH BARANG

        cout << "\nYakin ingin menambahkan data barang '" << brg.nama_barang << "' ke List Barang?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
        while(jawab != 1 && jawab != 2){
            system("CLS");
            cout << "- Tambah Barang -\n" << endl;
            cout << "Isi keterangan barang:\nNama Barang  > " << brg.nama_barang << endl;
            cout << "Harga Barang > " << brg.harga_barang << endl;
            cout << "Stok Barang  > " << brg.stok_barang << endl;
            cout << "\nYakin ingin menambahkan data barang '" << brg.nama_barang << "' ke List Barang?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
        }

        // JIKA YAKIN UNTUK MENAMBAHKAN DATA BARANG KE LIST BARANG
        if(jawab == 1){
            cout << "\n*Saving..." << endl;
            brg.id_barang++;
            createElmn_Brg(PB, brg);
            insertFirst_Brg(LB,PB);
            sleep(1);
            system("CLS");
            cout << "Sukses menambahkan barang.\n\n";
            printInfo_Brg(LB);

            // APABILA INGIN MENAMBAH BARANG LAGI TANPA KEMBALI KE MENU AWAL
            cout << "Ingin tambah barang lagi?\n1. Ya\n2. Tidak\n\nPilih (angka) > "; cin >> jawab;
            while(jawab != 2 && jawab != 1){
                system("CLS");
                cout << endl << endl;
                printInfo_Brg(LB);
                cout << "*Maaf, input salah. Silakan coba lagi.\n" << endl;
                cout << "Ingin tambah barang lagi?\n1. Ya\n2. Tidak\n\nPilih (angka) > "; cin >> jawab;
            }

        // JIKA TIDAK JADI MENAMBAHKAN DATA BARANG KE LIST BARANG
        }else{
            system("CLS");
            cout << "Tidak ada data barang yang ditambahkan ke List Barang.\n" << endl;
            printInfo_Brg(LB);

            // APABILA INGIN MENAMBAH BARANG TANPA KEMBALI KE MENU AWAL
            cout << "Ingin kembali untuk menambah barang?\n1. Ya\n2. Tidak\n\nPilih (angka) > "; cin >> jawab;
            while(jawab != 2 && jawab != 1){
                system("CLS");
                cout << endl << endl;
                printInfo_Brg(LB);
                cout << "*Maaf, input salah. Silakan coba lagi.\n" << endl;
                cout << "Ingin kembali untuk menambah barang?\n1. Ya\n2. Tidak\n\nPilih (angka) > "; cin >> jawab;
            }
        }

    }while(jawab != 2);// KEMBALI KE MENU AWAL

    cout << endl << "*Loading...";
    sleep(1);
    system("CLS");
}

void menu_beli(List_Barang &LB, addrBarang &PB, infotype_barang &brg ,List_user &LU, addrUser &PU, infotype_user &pembeli, addrRelasi &PR, int jumlahBrg){
    int menu, jawab;

    // MENAMBAHKAN PEMBELI
    pembeli.id_user++;
    system("CLS");
    cout << "- Beli -\n" << endl;
    cout << "Isi identitas pembeli:\nNama Pembeli > ";
    cin.ignore();
    getline(cin, pembeli.nama);
    createElmn_user(PU, pembeli);
    insertLast_user(LU, PU);
    cout << "\n*Processing..." << endl;
    sleep(1);

    // MENAMBAHKAN BARANG KE LIST RELASI
    do{
        system("CLS");
        cout << "- Beli -\n" << endl;
        cout << "Nama Pembeli > " << pembeli.nama << endl << endl;
        printInfo_Brg(LB);
        cout << "Pilih barang yang mau dibeli:\nID Barang (angka) > ";
        cin >> brg.id_barang;

        // MENGECEK BARANG ADA ATAU TIDAK

        PB = findElmn_Brg(LB, brg);

        for(;PB == NULL;){
            system("CLS");
            cout << "- Beli -\n" << endl;
            cout << "Nama Pembeli > " << pembeli.nama << endl << endl;
            printInfo_Brg(LB);
            cout << "*Barang tidak ada atau salah input ID barang.";
            cout << "\n\nPilih barang yang mau dibeli:\nID Barang (angka) > ";
            cin >> brg.id_barang;
            PB = findElmn_Brg(LB, brg);
        }

        cout << "Jumlah Barang     > ";
        cin >> jumlahBrg;

        // KALAU JUMLAH BARANG YANG DIBELI = ATAU > STOK BARANG
        while(jumlahBrg > info(PB).stok_barang || jumlahBrg <= 0){
            system("CLS");
            cout << "- Beli -\n" << endl;
            cout << "Nama Pembeli > " << pembeli.nama << endl << endl;
            printInfo_Brg(LB);
            if(jumlahBrg > info(PB).stok_barang){
                cout << "Pilih barang yang mau dibeli:\nID Barang (angka) > " << brg.id_barang << endl;
                cout << "\n*Maaf jumlah barang yang akan dibeli melebihi stok barang yang tersedia. Silakan coba lagi.\n\nJumlah Barang     > ";
                cin >> jumlahBrg;
            }else if(jumlahBrg <= 0){
                cout << "Pilih barang yang mau dibeli:\nID Barang (angka) > " << brg.id_barang << endl;
                cout << "\n*Maaf input ditolak. Silakan coba lagi.\n\nJumlah Barang     > ";
                cin >> jumlahBrg;
            }
        }

        // KONFIRMASI PEMBELIAN

        cout << "\nYakin untuk melakukan transaksi pembelian?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
        while(jawab != 1 && jawab != 2){
            system("CLS");
            cout << "- Beli -\n" << endl;
            cout << "Nama Pembeli > " << pembeli.nama << endl << endl;
            printInfo_Brg(LB);
            cout << "Pilih barang yang mau dibeli:\nID Barang (angka) > " << brg.id_barang << endl;
            cout << "Jumlah Barang     > " << jumlahBrg << endl;
            cout << "\n*Maaf, input salah. Silakan coba lagi." << endl;
            cout << "\nYakin untuk melakukan transaksi pembelian?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
        }

        // JIKA YAKIN UNTUK MELAKUKAN TRANSAKSI PEMBELIAN
        if(jawab == 1){

            // MENAMBAHKAN BARANG KE RELASI
            brg.nama_barang = info(PB).nama_barang; brg.harga_barang = info(PB).harga_barang * jumlahBrg; brg.stok_barang = jumlahBrg;
            brg.totalTerjual = 0;
            info(PB).stok_barang = info(PB).stok_barang - jumlahBrg; info(PB).totalTerjual = info(PB).totalTerjual + jumlahBrg;

            createElmn_relasi(PR,brg);
            insertLast(listR(PU),PR);

            // MELANJUTKAN BELANJA ATAU BERHENTI
            cout << "\nMau:\n1. Lanjut belanja\n2. Checkout\n";
            cout << "Pilih menu (angka) > ";
            cin >> menu;

            while(menu != 1 && menu != 2){
                system("CLS");
                cout << "- Beli -\n" << endl;
                cout << "Nama Pembeli > " << pembeli.nama << endl << endl;
                printInfo_Brg(LB);
                cout << "Pilih barang yang mau dibeli:\nID Barang (angka) > " << brg.id_barang << endl;
                cout << "Jumlah Barang     > " << jumlahBrg << endl;
                cout << "\nYakin untuk melakukan transaksi pembelian?\n1. Ya\n2. Tidak\nPilih (angka) > 1" << endl;
                cout << "\n*Maaf, input salah. Silakan coba lagi.\n" << endl;
                cout << "Mau:\n1. Lanjut belanja\n2. Checkout\n";
                cout << "Pilih menu (angka) > ";
                cin >> menu;
            }
            cout << "\n*Saving...";
            sleep(1);
            system("CLS");
            cout << "- Beli -\n" << endl;
            cout << "Nama Pembeli > " << pembeli.nama << endl << endl;
            printInfo_Relasi(listR(PU));
            system("PAUSE");

        // JIKA BATAL MELAKUKAN TRANSAKSI PEMBELIAN
        }else{
            PR = cekInfo_Relasi(listR(PU));
            if(PR == NULL){// APABILA LIST RELASI PADA PEMBELI KOSONG
                addrUser Q = first(LU);
                while(next(Q) != PU){
                    Q = next(Q);
                }
                deleteAfter_user(LU, Q, PU);// MENGHAPUS DATA PEMBELI
            }
            system("CLS");
            cout << "*Loading...";
            sleep(1);
            system("CLS");
            cout << "- Beli -\n" << endl;
            cout << "Transaksi pembelian dibatalkan.\n" << endl;
            system("PAUSE");
            menu = 2;
        }

    }while(menu != 2);// KEMBALI KE MENU AWAL
    system("CLS");
    cout << "*Loading...";
    sleep(1);
    system("CLS");
}

void menu_hapus_barang(List_Barang &LB, addrBarang &PB, infotype_barang &brg){
    int jawab;
    system("CLS");
    cout << "- Hapus Data Barang -\n" << endl;
    printInfo_Brg(LB);
    cout << "Data Barang yang ingin dihapus:\nID Barang > ";
    cin >> brg.id_barang;
    PB = findElmn_Brg(LB, brg);

    for(;PB == NULL;){
        system("CLS");
        cout << "- Hapus Data Barang -\n" << endl;
        printInfo_Brg(LB);
        cout << "*Barang tidak ada atau salah input ID barang.\n";
        cout << "\nData Barang yang ingin dihapus:\nID Barang > ";
        cin >> brg.id_barang;
        PB = findElmn_Brg(LB, brg);
    }

    // KONFIRMASI PENGHAPUSAN DATA PEMBELI

    cout << "\nYakin ingin menghapus data barang '" << info(PB).nama_barang << "' dari List Barang?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
    while(jawab != 1 && jawab != 2){
        system("CLS");
        cout << "- Hapus Data Barang -\n" << endl;
        printInfo_Brg(LB);
        cout << "Data Barang yang ingin dihapus:\nID Barang > " << info(PB).id_barang << endl;
        cout << "\n*Maaf, input salah. Silakan coba lagi.\n" << endl;
        cout << "Yakin ingin menghapus data barang '" << info(PB).nama_barang << "' dari List Barang?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
    }

    // JIKA YAKIN UNTUK MENGHAPUS
    if(jawab == 1){
        if(prev(PB) == NULL){ // JIKA ALAMAT BARANG DI FIRST MAKA MENGHAPUS BARANG MENGGUNAKAN DELETE FIRST
            deleteFirst_Brg(LB, PB);
        }else if(PB == last(LB)){ // JIKA ALAMAT BARANG DI LAST MAKA MENGHAPUS BARANG MENGGUNAKAN DELETE LAST
            deleteLast_Brg(LB, PB);
        }else{ // JIKA ALAMAT BARANG TIDAK DI FIRST ATAU LAST MAKA MENGHAPUS BARANG MENGGUNAKAN DELETE AFTER
            deleteAfter_Brg(LB, prev(PB), PB);
        }
        cout << "\n*Deleting...\n" << endl;
        sleep(1);
        system("CLS");
        cout << "Sukses menghapus '" << info(PB).nama_barang << "' dari List Barang.\n" << endl;
        printInfo_Brg(LB);
        system("PAUSE");
        system("CLS");

    // JIKA TIDAK JADI MENGHAPUS
    }else{
        system("CLS");
        cout << "Tidak ada data barang yang terhapus dari List Barang.\n" << endl;
        printInfo_Brg(LB);
        system("PAUSE");
        system("CLS");
    }
}

void menu_hapus_pembeli(List_user &LU, addrUser &PU, infotype_user &pembeli){
    int jawab;
    system("CLS");
    cout << "- Hapus Data Pembeli -\n" << endl;
    printInfo_User(LU);
    addrUser P = first(LU);
    if(P != NULL){
        cout << "Data pembeli yang ingin dihapus:\nNama Pembeli > ";
        cin.ignore();
        getline(cin, pembeli.nama);
        PU = findElmn_User(LU, pembeli);

        for(;PU == NULL;){
            system("CLS");
            cout << "- Hapus Data Pembeli -\n" << endl;
            printInfo_User(LU);
            cout << "*Data pembeli tidak ada atau salah menuliskan nama pembeli. Silakan coba lagi." << endl;
            cout << "\nData pembeli yang ingin dihapus:\nNama Pembeli > ";
            getline(cin, pembeli.nama);
            PU = findElmn_User(LU, pembeli);
        }

        // KONFIRMASI PENGHAPUSAN DATA PEMBELI

        cout << "\nYakin ingin menghapus data pembeli a/n " << info(PU).nama << " dari List Pembeli?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
        while(jawab != 1 && jawab != 2){
            system("CLS");
            cout << "- Hapus Data Pembeli -\n" << endl;
            printInfo_User(LU);
             cout << "\nData pembeli yang ingin dihapus:\nNama Pembeli > " << info(PU).nama << endl;
            cout << "\n*Maaf, input salah. Silakan coba lagi.\n" << endl;
            cout << "Yakin ingin menghapus data pembeli a/n " << info(PU).nama << " dari List Pembeli?\n1. Ya\n2. Tidak\nPilih (angka) > "; cin >> jawab;
        }

        // JIKA YAKIN UNTUK MENGHAPUS
        if(jawab == 1){
            addrUser Q = first(LU);
            if(PU == Q){ // JIKA ALAMAT PEMBELI DI FIRST MAKA MENGHAPUS PEMBELI MENGGUNAKAN DELETE FIRST
                deleteFirst_user(LU, PU);
            }else if(next(PU) == Q){ // JIKA ALAMAT PEMBELI DI LAST MAKA MENGHAPUS PEMBELI MENGGUNAKAN DELETE LAST
                deleteLast_user(LU, PU);
            }else{ // JIKA ALAMAT PEMBELI TIDAK DI FIRST ATAU LAST MAKA MENGHAPUS PEMBELI MENGGUNAKAN DELETE AFTER
                while(next(Q) != PU){
                    Q = next(Q);
                }
                deleteAfter_user(LU, Q, PU);
            }
            cout << "\n*Deleting...\n" << endl;
            sleep(1);
            system("CLS");
            cout << "Sukses menghapus data pembeli a/n " << info(PU).nama << " dari List Pembeli.\n" << endl;
            printInfo_User(LU);
            system("PAUSE");
            system("CLS");

        // JIKA TIDAK JADI MENGHAPUS
        }else{
            system("CLS");
            cout << "Tidak ada data pembeli yang terhapus dari List Pembeli.\n" << endl;
            printInfo_User(LU);
            system("PAUSE");
            system("CLS");
        }
    }else{ // JIKA LIST KOSONG
        cout << "*Tidak ada data pembeli yang dapat dihapus.\n" << endl;
        system("PAUSE");
        system("CLS");
    }
}

void list_menu(List_Barang &LB, addrBarang &PB, infotype_barang &brg ,List_user &LU, addrUser &PU, infotype_user &pembeli, addrRelasi &PR, int jumlahBrg){

    cout << "- Welcome to Aplikasi Data Perbelanjaan! -\n" << endl;
    system("PAUSE");
    system("CLS");

    int menu;

    // LOOPING MENU. BERHENTI KETIKA MEMILIH MENU NOMER 0 (KELUAR)
    for(bool end = false; !(end);){

        cout << "- Aplikasi Data Perbelanjaan -\n\n" << "Menu :\n";
        cout << "1. List Barang\n2. Tambah Barang\n3. Beli\n4. List Pembeli\n5. Hapus Data Barang\n6. Hapus Data Pembeli\n7. Data Penjualan\n8. Data Barang Yang Terjual\n0. Keluar\n\n";
        cout << "Pilih menu (angka) > ";
        cin >> menu;

        if(menu == 1){
            // MENAMPILKAN DATA BARANG
            system("CLS");
            cout << "*Loading...";
            sleep(1);
            system("CLS");
            cout << "- List Barang -\n" << endl;
            printInfo_Brg(LB);
            system("PAUSE");
            system("CLS");

        }else if(menu == 2){
            // MENAMBAHKAN BARANG BARU
            menu_tambah_barang(LB,PB,brg);

        }else if(menu == 3){
            // MENAMBAHKAN DATA PEMBELI
            menu_beli(LB,PB,brg,LU,PU,pembeli,PR, jumlahBrg);

        }else if(menu == 4){
            // MENAMPILKAN DATA PEMBELI
            system("CLS");
            cout << "*Loading...";
            sleep(1);
            system("CLS");
            cout << "- Data Pembeli -\n" << endl;
            printInfo_User(LU);
            system("PAUSE");
            system("CLS");

        }else if(menu == 5){
            // MENGHAPUS DATA BARANG
            menu_hapus_barang(LB,PB,brg);

        }else if(menu == 6){
            // MENGHAPUS DATA PEMBELI
            menu_hapus_pembeli(LU,PU,pembeli);

        }else if(menu == 7){
            // MENAMPILKAN DATA PENJUALAN
            system("CLS");
            cout << "*Loading...";
            sleep(1);
            system("CLS");
            cout << "- Data Penjualan -\n" << endl;
            palingTerjual(LB);
            cout << endl;
            system("PAUSE");
            system("CLS");

        }else if(menu == 8){
            //MENAMPILKAN DATA BARANG YANG TERJUAL
            system("CLS");
            cout << "*Loading...";
            sleep(1);
            system("CLS");
            cout << "- Data Barang yang Terjual -" << endl;
            printinfo_brg_ygdibeli(LB,LU);
            system("PAUSE");
            system("CLS");

        }else if(menu == 0){
            // KELUAR
            end = true;
            system("CLS");
            cout << "- Terima kasih telah menggunakan aplikasi kami! -" << endl;
        }else{
            system("CLS");
        }
    }
}
