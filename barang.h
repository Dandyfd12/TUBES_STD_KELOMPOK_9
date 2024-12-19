#ifndef COBA_H_INCLUDED
#define COBA_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
using namespace std;

struct kategori {
    string namaKategori;
};

struct barang {
    string namaBarang;
};

typedef struct elementParent *adrKategori;
typedef struct elementChild *adrBarang;

typedef kategori infotypeParent;
typedef barang infotypeChild;

struct elementParent {
    infotypeParent info;
    adrKategori next, prev;
    adrBarang nextBarang;
};

struct elementChild {
    infotypeChild info;
    adrBarang next;
};

struct ListKategori {
    adrKategori first, last;
};

void createListKategori(ListKategori &L);
adrKategori createElementKategori(infotypeParent x);
adrBarang createElementBarang(infotypeChild x);
void insertLastKategori(ListKategori &L, adrKategori K);
void insertLastBarang(adrKategori K, adrBarang B);
void showAllKategori(ListKategori &L);
void showAll(ListKategori &L);
adrKategori searchKategori(ListKategori L, string jenisBarang);
void deleteKategori(ListKategori &L, string namaKategori);
void searchChildInParent(ListKategori &L, string namaKategori, string namaBarang);
void deleteChildInParent(ListKategori &L, string namaKategori, string namaBarang);
void jumlahBarangPerKategori(ListKategori &L);
void jumlahBarangKeseluruhan(ListKategori &L);
void updateKategori(ListKategori &L, string jenisBarang, kategori namaKategoriBaru);
void menu();
void tambahDataAwal(ListKategori &LK);

#endif
