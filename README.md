# 🏥 Sistem Monitoring Kesehatan

Program ini merupakan aplikasi berbasis C++ yang digunakan untuk melakukan pencatatan dan pemantauan kesehatan pasien secara digital melalui terminal (console). Pengguna dapat menambahkan data pasien, melakukan kalkulasi medis (IMT, BMR, Kebutuhan Air, Lemak Tubuh, Tekanan Darah), melihat histori pemeriksaan, serta mencetak laporan ke dalam file teks.

Project ini dibuat untuk menerapkan konsep:

* Struktur Data
* Algoritma
* Object Oriented Programming (OOP)
* File Handling (I/O)
* Modular Programming

---

# 📖 Latar Belakang

Dalam dunia kesehatan, pemantauan kondisi fisik dasar sangat penting untuk mencegah berbagai penyakit. Proses kalkulasi manual seperti menghitung Indeks Massa Tubuh (IMT), kebutuhan kalori harian (BMR), hingga persentase lemak tubuh seringkali memakan waktu dan rawan kesalahan. 

Oleh karena itu, dibuatlah program sistem monitoring kesehatan berbasis terminal menggunakan bahasa C++ dengan menerapkan berbagai konsep struktur data dan pemrograman berorientasi objek yang dipelajari dalam perkuliahan.

Melalui project ini, mahasiswa dapat memahami bagaimana struktur data seperti Array of Objects dan Stack digunakan dalam implementasi rekam medis digital sederhana.

---

# 🎯 Tujuan Project

Tujuan dibuatnya program ini adalah:

1. Membuat sistem pencatatan rekam medis sederhana berbasis C++.
2. Menerapkan konsep struktur data (Array dan Stack) dalam studi kasus nyata.
3. Melatih penggunaan Object Oriented Programming (OOP) termasuk *Inheritance* (Pewarisan sifat).
4. Menerapkan ekspor data riwayat ke bentuk file eksternal (`.txt`).
5. Membuat kode yang modular (terpecah menjadi beberapa *Header Files*) agar mudah dikembangkan oleh tim.

---

# 🧠 Konsep Program

Program ini menggunakan beberapa konsep utama:

| Konsep              | Fungsi                                              |
| ------------------- | --------------------------------------------------- |
| Struct              | Menyimpan kerangka data identitas pasien & riwayat  |
| Class               | Mengatur sistem dan mengenkapsulasi fungsi medis    |
| Inheritance (OOP)   | Mewariskan rumus kalkulator ke fungsi monitoring    |
| Array of Objects    | Menyimpan daftar pasien (maksimal 100 data)         |
| Stack               | Menyimpan histori pemeriksaan medis terakhir        |
| File Handling       | Mencetak dan menyimpan laporan ke file `.txt`       |
| Modular Programming | Memisahkan sistem menjadi 5 file `.h` yang terpusat |

---

# ⚙️ Fitur Program

## ✅ Manajemen Data Pasien (CRUD)

Pengguna dapat:
* Menambahkan data pasien baru (ID, Nama, Umur, JK, Berat, Tinggi)
* Menampilkan seluruh daftar pasien yang terdaftar
* Mengubah data pasien berdasarkan ID
* Menghapus data pasien dari sistem

---

## ✅ Kalkulasi Medis Komprehensif

Sistem dilengkapi rumus perhitungan akurat untuk:
* **IMT:** Menentukan status Kurus, Normal, Overweight, atau Obesitas.
* **BMR:** Menghitung kebutuhan kalori basal (kkal) yang dinamis berdasarkan jenis kelamin.
* **Kebutuhan Air:** Estimasi kebutuhan hidrasi harian (ml).
* **Body Fat:** Kalkulasi persentase lemak tubuh berdasarkan rumus standar medis.
* **Tekanan Darah:** Klasifikasi kondisi dari Normal hingga Hipertensi Tahap 2 (Sistolik/Diastolik).

---

## ✅ Histori Pemeriksaan (Stack)

Setiap fitur yang dicek akan masuk ke dalam tumpukan riwayat pemeriksaan.

Konsep yang digunakan:
```txt
LIFO (Last In First Out) - Pemeriksaan terbaru muncul di urutan teratas.
# 🏥 Sistem Monitoring Kesehatan Berbasis C++
> Kelompok Struktur Data — Sistem Monitoring Kesehatan

---

## ✅ Ekspor Laporan TXT

Sistem dapat mencetak struk rekam medis secara otomatis. Data disimpan dengan timestamp (waktu nyata) menggunakan library `<ctime>`.

**Output file:** `laporan_kesehatan.txt`

---

## 🧩 Struktur Folder Project

```
proyek-kesehatan/
│
├── main.cpp
├── DataModel.h
├── Kalkulator.h
├── Monitoring.h
├── Database.h
└── MenuUI.h
```

---

## 🔄 Alur Program

```
Mulai Program
      ↓
Tampilkan Menu Utama
      ↓
Tambah/Pilih Data Pasien
      ↓
Masuk Menu Kesehatan Pasien
      ↓
Pilih Fitur (IMT/BMR/Tensi/dsb)
      ↓
Proses Kalkulasi (OOP)
      ↓
Tampilkan Status Medis
      ↓
Simpan ke Stack (Histori)
      ↓
Opsi Ekspor Laporan (.txt)
      ↓
Selesai / Kembali ke Menu
```

---

## 🧮 Algoritma & Struktur Data yang Digunakan

### 1. Array of Objects
Digunakan pada `Monitoring daftarPasien[100];` untuk menampung banyak data pasien di dalam memori secara simultan. Memudahkan proses pencarian *(Sequential Search)* menggunakan ID.

### 2. Stack (Tumpukan)
Digunakan pada `stack<Riwayat> history;` untuk mencatat setiap aksi pengecekan medis. Konsep **LIFO** memastikan dokter/pengguna melihat riwayat yang paling baru terlebih dahulu.

### 3. Object Oriented Programming (Inheritance)
Penggunaan **Base Class** `dataKesehatan` yang diwariskan *(public)* ke **Derived Class** `Monitoring`. Ini memisahkan antara murni rumus matematika dan proses pelabelan status kesehatan.

---

## 💻 Cara Compile Program

Karena program ini bersifat modular, Anda hanya perlu melakukan compile pada file utama.

**Linux / MacOS / Windows (MinGW - VS Code Terminal)**
```bash
g++ main.cpp -o program_kesehatan
```

---

## ▶️ Menjalankan Program

**Linux / MacOS**
```bash
./program_kesehatan
```

**Windows**
```bash
.\program_kesehatan.exe
```

---

## 🖥️ Contoh Menu Program

```
==============================
 MENU KESEHATAN PASIEN
==============================
1. Hitung IMT
2. Hitung BMR
3. Kebutuhan Air
4. Tekanan Darah
5. Persentase Lemak Tubuh
6. Lihat Riwayat
0. Kembali
Pilihan : 
```

---

## 📝 Contoh Laporan TXT

```
================================
Tanggal : Mon Feb 09 14:20:10 2026
ID      : 101
Nama    : Andi
Umur    : 20
JK      : L
Fitur   : Tekanan Darah
Nilai   : 120
Status  : Elevated
================================
```

---

## 👥 Pembagian Tugas Kelompok

| No | Anggota | Tugas |
|----|---------|-------|
| 1 | **Faiz** | `DataModel.h` — Merancang fondasi data (Blueprint). Mengimplementasikan struct `dataPasien` untuk variabel identitas dan struct `Riwayat` untuk menampung log pemeriksaan kesehatan. |
| 2 | **Rahmawati** | `Kalkulator.h` — Implementasi logika inti matematika. Membangun Base Class `dataKesehatan` yang memuat fungsi hitung mutlak seperti `hitungIMT()`, `hitungBMR()`, `hitungAir()`, dan `hitungLemakTubuh()`. |
| 3 | **Valentino** | `Monitoring.h` — Implementasi Inheritance, Stack, dan File Handling. Membangun class `Monitoring` untuk menentukan status/kategori medis, mengatur tumpukan riwayat pemeriksaan (LIFO), dan fitur ekspor ke `laporan_kesehatan.txt`. |
| 4 | **Destiya** | `Database.h` — Manajemen Array of Objects. Membangun class `DatabasePasien` yang memuat logika CRUD (Tambah, Tampil, Ubah, Hapus) untuk mengelola hingga 100 data pasien, beserta algoritma pencarian ID. |
| 5 | **Farhat** | `MenuUI.h` — Implementasi antarmuka terminal. Merancang class `MenuAplikasi` yang mengatur navigasi `do-while` & `switch-case`, input `cin/getline`, serta menghubungkan pilihan user dengan sistem database. |

---

## 📌 Kelebihan Project

✅ **Penerapan OOP yang Kuat**
Memisahkan data, rumus matematika, status monitoring, dan penyimpanan database ke dalam class yang berbeda.

✅ **Kode Sangat Modular**
Program dipisahkan menjadi 5 file Header (`.h`), sehingga mencegah merge conflict di GitHub dan sangat mudah dikembangkan.

✅ **Fungsi Rekam Medis Real-Time**
Dilengkapi penyimpanan histori langsung menggunakan Stack dan fitur cetak bukti rekam medis eksternal.

---

## 👨‍💻 Author

**Kelompok 4**
Sistem Monitoring Kesehatan Berbasis C++
