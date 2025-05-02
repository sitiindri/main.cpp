/*
Nama        : Siti Indriyani
NIM         : 23533729
Mata Kuliah : Algoritma Strategis */

##include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Fungsi untuk menghitung jarak minimum dan mendapatkan rute optimal
pair<int, vector<int>> hitungJarakMinimum(vector<vector<int>> &jarak, int mulai) {
    int jumlahLab = jarak.size();
    vector<int> urutanLab;
    for (int i = 0; i < jumlahLab; i++) {
        if (i != mulai)
            urutanLab.push_back(i);
    }

    int jarakMinimum = INT_MAX;
    vector<int> ruteTerbaik;

    do {
        int totalJarak = 0;
        int dari = mulai;
        vector<int> ruteSekarang = {mulai};

        for (int i = 0; i < urutanLab.size(); i++) {
            int ke = urutanLab[i];
            totalJarak += jarak[dari][ke];
            dari = ke;
            ruteSekarang.push_back(ke);
        }

        // Kembali ke titik awal
        totalJarak += jarak[dari][mulai];
        ruteSekarang.push_back(mulai);

        if (totalJarak < jarakMinimum) {
            jarakMinimum = totalJarak;
            ruteTerbaik = ruteSekarang;
        }

    } while (next_permutation(urutanLab.begin(), urutanLab.end()));

    return {jarakMinimum, ruteTerbaik};
}

int main() {
    int jumlahLab;
    cout << "=== PROGRAM PENGECEKAN RUANG LAB (TSP - Brute Force) ===\n";
    cout << "Masukkan jumlah ruang laboratorium: ";
    cin >> jumlahLab;

    // Inisialisasi matriks jarak
    vector<vector<int>> jarak(jumlahLab, vector<int>(jumlahLab));
    cout << "\nMasukkan matriks jarak antar ruang lab (dalam meter):\n";
    for (int i = 0; i < jumlahLab; i++) {
        for (int j = 0; j < jumlahLab; j++) {
            cout << "Jarak dari Lab " << i << " ke Lab " << j << ": ";
            cin >> jarak[i][j];
        }
    }

    // Proses perhitungan
    int titikAwal = 0;
    auto hasil = hitungJarakMinimum(jarak, titikAwal);
    int jarakMinimum = hasil.first;
    vector<int> rute = hasil.second;

    // Output hasil
    cout << "\n=== HASIL PERHITUNGAN ===" << endl;
    cout << "Nama: SITI INDRIYANI" << endl;
    cout << "NIM : 23533729" << endl;
    cout << "Rute optimal pengecekan lab: ";
    for (int i = 0; i < rute.size(); i++) {
        cout << "Lab " << rute[i];
        if (i != rute.size() - 1) cout << " -> ";
    }
    cout << endl;
    cout << "Jarak minimum pengecekan semua ruang lab: " << jarakMinimum << " meter\n";

    return 0;
}
