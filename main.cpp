#include "tubes.h"

bool isExit = false; // Variabel untuk menentukan apakah program harus keluar atau tidak

// Fungsi untuk kembali ke menu utama atau keluar dari program
void xToMain() {
    string choice;
    cout << "\nInput 'X' untuk kembali ke menu utama / Input lainnya untuk keluar program : ";
    cin >> choice;
    if (choice == "X" || choice == "x") {
    } else {
        cout << "Input tidak valid. Keluar dari program..\n";
        isExit = true; // Jika input selain 'X', program keluar
    }
}

int main() {
    // Deklarasi variabel untuk list data
    ListAtlet listAtlet;
    ListPertandingan listPertandingan;
    ListRelasi listRelasi;

    // Inisialisasi list
    createListAtlet(listAtlet);
    createListPertandingan(listPertandingan);
    createListRelasi(listRelasi);

    // Loop utama program selama isExit bernilai false
    while (!isExit) {
        int menu;
        cout << "************ TUGAS BESAR STRUKTUR DATA ************" << endl;
        cout << "*      PENGOLAHAN DATA ATLET DAN PERTANDINGAN     *" << endl;
        cout << "*                                                 *" << endl;
        cout << "*    Oleh:                                        *" << endl;
        cout << "*    Mohammad Faraja Ahdaf  (103012300178)        *" << endl;
        cout << "*    Muhammad Rakha Pratama (103012300131)        *" << endl;
        cout << "***************************************************" << endl;
        cout << endl;

        cout << "********************** MENU ***********************" << endl;
        cout << "* 1. Tambah Data                                  *" << endl;
        cout << "* 2. Hapus Data                                   *" << endl;
        cout << "* 3. Pencarian Data                               *" << endl;
        cout << "* 4. Tampilkan Data                               *" << endl;
        cout << "* 5. Hitung Data                                  *" << endl;
        cout << "* 6. Edit Relasi                                  *" << endl;
        cout << "* 7. Keluar                                       *" << endl;
        cout << "***************************************************" << endl;
        cout << "                                                   " << endl;

        // Input menu pilihan
        cout << "* Pilih menu (1-7): ";
        cin >> menu;

        // Proses berdasarkan pilihan menu
        switch (menu) {
            case 1: { // Tambah Data
                int subMenu;
                cout << "******************* TAMBAH DATA *******************" << endl;
                cout << "* 1. Tambah data Atlet                            *" << endl;
                cout << "* 2. Tambah data Pertandingan                     *" << endl;
                cout << "* 3. Tambah Relasi                                *" << endl;
                cout << "***************************************************" << endl;
                cout << "                                                   " << endl;
                cout << "***************************************************" << endl;
                cout << "* Pilih sub-menu: ";
                cin >> subMenu;

                // Pilihan submenu untuk tambah data
                switch (subMenu) {
                    case 1: { // Tambah data Atlet
                        InfoAtlet dataAtlet;
                        cout << "* Masukkan ID Atlet: ";
                        cin >> dataAtlet.idAtlet;
                        addressAtlet s = findAtletByID(listAtlet, dataAtlet.idAtlet);
                        if (s != nullptr) {
                            cout << "Atlet dengan ID " << dataAtlet.idAtlet << " sudah ada! Gagal menambahkan data!" << endl;
                            xToMain();
                            clearScreen();
                        } else {
                            cout << "* Masukkan Nama Atlet: ";
                            cin.ignore();
                            getline(cin, dataAtlet.namaAtlet);
                            cout << "* Masukkan Kategori Olahraga: ";
                            getline(cin, dataAtlet.kategoriOlahraga);
                            cout << "* Masukkan Tingkat Kompetisi: ";
                            getline(cin, dataAtlet.tingkatKompetisi);
                            addressAtlet atletBaru = allocateAtlet(dataAtlet); // Alokasikan data atlet baru
                            insertFirstAtlet(listAtlet, atletBaru); // Masukkan ke list atlet

                            xToMain(); // Panggil fungsi untuk kembali ke menu utama
                            clearScreen(); // Bersihkan layar
                        }
                        break;
                    }
                    case 2: { // Tambah data Pertandingan
                        InfoPertandingan dataPertandingan;
                        cout << "* Masukkan ID Pertandingan: ";
                        cin >> dataPertandingan.idPertandingan;
                        addressChild s = findPertandinganByID(listPertandingan, dataPertandingan.idPertandingan);
                        if (s != nullptr) {
                            cout << "Pertandingan dengan ID " << dataPertandingan.idPertandingan << " sudah ada! Gagal menambahkan data!" << endl;
                            xToMain();
                            clearScreen();
                        } else {
                            cout << "* Masukkan Tanggal Pertandingan: ";
                            cin.ignore();
                            getline(cin, dataPertandingan.tanggalPertandingan);
                            cout << "* Masukkan Nama Pertandingan: ";
                            getline(cin, dataPertandingan.namaPertandingan);
                            cout << "* Masukkan Lokasi Pertandingan: ";
                            getline(cin, dataPertandingan.lokasiPertandingan);
                            cout << "* Masukkan Hadiah: ";
                            cin >> dataPertandingan.hadiah;

                            addressChild pertandinganBaru = allocatePertandingan(dataPertandingan); // Alokasikan pertandingan baru
                            insertLastPertandingan(listPertandingan, pertandinganBaru); // Masukkan ke list pertandingan
                            cout << "* Data Pertandingan dengan ID-" << info(pertandinganBaru).idPertandingan << " Berhasil ditambahkan !" << endl;
                            xToMain(); // Kembali ke menu utama
                            clearScreen(); // Bersihkan layar

                        }
                        break;
                    }
                    case 3: { // Tambah Relasi
                        addressAtlet PA = first(listAtlet);
                        addressChild PP = first(listPertandingan);

                        if (PA == nullptr || PP == nullptr) {
                            // Jika list atlet atau pertandingan kosong
                            cout << "List Atlet atau List Pertandingan kosong! Tidak bisa menambahkan relasi." << endl;
                        } else {
                            string idAtlet, idPertandingan;
                            cout << "* Masukkan ID Atlet: ";
                            cin >> idAtlet;
                            cout << "* Masukkan ID Pertandingan: ";
                            cin >> idPertandingan;

                            // Cari atlet dan pertandingan berdasarkan ID
                            addressAtlet atlet = findAtletByID(listAtlet, idAtlet);
                            addressChild pertandingan = findPertandinganByID(listPertandingan, idPertandingan);

                            // Validasi keberadaan atlet dan pertandingan
                            if (atlet == nullptr) {
                                cout << "Atlet dengan ID " << idAtlet << " tidak ditemukan!" << endl;
                            } else if (pertandingan == nullptr) {
                                cout << "Pertandingan dengan ID " << idPertandingan << " tidak ditemukan!" << endl;
                            } else {

                                // Cek apakah relasi sudah ada
                                addressRelasi R = first(listRelasi);
                                bool relasiSudahAda = false;

                                while (R != nullptr) {
                                    if (info(relasiAtlet(R)).idAtlet == idAtlet && info(relasiPertandingan(R)).idPertandingan == idPertandingan) {
                                        relasiSudahAda = true;
                                        break;
                                    }
                                    R = next(R);
                                }

                                if (relasiSudahAda) {
                                    cout << "Relasi antara Atlet ID-" << idAtlet << " dan Pertandingan ID-" << idPertandingan << " sudah ada! Gagal menambahkan relasi." << endl;
                                } else {
                                    // Tambahkan relasi baru
                                    addressRelasi relasiBaru = allocateRelasi(atlet, pertandingan);
                                    addRelasi(listRelasi, relasiBaru);
                                    cout << "Relasi ID Atlet-" << idAtlet << " dengan ID Pertandingan-" << idPertandingan << " berhasil ditambahkan!" << endl;
                                }
                            }
                        }
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    }
                }
                break;
            }
            case 2: { // Hapus Data
                int subMenu;
                cout << "******************* HAPUS DATA ********************" << endl;
                cout << "* 1. Hapus data Atlet Terakhir                    *" << endl;
                cout << "* 2. Hapus data Pertandingan pertama              *" << endl;
                cout << "* 3. Hapus Relasi                                 *" << endl;
                cout << "***************************************************" << endl;
                cout << "                                                   " << endl;
                cout << "***************************************************" << endl;
                cout << "* Pilih sub-menu: ";
                cin >> subMenu;

                // Pilihan submenu untuk hapus data
                switch (subMenu) {
                    case 1: { // Hapus data Atlet Terakhir
                        addressAtlet atletTerhapus;
                        deleteLastAtlet(listAtlet, atletTerhapus, listRelasi); // Hapus atlet terakhir
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    }
                    case 2: { // Hapus data Pertandingan pertama
                        addressChild pertandinganTerhapus;
                        deleteFirstPertandingan(listPertandingan, pertandinganTerhapus, listRelasi); // Hapus pertandingan pertama
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    }
                    case 3: { // Hapus Relasi
                        addressRelasi R = first(listRelasi);
                        if (R == nullptr) {
                        cout << "Belum ada Relasi sama sekali, Tidak bisa menghapus relasi." << endl;
                        } else {
                            string idAtlet, idPertandingan;
                            cout << "* Masukkan ID Atlet: ";
                            cin >> idAtlet;
                            cout << "* Masukkan ID Pertandingan: ";
                            cin >> idPertandingan;

                            hapusRelasi(listRelasi, idAtlet, idPertandingan); // Hapus relasi berdasarkan ID atlet dan pertandingan
                            xToMain(); // Kembali ke menu utama
                            clearScreen(); // Bersihkan layar
                            break;
                        }
                    }
                }
                break;
            }
            case 3: { // Pencarian Data
                int subMenu;
                cout << "****************** PENCARIAN DATA *****************" << endl;
                cout << "* 1. Cari data Atlet                              *" << endl;
                cout << "* 2. Cari data Pertandingan                       *" << endl;
                cout << "* 3. Cari Relasi tertentu                         *" << endl;
                cout << "***************************************************" << endl;
                cout << "                                                   " << endl;
                cout << "***************************************************" << endl;
                cout << "* Pilih sub-menu: ";
                cin >> subMenu;

                // Pilihan submenu untuk pencarian
                switch (subMenu) {
                    case 1:
                        cariDataAtlet(listAtlet); // Cari data atlet
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 2:
                        cariDataPertandingan(listPertandingan); // Cari data pertandingan
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 3:
                        cariRelasiTertentu(listAtlet, listPertandingan, listRelasi); // Cari relasi tertentu
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                }
                break;
            }
            case 4: { // Tampilkan Data
                int subMenu;
                cout << "*********************** TAMPILKAN DATA *************************" << endl;
                cout << "* 1. Tampilkan semua data Atlet                                *" << endl;
                cout << "* 2. Tampilkan semua data Pertandingan                         *" << endl;
                cout << "* 3. Tampilkan data Pertandingan dari Atlet tertentu           *" << endl;
                cout << "* 4. Tampilkan setiap Atlet beserta Pertandingannya            *" << endl;
                cout << "* 5. Tampilkan setiap Pertandingan beserta Atletnya            *" << endl;
                cout << "* 6. Tampilkan data Atlet yang mengikuti Pertandingan tertentu *" << endl;
                cout << "****************************************************************" << endl;
                cout << "                                                                " << endl;
                cout << "****************************************************************" << endl;
                cout << "* Pilih sub-menu: ";
                cin >> subMenu;

                // Pilihan submenu untuk menampilkan data
                switch (subMenu) {
                    case 1:
                        showAllAtlet(listAtlet); // Tampilkan semua data atlet
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 2:
                        showAllPertandingan(listPertandingan); // Tampilkan semua data pertandingan
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 3:
                        showPertandinganFromAtlet(listRelasi, listAtlet); // Tampilkan pertandingan dari atlet tertentu
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 4:
                        showAtletWithPertandingan(listAtlet, listRelasi); // Tampilkan atlet beserta pertandingannya
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 5:
                        showPertandinganWithAtlet(listPertandingan, listRelasi); // Tampilkan atlet dari pertandingan
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 6:
                        showAtletFromPertandingan(listPertandingan, listRelasi); // Cari pertandingan berdasarkan atlet tertentu
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                }
                break;
            }
            case 5: { // Hitung Data
                int subMenu;
                cout << "****************** HITUNG DATA ********************************" << endl;
                cout << "* 1. Hitung total Pertandingan dari setiap Atlet              *" << endl;
                cout << "* 2. Hitung total Atlet yang mengikuti Pertandingan tertentu  *" << endl;
                cout << "* 3. Hitung total Pertandingan yang tidak memiliki Atlet      *" << endl;
                cout << "***************************************************************" << endl;
                cout << "                                                               " << endl;
                cout << "***************************************************************" << endl;
                cout << "* Pilih sub-menu: ";
                cin >> subMenu;

                // Pilihan submenu untuk menghitung data
                switch (subMenu) {
                    case 1:
                        countRelationsPerAtlet(listAtlet, listRelasi); // Hitung total pertandingan per atlet
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 2:
                        countRelationsOfPertandingan(listPertandingan, listRelasi); // Hitung total atlet di pertandingan tertentu
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                    case 3:
                        countPertandinganWithoutRelations(listPertandingan, listRelasi); // Hitung pertandingan yang tidak memiliki atlet
                        xToMain(); // Kembali ke menu utama
                        clearScreen(); // Bersihkan layar
                        break;
                }
                break;
            }
            case 6: { // Edit Relasi
                editRelasi(listAtlet, listPertandingan, listRelasi); // Edit relasi antara atlet dan pertandingan
                xToMain(); // Kembali ke menu utama
                clearScreen(); // Bersihkan layar
                break;
            }
            case 7: {
                isExit = true; // Program keluar
                break;
            }
            default:
                clearScreen();
                cout << "Menu tidak valid!" << endl; // Pilihan menu tidak valid
                break;
        }
    }

    return 0; // Program selesai
}
