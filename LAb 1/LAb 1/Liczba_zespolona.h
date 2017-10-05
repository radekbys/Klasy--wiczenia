#ifndef LICZBA_ZESPOLONA_H
#define LICZBA_ZESPOLONA_H

#include <iostream>

class Liczba_zespolona
{
	int Im;
	int Re;

	Liczba_zespolona();
	Liczba_zespolona(int im);
	Liczba_zespolona(int im, int re);
	Liczba_zespolona(const Liczba_zespolona &arg) ;
	~Liczba_zespolona();

public:
	void set_Im(int);
	void set_Re(int);

	int get_Im();
	int get_Re();
};
#endif