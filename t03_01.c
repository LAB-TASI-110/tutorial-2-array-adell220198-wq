#include <stdio.h> // Untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Untuk fungsi utilitas umum, sesuai permintaan user
#include <string.h> // Untuk fungsi manipulasi string, sesuai permintaan user

int main() {
    int n;          // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int current_num; // Variabel sementara untuk menyimpan bilangan yang sedang dibaca
    int min_val;    // Variabel untuk menyimpan nilai terkecil
    int max_val;    // Variabel untuk menyimpan nilai terbesar

    // Langkah 1: Membaca bilangan pertama yang menyatakan jumlah data berikutnya (n)
    scanf("%d", &n);

    // Langkah 2: Membaca bilangan pertama dari n data untuk inisialisasi min_val dan max_val
    // Ini penting karena kita belum tahu rentang nilai yang akan masuk, jadi data pertama menjadi acuan awal
    if (n > 0) { // Pastikan ada setidaknya satu angka untuk dibaca setelah 'n'
        scanf("%d", &current_num);
        min_val = current_num;
        max_val = current_num;

        // Langkah 3: Melakukan perulangan untuk membaca sisa n-1 bilangan
        // Dimulai dari i=1 karena satu bilangan sudah dibaca untuk inisialisasi
        for (int i = 1; i < n; i++) {
            scanf("%d", &current_num); // Membaca bilangan berikutnya

            // Membandingkan dengan nilai minimum yang sudah ada
            if (current_num < min_val) {
                min_val = current_num; // Jika lebih kecil, update min_val
            }

            // Membandingkan dengan nilai maksimum yang sudah ada
            if (current_num > max_val) {
                max_val = current_num; // Jika lebih besar, update max_val
            }
        }
    } else {
        // Handle kasus jika n <= 0, misalnya dengan menginisialisasi nilai sentinel atau pesan error
        // Untuk tujuan tugas ini, kita asumsikan n akan selalu positif seperti di contoh.
        // Namun, dalam praktik yang baik, penanganan error untuk input n yang tidak valid perlu dipertimbangkan.
        // Untuk sekarang, jika n <= 0, program akan keluar tanpa menampilkan min/max yang valid.
        // Bisa juga diatur: min_val = 0; max_val = 0; atau nilai default lain jika tidak ada input data.
        // Sesuai contoh, asumsikan n selalu > 0.
        return 1; // Mengembalikan kode error jika n tidak valid
    }


    // Langkah 4: Menampilkan nilai terkecil dan terbesar sesuai format yang diminta
    printf("%d\n", min_val); // Menampilkan nilai terkecil diikuti baris baru
    printf("%d\n", max_val); // Menampilkan nilai terbesar diikuti baris baru

    return 0; // Mengembalikan 0 menandakan program berjalan sukses
}
