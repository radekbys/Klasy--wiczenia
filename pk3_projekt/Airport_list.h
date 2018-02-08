#ifndef _AIRPORT_LIST_H_
#define _AIRPORT_LIST_H_

#include "Airport.h"


//definicja elementu listy
struct element
{
	Airport port;
	element * next;
};


//lista lotnisk dfinicja klasy
class Airport_list
{
	element * head;

public:
	void add(Airport & a);
	element* list_add(Airport & a, element * head);
	element* remove_last(element * head);

	Airport_list();
	~Airport_list();
	
	
	friend class Find_flight;
};



#endif