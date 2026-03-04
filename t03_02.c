#include <stdio.h>   // Untuk printf dan scanf
#include <limits.h>  // Untuk INT_MAX dan INT_MIN
#include <float.h>   // Untuk DBL_MAX

int main() {
    int n; // Variabel untuk menyimpan jumlah baris masukan data
    
    // Membaca nilai n dari input
    // Asumsi: n akan selalu berada di antara -100 dan 100 seperti yang dijelaskan, dan n > 0 untuk data yang valid.
    if (scanf("%d", &n) != 1) {
        // Handle error jika input n tidak valid
        fprintf(stderr, "Error: Gagal membaca nilai n.\n");
        return 1; 
    }

    // Inisialisasi nilai minimum, maksimum, dan rata-rata terendah
    // Menggunakan INT_MAX dan INT_MIN dari <limits.h> untuk inisialisasi yang robust
    // Menggunakan DBL_MAX dari <float.h> untuk inisialisasi rata-rata terendah
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    double min_avg = DBL_MAX;

    int prev_val; // Variabel untuk menyimpan nilai sebelumnya
    int current_val; // Variabel untuk menyimpan nilai yang sedang dibaca
    
    // Flag untuk menandakan apakah ini adalah iterasi pertama setelah membaca n
    // Ini penting untuk penanganan 'prev_val' dan inisialisasi min_avg
    int first_data_read = 0; 

    // Loop untuk membaca n baris nilai berikutnya
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &current_val) != 1) {
            // Handle error jika input data tidak valid
            fprintf(stderr, "Error: Gagal membaca data ke-%d.\n", i + 1);
            return 1;
        }

        // Memperbarui nilai minimum dan maksimum
        if (current_val < min_val) {
            min_val = current_val;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }

        // Jika ini bukan nilai pertama yang dibaca (yaitu, ada nilai sebelumnya untuk perbandingan)
        if (first_data_read == 1) {
            // Hitung rata-rata dari nilai sebelumnya dan nilai saat ini
            // Penting: Lakukan type casting ke double untuk perhitungan floating point
            double current_avg = (double)(prev_val + current_val) / 2.0;

            // Perbarui rata-rata terendah jika rata-rata saat ini lebih kecil
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
        } else {
            // Setelah membaca nilai pertama, set flag agar iterasi berikutnya bisa menghitung rata-rata
            first_data_read = 1;
        }
        
        // Simpan nilai saat ini sebagai nilai sebelumnya untuk iterasi berikutnya
        prev_val = current_val;
    }

    // Mencetak hasil sesuai format yang diminta
    printf("%d\n", min_val);      // Barisan keluaran kedua: nilai terkecil
    printf("%d\n", max_val);      // Barisan keluaran ketiga: nilai terbesar
    
    // Barisan keluaran keempat: nilai rata-rata terendah dengan 2 digit presisi
    // Periksa jika n < 2, karena min_avg tidak akan terhitung
    if (n < 2) {
        printf("N/A\n"); // Atau pesan lain jika tidak ada pasangan untuk dihitung rata-rata
    } else {
        printf("%.2f\n", min_avg);
    }

    return 0; // Program berakhir dengan sukses
}