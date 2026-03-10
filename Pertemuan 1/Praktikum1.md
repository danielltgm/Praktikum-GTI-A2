# Pertemuan 1 - GTI A2

## Identitas
- **Nama** : Daniel Lamganda Tua Gultom  
- **NIM**  : 24060124120048  
- **Lab**  : A2  

---

# Output Lab

## 1. Shapes Demo
<img width="954" height="767" alt="image" src="https://github.com/user-attachments/assets/d70e7f2b-f091-41d4-a4a7-c30c6fa47d40" />

## 2. Primitif Drawing
<img width="958" height="757" alt="image" src="https://github.com/user-attachments/assets/48dfe3bf-4587-46ec-ac41-9a2b362086b2" />

## 3. Membuat Titik
<img width="960" height="765" alt="image" src="https://github.com/user-attachments/assets/8b3231eb-b244-4b26-a1d2-9ab07f54bcf8" />

## 4. Membuat Garis
<img width="958" height="758" alt="image" src="https://github.com/user-attachments/assets/a0ed4de2-8adc-4eda-aec3-68cea395b864" />

## 5. Membuat Segitiga
<img width="953" height="762" alt="image" src="https://github.com/user-attachments/assets/d0445a95-7272-4e83-b8db-8f052441e784" />

## 6. Membuat Segiempat
<img width="957" height="766" alt="image" src="https://github.com/user-attachments/assets/4d5d64ab-5fb1-4577-bb75-91b5e7dc37dc" />


# Point Keaktifan
### 1.
Fungsi `glColor3f(1.0f, 0.0f, 0.0f)` pada OpenGL digunakan untuk mengatur warna objek yang akan digambar menggunakan tiga komponen warna RGB (Red, Green, Blue). Angka **3** pada `glColor3f` menunjukkan bahwa fungsi ini menggunakan tiga parameter warna. Pada contoh tersebut, nilai **1.0f** pada komponen merah berarti warna merah ditampilkan secara maksimal, sedangkan **0.0f** pada hijau dan biru berarti kedua warna tersebut tidak digunakan, sehingga menghasilkan warna merah. Huruf **f** di belakang angka menunjukkan bahwa nilai tersebut bertipe data **float** dengan rentang nilai **0.0 sampai 1.0**. Untuk menghasilkan warna hijau digunakan `glColor3f(0.0f, 1.0f, 0.0f)`.

### 2.
Di dalam OpenGL terdapat fungsi `glColor4f()`, yang merupakan pengembangan dari `glColor3f()`. Fungsi ini menggunakan empat komponen warna yaitu **Red (R), Green (G), Blue (B), dan Alpha (A)**. Komponen **Alpha** digunakan untuk mengatur tingkat transparansi suatu objek. Nilai alpha berada pada rentang **0.0 sampai 1.0**, di mana **0.0 berarti sangat transparan** dan **1.0 berarti tidak transparan**.

### 3.
Fungsi `glVertex3f(-0.10, -0.10, 0.00)` digunakan untuk menentukan posisi sebuah titik (vertex) dalam ruang koordinat tiga dimensi pada OpenGL. Angka **3** menunjukkan bahwa fungsi ini menggunakan tiga koordinat yaitu **x, y, dan z**. Pada contoh tersebut titik berada pada posisi **x = -0.10**, **y = -0.10**, dan **z = 0.00**.

### 4.
Fungsi `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)` digunakan untuk mengatur mode tampilan awal pada program OpenGL yang menggunakan GLUT. Parameter **GLUT_SINGLE** berarti menggunakan **single buffering**, sedangkan **GLUT_RGB** berarti menggunakan sistem warna **RGB (Red, Green, Blue)**.

# Tugas
### Membuat program dengan memanfaatkan fungsi pada OpenGL
<img width="893" height="648" alt="image" src="https://github.com/user-attachments/assets/a181045c-c6e6-4777-970c-a5d003a494c6" />

### 1. GL_POINTS
#### GL_POINTS adalah primitif OpenGL yang digunakan untuk menggambar titik tunggal pada layar. Setiap koordinat yang diberikan dengan fungsi glVertex akan ditampilkan sebagai satu titik. Fungsi ini biasanya digunakan untuk menampilkan koordinat tertentu dalam ruang grafis atau sebagai dasar dalam pembuatan bentuk grafis yang lebih kompleks. Ukuran titik dapat diatur menggunakan fungsi glPointSize().

### 2. GL_LINES
#### GL_LINES digunakan untuk menggambar garis lurus antara dua titik. Setiap dua vertex yang dimasukkan akan membentuk satu garis. Jika ada empat vertex, maka akan terbentuk dua garis yang terpisah. Fungsi ini digunakan ketika ingin menggambar beberapa garis yang tidak saling terhubung.

### 3. GL_LINE_STRIP
#### GL_LINE_STRIP digunakan untuk menggambar beberapa garis yang saling terhubung secara berurutan. Garis pertama dibuat dari vertex pertama ke vertex kedua, lalu vertex kedua ke vertex ketiga, dan seterusnya. Bentuk yang dihasilkan adalah rangkaian garis yang saling tersambung tetapi tidak menutup kembali ke titik awal.

### 4. GL_LINE_LOOP
#### GL_LINE_LOOP hampir sama dengan GL_LINE_STRIP, yaitu menggambar garis yang saling terhubung. Perbedaannya adalah pada titik terakhir yang otomatis dihubungkan kembali ke titik pertama, sehingga membentuk sebuah loop atau bentuk tertutup.

### 5. Perbedaan GL_LINES, GL_LINE_STRIP, dan GL_LINE_LOOP
#### GL_LINES membuat garis terpisah-pisah, setiap dua titik membentuk satu garis.
#### GL_LINE_STRIP membuat garis berurutan dan saling terhubung, tetapi tidak menutup bentuk.
#### GL_LINE_LOOP sama seperti line strip tetapi garis terakhir otomatis terhubung ke titik pertama sehingga membentuk loop tertutup.

### 6. GL_TRIANGLES
#### GL_TRIANGLES digunakan untuk menggambar bentuk segitiga dengan cara setiap tiga vertex membentuk satu segitiga. Jika ada enam vertex maka akan terbentuk dua segitiga yang terpisah.

### 7. GL_TRIANGLE_STRIP
#### GL_TRIANGLE_STRIP digunakan untuk membuat beberapa segitiga yang saling berbagi sisi. Setelah segitiga pertama terbentuk dari tiga vertex, setiap vertex berikutnya akan membentuk segitiga baru dengan dua vertex sebelumnya. Cara ini lebih efisien karena membutuhkan lebih sedikit vertex.

### 8. GL_TRIANGLE_FAN
#### GL_TRIANGLE_FAN digunakan untuk membuat beberapa segitiga yang berbagi satu titik pusat. Semua segitiga akan memiliki satu vertex yang sama sebagai pusat, sedangkan vertex lainnya menyebar di sekelilingnya sehingga bentuknya seperti kipas (fan).

### 9. Perbedaan GL_TRIANGLES, GL_TRIANGLE_STRIP, dan GL_TRIANGLE_FAN
#### GL_TRIANGLES membuat segitiga terpisah, setiap tiga vertex menjadi satu segitiga.
#### GL_TRIANGLE_STRIP membuat segitiga yang saling terhubung dan berbagi sisi.
#### GL_TRIANGLE_FAN membuat segitiga yang berpusat pada satu titik yang sama, seperti kipas.

### 10. GL_QUADS
#### GL_QUADS digunakan untuk menggambar segiempat dengan empat vertex. Setiap empat vertex yang dimasukkan akan membentuk satu bidang segiempat.

### 11. GL_QUAD_STRIP
#### GL_QUAD_STRIP digunakan untuk membuat beberapa segiempat yang saling terhubung secara berurutan. Setiap dua vertex tambahan akan membentuk segiempat baru yang berbagi sisi dengan segiempat sebelumnya.

### 12. Perbedaan GL_QUADS dan GL_QUAD_STRIP
#### GL_QUADS membuat segiempat yang berdiri sendiri, setiap empat vertex membentuk satu bidang.
#### GL_QUAD_STRIP membuat segiempat yang saling terhubung dan berbagi sisi sehingga membentuk rangkaian segiempat.
