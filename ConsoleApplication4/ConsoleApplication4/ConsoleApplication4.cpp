#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Jakas {
public:
	Jakas();
	~Jakas();
	void rob_tablice(int rozmiar, int d, int g);
	void pokaz_tablice(int rr);
	void sortuj_tablice(int rozmiar);

private:
	int *tab;
	bool istnieje;
};

Jakas::Jakas() {
	istnieje = false;
}

void Jakas::sortuj_tablice(int rozmiar) {
	if (istnieje == true) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 1; j < rozmiar - i; j++) {
				if ((*(tab + j - 1)) > (*(tab + j))) {
					swap((*(tab + j - 1)), (*(tab + j)));
				}
			}
		}
	}
}

void Jakas::rob_tablice(int rozmiar, int d, int g) {
	tab = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		*(tab + i) = d + rand() % (g - d);
	}
	istnieje = true;
}

void Jakas::pokaz_tablice(int rr) {
	if (istnieje == true) {
		for (int i = 0; i < rr; i++) {
			cout << *(tab + i) << "\t";
		}
		cout << endl;
	}
	else
		cout << "Tablica nie zostala utworzona" << endl;
}

Jakas::~Jakas() {
	cout << "Działa destruktor." << endl;
	delete[]tab;
	istnieje = false;
}

int main() {
	int rozmiar, d, g;
	srand(time(0));
	cout << "Podaj rozmiar tablicy: " << endl;
	cin >> rozmiar;
	cout << "Podaj dolny zakres tablicy: " << endl;
	cin >> d;
	cout << "Podaj gorny zakres tablicy: " << endl;
	cin >> g;
	Jakas *ptr;
	ptr = new Jakas;
	ptr->rob_tablice(rozmiar, d, g);
	ptr->pokaz_tablice(rozmiar);
	ptr->sortuj_tablice(rozmiar);
	ptr->pokaz_tablice(rozmiar);
	return 0;
}
