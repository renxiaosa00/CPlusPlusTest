#include "stdafx.h"
#include "Stonewt.h"
#include<iostream>
using std::cout;
void display(const Stonewt &st,int n);

int _tmain(int argc, _TCHAR* argv[])
{
	Stonewt incognito = 275;
	Stonewt wolfe(287.5);
	Stonewt taft(21,8);
	//这是我写的测试程序
	Stonewt a(2,8);
	Stonewt temp;
	temp = a * 2.0;
	temp.show_lbs();
	temp.show_stn();

	//cout << "the celebrity weighed ";
	//incognito.show_stn();
	//cout << "the detective weighed ";
	//wolfe.show_stn();
	//cout << "the president weighed ";
	//taft.show_lbs();
	//incognito = 276.8;
	//taft = 325;
	//cout << "after dinner,the celebrity weighed ";
	//incognito.show_stn();
	//cout << "after dinner,thw prisident weighted ";
	//taft.show_lbs();
	//display(taft,2);
	//cout << "the wrestler weighted even more.\n";
	//display(422,2);
	//cout << "no stone left unearned\n";
	std::cin.get();


	return 0;
}

void display(const Stonewt &st, int n)
{
	for (int i = 0; i < n;i++)
	{
		cout << "wow! ";
		st.show_stn();
	}
}