#include <iostream>
using namespace std;

class CDruga {
public:
	CDruga();
	void wypelnij_tablice();
	void pokaz_tablice();

private:
	int tab[10];
};

int main() {
	CDruga ob;
	ob.wypelnij_tablice;
	ob.pokaz_tablice;
	return 0;
}

void CDruga::wypelnij_tablice() {
	for (int i = 0; i < 10; i++) {
		tab[i] = i + 1;
	}
}

void CDruga::pokaz_tablice() {
	for (int i = 0; i < 10; i++) {
		cout << tab[i] << endl;
	}
}