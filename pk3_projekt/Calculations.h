#ifndef _CALCULATIONS_H
#define _CALCULATIONS_H

#include "Airport.h"
#include "Seat.h"
#include <math.h>


//oblicza dystans w km
double distance(Airport a, Airport b);


//oblicza cenê przelotu
double price(C1_seat c, double distance);
double price(E_seat e, double distance);

#endif