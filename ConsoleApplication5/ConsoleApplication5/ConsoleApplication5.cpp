// ConsoleApplication5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class CTestWsk {
public:
	CTestWsk();
	~CTestWsk();
	int pokaz_pierwsza();
	void ustaw_pierwsza(int wart);
	int pokaz_druga();
	void ustaw_druga(int ww);
	void wypelnij_tablice(int n, int g, int d);
	void pokaz_tablice(int n);

private:
	int pierwsza_liczba;
	int druga_liczba;
	int* tablica;
};

CTestWsk::CTestWsk() {
	pierwsza_liczba = 0;
	druga_liczba = 0;
}

CTestWsk::~CTestWsk() {
	delete[] tablica;
}

int CTestWsk::pokaz_pierwsza() {
	return pierwsza_liczba;
}
void CTestWsk::ustaw_pierwsza(int wart) {
	pierwsza_liczba = wart;
}
int CTestWsk::pokaz_druga() {
	return druga_liczba;
}
void CTestWsk::ustaw_druga(int ww) {
	druga_liczba = ww;
}
void CTestWsk::wypelnij_tablice(int n,int d, int g) {
	tablica = new int[n];
	for (int i = 0; i < n; i++) {
		*(tablica + i) = d + rand() % (g - d);
	}
}
void CTestWsk::pokaz_tablice(int n) {
	for (int i = 0; i < n; i++) {
		cout << (*(tablica+i)) << "\t";
	}
	cout << endl;
}

int main()
{
	srand(time(0));
	CTestWsk* tab[5];
	int liczba1; 
	int liczba2, n;
	CTestWsk ppp;
	CTestWsk *ptr;
	//ptr = &ppp;
	//ptr = new CTestWsk;
	for (int i = 0; i < 5; i++) {
		tab[i] = new CTestWsk;
		cout << "Podaj pierwsza liczbe (calkowita): " << endl;
		cin >> liczba1;
		cout << "Podaj druga liczbe (zmienooprzecinkowa): " << endl;
		cin >> liczba2;
		cout << "Podaj rozmiar tablicy: " << endl;
		cin >> n;
		tab[i]->ustaw_pierwsza(liczba1);
		tab[i]->ustaw_druga(liczba2);
		tab[i]->wypelnij_tablice(n, liczba1, liczba2);
	}

	for (int i = 0; i < 5; i++) {
		cout << "Pierwsza wartosc zmiennej dynamicznej: " << tab[i]->pokaz_pierwsza() << endl;
		cout << "Druga wartosc zmiennej dynamicznej: " << tab[i]->pokaz_druga() << endl;
		tab[i]->pokaz_tablice(n);
	}

	for (int i = 0; i < 5; i++) {
		delete tab[i];
	}



	//cout << "Podaj poczatek zakresu: " << endl;
	//cin >> liczba1;
	//cout << "Podaj koniec zakresu: " << endl;
	//cin >> liczba2;

	//ptr->wypelnij_tablice(liczba1, liczba2);
	//ptr->pokaz_tablice();

	//ptr->ustaw_pierwsza(liczba1);
	//cout << "Pierwsza wartosc zmiennej dynamicznej: " << ptr->pokaz_pierwsza() << endl;
	//ptr->ustaw_druga(liczba2);
	//cout << "Druga wartosc zmiennej dynamicznej: " << ptr->pokaz_druga() << endl;

	//cout << "Pierwsza wartosc: " << ppp.pokaz_pierwsza() << endl;
	//ppp.pokaz_tablice();
	//cout << "Druga wartosc: " << ptr->pokaz_druga() << endl;

	//delete ptr;
	return 0;
}
