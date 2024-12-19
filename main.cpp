#include "barang.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ListKategori LK;
    createListKategori(LK);
    tambahDataAwal(LK);
    int pilihan;
    do {
        menu();
        cin >> pilihan;
        switch (pilihan) {
            case 1: {
                infotypeParent kategori;
                cout << "Masukkan nama kategori: ";
                cin >> kategori.namaKategori;
                adrKategori newKategori = createElementKategori(kategori);
                insertLastKategori(LK, newKategori);
                break;
            }
            case 2: {
                infotypeParent kategori;
                infotypeChild Barang;
                cout << "Masukkan nama kategori: ";
                cin >> kategori.namaKategori;
                adrKategori K = searchKategori(LK, kategori.namaKategori);
                if (K != nullptr) {
                    cout << "Masukkan nama barang: ";
                    cin >> Barang.namaBarang;
                    adrBarang newBarang = createElementBarang(Barang);
                    insertLastBarang(K, newBarang);
                } else {
                    cout << "Kategori tidak ditemukan" << endl;
                }
                break;
            }
            case 3:
                showAllKategori(LK);
                break;
            case 4:
                showAll(LK);
                break;
            case 5: {
                string namaKategori;
                cout << "Masukkan nama kategori yang akan dihapus: ";
                cin >> namaKategori;
                deleteKategori(LK, namaKategori);
                break;
            }
            case 6: {
                string namaKategori, namaBarang;
                cout << "Masukkan nama kategori: ";
                cin >> namaKategori;
                cout << "Masukkan nama barang: ";
                cin >> namaBarang;
                deleteChildInParent(LK, namaKategori, namaBarang);
                break;
            }
            case 7: {
                string namaKategoriLama;
                kategori kategoriBaru;
                cout << "Masukkan nama kategori yang akan diupdate: ";
                cin >> namaKategoriLama;
                cout << "Masukkan nama kategori baru: ";
                cin >> kategoriBaru.namaKategori;
                updateKategori(LK, namaKategoriLama, kategoriBaru);
                cout << "Kategori berhasil diupdate" << endl;
                break;
            }
            case 8:
                jumlahBarangPerKategori(LK);
                break;
            case 9:
                jumlahBarangKeseluruhan(LK);
                break;
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 0);
    return 0;
}

