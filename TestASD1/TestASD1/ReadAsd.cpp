#include "ReadAsd.h"


ReadAsd::ReadAsd()
{
}

ReadAsd::ReadAsd(const string &fileName)
	:_fileName(fileName), _p_fin(nullptr), _p_fou(nullptr), _p_spectral(nullptr), _p_whitebord(nullptr), _p_tagSpectral(nullptr)

ReadAsd::~ReadAsd()
{
	if (_p_fin)
	{
		delete [] _p_fin;
		_p_fin = nullptr;
	}

	if (_p_fou)
	{
		delete [] _p_fou;
		_p_fou = nullptr;
	}
	if (_tagSpectral)
	{
		delete [] _tagSpectral;
		_p_tagSpectral = nullptr;
	}
}

bool ReadAsd:: openFile()
{
	_p_fin = fopen(_fileName, "rb");
	if (_p_fin = NULL)
		return false;

	return true;
}
double *ReadAsd::readTagDN()
{
	_p_spectral = new double[2151];
	fseek(_p_fin, 484, SEEK_SET);
	fread(_p_spectral, sizeof(double) * 2151, 2151, _p_fin);

	return _p_spectral;
}
double *ReadAsd::readWhiteDN()
{
	_p_whitebord = new double[2151];
	int index = 484 + sizeof(double) * 2151 + 20;
	fseek(_p_fin, index, SEEK_SET);
	fread(_p_whitebord, sizeof(double) * 2151, 2151, _p_fin);

	return _p_whitebord;

}

double *ReadAsd::writeSpectral()
{
	vector<double> _p_tagSpectral, _p_x;
	/*_p_tagSpectral = new double[2151];
	_p_x = new double[2151];*/
	for (int i = 0; i < 2151; i++)
	{
		_p_x[i] = 350 + i;
		_p_tagSpectral[i] = _p_spectral[i] / _p_whitebord[i];
	}

	return _p_tagSpectral;
}

double *ReadAsd::meanSpectral(double *tagSpectral, n)
{
	double mean = new double[2151];
	for (int i = 0; i < 2151; i++)
	{
		mean[i] = sum(tagSpectral[i]) / n;
	}


}


float ReadAsd::readSplice1()
{
	fseek(_p_fin, 444, SEEK_SET);
	fread(&_splice1, sizeof(float), 1, _p_fin);
	return _splice1;
}
float ReadAsd::readSplice2()
{
	fseek(_p_fin, 448, SEEK_SET);
	fread(&_splice2, sizeof(float), 1, _p_fin);
}

