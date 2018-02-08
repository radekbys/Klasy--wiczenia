#ifndef _AIRPORT_H_
#define _AIRPORT_H_

#include <string>
#include "Flight.h"


//stuktura element listy
struct element_flights
{
	Flight fly;
	element_flights* next;
};


class Airport
{
	//Klasa ta zawiera deklaracje parametrów lotniska, nazwa po³o¿enie,
	//zawiera tak¿e listê odlotów z tego lotniska

	std::string name;

	//N-dodatnie S-ujemne, E-dodatnie, W -ujemne
	double longtitude;
	double latitude;


	element_flights* head;

public:


	//metody obs³ugi listy
	void add(Flight & a);
	element_flights* list_add(Flight & a, element_flights * head);
	element_flights* remove_last(element_flights * head);


	//u¿yty w Find_flights :: read_files
	Airport & operator =(const Airport &);



	//settery i gettery
	void set_name(std :: string n);
	void set_latitude(double lat);
	void set_longtitude(double lon);
	
	std::string get_name()const;
	double get_latitude()const;
	double get_longtitude()const;



	//konstruktory i destruktor
	Airport();
	Airport(std::string nzw, double dlugosc, double szerokosc);//u¿yty w Find_flights :: read_files
	~Airport();

	friend class Find_flight;
};

#endif