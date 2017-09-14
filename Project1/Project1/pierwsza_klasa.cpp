#include "pierwsza_klasa.h"


void pierwsza_klasa::wypisz()
{
	std::cout << tekst;
	return;
}

void pierwsza_klasa::czas()
{
	double czas = time(NULL) + 2.5;
	while (time(NULL) < czas);
	return;
}
