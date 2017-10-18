#include <iostream>
#include "Zespolona.h"

using namespace std;

int main()
{
	Zespolona z(1 , 2);
	Zespolona zz(2 , 1);

	zz += z;

	cout << zz.getim() << endl;

	cout << zz << endl;

	zz = z;

	cout << zz << endl;

	++zz;

	cout << zz << endl;

	int i = 2 + zz;

	cout << i << endl;

	zz(8, 8);

	cout << zz << endl;

	system("PAUSE");
	return 0;
}