#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h>  // Untuk EXIT_SUCCESS
#include <limits.h>  // Untuk INT_MAX dan INT_MIN

int main(void) {
    int n;
    int current_num;
    int min_val = INT_MAX; // Inisialisasi min_val dengan nilai integer terbesar
    int max_val = INT_MIN; // Inisialisasi max_val dengan nilai integer terkecil
    
    // Inisialisasi rata-rata berturut-turut dengan nilai ekstrem yang sesuai
    // Menggunakan nilai yang cukup besar/kecil untuk memastikan nilai pertama akan selalu memperbarui
    double min_avg_consecutive = 1e38;  
    double max_avg_consecutive = -1e38; 
    
    int prev_num; // Menyimpan angka sebelumnya untuk perhitungan rata-rata
    int i;        // Iterator loop

    // Baca nilai n
    if (scanf("%d", &n) != 1) {
        // Penanganan error jika input n gagal
        fprintf(stderr, "Error: Gagal membaca nilai n.\n");
        return EXIT_FAILURE;
    }

    // Periksa apakah n positif untuk menghindari loop yang tidak perlu atau error
    if (n <= 0) {
        // Jika n tidak positif, tidak ada angka yang akan diproses
        // Output akan mencerminkan nilai inisialisasi atau kasus tanpa data
        printf("%d\n", min_val == INT_MAX ? 0 : min_val); // Atau bisa juga menampilkan pesan error/0
        printf("%d\n", max_val == INT_MIN ? 0 : max_val); // Atau bisa juga menampilkan pesan error/0
        printf("%.2f\n", 0.00); // Tidak ada rata-rata jika n <= 1
        printf("%.2f\n", 0.00); // Tidak ada rata-rata jika n <= 1
        return EXIT_SUCCESS;
    }

    // Loop untuk membaca n angka berikutnya
    for (i = 0; i < n; i++) {
        if (scanf("%d", &current_num) != 1) {
            // Penanganan error jika input angka gagal
            fprintf(stderr, "Error: Gagal membaca angka ke-%d.\n", i + 1);
            return EXIT_FAILURE;
        }

        // Perbarui nilai minimum dan maksimum
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Hitung rata-rata dua angka berturut-turut jika sudah ada angka sebelumnya
        if (i > 0) {
            double current_avg = (double)(prev_num + current_num) / 2.0;
            
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }

        // Simpan angka saat ini sebagai angka sebelumnya untuk iterasi berikutnya
        prev_num = current_num;
    }

    // Output hasil sesuai format yang diminta
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    // Untuk rata-rata, jika n <= 1, maka tidak ada pasangan berurutan
    // Kita cek apakah min_avg_consecutive masih di nilai inisialisasi
    if (n <= 1) {
        printf("%.2f\n", 0.00); // Atau bisa disesuaikan dengan kebutuhan, misal NAN
        printf("%.2f\n", 0.00); // Atau bisa disesuaikan dengan kebutuhan, misal NAN
    } else {
        printf("%.2f\n", min_avg_consecutive);
        printf("%.2f\n", max_avg_consecutive);
    }

    return EXIT_SUCCESS; // Program berhasil dieksekusi
}
