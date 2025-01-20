#include "tubes.h"

// Fungsi untuk membuat list atlet kosong
void createListAtlet(ListAtlet &L) {
    // I.S. List L terdefinisi dan mungkin berisi elemen-elemen//+
    // F.S. List L menjadi list kosong dengan first(L) = nullptr//+
    first(L) = nullptr;  // Menetapkan elemen pertama list atlet menjadi null
}


// Fungsi untuk mengalokasikan memori dan membuat elemen atlet baru
addressAtlet allocateAtlet(InfoAtlet data) {
    addressAtlet P = new ElmtAtlet;  // Mengalokasikan memori untuk elemen baru
    info(P) = data;  // Menetapkan data atlet pada elemen tersebut
    next(P) = nullptr;  // Menetapkan pointer next menjadi null
    return P;  // Mengembalikan elemen yang telah dibuat
}

// Fungsi untuk menambahkan atlet baru ke posisi pertama dalam list
void insertFirstAtlet(ListAtlet &L, addressAtlet P) {
        // Jika list kosong, elemen pertama menjadi elemen yang baru
        if (first(L) == nullptr) {
            first(L) = P;
            cout << "* Data Atlet dengan ID-" << info(P).idAtlet << " Berhasil ditambahkan menjadi peserta pertama !" << endl;
        } else {
            // Jika list tidak kosong, elemen baru menjadi elemen pertama dan elemen pertama sebelumnya menjadi elemen berikutnya
            next(P) = first(L);
            first(L) = P;
            cout << "* Data Atlet dengan ID-" << info(P).idAtlet << " Berhasil ditambahkan menjadi peserta pertama !" << endl;
        }
}

// Fungsi untuk menghapus atlet terakhir dalam list
void deleteLastAtlet(ListAtlet &L, addressAtlet &P, ListRelasi &listRelasi) {
    if (first(L) == nullptr) {
        cout << "List Atlet kosong!" << endl;
        P = nullptr;  // Jika list kosong, tidak ada elemen yang dapat dihapus
    } else if (next(first(L)) == nullptr) {
        // Jika hanya ada satu elemen dalam list
        P = first(L);
        first(L) = nullptr;  // Menghapus elemen pertama
    } else {
        addressAtlet temp = first(L);
        // Mencari elemen sebelum elemen terakhir
        while (next(next(temp)) != nullptr) {
            temp = next(temp);
        }
        P = next(temp);  // Elemen terakhir
        next(temp) = nullptr;  // Menghapus elemen terakhir
    }

    // Jika elemen berhasil dihapus
    if (P != nullptr) {
        string idAtletTerhapus = info(P).idAtlet;

        // Hapus semua relasi yang terkait dengan ID atlet
        addressRelasi R = first(listRelasi);
        while (R != nullptr) {
            addressRelasi nextR = next(R); // Simpan elemen berikutnya sebelum R dihapus
            if (info(relasiAtlet(R)).idAtlet == idAtletTerhapus) {
                hapusRelasi(listRelasi, idAtletTerhapus, info(relasiPertandingan(R)).idPertandingan);
            }
            R = nextR;
        }

        cout << "Data atlet dengan ID " << idAtletTerhapus << " telah dihapus." << endl;
    } else {
        cout << "Tidak ada data atlet yang dihapus." << endl;
    }
}


// Fungsi untuk menampilkan semua data atlet dalam list
void showAllAtlet(ListAtlet L) {
    if (first(L) == nullptr) {
        cout << "List Atlet kosong!" << endl;  // Jika list kosong
    } else {
        addressAtlet P = first(L);
        // Menelusuri dan menampilkan data setiap atlet
        while (P != nullptr) {
            cout << "ID Atlet: " << info(P).idAtlet << endl;
            cout << "Nama Atlet: " << info(P).namaAtlet << endl;
            cout << "Kategori Olahraga: " << info(P).kategoriOlahraga << endl;
            cout << "Tingkat Kompetisi: " << info(P).tingkatKompetisi << endl;
            cout << "----------------------------" << endl;
            P = next(P);  // Beralih ke elemen berikutnya
        }
    }
}

// Fungsi untuk mencari atlet berdasarkan ID
addressAtlet findAtletByID(ListAtlet L, string idCari) {
    addressAtlet atlet = first(L);
    // Menelusuri list dan mencari ID yang cocok
    while (atlet != nullptr && info(atlet).idAtlet != idCari) {
        atlet = next(atlet);
    }
    return atlet;  // Mengembalikan atlet yang ditemukan (atau null jika tidak ada)
}

// Fungsi untuk mencari dan menampilkan data atlet berdasarkan ID
void cariDataAtlet(ListAtlet listAtlet) {
    addressAtlet P = first(listAtlet);

    if (P == nullptr) {
        cout << "Belum ada Data Atlet (List Atlet Kosong) !" << endl;
    } else {
        string idAtlet;
        cout << "Masukkan ID Atlet yang ingin dicari: ";
        cin >> idAtlet;

        addressAtlet atlet = findAtletByID(listAtlet, idAtlet);
        if (atlet != nullptr) {
            cout << "ID Atlet: " << info(atlet).idAtlet << endl;
            cout << "Nama Atlet: " << info(atlet).namaAtlet << endl;
            cout << "Kategori Olahraga: " << info(atlet).kategoriOlahraga << endl;
            cout << "Tingkat Kompetisi: " << info(atlet).tingkatKompetisi << endl;
        } else {
            cout << "Atlet dengan ID " << idAtlet << " tidak ditemukan." << endl;
        }
    }
}

// Fungsi untuk membuat list pertandingan kosong
void createListPertandingan(ListPertandingan &L) {
    first(L) = nullptr;  // Menetapkan elemen pertama menjadi null
    last(L) = nullptr;  // Menetapkan elemen terakhir menjadi null
}

// Fungsi untuk mengalokasikan memori dan membuat elemen pertandingan baru
addressChild allocatePertandingan(InfoPertandingan data) {
    addressChild P = new ElmtPertandingan;  // Mengalokasikan memori untuk elemen pertandingan baru
    info(P) = data;  // Menetapkan data pertandingan
    next(P) = nullptr;  // Menetapkan pointer next menjadi null
    prev(P) = nullptr;  // Menetapkan pointer prev menjadi null
    return P;  // Mengembalikan elemen yang telah dibuat
}

// Fungsi untuk menambahkan pertandingan ke posisi terakhir dalam list
void insertLastPertandingan(ListPertandingan &L, addressChild P) {
    if (first(L) == nullptr) {
        first(L) = P;
        last(L) = P;  // Jika list kosong, elemen pertama dan terakhir menjadi elemen baru
    } else {
        next(last(L)) = P;  // Menetapkan pointer next elemen terakhir menjadi elemen baru
        prev(P) = last(L);  // Menetapkan pointer prev elemen baru ke elemen terakhir
        last(L) = P;  // Menetapkan elemen terakhir menjadi elemen baru
    }
}

// Fungsi untuk menghapus pertandingan pertama dalam list
void deleteFirstPertandingan(ListPertandingan &L, addressChild &P, ListRelasi &listRelasi) {
    if (first(L) == nullptr) {
        cout << "List Pertandingan kosong!" << endl;
        P = nullptr;  // Jika list kosong, tidak ada elemen yang dapat dihapus
    } else {
        P = first(L);  // Menyimpan elemen pertama
        if (first(L) == last(L)) {
            // Jika hanya ada satu elemen dalam list
            first(L) = last(L) = nullptr;
        } else {
            // Ubah elemen pertama menjadi elemen berikutnya
            first(L) = next(first(L));
            prev(first(L)) = nullptr;
        }
        // Hapus hubungan pointer dari elemen yang dihapus
        next(P) = nullptr;
        prev(P) = nullptr;
    }

    // Jika elemen berhasil dihapus
    if (P != nullptr) {
        string idPertandinganTerhapus = info(P).idPertandingan;

        // Hapus semua relasi yang terkait dengan ID pertandingan
        addressRelasi R = first(listRelasi);
        while (R != nullptr) {
            addressRelasi nextR = next(R);  // Simpan elemen berikutnya sebelum R dihapus
            if (info(relasiPertandingan(R)).idPertandingan == idPertandinganTerhapus) {
                hapusRelasi(listRelasi, info(relasiAtlet(R)).idAtlet, idPertandinganTerhapus);  // Hapus relasi terkait
            }
            R = nextR;
        }

        cout << "Data pertandingan dengan ID " << idPertandinganTerhapus << " telah dihapus." << endl;
    } else {
        cout << "Tidak ada data pertandingan yang dihapus." << endl;
    }
}

// Fungsi untuk menampilkan semua data pertandingan dalam list
void showAllPertandingan(ListPertandingan L) {
    if (first(L) == nullptr) {
        cout << "List Pertandingan kosong!" << endl;  // Jika list kosong
    } else {
        addressChild P = first(L);
        // Menelusuri dan menampilkan data setiap pertandingan
        while (P != nullptr) {
            cout << "ID Pertandingan: " << info(P).idPertandingan << endl;
            cout << "Tanggal Pertandingan: " << info(P).tanggalPertandingan << endl;
            cout << "Nama Pertandingan: " << info(P).namaPertandingan << endl;
            cout << "Lokasi Pertandingan: " << info(P).lokasiPertandingan << endl;
            cout << "Hadiah: " << info(P).hadiah << endl;
            cout << "----------------------------" << endl;
            P = next(P);  // Beralih ke elemen berikutnya
        }
    }
}

// Fungsi untuk mencari pertandingan berdasarkan ID
addressChild findPertandinganByID(ListPertandingan L, string idCariP) {
    addressChild pertandingan = first(L);
    // Menelusuri list dan mencari ID yang cocok
    while (pertandingan != nullptr && info(pertandingan).idPertandingan != idCariP) {
        pertandingan = next(pertandingan);
    }
    return pertandingan;  // Mengembalikan pertandingan yang ditemukan (atau null jika tidak ada)
}

// Fungsi untuk mencari dan menampilkan data pertandingan berdasarkan ID
void cariDataPertandingan(ListPertandingan listPertandingan) {
    addressChild P = first(listPertandingan);
    if (P == nullptr) {
        cout << "Belum ada Data Pertandingan (List Pertandingan Kosong) !" << endl;
    } else {
        string idPertandingan;
        cout << "Masukkan ID Pertandingan yang ingin dicari: ";
        cin >> idPertandingan;

        addressChild pertandingan = findPertandinganByID(listPertandingan, idPertandingan);
        if (pertandingan != nullptr) {
            cout << "ID Pertandingan: " << info(pertandingan).idPertandingan << endl;
            cout << "Nama Pertandingan: " << info(pertandingan).namaPertandingan << endl;
            cout << "Lokasi Pertandingan: " << info(pertandingan).lokasiPertandingan << endl;
            cout << "Tanggal Pertandingan: " << info(pertandingan).tanggalPertandingan << endl;
            cout << "Hadiah: " << info(pertandingan).hadiah << endl;
        } else {
            cout << "Pertandingan dengan ID " << idPertandingan << " tidak ditemukan." << endl;
        }
    }
}


// Fungsi untuk membuat list relasi kosong
void createListRelasi(ListRelasi &L) {
    first(L) = nullptr;  // Menetapkan elemen pertama list relasi menjadi null
}

// Fungsi untuk mengalokasikan memori dan membuat elemen relasi baru
addressRelasi allocateRelasi(addressAtlet A, addressChild P) {
    addressRelasi R = new ElmtRelasi;  // Mengalokasikan memori untuk elemen relasi baru
    atlet(R) = A;  // Menetapkan atlet yang terkait dalam relasi
    pertandingan(R) = P;  // Menetapkan pertandingan yang terkait dalam relasi
    next(R) = nullptr;  // Menetapkan pointer next menjadi null
    return R;  // Mengembalikan elemen relasi yang baru dibuat
}

// Fungsi untuk menambahkan relasi ke dalam list relasi
void addRelasi(ListRelasi &L, addressRelasi R) {
    if (first(L) == nullptr) {
        first(L) = R;  // Jika list kosong, relasi menjadi elemen pertama
    } else {
        addressRelasi temp = first(L);
        // Menelusuri list untuk menambahkan relasi ke akhir list
        while (next(temp) != nullptr) {
            temp = next(temp);
        }
        next(temp) = R;  // Menetapkan relasi baru ke elemen terakhir
    }
}

// Fungsi untuk menampilkan data atlet beserta pertandingan yang diikuti
void showAtletWithPertandingan(ListAtlet listAtlet, ListRelasi listRelasi) {
    if (first(listAtlet) == nullptr) {
        cout << "List Atlet kosong!" << endl;
        return;
    }
    if (first(listRelasi) == nullptr) {
        cout << "Tidak ada relasi antara Atlet dan Pertandingan!" << endl;
        return;
    }

    addressAtlet atlet = first(listAtlet);
    // Menelusuri setiap atlet dalam list
    while (atlet != nullptr) {
        cout << "ID Atlet: " << info(atlet).idAtlet << endl;
        cout << "Nama Atlet: " << info(atlet).namaAtlet << endl;
        cout << "Kategori Olahraga: " << info(atlet).kategoriOlahraga << endl;
        cout << "Tingkat Kompetisi: " << info(atlet).tingkatKompetisi << endl;
        cout << "Pertandingan yang diikuti: " << endl;

        bool found = false;
        addressRelasi relasi = first(listRelasi);
        // Menelusuri list relasi untuk menemukan pertandingan yang diikuti oleh atlet
        while (relasi != nullptr) {
            if (relasiAtlet(relasi) == atlet) {
                cout << "  - ID Pertandingan: " << info(pertandingan(relasi)).idPertandingan << endl;
                cout << "    Nama Pertandingan: " << info(pertandingan(relasi)).namaPertandingan << endl;
                cout << "    Lokasi: " << info(pertandingan(relasi)).lokasiPertandingan << endl;
                cout << "    Tanggal: " << info(pertandingan(relasi)).tanggalPertandingan << endl;
                cout << "    Hadiah: " << info(pertandingan(relasi)).hadiah << endl;
                found = true;
            }
            relasi = next(relasi);
        }

        if (!found) {
            cout << "  Tidak ada pertandingan yang diikuti." << endl;
        }
        cout << "----------------------------" << endl;
        atlet = next(atlet);  // Beralih ke atlet berikutnya
    }
}

void showPertandinganWithAtlet(ListPertandingan listPertandingan, ListRelasi listRelasi) {
    if (first(listPertandingan) == nullptr) {
        cout << "List Pertandingan kosong!" << endl;
        return;
    }
    if (first(listRelasi) == nullptr) {
        cout << "Tidak ada relasi antara Atlet dan Pertandingan!" << endl;
        return;
    }

    addressChild pertandingan = first(listPertandingan);
    // Menelusuri setiap pertandingan dalam list
    while (pertandingan != nullptr) {
        cout << "ID Pertandingan: " << info(pertandingan).idPertandingan << endl;
        cout << "Nama Pertandingan: " << info(pertandingan).namaPertandingan << endl;
        cout << "Lokasi Pertandingan: " << info(pertandingan).lokasiPertandingan << endl;
        cout << "Tanggal Pertandingan: " << info(pertandingan).tanggalPertandingan << endl;
        cout << "Hadiah: " << info(pertandingan).hadiah << endl;
        cout << "Atlet yang mengikuti pertandingan ini: " << endl;

        bool found = false;
        addressRelasi relasi = first(listRelasi);
        // Menelusuri list relasi untuk menemukan pertandingan yang diikuti oleh atlet
        while (relasi != nullptr) {
            if (relasiPertandingan(relasi) == pertandingan) {
                cout << "  - ID Atlet: " << info(atlet(relasi)).idAtlet << endl;
                cout << "    Nama Atlet: " << info(atlet(relasi)).namaAtlet << endl;
                cout << "    Kategori Olahraga: " << info(atlet(relasi)).kategoriOlahraga << endl;
                cout << "    Tingkat Kompetisi: " << info(atlet(relasi)).tingkatKompetisi << endl;
                found = true;
            }
            relasi = next(relasi);
        }

        if (!found) {
            cout << "  Tidak ada pertandingan yang diikuti." << endl;
        }
        cout << "----------------------------" << endl;
        pertandingan = next(pertandingan);  // Beralih ke atlet berikutnya
    }
}

// Fungsi untuk menghapus relasi antara atlet dan pertandingan berdasarkan ID
void hapusRelasi(ListRelasi &listRelasi, string idAtlet, string idPertandingan) {
    addressRelasi R = first(listRelasi);
    addressRelasi prevR = nullptr;

    while (R != nullptr) {
        // Mengecek jika relasi sesuai dengan ID atlet dan ID pertandingan
        if (info(relasiAtlet(R)).idAtlet == idAtlet && info(relasiPertandingan(R)).idPertandingan == idPertandingan) {
            if (prevR == nullptr) {
                first(listRelasi) = next(R);  // Jika relasi pertama, ganti dengan elemen berikutnya
            } else {
                next(prevR) = next(R);  // Jika relasi di tengah atau belakang, hilangkan elemen yang sesuai
            }
            cout << "Relasi antara Atlet ID-" << idAtlet << " dan Pertandingan ID-" << idPertandingan << " berhasil dihapus." << endl;
            return;
        }
        prevR = R;
        R = next(R);
    }

    cout << "Relasi tidak ditemukan!" << endl;
}

// Fungsi untuk menampilkan pertandingan yang diikuti oleh atlet berdasarkan ID atlet
void showPertandinganFromAtlet(ListRelasi &listRelasi, ListAtlet &listAtlet) {
    addressAtlet PA = first(listAtlet);

    if (PA == nullptr) { // jika list atlet kosong maka otomatis belum ada relasi.
        cout << "Belum ada Data Atlet (List Atlet Kosong) !" << endl;
    } else {
        string idAtlet;
        cout << "Masukkan ID Atlet: ";
        cin >> idAtlet;

        addressAtlet atlet = findAtletByID(listAtlet, idAtlet);
        if (atlet == nullptr) {
            cout << "Atlet dengan ID tersebut tidak ditemukan!" << endl;
        } else {
            cout << "Pertandingan yang diikuti oleh Atlet ID-" << idAtlet
                 << " (" << info(atlet).namaAtlet << "):" << endl;

            addressRelasi relasi = first(listRelasi);
            bool found = false;
            // Menelusuri list relasi untuk menemukan pertandingan yang diikuti oleh atlet tersebut
            while (relasi != nullptr) {
                if (relasiAtlet(relasi) == atlet) {
                    found = true;
                    cout << "- ID Pertandingan: " << info(relasiPertandingan(relasi)).idPertandingan
                         << ", Nama: " << info(relasiPertandingan(relasi)).namaPertandingan << endl;
                }
                relasi = next(relasi);
            }
            if (!found) {
                cout << "Atlet ini belum mengikuti pertandingan apapun." << endl;
            }
        }
}
}

// Fungsi untuk mencari relasi antara atlet dan pertandingan berdasarkan ID
void cariRelasiTertentu(ListAtlet listAtlet, ListPertandingan listPertandingan, ListRelasi listRelasi) {
    string idAtlet, idPertandingan;
    cout << "Masukkan ID Atlet yang ingin dicari: ";
    cin >> idAtlet; // Menerima input ID Atlet
    cout << "Masukkan ID Pertandingan yang ingin dicari: ";
    cin >> idPertandingan; // Menerima input ID Pertandingan

    // Mencari atlet dan pertandingan berdasarkan ID
    addressAtlet atlet = findAtletByID(listAtlet, idAtlet);
    addressChild pertandingan = findPertandinganByID(listPertandingan, idPertandingan);

    // Memeriksa apakah atlet dan pertandingan ditemukan
    if (atlet != nullptr && pertandingan != nullptr) {
        addressRelasi relasi = first(listRelasi); // Mulai iterasi dari relasi pertama
        bool found = false;
        while (relasi != nullptr) {
            // Mencocokkan relasi berdasarkan ID Atlet dan ID Pertandingan
            if (idAtlet == info(atlet(relasi)).idAtlet && idPertandingan == info(pertandingan(relasi)).idPertandingan) {
                cout << "Relasi ditemukan: Atlet dengan ID " << idAtlet << " berpartisipasi dalam Pertandingan dengan ID " << idPertandingan << endl;
                found = true; // Menandakan relasi ditemukan
                break;
            }
            relasi = next(relasi); // Melanjutkan ke relasi berikutnya
        }
        // Menampilkan pesan jika relasi tidak ditemukan
        if (!found) {
            cout << "Relasi antara Atlet dengan ID " << idAtlet << " dan Pertandingan dengan ID " << idPertandingan << " tidak ditemukan." << endl;
        }
    } else {
        cout << "Atlet atau Pertandingan tidak ditemukan." << endl; // Jika atlet atau pertandingan tidak ditemukan
    }
}

// Fungsi untuk mengedit relasi antara atlet dan pertandingan
void editRelasi(ListAtlet &listAtlet, ListPertandingan &listPertandingan, ListRelasi &listRelasi) {
    addressAtlet PA = first(listAtlet);
    addressChild PP = first(listPertandingan);

    if (PA == nullptr || PP == nullptr) {
        cout << "Data Atlet atau Data Pertandingan Kosong, tidak bisa edit relasi." << endl; // jika salah satu list kosong, otomatis tidak bisa edit relasi karena belum ada relasi yang di tambahkan.
    } else {
    string idAtlet, idPertandinganLama, idPertandinganBaru;
    cout << "Masukkan ID Atlet yang ingin diubah relasinya: ";
    cin >> idAtlet; // Menerima input ID Atlet

    addressAtlet atlet = findAtletByID(listAtlet, idAtlet); // Mencari atlet berdasarkan ID
    if (atlet == nullptr) {
        cout << "Atlet dengan ID " << idAtlet << " tidak ditemukan!" << endl;
        return;
    }
    cout << "Masukkan ID Pertandingan Lama yang akan diganti: ";
    cin >> idPertandinganLama; // Menerima input ID Pertandingan Lama
    addressChild pertandinganLama = findPertandinganByID(listPertandingan, idPertandinganLama); // Mencari pertandingan lama
    if (pertandinganLama == nullptr) {
        cout << "Pertandingan lama dengan ID " << idPertandinganLama << " tidak ditemukan!" << endl;
        return;
    }
    addressRelasi relasi = first(listRelasi); // Mulai iterasi dari relasi pertama
    addressRelasi relasiTarget = nullptr;
    while (relasi != nullptr) {
        // Mencocokkan relasi berdasarkan atlet dan pertandingan lama
        if (atlet(relasi) == atlet && pertandingan(relasi) == pertandinganLama) {
            relasiTarget = relasi; // Menandakan relasi yang ingin diubah ditemukan
            break;
        }
        relasi = next(relasi); // Melanjutkan ke relasi berikutnya
    }
    if (relasiTarget == nullptr) {
        cout << "Relasi antara Atlet dengan ID " << idAtlet << " dan Pertandingan dengan ID " << idPertandinganLama << " tidak ditemukan!" << endl;
        return;
    }
    cout << "Masukkan ID Pertandingan Baru untuk menggantikan relasi: ";
    cin >> idPertandinganBaru; // Menerima input ID Pertandingan Baru
    addressChild pertandinganBaru = findPertandinganByID(listPertandingan, idPertandinganBaru); // Mencari pertandingan baru
    if (pertandinganBaru == nullptr) {
        cout << "Pertandingan baru dengan ID " << idPertandinganBaru << " tidak ditemukan!" << endl;
        return;
    }
    pertandingan(relasiTarget) = pertandinganBaru; // Mengubah pertandingan pada relasi yang ditemukan
    cout << "Relasi berhasil diperbarui! Atlet dengan ID " << idAtlet << " sekarang terhubung dengan Pertandingan dengan ID " << idPertandinganBaru << "." << endl;
    }
}

// Fungsi untuk mencari daftar atlet yang mengikuti pertandingan tertentu
void showAtletFromPertandingan(ListPertandingan &listPertandingan, ListRelasi &listRelasi) {
    addressChild P = first(listPertandingan);

    if (P == nullptr) {
        cout << "Data pertandingan kosong, tidak bisa mencari pertandingan." << endl;
    } else {
        string idPertandingans;
        cout << "Masukkan ID pertandingan: ";
        cin.ignore();
        getline(cin, idPertandingans); // Menerima input ID Pertandingan
        addressChild pertandingan = findPertandinganByID(listPertandingan, idPertandingans); // Mencari pertandingan berdasarkan ID
        if (pertandingan == nullptr) {
            cout << "Pertandingan dengan ID '" << idPertandingans << "' tidak ditemukan!" << endl;
            return;
        }
        cout << "Daftar atlet yang mengikuti pertandingan '" << info(pertandingan).namaPertandingan << "':\n" << endl;
        addressRelasi relasi = first(listRelasi); // Mulai iterasi dari relasi pertama
        bool adaAtlet = false;
        int i = 0;
        while (relasi != nullptr) {
            // Mencocokkan pertandingan dengan relasi
            if (pertandingan(relasi) == pertandingan) {
                cout << i+1 << "." << "ID Atlet : " << info(atlet(relasi)).idAtlet << endl;
                cout << "Nama Atlet : " << info(atlet(relasi)).namaAtlet << endl;
                cout << "Kategori Olahraga : " << info(atlet(relasi)).kategoriOlahraga << endl;
                cout << "Tingkat Kompetisi : " << info(atlet(relasi)).tingkatKompetisi << endl;
                cout << endl;
                adaAtlet = true; // Menandakan ada atlet yang ditemukan
                i++;
            }
            relasi = next(relasi); // Melanjutkan ke relasi berikutnya
        }
        if (!adaAtlet) {
            cout << "Tidak ada atlet yang terdaftar pada pertandingan ini." << endl; // Jika tidak ada atlet ditemukan
        }
    }
}

// Fungsi untuk menghitung jumlah pertandingan yang diikuti oleh setiap atlet
void countRelationsPerAtlet(ListAtlet &listAtlet, ListRelasi &listRelasi) {
    addressAtlet atlet = first(listAtlet); // Mulai iterasi dari atlet pertama
    if (first(listRelasi) == NULL) {
        cout << "Tidak ada atlet satupun yang mengikuti pertandingan!" << endl;
        return;
    }
    while (atlet != NULL) {
        int count = 0;
        addressRelasi relasi = first(listRelasi); // Reset ke awal listRelasi untuk setiap atlet
        while (relasi != NULL) {
            if (atlet(relasi) == atlet) {
                count++; // Menambah jumlah pertandingan yang diikuti oleh atlet
            }
            relasi = next(relasi); // Melanjutkan ke relasi berikutnya
        }
        cout << "Atlet dengan ID-" << info(atlet).idAtlet << " mengikuti " << count << " pertandingan." << endl;
        atlet = next(atlet); // Melanjutkan ke atlet berikutnya
    }
}

// Fungsi untuk menghitung jumlah atlet yang mengikuti pertandingan tertentu
void countRelationsOfPertandingan(ListPertandingan &listPertandingan, ListRelasi &listRelasi) {
    if (first(listRelasi) == NULL) {
        cout << "Tidak ada pertandingan satupun yang diikuti atlet !" << endl;
        return;
    }
    string idPertandingan;
    cout << "Masukkan ID Pertandingan yang ingin dihitung jumlah relasinya: ";
    cin >> idPertandingan; // Menerima input ID Pertandingan
    addressChild targetPertandingan = findPertandinganByID(listPertandingan, idPertandingan); // Mencari pertandingan berdasarkan ID
    if (targetPertandingan == nullptr) {
        cout << "Pertandingan dengan ID " << idPertandingan << " tidak ditemukan!" << endl;
        return;
    }
    int count = 0;
    addressRelasi relasi = first(listRelasi); // Mulai iterasi dari relasi pertama
    while (relasi != NULL) {
        if (pertandingan(relasi) == targetPertandingan) {
            count++; // Menambah jumlah atlet yang mengikuti pertandingan
        }
        relasi = next(relasi); // Melanjutkan ke relasi berikutnya
    }
    cout << "Jumlah Atlet yang mengikuti Pertandingan  " << info(targetPertandingan).namaPertandingan << ": " << count << endl;
}

// Fungsi untuk menghitung jumlah pertandingan yang tidak diikuti atlet
void countPertandinganWithoutRelations(ListPertandingan &listPertandingan, ListRelasi &listRelasi) {
    int count = 0;
    addressChild pertandingan = first(listPertandingan); // Mulai iterasi dari pertandingan pertama
    while (pertandingan != NULL) {
        bool hasRelation = false;
        addressRelasi relasi = first(listRelasi); // Reset ke awal listRelasi untuk setiap pertandingan
        while (relasi != NULL) {
            if (pertandingan(relasi) == pertandingan) {
                hasRelation = true; // Menandakan pertandingan memiliki relasi dengan atlet
                break;
            }
            relasi = next(relasi); // Melanjutkan ke relasi berikutnya
        }

        if (!hasRelation) {
            count++; // Menambah jumlah pertandingan yang tidak diikuti atlet
        }

        pertandingan = next(pertandingan); // Melanjutkan ke pertandingan berikutnya
    }

    cout << "Jumlah pertandingan yang tidak diikuti Atlet: " << count << endl;
}

// Fungsi untuk membersihkan layar terminal
void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Perintah untuk Windows
    #else
        system("clear"); // Perintah untuk Linux/macOS
    #endif
}
