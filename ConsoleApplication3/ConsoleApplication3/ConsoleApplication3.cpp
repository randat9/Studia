// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class CDruga {
public:
	CDruga();
	void wypelnij_tablice(int dol, int gora);
	void pokaz_tablice();
	int licz();
	int najw();
	int najm();

private:
	int liczba_c;
	int liczba_f;
	int tab[10];
};

int main() {
	int dol, gora;
	srand(time(0));
	CDruga* tt[5];
	CDruga *ptr;
	cout << "Podaj dolna granice: ";
	cin >> dol;
	cout << "Podaj gorna granice: ";
	cin >> gora;

	for (int i = 0; i < 5; i++) {

		tt[i] = new CDruga;
		tt[i]->wypelnij_tablice(dol, gora);
		tt[i]->pokaz_tablice();
		cout << "Suma liczb tablicy wynosi: " << tt[i]->licz() << endl;
		cout << "Najmniejszy element tablicy: " << tt[i]->najm() << endl;
		cout << "Najwiekszy element tablicy: " << tt[i]->najw() << endl;
		cout << endl << endl;
	}

	//ptr = new CDruga;
	//cout << "Tablica przed wypelnieniem: " << endl;
	//ptr->pokaz_tablice();
	//cout << "Tablica po wypelnieniu: " << endl;
	//ptr->wypelnij_tablice(dol, gora);
	//ptr->pokaz_tablice();
	//cout << "Suma liczb tablicy wynosi: " << ptr->licz() << endl;
	//cout << "Najwiekszy element tablicy: " << ptr->najw() << endl;
	//cout << "Najmniejszy element tablicy: " << ptr->najm() << endl;
	for (int i = 0; i < 5; i++) {
		delete tt[i];
	}
	return 0;
}

CDruga::CDruga() {
	for (int i = 0; i < 10; i++) {
		tab[i] = 0;
	}
}

void CDruga::wypelnij_tablice(int dol, int gora) {

	//srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		tab[i] = dol + rand() % (gora - dol);
	}
}

void CDruga::pokaz_tablice() {
	for (int i = 0; i < 10; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;
}

int CDruga::licz() {
	int suma = 0;
	for (int i = 0; i < 10; i++) {
		suma = suma + tab[i];
	}
	return suma;
}

int CDruga::najw() {
	int najw = tab[0];
	for (int i = 0; i < 10; i++) {
		if (najw < tab[i]) najw = tab[i];
	}

	return najw;
}

int CDruga::najm() {
	int najm = tab[0];
	for (int i = 0; i < 10; i++) {
		if (najm > tab[i]) najm = tab[i];
	}

	return najm;
}