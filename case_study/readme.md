# 📌 Queue: Sistem Antrian di Bank

## 📖 Deskripsi
Program ini merupakan implementasi **Queue (Antrian)** dari nol (*full scratch*) tanpa menggunakan library STL `queue`.  
Studi kasus yang digunakan adalah **sistem antrian di bank**, di mana setiap nasabah akan dilayani berdasarkan urutan kedatangan (**FIFO - First In, First Out**).

## 🎯 Fitur
- `enqueue`: Menambahkan nasabah baru ke dalam antrian.  
- `dequeue`: Memanggil nasabah yang berada di depan antrian untuk dilayani.  
- `peek`: Melihat nasabah berikutnya yang akan dipanggil tanpa mengeluarkannya dari antrian.  
- `isEmpty`: Mengecek apakah antrian kosong.  
- Menampilkan daftar antrian saat ini.  

## 🏦 Studi Kasus
Nasabah datang ke bank dan mengambil nomor antrian.  
Setiap nomor dimasukkan ke dalam **queue**. Teller bank akan memanggil nasabah sesuai nomor urut — yang paling awal datang akan dilayani lebih dulu.  
Jika ada nasabah baru datang, mereka masuk ke antrian paling belakang.  

## 📌 Catatan
- Implementasi bisa dibuat dengan **array statis**, **array dinamis**, atau **linked list**.  
- Untuk versi lanjutan, bisa dibuat **circular queue** agar lebih efisien dalam penggunaan memori.  

---
✍️ Dibuat sebagai latihan implementasi **Queue dari nol** dalam studi kasus dunia nyata.
