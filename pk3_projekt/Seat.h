#ifndef _SEAT_H_
#define _SEAT_H_


//klasa dotycz¹ca miejsc


//klas glówna(abstrakcyjna)
class Seat
{
protected:
	bool reserved;
	double tarrif;
	double base_cost;

public:

	virtual void reserve() = 0;
	virtual void release_reserve() = 0;

	double get_tarrif() const;
	double get_base_cost() const;

	bool is_reserved();
};



//klasy potomne
class C1_seat
	:public Seat
{
public:
		void reserve();
		void release_reserve();

		C1_seat();
};

class E_seat
	:public Seat
{
public:
	void reserve();
	void release_reserve();

	E_seat();
};



#endif

