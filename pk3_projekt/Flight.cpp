#include "Flight.h"

void Flight::reserve_E(int ee)
{
	for (int i = 0; i < ee; i++)
	{
		seats_E[reserved_E].reserve();
		reserved_E++;
	}
}

void Flight::reserve_C1(int cc)
{
	for (int i = 0; i < cc; i++)
	{
		seats_C1[reserved_C1].reserve();
		reserved_C1++;
	}
}

//operator kopiuj¹cy
Flight & Flight::operator=(const Flight & ff)
{
	delete[] seats_C1;
	delete[] seats_E;
	
	number_of_C1 = ff.number_of_C1;
	number_of_E = ff.number_of_E;
	destination = ff.destination;

	seats_C1 = new C1_seat[number_of_C1];
	seats_E = new E_seat[number_of_E];

	departure = ff.departure;
	arrival = ff.arrival;

	reserved_C1 = ff.reserved_C1;
	reserved_E = ff.reserved_E;


	for (int i = 0; i < reserved_E; i++)
	{
			seats_E[i].reserve();
	}

	for (int i = 0; i < reserved_C1; i++)
	{
			seats_C1[i].reserve();
	}
	return *this;
}


//konstruktory

Flight::Flight()
{
	seats_C1 = nullptr;
	seats_E = nullptr;
	destination = "none";

	departure = 0;
	arrival = 0;

	number_of_C1 = 0;
	number_of_E = 0;

	reserved_C1 = 0;
	reserved_E = 0;
}

Flight::Flight(std::string des, long long int dep, long long int arr, int E, int C1, int rE, int rC1)
{
	seats_C1 = new C1_seat[C1];
	seats_E = new E_seat[E];
	destination = des;

	departure = dep;
	arrival = arr;

	number_of_C1 = C1;
	number_of_E = E;

	reserved_C1 = rC1;
	reserved_E = rE;
}


//destruktort
Flight::~Flight()
{
		delete[] seats_C1;
		delete[] seats_E;
}
