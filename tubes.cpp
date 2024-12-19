#include "barang.h"

void createListKategori(ListKategori &L) {
    first(L) = nullptr;
    last(L) = nullptr;
}

adrKategori createElementKategori(infotypeParent x) {
    adrKategori P = new elementParent;
    info(P) = x;
    next(P) = nullptr;
    prev(P) = nullptr;
    P->nextBarang = nullptr;
    return P;
}

adrBarang createElementBarang(infotypeChild x) {
    adrBarang P = new elementChild;
    info(P) = x;
    next(P) = nullptr;
    return P;
}

void insertLastKategori(ListKategori &L, adrKategori K) {
    if (first(L) == nullptr) {
        first(L) = K;
        last(L) = K;
    } else {
        prev(K) = last(L);
        next(last(L)) = K;
        last(L) = K;
    }
}

void insertLastBarang(adrKategori K, adrBarang B) {
    if (K->nextBarang == nullptr) {
        K->nextBarang = B;
    } else {
        adrBarang Q = K->nextBarang;
        while (next(Q) != nullptr) {
            Q = next(Q);
        }
        next(Q) = B;
    }
}

void showAllKategori(ListKategori &L) {
    adrKategori P = first(L);
    if (P == nullptr) {
        cout << "Kategori kosong" << endl;
    } else {
        while (P != nullptr) {
            cout << info(P).namaKategori << endl;
            P = next(P);
        }
    }
}

void showAll(ListKategori &L) {
    adrKategori P = first(L);
    while (P != nullptr) {
        cout << info(P).namaKategori << " : ";
        adrBarang Q = P->nextBarang;
        if (Q == nullptr) {
            cout << "(Barang kosong)";
        } else {
            while (Q != nullptr) {
                cout << info(Q).namaBarang;
                Q = next(Q);
                if (Q != nullptr) {
                    cout << ", ";
                }
            }
        }
        cout << endl;
        P = next(P);
    }
}


adrKategori searchKategori(ListKategori L, string jenisBarang) {
    adrKategori P = first(L);
    while (P != nullptr) {
        if (info(P).namaKategori == jenisBarang) {
            return P;
        }
        P = next(P);
    }
    return nullptr;
}

void searchChildInParent(ListKategori &L, string namaKategori, string namaBarang) {
    adrKategori P = searchKategori(L, namaKategori);
    if (P != nullptr) {
        adrBarang Q = P->nextBarang;
        while (Q != nullptr) {
            if (info(Q).namaBarang == namaBarang) {
                cout << "Barang ditemukan: " << namaBarang << " di kategori " << namaKategori << endl;
                return;
            }
            Q = next(Q);
        }
    }
    cout << "Barang tidak ditemukan" << endl;
}

void deleteKategori(ListKategori &L, string namaKategori) {
    adrKategori P = searchKategori(L, namaKategori);

    if (P == nullptr) {
        cout << "Kategori tidak ditemukan" << endl;
        return;
    }
    adrBarang Q = P->nextBarang;
    while (Q != nullptr) {
        adrBarang temp = Q;
        Q = next(Q);
        delete temp;
    }
    if (P == first(L) && P == last(L)) {
        first(L) = nullptr;
        last(L) = nullptr;
    }
    else if (P == first(L)) {
        first(L) = next(P);
        prev(first(L)) = nullptr;
    }
    else if (P == last(L)) {
        last(L) = prev(P);
        next(last(L)) = nullptr;
    }
    else {
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
    }

    delete P;
    cout << "Kategori " << namaKategori << " berhasil dihapus" << endl;
}

void deleteChildInParent(ListKategori &L, string namaKategori, string namaBarang) {
    adrKategori P = searchKategori(L, namaKategori);
    if (P != nullptr) {
        adrBarang Q = P->nextBarang;
        adrBarang prec = nullptr;
        while (Q != nullptr && info(Q).namaBarang != namaBarang) {
            prec = Q;
            Q = next(Q);
        }
        if (Q != nullptr) {
            if (prec == nullptr) {
                P->nextBarang = next(Q);
            } else {
                next(prec) = next(Q);
            }
            delete Q;
        }
    }
}

void jumlahBarangPerKategori(ListKategori &L) {
    adrKategori P = first(L);
    while (P != nullptr) {
        int count = 0;
        adrBarang Q = P->nextBarang;
        while (Q != nullptr) {
            count++;
            Q = next(Q);
        }
        cout << info(P).namaKategori << " terdapat " << count << " barang." << endl;
        P = next(P);
    }
}

void jumlahBarangKeseluruhan(ListKategori &L) {
    int total = 0;
    adrKategori P = first(L);
    while (P != nullptr) {
        adrBarang Q = P->nextBarang;
        while (Q != nullptr) {
            total++;
            Q = next(Q);
        }
        P = next(P);
    }
    cout << "Total barang keseluruhan: " << total << endl;
}

void updateKategori(ListKategori &L, string jenisBarang, kategori namaKategoriBaru) {
    adrKategori P = searchKategori(L, jenisBarang);
    if (P != nullptr) {
        info(P).namaKategori = namaKategoriBaru.namaKategori;
    }
}

void menu() {
    cout << "==========================" << endl;
    cout << "        MENU UTAMA        " << endl;
    cout << "==========================" << endl;
    cout << "1. Tambah Kategori" << endl;
    cout << "2. Tambah Barang" << endl;
    cout << "3. Tampilkan Kategori" << endl;
    cout << "4. Tampilkan Seluruh Data" << endl;
    cout << "5. Hapus Kategori" << endl;
    cout << "6. Hapus Barang pada Kategori" << endl;
    cout << "7. Update Nama Kategori" << endl;
    cout << "8. Jumlah Barang per Kategori" << endl;
    cout << "9. Jumlah Barang Keseluruhan" << endl;
    cout << "0. Keluar" << endl;
    cout << "==========================" << endl;
    cout << "Masukkan pilihan Anda: ";
}

void tambahDataAwal(ListKategori &LK) {

    adrKategori K1 = createElementKategori({"Elektronik"});
    insertLastBarang(K1, createElementBarang({"TV"}));
    insertLastBarang(K1, createElementBarang({"Radio"}));
    insertLastBarang(K1, createElementBarang({"HP"}));
    insertLastBarang(K1, createElementBarang({"Komputer"}));
    insertLastBarang(K1, createElementBarang({"Headset"}));
    insertLastKategori(LK, K1);

    adrKategori K2 = createElementKategori({"Pakaian"});
    insertLastBarang(K2, createElementBarang({"Kaos"}));
    insertLastBarang(K2, createElementBarang({"Celana"}));
    insertLastBarang(K2, createElementBarang({"Topi"}));
    insertLastBarang(K2, createElementBarang({"Jaket"}));
    insertLastKategori(LK, K2);

    adrKategori K3 = createElementKategori({"Dapur"});
    insertLastBarang(K3, createElementBarang({"Pisau"}));
    insertLastBarang(K3, createElementBarang({"Kompor"}));
    insertLastBarang(K3, createElementBarang({"Oven"}));
    insertLastBarang(K3, createElementBarang({"Panci"}));
    insertLastKategori(LK, K3);

}
