#ifndef _FLIGHT_H_
#define _FLIGHT_H_

#include "Seat.h"
#include <string>

class Flight
{
	//Wskaüniki na tablice z miejscami z≥oøone ze wskaünikÛw polimorficznych

	Seat *seats_C1;
	Seat *seats_E;

	long long int departure;
	long long int arrival;

	int number_of_E, number_of_C1, reserved_E, reserved_C1;

	std :: string  destination;

public:

	void reserve_E(int ee);
	void reserve_C1(int cc);

	Flight & operator =( const Flight & ff);


	Flight();
	Flight(std:: string des, long long int dep, long long int arr, int E, int C1,int rE, int rC1);
	~Flight();


	friend class Find_flight;
};

#endif