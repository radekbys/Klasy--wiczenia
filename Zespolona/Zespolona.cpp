#include "Zespolona.h"


Zespolona & Zespolona::operator-(const Zespolona & z2) const
{
	return Zespolona(IM - z2.getim(), RE - z2.getre());
}


Zespolona & Zespolona::operator+(const Zespolona & z2) const
{
	return Zespolona (IM + z2.getim() , RE + z2.getre());
}

Zespolona & Zespolona::operator++()
{
	this->IM +=1;
	this->RE +=1;
	return *this;
}

Zespolona & Zespolona::operator += (const Zespolona & z2)
{
	this ->IM += z2.IM;
	this ->RE += z2.RE;
	return *this ;
}

Zespolona & Zespolona::operator+=(int re)
{
	this->RE = re;
	return *this;
}



Zespolona & Zespolona::operator=(const Zespolona & z2)
{
	this->IM = z2.IM;
	this->RE = z2.RE;
	return *this;
}


int & Zespolona::operator[](int i) const
{
	if (i == 0)
	{
		int i = IM;
		return i;
	}
	else
	{
		int r = RE;
		return r;
	}
}


bool & Zespolona::operator!=(const Zespolona & z2) const
{
	if (IM == z2.IM && RE == z2.RE)
	{
		bool zwrot = true;
		return zwrot;
	}
	else
	{
		bool zwrot = true;
		return zwrot;
	}
}

bool & Zespolona::operator==(const Zespolona & z2) const
{
	if (IM == z2.IM && RE == z2.RE)
	{
		bool zwrot = true;
		return zwrot;
	}
	else
	{
		bool zwrot = false;
		return zwrot;
	}
}


Zespolona & Zespolona::operator()(int im, int re)
{
	this->IM = im;
	this->RE = re;
	return *this;
}

int Zespolona::getim() const
{
	return IM;
}

int Zespolona::getre() const
{
	return RE;
}


void Zespolona::setim(int im)
{
	IM = im;
}


void Zespolona::setre(int re)
{
	RE = re;
}


Zespolona::Zespolona(int im, int re)
	:
	IM(im),
	RE(re)
{
}


Zespolona::Zespolona()
	:
	IM(0),
	RE(0)
{
}


Zespolona::~Zespolona()
{
}


ostream & operator<<(ostream & output, const Zespolona & z2)
{
	output << "RE : " << z2.RE << " IM : " << z2.IM;
	return output;
}


istream & operator>>(istream & input, Zespolona & z2)
{
	int im, re;
	input >> im >> re ;
	z2.setim(im);
	z2.setre(re);
	return input;
}


Zespolona & operator+(const Zespolona & z1, const Zespolona & z2)
{
	return Zespolona(z1.getim() + z2.getim(), z1.getre() + z2.getre());
}


Zespolona & operator-(Zespolona & z1, Zespolona & z2)
{
	return Zespolona(z1.getim() - z2.getim(), z1.getre() - z2.getre());
}

int operator+(int i, Zespolona & z2)
{
	return i + z2.getre() ;
}
