#include "Seat.h"


//rezerwowanie miejsca i zwalnianie rezerwacji
void C1_seat::reserve()
{
	reserved = true;
}

void C1_seat::release_reserve()
{
	reserved = false;
}

void E_seat::reserve()
{
	reserved = true;
}

void E_seat::release_reserve()
{
	reserved = false;
}


//konstruktory
C1_seat::C1_seat()
{
	reserved = false;
	tarrif = 0.5;
	base_cost = 60;
}

E_seat::E_seat()
{
	reserved = false;
	tarrif = 0.4;
	base_cost = 30;
}


//pobieranie i ustawianie taryfy
double Seat::get_tarrif() const
{
	return tarrif;
}

double Seat::get_base_cost() const
{
	return base_cost;
}


//sprawdza zarezerwowanie

bool Seat::is_reserved()
{
	if (reserved)
		return true;
	return false;
}