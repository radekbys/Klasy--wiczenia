#include "Calculations.h"

//oblicza cenê biletu dla
double price(C1_seat c, double distance)
{
	double price = distance * c.get_tarrif() + c.get_base_cost();
	return price;
}

//prze³adowana funkcja
double price(E_seat e, double distance)
{
	double price = distance * e.get_tarrif() + e.get_base_cost();
	return price;
}


//oblicza dystans miêdy lotniskami
double distance(Airport a, Airport b)
{
	//zwraca odleg³oœc miêdzy dwoma punktami na globie w km

	double earthRadius = 6371000; //promien ziemi

	double difflat = a.get_latitude() - b.get_latitude(); //ró¿nica szerokoœci geograficznych
	double difflon = a.get_longtitude() - b.get_longtitude(); //ró¿nica d³ugoœci geograficznych

	double A = sin(difflat / 2) * sin(difflat / 2) + cos(b.get_latitude())
		* cos(a.get_latitude()) * sin(difflon / 2) * sin(difflon / 2);

	double B = 2 * asin(sqrt(A));

	double distance = (earthRadius*B) / 1000;

	return distance;
}