# KEOMPOK 9
TUBES STRUKTUR DATA KELOMPOK 9

Disusun oleh
1. 103012300180 - Dandy Fadilla
2. 103012300273 - Nevan Nabil Firmansyah Har

DESKRIPSI TUGAS BESAR

Membuat sebuah aolikasi yang memodelkan kategori barang dengan barangnya

**FUNGSI FUNGSI YANG ADA DALAM APLIKASI INI**
1. Insert data parent dari depan/belakang (5) -> menambahkan sebuah kategori (parent) baru dengan menggunakan inserLastKategori
2. Show all data parent (5) -> Menampilkan seluruh data kategori (parent) yang sudah ada.
3. Menghapus data parent dan childnya (5)  -> delete sebuah kategori dan juga delete barang
4. Mencari data parent (5) -> Mencari jenis kategori yang ada, kami menggunakannya sebagai bantuan untuk procedure seperti searchChildInParent
5. Insert data child (10)  -> Menambahkan data child atau data barang
6. Mengubah data parent / data child (10) -> mengubah data barang (child) 
7. Menampilkan seluruh data parent beserta childnya (15) -> showAll menjadi procedure untuk menampilkan seluruh data yang ada
8. Mencari data child pada parent tertentu (10) -> mencari data barang / child di dalam sebuah parent, di bantu dengan procedure mencari data parent
9. Menghapus data child pada parent tertentu (15) -> sama seperti mencari data, menggunakan bantuan procedure mencari data parent, lalu menghapus data barang yang akan dihapus
10. Menghitung banyak   barang tiap  kategori (10) -> menjumlahkan banyaknya barang yang ada dalam setiap kategori, dan kami menambahkan menjumlahkan total seluruh barang yang ada
11. Main program (10)

# tambahan fungsi dan procedure
void createListKategori(ListKategori &L);

adrKategori createElementKategori(infotypeParent x);

adrBarang createElementBarang(infotypeChild x);

void jumlahBarangKeseluruhan(ListKategori &L);

void menu();

void tambahDataAwal(ListKategori &LK);

# fungsi yang ada dalam aplikasi kami

```
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
```
