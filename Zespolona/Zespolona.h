#ifndef _ZESPOLONA_H_
#define _ZESPOLONA_H_


#include <iostream>

using namespace std;


class Zespolona
{
	int IM;
	int RE;

public:

	Zespolona & operator- (const Zespolona &z2) const;
	Zespolona & operator+ (const Zespolona &z2) const;
	Zespolona & operator++ ();
	Zespolona & operator+= (const Zespolona &z2);
	Zespolona & operator+= (int re);
	Zespolona & operator=( const Zespolona &z2);
	int & operator[] (int i) const;
	bool & operator!= (const Zespolona &z2) const;
	bool & operator== (const Zespolona &z2) const;
	friend ostream &operator<<(ostream &output, const Zespolona &z2);
	friend istream &operator>>(istream &input, const Zespolona &z2);
	Zespolona & operator()(int im, int re);

	int getim() const ;
	int getre() const ;
	void setim(int im);
	void setre(int re);

	Zespolona(int im, int re);
	Zespolona();
	~Zespolona();
};


Zespolona & operator+ (Zespolona &z1,Zespolona &z2);
Zespolona & operator- (Zespolona &z1, Zespolona &z2);
int operator+(int i, Zespolona &z2);

# endif
