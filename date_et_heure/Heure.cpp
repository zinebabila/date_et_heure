#include "Heure.h"
#include <iostream>
using namespace std;

Time::Heure::Heure(int h, int m, int s)
{
	if (h <= 23 && h >= 0) this->heure = h;
	if (m <= 59 && m >= 0) this->minute = m;
	if (s <= 59 && s >= 0) this->seconde = s;
}

void Time::Heure::afficher() const
{
	cout << this->heure << "h:" << this->minute << "min:" << this->seconde << "s" << endl;
}

int Time::Heure::converttosec() const
{
	return this->heure * 3600 + this->minute * 60 + this->seconde;
}

bool Time::Heure::operator>( Heure h) const
{
	bool res=false;
	if (this->converttosec()>h.converttosec()) res = true;
	
	return res;
}
