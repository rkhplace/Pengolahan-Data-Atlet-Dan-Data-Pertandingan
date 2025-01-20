#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define last(L) L.last
#define first(L) L.first
#define info(P) P->info
#define atlet(R) R->atlet
#define pertandingan(R) R->pertandingan
#define relasiAtlet(R) R->atlet
#define relasiPertandingan(R) R->pertandingan
#define namaPertandingan(R) info(R).pertandingan->info.nama
#define idPertandingan(R) info(R).pertandingan->info.idPertandingan
#define namaAtlet(R) info(R).atlet->info.nama
#define idAtlet(R) info(R).atlet->info.idAtlet

// Tipe data untuk elemen-elemen linked list
typedef struct ElmtAtlet* addressAtlet;
typedef struct ElmtPertandingan* addressChild;
typedef struct ElmtRelasi* addressRelasi;

// Struktur data untuk menyimpan informasi atlet
struct InfoAtlet {
    string idAtlet;  // ID atlet
    string namaAtlet;  // Nama atlet
    string kategoriOlahraga;  // Kategori olahraga
    string tingkatKompetisi;  // Tingkat kompetisi
};

// Elemen linked list untuk atlet
struct ElmtAtlet {
    InfoAtlet info;  // Data atlet
    addressAtlet next;  // Pointer ke elemen berikutnya
};

// Linked list untuk menyimpan atlet
struct ListAtlet {
    addressAtlet first;  // Pointer ke elemen pertama
};

// Struktur data untuk menyimpan informasi pertandingan
struct InfoPertandingan {
    string idPertandingan;  // ID pertandingan
    string tanggalPertandingan;  // Tanggal pertandingan
    string namaPertandingan;  // Nama pertandingan
    string lokasiPertandingan;  // Lokasi pertandingan
    string hadiah;  // Hadiah pertandingan
};

// Elemen linked list untuk pertandingan
struct ElmtPertandingan {
    InfoPertandingan info;  // Data pertandingan
    addressChild next;  // Pointer ke elemen berikutnya
    addressChild prev;  // Pointer ke elemen sebelumnya
};

// Linked list untuk menyimpan pertandingan
struct ListPertandingan {
    addressChild first;  // Pointer ke elemen pertama
    addressChild last;  // Pointer ke elemen terakhir
};

// Elemen linked list untuk relasi atlet-pertandingan
struct ElmtRelasi {
    addressAtlet atlet;  // Pointer ke atlet
    addressChild pertandingan;  // Pointer ke pertandingan
    addressRelasi next;  // Pointer ke elemen berikutnya
};

// Linked list untuk menyimpan relasi atlet-pertandingan
struct ListRelasi {
    addressRelasi first;  // Pointer ke elemen pertama
};

// Fungsi untuk membuat list atlet kosong
void createListAtlet(ListAtlet &L);

// Fungsi untuk mengalokasikan memori untuk elemen atlet baru
addressAtlet allocateAtlet(InfoAtlet data);

// Fungsi untuk menambahkan atlet di awal list
void insertFirstAtlet(ListAtlet &L, addressAtlet P);

// Fungsi untuk menghapus atlet di akhir list
void deleteLastAtlet(ListAtlet &L, addressAtlet &P, ListRelasi &listRelasi);

// Fungsi untuk menampilkan semua data atlet
void showAllAtlet(ListAtlet L);

// Fungsi untuk mencari atlet berdasarkan ID
addressAtlet findAtletByID(ListAtlet L, string idCari);

// Fungsi untuk mencari data atlet
void cariDataAtlet(ListAtlet listAtlet);

// Fungsi untuk membuat list pertandingan kosong
void createListPertandingan(ListPertandingan &L);

// Fungsi untuk mengalokasikan memori untuk elemen pertandingan baru
addressChild allocatePertandingan(InfoPertandingan data);

// Fungsi untuk menambahkan pertandingan di akhir list
void insertLastPertandingan(ListPertandingan &L, addressChild P);

// Fungsi untuk menghapus pertandingan di awal list
void deleteFirstPertandingan(ListPertandingan &L, addressChild &P, ListRelasi &ListRelasi);

// Fungsi untuk menampilkan semua data pertandingan
void showAllPertandingan(ListPertandingan L);

// Fungsi untuk mencari data pertandingan
void cariDataPertandingan(ListPertandingan listPertandingan);

// Fungsi untuk mencari pertandingan berdasarkan ID
addressChild findPertandinganByID(ListPertandingan L, string idCariP);

// Fungsi untuk membuat list relasi kosong
void createListRelasi(ListRelasi &L);

// Fungsi untuk mengalokasikan memori untuk elemen relasi baru
addressRelasi allocateRelasi(addressAtlet A, addressChild P);

// Fungsi untuk menambahkan relasi ke dalam list
void addRelasi(ListRelasi &L, addressRelasi R);

// Fungsi untuk menampilkan atlet yang berpartisipasi dalam pertandingan
void showAtletWithPertandingan(ListAtlet listAtlet, ListRelasi listRelasi);

// Fungsi untuk menghapus relasi antara atlet dan pertandingan
void hapusRelasi(ListRelasi &listRelasi, string idAtlet, string idPertandingan);

// Fungsi untuk menampilkan pertandingan berdasarkan atlet
void showPertandinganFromAtlet(ListRelasi &listRelasi, ListAtlet &listAtlet);

// Fungsi untuk mencari relasi tertentu antara atlet dan pertandingan
void cariRelasiTertentu(ListAtlet listAtlet, ListPertandingan listPertandingan, ListRelasi listRelasi);

// Fungsi untuk mengedit relasi
void editRelasi(ListAtlet &listAtlet, ListPertandingan &listPertandingan, ListRelasi &listRelasi);

// Fungsi untuk menampilkan atlet berdasarkan pertandingan
void showAtletFromPertandingan(ListPertandingan &listPertandingan, ListRelasi &listRelasi);

// Fungsi untuk menghitung jumlah pertandingan tanpa relasi
void countPertandinganWithoutRelations(ListPertandingan &listPertandingan, ListRelasi &listRelasi);

// Fungsi untuk menghitung jumlah relasi yang terkait dengan pertandingan
void countRelationsOfPertandingan(ListPertandingan &listPertandingan, ListRelasi &listRelasi);

// Fungsi untuk menghitung jumlah relasi yang dimiliki oleh atlet
void countRelationsPerAtlet(ListAtlet &listAtlet, ListRelasi &listRelasi);

void showPertandinganWithAtlet(ListPertandingan listPertandingan, ListRelasi listRelasi);

// Fungsi untuk membersihkan layar
void clearScreen();

#endif // TUBES_H_INCLUDED
