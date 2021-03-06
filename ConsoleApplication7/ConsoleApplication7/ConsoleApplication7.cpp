#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class CPierwsza
{
public:
	CPierwsza();
	void zmien_calk(int aa);
	int pokaz_calk();
	void zmien_gora(int gg);
	void zmien_dol(int dd);
	int pokaz_gora();
	int pokaz_dol();

private:
	int liczb_c;
	int gora;
	int dol;
};

class CDruga :public CPierwsza
{
public:
	CDruga();
	~CDruga();
	void zrob_tablice();
	void wypelnij_tablice();
	void pokaz_tablice();
	int rozmiar;
private:
	int *tab;
	int czy_jest_tablica;
};

CPierwsza::CPierwsza()
{
	liczb_c = 0;
	gora = 0;
	dol = 0;
}

void CPierwsza::zmien_calk(int aa)
{
	liczb_c = aa;
}

void CPierwsza::zmien_dol(int dd) 
{
	dol = dd;
}

void CPierwsza::zmien_gora(int gg)
{
	gora = gg;
}

int CPierwsza::pokaz_calk()
{
	return liczb_c;
}

int CPierwsza::pokaz_gora()
{
	return gora;
}

int CPierwsza::pokaz_dol()
{
	return dol;
}

CDruga::CDruga()
{
	czy_jest_tablica = 0;
}

CDruga::~CDruga()
{
	delete[] tab;
}

void CDruga::zrob_tablice()
{
	if (czy_jest_tablica == 0) {
		rozmiar = pokaz_calk();
		tab = new int[rozmiar];
	}
	czy_jest_tablica = 1;
}
void CDruga::wypelnij_tablice()
{
	if (czy_jest_tablica > 0) {
		for (int i = 0; i < rozmiar; i++)
			*(tab + i) = pokaz_dol() + rand() % (pokaz_gora() - pokaz_dol());
	}
}
void CDruga::pokaz_tablice()
{
	if (czy_jest_tablica>0){
		for (int i = 0; i < rozmiar; i++){
			cout << *(tab = i) << " ";
		cout << endl;
		}
}

int main()
{
	int dolny_zakres, gorny_zakres, rozmiar_tablicy;
	CDruga ob;
	srand(time(NULL));
	cout << "Podaj rozmiar tablicy: ";
	cin >> rozmiar_tablicy;
	cout << "Podaj dolny zakres: ";
	cin >> dolny_zakres;
	cout << "Podaj gorny zakres: ";
	cin >> gorny_zakres;
	ob.zmien_calk(rozmiar_tablicy);
	ob.zmien_dol(dolny_zakres);
	ob.zmien_gora(gorny_zakres);
	ob.zrob_tablice();
	ob.wypelnij_tablice();
	ob.pokaz_tablice();
	return 0;
}