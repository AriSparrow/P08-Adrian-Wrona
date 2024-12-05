#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Funkcja obliczajaca odleglosc euklidesowa miedzy dwoma punktami
double e_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Funkcja do obliczenia najblizszego sasiada
void find_nearest_neighbors(int n, double x[], double y[], int neighbors[]) {
    for (int i = 0; i < n; i++) {
        double min_distance = 1e10;  // Bardzo duza wartosc poczatkowa
        int nearest = -1;

        // Sprawdzamy odleglosc kazdego punktu od innych punktów
        for (int j = 0; j < n; j++) {
            if (i != j) {  // Nie porównujemy punktu z samym soba
                double distance = e_distance(x[i], y[i], x[j], y[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    nearest = j;
                }
            }
        }
        neighbors[i] = nearest;  // Zapisujemy indeks najblizszego sasiada
    }
}

int main() {
    int n[] = { 2500, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};  // Liczba punktów do testów
    srand(time(NULL));  // Inicjalizacja generatora liczb losowych
    for (int t = 0; t < 10; t++) {
        int points_count = n[t];  // Liczba punktów w biezacym tescie

        double x[points_count], y[points_count];
        int neighbors[points_count];

        // Generowanie losowych wspólrzednych punktów
        printf("\nGenerowanie wspolrzednych punktow dla n = %d...\n", points_count);
        for (int i = 0; i < points_count; i++) {
            // Losowanie wspólrzednych x i y w zakresie [0, 100]
            x[i] = rand() % 100 ;  // Liczby losowe w przedziale [0, 100]
            y[i] = rand() % 100 ;  // Liczby losowe w przedziale [0, 100]
    }

        // Zmierzenie czasu wykonania
        clock_t start = clock();

        // Wywolanie funkcji do znalezienia najblizszych sasiadów
        find_nearest_neighbors(points_count, x, y, neighbors);

        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Czas wykonania dla %d punktow: %f sekundy\n", points_count, time_taken);


    }

    return 0;
}

