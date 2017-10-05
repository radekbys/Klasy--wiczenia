#include "Liczba_zespolona.h"


Liczba_zespolona::Liczba_zespolona()
{
	Im = 0;
	Re = 0;
	std::cout << "konstruktor bezargumentowy wywolany\n";
}

Liczba_zespolona::Liczba_zespolona(int im)
{
	Im = im;
	Re = 0;
	std::cout << "konstruktor jednoargumentowy wywolany\n";
}

Liczba_zespolona::Liczba_zespolona(int im, int re)
{
	Im = im;
	Re = re;
	std::cout << "konstruktor wieloargumentowy wywolany\n";
}

Liczba_zespolona::Liczba_zespolona(const Liczba_zespolona &arg)
{

	std::cout << "konstruktor kopiuj¹cy wywolany\n";
}

Liczba_zespolona::~Liczba_zespolona()
{
	std::cout << "destruktor wywolany\n";
}

void Liczba_zespolona::set_Im(int im)
{
	Im = im;
}

void Liczba_zespolona::set_Re(int re)
{
	Re = re;
}

int Liczba_zespolona::get_Im()
{
	return Im;
}

int Liczba_zespolona::get_Re()
{
	return Re;
}
