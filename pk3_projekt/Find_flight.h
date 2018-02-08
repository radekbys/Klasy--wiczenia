#ifndef _FIND_FLIGHT_H_
#define _FIND_FLIGHT_H_

#include "Airport_list.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>  
#include "calculations.h"

class Find_flight
{
public:

	void read_files(std :: string name , Airport_list& ar);

	void fill_flights(Airport_list& ar);

	void wypisz_lotniska(Airport_list& ar);

	Airport pobierz_start(Airport_list & ar);

	Airport pobierz_koniec(Airport_list & ar);

	void ile_biletow(unsigned int & E, unsigned int & C1);

	std::vector <Flight *>  znajdz_polaczenie(Airport& start, Airport& finish, Airport_list & ar,const int &rez_E , const int& rez_C1);

	bool czy_rezerwowac(std::vector <Flight *> & loty, Airport & beginning, Airport & finish, const int& rez_E, const int& rez_C1);

	void rezerwuj(std::vector <Flight *> & loty, const int& rez_E, const int& rez_C1);

	void wypisz_pliki(Airport_list& ar);

	Find_flight();
	~Find_flight();
};

#endif