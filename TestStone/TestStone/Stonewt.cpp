#include "stdafx.h"
#include <iostream>
#include "Stonewt.h"
using std::cout;

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn*Lbs_per_stn + lbs;
}



Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}


Stonewt::~Stonewt()
{
}

void Stonewt::show_stn() const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

Stonewt Stonewt::operator*(double b) const
{
	Stonewt result;
	/*result.pounds = (pounds*b) % Lbs_per_stn;
	result.stone = stone*b + (pounds*b) / Lbs_per_stn;*/

	long totalpounds = stone * b * Lbs_per_stn + pds_left * b;
	result.pds_left = totalpounds % Lbs_per_stn;
	result.stone = totalpounds / Lbs_per_stn;
	result.pounds = totalpounds;

	

	return result;
}