#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAX_POINTS 100000  // Maksymalna liczba punktow

// Funkcja obliczajaca odleglosc euklidesowa
// (odleglosc pitagorejska) miedzy dwoma punktami (x1, y1) i (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



int main() {

    srand(time(NULL));

    int n;  // Liczba punktow
    printf("Podaj liczbe punktow: ");
   scanf("%d", &n);
    printf("\n");
	double x[MAX_POINTS], y[MAX_POINTS];  // Tablice przechowujace wspolrzedne punktow
    int nearest[MAX_POINTS];  // Tablica przechowuj aca pozycje najblizszych sasiadów

    // Wczytanie wspolrzednych punktow
    for (int i = 0; i < n; i++) {
    	//x[i] = rand() % 100-50;
    	//y[i] = rand() % 100-50;
    	//printf("Punkt %d: x= %.f, y= %.f \n",i+1, x[i], y[i]);
        printf("Punkt %d: \n",i+1); // odliczmy ilosc punktów od 1, nie od 0
        printf(" Podaj wspolrzedne punktu (x): ");
        scanf("%lf",&x[i]);
        printf(" Podaj wspolrzedne punktu (y): ");
        scanf("%lf",&y[i]);
        printf("\n");


    }
    // Dla kazdego punktu znajdz najblizszego sasiada
    for (int i = 0; i < n; i++) {
        double min_distance = -1;  // Minimalna odleglosc
        // (zaczynamy od wartosci -1, aby znalesc pierwsza odleglosc)
        int nearest_index = -1;  // Indeks najblizszego punktu

        for (int j = 0; j < n; j++) {
            if (i != j) {  // Nie porownujemy punktu z samym soba
                double dist = distance(x[i], y[i], x[j], y[j]);

                // Sprawdzamy, czy znalezlismy mniejsza odleglosc
                if (min_distance == -1 || dist < min_distance) {
                    min_distance = dist;
                    nearest_index = j;
                }
            }
        }

        // Zapisujemy indeks najblizszego punktu
        nearest[i] = nearest_index;
    }

    // Wyswietlanie wynikow
    printf("\nIndeksy najblizszych sasiadow:\n");
    for (int i = 0; i < n; i++) {
        printf("Dla punktu %d najblizszy sasiad to punkt %d \n", i + 1, nearest[i] + 1);
        // dodajemy 1 do najblizszego sasiada by zgadzala sie z iloscia punktów
    }

    return 0;}

