#include "Find_flight.h"





void Find_flight::read_files(std::string name, Airport_list& ar)
{
	//wczytuje dane dotycz¹ce lotnisk, ich nazwy i po³o¿eni
	
	std::fstream  file;
	file.open(name , std::ios::in);

		if (!file.good())
		{
			throw "cannot open datafile\n";
		}

		//dane lotniska czytane z pliku
		std::string word;
		double lon;
		double lat;

		while (true)
		{
			//wype³nianie listy lotnisk

			file >> word >> lon >> lat;
			if (file.eof())
				break;
			Airport *a = new Airport(word,lon,lat);
			ar.add(*a);
			delete a;
		}

	file.close();
	return;

	//brak wycieków na tym etapie
}

void Find_flight::fill_flights(Airport_list & ar)
{
	std::fstream  file;
	
	//potrzebne wskaŸniki pomocnicze
	element * helper = ar.head;
	Flight * wsk = nullptr;
	//element_flights* flights;


	//zmienne odczytywane z pliku
	std::string destination;
	long long int departure;
	long long int arrival;
	int E_seats, C1_seats, E_reserved, C1_reserved;

	//czytanie z pliku
	while (helper)
	{
		//czytanie plików kolejnych lotnisk

		file.open(helper->port.get_name() + ".txt", std::ios::in);
	
		if (!file.good())
			throw "cannot open flights files\n";

	
		while (true)
		{
			//wype³nianie list lotów kolejnych lotnisk

			file >> destination >> departure >> arrival >> E_seats >>C1_seats >>E_reserved >> C1_reserved;

			if (file.eof())
				break;

			wsk = new Flight(destination, departure, arrival, E_seats, C1_seats, E_reserved, C1_reserved);

			helper->port.add(*wsk);

			delete wsk;
		}

		//przejœcie do nastêpnego lotniska
		helper = helper->next;

		//zamkniêcie pliku by nie spowodowac niepotrzebnych zmian
		file.close();
	}
}

void Find_flight::wypisz_lotniska(Airport_list & ar)
{
	//wypisuje w konsoli ponumerowane lotniska

	element * helper = ar.head;

	system("cls");

	for (int i = 0; helper; i++)
	{
		std:: cout <<i  << ".  "<<helper->port.get_name() <<std:: endl;
		helper = helper->next;
	}
}

Airport Find_flight::pobierz_start(Airport_list & ar)
{
	//Metoda ta pobiera od u¿ytkownika lotniska pocz¹tkowego

	wypisz_lotniska(ar);
	int nr_pocz;
	std::cout << "Podaj numer lotniska poczatkowego:  ";
	std::cin >> nr_pocz;

	Airport zwracany;

	element* helper = ar.head;

	if (!helper)
		throw "brak lotnisk\n";

	//pêtla poni¿ej wyszukuje strukturê z po¿¹danym lotniskiem
	while (nr_pocz > 0)
	{
		helper = helper->next;
		if (!helper)
			throw "nie ma lotniska o tym numerze\n";//niepowodzenie, zwrot wyj¹tku
		nr_pocz--;
	}

	zwracany = helper->port;

	system("cls");

	return zwracany;

}

Airport Find_flight::pobierz_koniec(Airport_list & ar)
{
	//Metoda ta pobiera od u¿ytkownika lotniska koñcowego, dzia³a jak ta powy¿ej

	wypisz_lotniska(ar);
	int nr_pocz;
	std::cout << "Podaj numer lotniska koncowego:  ";
	std::cin >> nr_pocz;

	Airport zwracany;

	element* helper = ar.head;

	if (!helper)
		throw "brak lotnisk\n";

	//pêtla poni¿ej wyszukuje strukturê z po¿¹danym lotniskiem
	while (nr_pocz > 0)
	{
		helper = helper->next;
		if (!helper)
			throw "nie ma lotniska o tym numerze\n";//niepowodzenie, zwrot wyj¹tku
		nr_pocz--;
	}

	zwracany = helper->port;

	system("cls");

	return zwracany;
}

void Find_flight::ile_biletow(unsigned int & E, unsigned int & C1)
{
	//zape³nia zmienne przekazywane przez referencjê

	std::cout << "Podaj liczbe biletow w klasie ekonomicznej:  ";
	std:: cin >> E;
	std::cout << "\n\nPodaj liczbe biletow w pierwszej klasie:  ";
	std::cin >> C1;
	system("cls");
}

std::vector<Flight*> Find_flight::znajdz_polaczenie(Airport& start, Airport& finish, Airport_list & ar,const int& rez_E,const int& rez_C1)
{
	std::vector<Flight*>returned;
	

	//nazwy lotnisk pocz¹tkowego i koncowego
	std::string start_name = start.get_name();
	std::string finish_name = finish.get_name();

	Airport * beginning = nullptr;

	element * helper = ar.head;

	//pobiera wskaznik na lotnisko pocz¹tkowe
	while (helper)
	{
		if (helper->port.get_name() == start_name)
		{
			beginning = &(helper->port);
			break;
		}
		helper = helper->next;
	}

	//head na listê lotów z pierwszego lotniska
	element_flights * helper2 = beginning->head;
	Flight *fl = nullptr; //pomocniczy pointer


	int wolne_E;
	int wolne_C1;

	//Znajduje bezpoœrednie po³¹czenie
	while (helper2)
	{
		wolne_E = helper2->fly.number_of_E - helper2->fly.reserved_E;
		wolne_C1 = helper2->fly.number_of_C1 - helper2->fly.reserved_C1;

		if ((helper2->fly.destination == finish_name)  &&	//czy leci do naszego celu
		(wolne_E >= rez_E) &&	//czy ma wystarczaj¹co du¿o miejsc w klasie ekonomicznej
		(wolne_C1 >= rez_C1))	//czy ma wystarczaj¹co du¿o miejsc w pierwszej klasie
		{
			fl = & helper2->fly;
			returned.push_back(fl);
			return returned;
		}
		helper2 = helper2->next;
	}


	element_flights * helper3 = beginning->head;
	element_flights * helper4 = nullptr;
	element * helper5 = ar.head;

	//znajduje po³¹czenie z przesiadk¹
	while (helper3)
	{
		helper5 = ar.head;
		helper4 = nullptr;

		fl = &helper3->fly;
		returned.push_back(fl);

		wolne_E = helper3->fly.number_of_E - helper3->fly.reserved_E;
		wolne_C1 = helper3->fly.number_of_C1 - helper3->fly.reserved_C1;

		if (wolne_E >= rez_E &&												//czy ma wystarczaj¹co du¿o miejsc w klasie ekonomicznej
			wolne_C1 >= rez_C1)												//czy ma wystarczaj¹co du¿o miejsc w pierwszej klasie
		{
			//Je¿eli powy¿szy warunek nie zosta³ spe³niony to program nie wchodzi w poni¿sze dwie pêtle

			while (helper5)//znajduje lotnisko na ktorym l¹dujemy podczas przesiadki
			{
				if (helper5->port.name == helper3->fly.destination)
				{
					helper4 = helper5->port.head;
					break;
				}
				helper5 = helper5->next;
			}

			while (helper4)//znajduje drugi lot
			{

				wolne_E = helper4->fly.number_of_E - helper4->fly.reserved_E;
				wolne_C1 = helper4->fly.number_of_C1 - helper4->fly.reserved_C1;

							//czy dotrze do celu					//czy nastêpuje po naszym przylocie
				if (helper4->fly.destination == finish_name  &&  helper4->fly.departure > helper3->fly.arrival &&
					wolne_E >= rez_E &&			//czy ma wystarczaj¹co du¿o miejsc w klasie ekonomicznej
					wolne_C1 >= rez_C1)			//czy ma wystarczaj¹co du¿o miejsc w pierwszej klasie
				{
					fl = &helper4->fly;
					returned.push_back(fl);//dodaje drugi przelot do wektora
					return returned;
				}

				helper4 = helper4->next;
			}
		}
		helper3 = helper3->next;//idzie dalej
		returned.pop_back();//usuwa niepoprawny przelot z wektora
	}

	throw "nie ma przelotu z maksymalnie jedna przesiadka\n";


}

bool Find_flight::czy_rezerwowac(std::vector<Flight*>& loty, Airport & beginning, Airport & finish, const int& rez_E, const int& rez_C1)
{
	//ta metoda ma na celu pobranie potwierdzenie
	//ale wpierw prezentuje trasê i cenê lotu

	system("cls");

	//wypisanie danych na ekran
	std::cout << std::setw(13) << "z" << std::setw(13) << "do" << std::setw(12) 
		<< "odlot" << std::setw(5) << "godz" << std::setw(5) << "min" << std::setw(12) << "przylot" 
		<< std::setw(5) << "godz" << std::setw(5) << "min" << std:: endl << std :: endl;
 
	//wypisanie danych na ekran - pierwszy lot
		std::cout << std::setw(13) << beginning.name << std::setw(13) << loty[0]->destination << std::setw(12)
			<< (loty[0]->departure)/10000 << std::setw(5) << ((loty[0]->departure)%10000)/100 << std::setw(5)
			<< ((loty[0]->departure) % 100) << std::setw(12)
			<< (loty[0]->arrival) / 10000 << std::setw(5) << ((loty[0]->arrival) % 10000) / 100 << std::setw(5) 
			<< ((loty[0]->arrival) % 100) << std:: endl;
	
	//wypisanie danych na ekran - ewentualny drugi lot
		if (loty.size() == 2)
		{
			std::cout << std::setw(13) << loty[0]->destination << std::setw(13) << loty[1]->destination << std::setw(12)
				<< (loty[1]->departure) / 10000 << std::setw(5) << ((loty[1]->departure) % 10000) / 100 << std::setw(5)
				<< ((loty[1]->departure) % 100) << std::setw(12)
				<< (loty[1]->arrival) / 10000 << std::setw(5) << ((loty[1]->arrival) % 10000) / 100 << std::setw(5)
				<< ((loty[1]->arrival) % 100) << std::endl;
		}

		//obliczanie ceny:
	double dystans =distance(beginning,finish);
	C1_seat cc;
	E_seat ee;
	
	double e_price = rez_E * price(ee,dystans);
	double c_price = rez_C1 * price(cc, dystans);

	//podaje cenê
	std::cout << "\n\ncena biletow wynosi: " << e_price + c_price<<" zl";

	//p
		std::cout << "\n\n" << "Czy rezerwowac? (podaj 0 lub 1) : ";
		int wynik;
		std::cin >> wynik;
		
		if(wynik ==0)
	return false;

		return true;
}

void Find_flight::rezerwuj(std::vector<Flight*>& loty, const int & rez_E, const int & rez_C1)
{
	for (int i = 0; i < loty.size(); i++)
	{
		loty[i]->reserve_E(rez_E);
		loty[i]->reserve_C1(rez_C1);
	}
}

void Find_flight::wypisz_pliki(Airport_list & ar)
{
	std::fstream  file;

	//potrzebne wskaŸniki pomocnicze
	element * helper = ar.head;
	element_flights *helper2 = nullptr;


	//zapisd pliku
	while (helper)
	{
		//zapis plików kolejnych lotnisk

		file.open(helper->port.get_name() + ".txt", std::ios::out);

		if (!file.good())
			throw "cannot open flights files\n";

		helper2 = helper->port.head;

		while (helper2)
		{
			//wype³nianie list lotów kolejnych lotnisk

			file << helper2->fly.destination <<" " << helper2->fly.departure  << " " << helper2->fly.arrival << " "
				<< helper2->fly.number_of_E << " "<< helper2->fly.number_of_C1 <<" " << helper2->fly.reserved_E << " "
				<< helper2->fly.reserved_C1 << std:: endl ;

			helper2 = helper2->next;

		}

		//przejœcie do nastêpnego lotniska
		helper = helper->next;

		//zamkniêcie pliku by nie spowodowac niepotrzebnych zmian
		file.close();
	}
}


Find_flight::Find_flight()
{
}


Find_flight::~Find_flight()
{
}
