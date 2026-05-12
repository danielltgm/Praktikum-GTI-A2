# Pertemuan 3 - GTI A2

## Identitas
- **Nama** : Daniel Lamganda Tua Gultom  
- **NIM**  : 24060124120048  
- **Lab**  : A2  

---

# Output Lab
## 1. Kamera
<img width="514" height="520" alt="image" src="https://github.com/user-attachments/assets/e4e36414-20cf-4d9f-b7d2-a49788a9c7a3" />

## 2. Depth and Lighting
<img width="979" height="580" alt="image" src="https://github.com/user-attachments/assets/d1710190-90ca-4668-ac3d-a43ebc96fdb7" />

---

## Jawab Pertanyaan dari Percobaan Kamera
1. Supaya objek dapat kita gerakin menggunakan interaksi dengan keyboard, kita perlu variabel buat menyimpan nilai perubahan seperti sudut rotasi. Saya membuat fungsi callback keyboard menggunakan glutKeyboardFunc untuk menangkap input dari pengguna. Di dalam fungsi tersebut, setiap tombol yang ditekan akan mengubah nilai variabel, misalnya menambah atau mengurangi sudut rotasi objek. Setelah itu, saya juga menggunakan glutPostRedisplay() digunakan agar tampilan diperbarui sehingga perubahan bisa langsung terlihat di layar. Si variabelnya harus dipakai dalam fungsi display(), misalnya pada glRotated, sehingga perubahan dari keyboard bisa benar-benar mempengaruhi pergerakan objek.
2. Fungsi gluLookAt digunakan untuk mengatur posisi dan arah kamera dalam dunia 3D. Fungsi ini menentukan letak kamera (eye position), titik yang dilihat (center), serta arah atas (up vector). Pada kode yang saya buat, saya memposisikan kamera berada di posisi (0,0,5), mengarah ke titik (0,0,0), dengan arah atas di sumbu Y. Dengan fungsi ini, kita tuh bisa mengatur sudut pandang seperti “mata” pengamat dalam ruang 3D sehingga objek terlihat dari perspektif yang diinginkan.
3. Dalam OpenGL terdapat dua jenis matriks utama yaitu Projection dan ModelView yang memiliki fungsi berbeda. ModelView digunakan untuk mengatur posisi objek dan kamera dalam ruang 3D, termasuk transformasi seperti rotasi, translasi, dan skala. Perubahan rotasi objek terjadi di tahap ModelView menggunakan glRotated. Sementara itu, Projection digunakan untuk mengatur bagaimana dunia 3D ditampilkan ke layar 2D, termasuk efek perspektif seperti objek jauh terlihat lebih kecil dan objek dekat terlihat lebih besar, yang diatur dengan gluPerspective. Kedua matriks ini digunakan bersama karena ModelView mengatur “isi dunia 3D”, sedangkan Projection mengatur “cara dunia itu ditampilkan ke layar”, sehingga hasil visual menjadi realistis dan sesuai pandangan manusia.
   
---

## Jawab Pertanyaan dari Percobaan Depth and Lighting
1. Lighting atau pencahayaan pada OpenGL adalah sistem yang digunakan untuk memberikan efek cahaya pada objek 3D agar terlihat lebih realistis. Tanpa lighting, objek hanya akan tampil sebagai warna datar tanpa bayangan atau kedalaman. Dalam OpenGL, lighting bekerja dengan cara menghitung interaksi antara cahaya (light source) dan permukaan objek berdasarkan posisi, arah normal, serta sifat material objek. Komponen utama lighting biasanya terdiri dari ambient (cahaya merata), diffuse (cahaya yang tergantung arah), dan specular (pantulan cahaya yang mengkilap). Dengan kombinasi ini, objek 3D bisa terlihat memiliki bentuk, volume, dan tekstur visual yang lebih nyata.
2. Fungsi lighting() pada kode tersebut digunakan untuk mengaktifkan dan mengatur semua konfigurasi pencahayaan di OpenGL. Di dalamnya terdapat beberapa pengaturan penting seperti mengaktifkan depth test agar objek yang dekat menutupi yang jauh, mengaktifkan GL_LIGHTING untuk menyalakan sistem cahaya, serta mengaktifkan GL_LIGHT0 sebagai sumber cahaya utama. Selain itu, fungsi ini juga mengatur karakteristik cahaya seperti ambient, diffuse, specular, dan posisi cahaya menggunakan glLightfv. Tidak hanya itu, material objek juga diatur menggunakan glMaterialfv, sehingga permukaan objek memiliki sifat pantulan cahaya tertentu. Fungsi ini berperan sebagai “setup utama” agar seluruh sistem pencahayaan di scene berjalan dengan benar dan konsisten.
3. Kubus pada kode di atas sebenarnya dibuat dari beberapa bidang (face) yang disusun menggunakan primitive GL_QUADS. Setiap sisi kubus digambar satu per satu dengan koordinat titik yang berbeda, lalu diposisikan menggunakan transformasi seperti glTranslatef dan glRotated. Dengan cara ini, terbentuklah sebuah objek 3D yang menyerupai kotak kayu dari enam sisi. Sementara itu, grid dibuat menggunakan GL_LINES yang digambar berulang dalam loop untuk membentuk garis horizontal dan vertikal di bidang XZ, sehingga terlihat seperti lantai atau referensi ruang 3D. Grid ini membantu pengguna memahami posisi dan kedalaman objek di dunia 3D. Untuk pencahayaan, sistem lighting yang sudah diaktifkan melalui fungsi lighting() bekerja dengan cara menghitung bagaimana cahaya dari sumber (GL_LIGHT0) mengenai permukaan kubus dan grid. Cahaya ambient memberikan pencahayaan dasar, diffuse menentukan bagian terang berdasarkan arah cahaya, sedangkan specular menciptakan efek pantulan. Karena material objek juga diatur, maka kubus dan permukaan lain akan bereaksi terhadap cahaya sehingga terlihat memiliki volume dan tidak datar. Kombinasi antara geometri (kubus dan grid) serta lighting inilah yang membuat scene 3D terlihat hidup dan realistis.

---

## Tugas Praktikum: TugasMobil3D
1. Tampak Depan
   <img width="987" height="583" alt="image" src="https://github.com/user-attachments/assets/208dd3c1-5905-427d-8d3e-60e28e54a76e" />

3. Tampak Belakang
   <img width="988" height="582" alt="image" src="https://github.com/user-attachments/assets/4edf7ac8-e0d3-47b7-86d9-c582ef7b1a5b" />
   
5. Tampak Samping (Saya menggunakan pov kiri mobil)
   <img width="982" height="579" alt="image" src="https://github.com/user-attachments/assets/12173a4f-7956-4157-98f9-7d8e78ef4f55" />
