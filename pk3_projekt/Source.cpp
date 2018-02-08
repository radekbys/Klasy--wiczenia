#include <iostream>
#include "Airport_list.h"
#include "calculations.h"
#include "Find_flight.h"

//#include <vld.h>

using namespace std;

//void test_struktur_wyciekow();


int main()
{
	// test_struktur_wyciekow();


	//zmienne
	Find_flight omnitool;
	Airport_list airports;
	string name = "Lotniska.txt";

	Airport start_port;
	Airport end_port;

	unsigned int rezerwowane_bilety_E;
	unsigned int rezerwowane_bilety_C1;

	std:: vector< Flight *> loty;

	bool rezerwowanie;

	//blok try, tu dzia³a program
	try 
	{
		//wczytuje listê lotnisk z pliku
		omnitool.read_files(name, airports);

		//wczytuje listy lotów ka¿dego lotniska z plików
		omnitool.fill_flights(airports);

		//pobiera kopiê lotniska startowego
		start_port = omnitool.pobierz_start(airports);

		//pobiera kopiê lotniska koñcowego
		end_port = omnitool.pobierz_koniec(airports);

		//pobiera od u¿ytkownika liczbê i rodzaj biletów
		omnitool.ile_biletow(rezerwowane_bilety_E, rezerwowane_bilety_C1);

		//uzyskuje wektor wskaŸników na loty(1 lub 2) w których chcemy zarezerwowac miejsca
		loty = omnitool.znajdz_polaczenie(start_port, end_port, airports, rezerwowane_bilety_E, rezerwowane_bilety_C1);

		//uzyskuje potwierdzenie rezerwacji
		rezerwowanie = omnitool.czy_rezerwowac(loty, start_port, end_port, rezerwowane_bilety_E, rezerwowane_bilety_C1);

		//rezerwowanie biletow
		if (rezerwowanie)
		omnitool.rezerwuj(loty, rezerwowane_bilety_E, rezerwowane_bilety_C1);

		//wypisywanie do pliku
		omnitool.wypisz_pliki(airports);
	}



	catch (const char* info)
	{
		system("cls");

		cout << info  << endl  << endl;

		system("PAUSE");
		exit(1);
	}


	loty.clear();

	return 0;
}


/*void test_struktur_wyciekow()
{
	//test struktury danych listy lotnisk

	Airport* a, *b;
	a = new Airport;
	b = new Airport;
	a->set_name("Warszawa");
	b->set_name("Berlin");

	Flight *c = new Flight("NY", 16, 16);
	Flight *d = new Flight("London", 12, 145);

	a->add(*c);
	b->add(*d);

	Airport_list al;
	al.add(*a);
	al.add(*b);
	delete a;
	delete b;

	delete c;
	delete d;
}*/