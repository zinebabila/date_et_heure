#include "DateH.h"
#include <iostream>
#include <assert.h>
using namespace std;

Time::DateH::DateH(int h, int m, int s, int j = 0, int mo = 0, int a = 0)
	:Heure(h, m, s)
{
	assert(validerjour(j, mo, a));
		this->jour = j;
		this->mois = mo;
		this->annee = a;
	

	
}
	
void Time::DateH::afficher() const
{
	this->Heure::afficher();
	cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}

bool Time::DateH::operator>(DateH h) const
{
	bool res=false;
	
	if (this->annee > h.annee)res = true;
	else {
		if (this->mois > h.mois) res = true;
		else if (this->jour > h.jour) res = true;
	}
	return res;
}
bool Time::DateH::bissextille(int a)
{
	return((a % 4 == 0) && ((a % 100 != 0) || (a % 400 == 0)));
	
}
int Time::DateH::nbr_jour_mois(int m, int a)
{
	if (bissextille(a) && m == 2)
		return 29;
	if (!bissextille(a) && m == 2)
	return 28;
	//if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	if ((m % 2 == 0 && m > 7) || (m % 2 != 1 && m <= 7))
		return 31;
	//if(m == 4 || m == 6 || m == 9 || m == 11)
	return 30;
}
bool Time::DateH::validerjour(int j,int m,int a)
{
	
	return ((j > 0 && j <= nbr_jour_mois(m, a)) && (m > 0 && m < 13) && (a > 1999 && a < 2999));
}



	

