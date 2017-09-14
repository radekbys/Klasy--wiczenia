#include "pierwsza_klasa.h"

using namespace std;

int main()
{
	pierwsza_klasa witaj_swiecie;

	witaj_swiecie.tekst = "Witaj swiecie!!!\n";

	witaj_swiecie.wypisz();

	witaj_swiecie.czas();

	cout << "koniec";

	return 0;
}