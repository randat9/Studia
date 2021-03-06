
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class CPodstawowa {
public:

	CPodstawowa();
	int pokaz_stala();
	float pokaz_zmienno();
	void ustaw_stala(int st);
	void ustaw_zmienno(float zm);
	void ustaw_dol(int d);
	void ustaw_gora(int g);

private:
	int liczba_stala;
	float liczba_zmienno;
	int g;
	int d;
};

CPodstawowa::CPodstawowa() {
	liczba_stala = 0;
	liczba_zmienno = 0;
}

int CPodstawowa::pokaz_stala() {
	return liczba_stala;
}

float CPodstawowa::pokaz_zmienno() {
	return liczba_zmienno;
}

void CPodstawowa::ustaw_stala(int st) {
	liczba_stala = st;
}

void CPodstawowa::ustaw_zmienno(float zm) {
	liczba_zmienno = zm;
}

void CPodstawowa::ustaw_dol(int d) {
	liczba_stala = d;
}

void CPodstawowa::ustaw_gora(int g) {
	liczba_stala = g;
}



class CDruga : public CPodstawowa {

public:
	CDruga();
	~CDruga();
	void zrob_tablice();
	void wypelnij_tablica();
	void pokaz_tablice();


private:
	int *tab;
	int rozmiar;
	int czy_jest_tablica;
};

CDruga::CDruga(): CPodstawowa() {
	czy_jest_tablica = 0;
	rozmiar = 1;
}

CDruga::~CDruga() {
	delete[] tab;
}

void CDruga::zrob_tablice() {
	if (czy_jest_tablica == 0) {
		rozmiar = pokaz_stala();
		tab = new int[rozmiar];
	}
	czy_jest_tablica = 1;
}

void CDruga::wypelnij_tablica(int d, int g) {
	if (czy_jest_tablica > 0) {
		for (int i = 0; i < rozmiar; i++) {
			*(tab + i) = ustaw_dol() + rand() % (ustaw_gora() - ustaw_dol());
		}
	}
}

void CDruga::pokaz_tablice() {
	if (czy_jest_tablica > 0) {
		for (int i = 0; i < rozmiar; i++) {
			cout << *(tab + i) << endl;
		}
	}
}


int main()
{
	srand(time(0);
	int liczba1;
	float liczba2;
	int rozmiar_tab;
	int d, g;

	CDruga ob;

	//CPodstawowa *ptr;
	//ptr = new CPodstawowa;

	//cout << ptr->pokaz_stala() << endl;
	//cout << ptr->pokaz_zmienno() << endl;

	//cout << "Podaj liczbe staloprzecinkowa: " << endl;
	//cin >> liczba1;
	//cout << "Podaj liczbe zmiennoprzecinkowa: " << endl;
	//cin >> liczba2;

	//ptr->ustaw_stala(liczba1);
	//ptr->ustaw_zmienno(liczba2);

	//cout << ptr->pokaz_stala() << endl;
	//cout << ptr->pokaz_zmienno() << endl;

	cout << "Podaj rozmiar tablicy: " << endl;
	cin >> rozmiar_tab;
	cout << "Podaj dolny zakres: " << endl;
	cin >> d;
	cout << "Podaj gorny zakres: " << endl;
	cin >> g;

	ob.ustaw_stala(rozmiar_tab);
	ob.zrob_tablice();
	ob.wypelnij_tablica(d, g);
	ob.pokaz_tablice();

	return 0;
}