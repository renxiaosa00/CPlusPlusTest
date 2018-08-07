#pragma once
class Stonewt
{
private:
	enum{Lbs_per_stn=14};
	int stone;
	double pds_left;
	double pounds;

public:
	Stonewt(double lbs);
	Stonewt(int stn,double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;

	//需要重载的*操作符
	Stonewt operator*(double d) const;

};

