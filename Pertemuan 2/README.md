# Pertemuan 2 - GTI A2

## Identitas
- **Nama** : Daniel Lamganda Tua Gultom  
- **NIM**  : 24060124120048  
- **Lab**  : A2  

---

# Output Lab
## 1. Translasi Objek
<img width="953" height="760" alt="image" src="https://github.com/user-attachments/assets/2b370cb0-aff8-4d06-b05b-8fe5d8fcc63b" />

## 2. Rotasi Objek
<img width="952" height="753" alt="image" src="https://github.com/user-attachments/assets/6adfa19e-34a0-4c06-b475-7297e0bdb53f" />

## 3. Stack Objek
<img width="952" height="756" alt="image" src="https://github.com/user-attachments/assets/93b11633-5835-4ab2-9bf3-73fe6fe07a82" />

## Jawab Pertanyaan dari Stack Objek (Pertanyaan di modul)
1. Bagian yang disebut stack pada kode di atas adalah penggunaan fungsi glPushMatrix() dan glPopMatrix(). Setiap kali glPushMatrix() dipanggil, kondisi matrix transformasi saat ini disimpan ke dalam stack, dan ketika glPopMatrix() dipanggil, kondisi matrix terakhir yang disimpan diambil kembali. Dengan demikian, blok kode yang dibungkus oleh pasangan fungsi ini membentuk bagian stack yang mengatur transformasi secara lokal.
2. Fungsi glPushMatrix() adalah untuk menyimpan state (keadaan) matrix transformasi saat ini ke dalam stack, sedangkan glPopMatrix() mengembalikan state matrix yang terakhir disimpan dari stack. Fungsi ini penting karena memungkinkan kita melakukan transformasi seperti translasi atau rotasi pada objek tertentu tanpa mengubah transformasi global. Dengan menggunakan stack, kita menjaga agar transformasi objek yang satu tidak mempengaruhi objek lain, sehingga memudahkan pengelolaan objek yang kompleks dan hierarkis.
3. Perbedaan rotasi atau translasi di dalam stack dan di luar stack terletak pada cakupan pengaruhnya. Transformasi yang dilakukan di dalam stack, yaitu di antara glPushMatrix() dan glPopMatrix(), bersifat lokal dan hanya memengaruhi objek yang sedang digambar di dalam blok tersebut. Setelah glPopMatrix(), transformasi tersebut hilang dan matrix kembali ke kondisi sebelumnya. Sebaliknya, transformasi yang dilakukan di luar stack akan bersifat global dan mempengaruhi semua objek yang digambar setelahnya sampai matrix diubah kembali, sehingga tidak ada isolasi transformasi antar objek.

## Tugas Praktikum: MobilPertamaku (openGL)
<img width="1200" height="797" alt="image" src="https://github.com/user-attachments/assets/6df15d29-6257-4aaf-828b-8ff331ab7af1" />

## Penjelasan
1. lingkaran (float x, float y, float r): Fungsi ini menggambar lingkaran berisi menggunakan poligon dengan 360 titik. Titik-titik yang digunakan dihitung berdasarkan posisi pusat (x,y) dan radius r dengan menggunakan fungsi sin dan cos.
2. gambarRoda(): Menggambar sebuah roda mobil yang tersusu dari 2 lingkaran; yang besar sebagai ban; dan yang kecil sebagai velg. Menggunakan glPushMatrix() dan glPopMatrix() untuk menyimpan dan mengembalikan state matrix sehingga transformasi yang terjadi itu tidak mempengaruhi  bagian yang lain.
3. gambarMobil(): Menggambar mobil dengan terdiri dari banyak bagian, yaitu: Badan utama (persegi panjang warna merah), Atap mobil (trapesium warna merah tua), Jendela (persegi panjang biru muda), dilengkapi garis pemisah agar terlihat dua jendela, Gagang pintu (persegi panjang hitam kecil), Roda depan dan roda belakang menggunakan gambarRoda() yang ditempatkan dengan translasi.
4. gambarJalan(): Menggambar jalan raya yang terdiri dari persegi panjang abu-abu dan garis jalan putih sebagai marka jalan. Garis putih dibuat berulang menggunakan for looping.
