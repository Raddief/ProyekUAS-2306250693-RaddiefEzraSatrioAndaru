#include <stdio.h>
#include <math.h>

// Fungsi untuk menghitung solusi analitik
double analitik(double t, double i0, double R, double L) {
    return i0 * exp(-R / L * t);
}

// Fungsi utama
int main() {
    // Deklarasi dan inisialisasi parameter rangkaian
    double L = 1.0;          // Induktansi (Henry)
    double R = 1.5;          // Resistansi (Ohm)
    double i0 = 0.5;         // Arus awal (Ampere)
    double h = 0.5;          // Ukuran langkah waktu (detik)
    double t_max = 5.0;      // Waktu maksimum (detik)

    // Faktor trapezoidal untuk sistem RL linier
    double alpha = (1 - (h * R) / (2 * L)) / (1 + (h * R) / (2 * L));

    // Inisialisasi variabel
    double t = 0.0;
    double i_n = i0;
    double i_an;
    double error;

    // Header tabel
    printf("t (s)\tAnalitik (A)\tTrapezoidal (A)\tError Absolut\n");
    printf("----------------------------------------------------------\n");

    // Iterasi solusi numerik hingga t_max
    while (t <= t_max + 1e-6) {
        // Hitung nilai analitik pada waktu t
        i_an = analitik(t, i0, R, L);

        // Hitung error absolut
        error = fabs(i_an - i_n);

        // Cetak hasil
        printf("%.1f\t%.6f\t%.6f\t\t%.6f\n", t, i_an, i_n, error);

        // Perbarui nilai i menggunakan metode Trapezoidal
        i_n = alpha * i_n;

        // Perbarui waktu
        t += h;
    }

    return 0;
}
