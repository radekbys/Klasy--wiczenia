#include "Airport.h"

//obs³uga listy
void Airport::add(Flight & a)
{
	head = list_add(a, head);
}

element_flights * Airport::list_add(Flight & a, element_flights * head)
{
	if (head != nullptr)
	{
		head->next = list_add(a, head->next);
		return head;
	}
	else
	{
		head = new element_flights;
		head->fly = a;
		head->next = nullptr;
		return head;
	}
}




//operator kopiu¹cy
Airport & Airport::operator=(const Airport & air)
{
	this->name = air.get_name();
	this->latitude = air.get_latitude();
	this->longtitude = air.get_longtitude();
	this->head = nullptr;
	return *this;
}




//settery i gettery
void Airport::set_name(std::string n)
{
	name = n;
}

void Airport::set_latitude(double lat)
{
	if (lat > 180 || lat < -180)
	{
		throw ("wrong_latitude " + name);
	}
	else
	{
		latitude = lat;
	}
}

void Airport::set_longtitude(double lon)
{
	if (lon > 90 || lon < -90)
	{
		throw ("wrong_longtitude " + name);
	}
	else
	{
		longtitude = lon;
	}

}

std::string Airport::get_name() const
{
	return name;
}

double Airport::get_latitude() const
{
	return latitude;
}

double Airport::get_longtitude() const
{
	return longtitude;
}




//konstruktory i destruktor
Airport::Airport()
{
	name = " ";
	longtitude = 0;
	latitude = 0;
	head = nullptr;
}

Airport::Airport(std::string nzw, double dlugosc, double szerokosc)
:name(nzw),
longtitude(dlugosc),
latitude(szerokosc), 
head(nullptr)
{
}


element_flights * Airport::remove_last(element_flights * head)
{
	if (head == nullptr)
	{
		return head;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		head->next = remove_last(head->next);
	}
	return head;
}


Airport::~Airport()
{
	while (head)
	{
		head = remove_last(head);
	}
}
