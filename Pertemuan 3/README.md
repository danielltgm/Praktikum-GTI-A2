# Pertemuan 3 - GTI A2

## Identitas
- **Nama** : Daniel Lamganda Tua Gultom  
- **NIM**  : 24060124120048  
- **Lab**  : A2  

---

# Output Lab
## 1. Proyeksi
<img width="448" height="491" alt="image" src="https://github.com/user-attachments/assets/8f508423-d80c-4bc2-8370-8e13411a1c4c" />

## 2. Kubus Berotasi
<img width="446" height="489" alt="image" src="https://github.com/user-attachments/assets/48166642-ac4b-4b6d-9e9d-27502fc8cf39" />

## 3. Lengan Bergerak
<img width="1048" height="898" alt="image" src="https://github.com/user-attachments/assets/708b0485-8819-4724-910c-605c13d463e7" />

---

## Jawab Pertanyaan dari 3 percobaan di atas (Pertanyaan di modul)
1. Fungsi glutReshapeFunc digunakan untuk mendefinisikan prosedur callback ketika jendela OpenGL diubah ukurannya. Dengan adanya fungsi ini, program bisa menyesuaikan tampilan grafis sesuai dimensi baru jendela, misalnya mengatur ulang viewport atau proyeksi agar gambar tidak terdistorsi. Sedangkan glutPostRedisplay berfungsi memberi tahu sistem bahwa tampilan perlu digambar ulang. Jadi, kl ada perubahan yang memengaruhi tampilan, fungsi ini memicu pemanggilan ulang prosedur display sehingga gambar diperbarui.
2. Prosedur Idle dalam kode animasi kubus bergerak bertugas menjalankan aksi ketika program sedang tidak menerima input lain. Dipakai untuk mengatur animasi berulang, seperti pergerakan kubus secara terus-menerus. Idle menjaga agar objek tetap bergerak atau berubah meskipun pengguna tidak melakukan interaksi.
3. Proyeksi dalam grafik komputer adalah proses memetakan objek tiga dimensi ke bidang dua dimensi agar bisa ditampilkan di layar. Dalam OpenGL, ada dua hal penting, yaitu: projection dan modelview. Projection mengatur bagaimana objek 3D diproyeksikan ke layar, misalnya kl kita menggunakan proyeksi perspektif atau ortografis. Sementara modelview mengatur posisi dan orientasi objek serta kamera dalam ruang 3D. Sederhananya, projection menentukan cara pandang, sedangkan modelview menentukan bagaimana objek ditempatkan dan dilihat dalam ruang.
   
---

## Tugas Praktikum: AkuPunyaTangan (openGL)
1. Secara keseluruhan, program ini mensimulasikan lengan dengan dua sendi. Bahu dan siku bisa digerakkan secara interaktif lewat keyboard, dan hasilnya terlihat sebagai lengan atas dan bawah yang berputar sesuai sudut rotasi. Jadi, inti kerjanya adalah menggabungkan translasi, rotasi, dan skala pada objek kubus untuk membentuk lengan yang bisa bergerak seperti nyata.
   Pertama, fungsi init() hanya menyiapkan warna latar belakang hitam dan model shading sederhana. Fungsi inti ada di display(), di sana layar dibersihkan lalu dilakukan serangkaian transformasi: bahu digerakkan dengan kombinasi glTranslatef dan glRotatef, kemudian digambar lengan atas berupa kubus yang diskalakan memanjang. Setelah itu, posisi digeser ke arah siku, dilakukan rotasi lagi untuk mensimulasikan gerakan sendi siku, lalu digambar lengan bawah. Semua transformasi dibungkus dengan glPushMatrix dan glPopMatrix agar setiap bagian lengan punya transformasi sendiri tanpa mengganggu bagian lain.
   Fungsi reshape() mengatur ulang proyeksi perspektif ketika ukuran jendela berubah. Reshape() menyesuaikan viewport, lalu mengatur proyeksi dengan gluPerspective sehingga tampilan tetap proporsional. Fungsi keyboard() dipakai untuk mengontrol gerakan: tombol g dan s memutar bahu, sedangkan e dan E memutar siku. Setiap kali tombol ditekan, nilai sudut rotasi bertambah atau berkurang, lalu glutPostRedisplay() dipanggil supaya tampilan digambar ulang dengan posisi baru.
2. Gambar Bahu, Siku, Pergelangan, 4 Jari, dan Ibu Jari
   <img width="1343" height="938" alt="image" src="https://github.com/user-attachments/assets/26f1551c-b8bc-41c4-9fec-46db026d2abb" />
   ### Penjelasan
   Program ini secara keseluruhan mensimulasikan sebuah lengan lengkap dengan bahu, siku, pergelangan, telapak tangan, dan jari‑jari menggunakan OpenGL. Struktur utamanya dimulai dari bahu yang bisa diputar, lalu dilanjutkan ke siku, kemudian pergelangan tangan. Setelah itu digambar telapak tangan sebagai basis, dan dari telapak ini muncul jari‑jari. Setiap jari digambar dengan fungsi khusus: drawFinger untuk jari biasa (3 ruas) dan drawThumb untuk ibu jari (2 ruas). Prinsip kerjanya adalah kombinasi transformasi matriks (glTranslatef, glRotatef, glScalef) yang disusun berurutan sehingga setiap ruas jari atau bagian lengan bisa bergerak relatif terhadap sendi sebelumnya. Dengan cara ini, gerakan yang dihasilkan menyerupai gerakan nyata lengan manusia, karena setiap sendi memengaruhi posisi bagian berikutnya. Tampilan digambar ulang setiap kali ada perubahan dengan glutPostRedisplay, dan proyeksi perspektif diatur agar gambar tetap proporsional saat jendela diubah ukurannya.
   ### Interaksi dengan Keyboard
   Interaksi dengan keyboard memungkinkan pengguna menggerakkan setiap sendi dan ruas jari secara manual. Tombol s dan S menggerakkan bahu ke arah berlawanan, e dan E untuk siku, serta w dan W untuk pergelangan. Jari‑jari diatur dengan kombinasi tombol angka dan huruf: jari telunjuk memakai 1, !, dan q untuk tiga ruas; jari tengah dengan 2, @, dan a; jari manis dengan 3, #, dan z; jari kelingking dengan 4, $, dan x. Ibu jari digerakkan dengan 5 dan % untuk dua ruasnya. Dengan menekan tombol‑tombol ini, sudut rotasi tiap sendi bertambah sehingga bagian lengan atau jari berputar sesuai input. Tombol ESC digunakan untuk keluar dari program. Jadi, keyboard berfungsi sebagai kontrol interaktif yang memungkinkan pengguna menggerakkan lengan dan jari secara detail, seolah‑olah mengendalikan tangan virtual.
3. ### Penjelasan
   a. Pergerakan Bahu (menekan tombol "s" yang artinya berputar +5° terhadap sumbu Z, saya menekan 18 kali yang artinya +90° terhadap sumbu Z)
### Sebelum
<img width="1346" height="937" alt="image" src="https://github.com/user-attachments/assets/4b014e28-4efd-4ea0-9a5f-a793a7b9a8eb" />

### Sesudah
<img width="1343" height="935" alt="image" src="https://github.com/user-attachments/assets/cec0ce0a-743b-4c76-936f-37ee78e53e54" />

  b. Pergerakan Siku (menekan tombol "E" yang artinya berputar -5° terhadap sumbu Z, saya menekan 18 kali yang artinya -90° terhadap sumbu Z)
### Sebelum
<img width="1345" height="938" alt="image" src="https://github.com/user-attachments/assets/84981b9c-1c8d-42c6-8dcb-f80fbd554841" />

### Sesudah
<img width="1344" height="935" alt="image" src="https://github.com/user-attachments/assets/807dc026-5b47-4498-8e30-94f21c0a5ce7" />

  c. Pergerakan Pergelangan (menekan tombol "W" yang artinya berputar -5° terhadap sumbu Z, saya menekan 18 kali yang artinya -90° terhadap sumbu Z)
### Sebelum
<img width="1349" height="939" alt="image" src="https://github.com/user-attachments/assets/61dde71a-bc36-462e-b66c-37f8e99184d5" />

### Sesudah
<img width="1343" height="938" alt="image" src="https://github.com/user-attachments/assets/cf63e415-8ffc-4eea-89d0-2617ef535764" />

  d. Pergerakan Jari (menekan tombol-tombol kombinasi yang telah dijelaskan sebelumnya, berputar +5° terhadap sumbu Z setiap kali tombol kombinasi di tekan)
### Angka 1
<img width="1343" height="933" alt="image" src="https://github.com/user-attachments/assets/72a06f94-81d7-4c1d-b500-b8daad87d6d1" />

### Metal (Anak Muda, maklum)
<img width="1349" height="944" alt="image" src="https://github.com/user-attachments/assets/81d93652-1ee3-4440-97e0-95642d92091f" />

### Pose Laki-Laki (kl disuruh foto)
<img width="1347" height="943" alt="image" src="https://github.com/user-attachments/assets/fc913fda-7401-4915-b968-8b460a8fdf1d" />

