#pragma once
class ReadAsd
{
public:
	ReadAsd();
	ReadAsd(const string &fileName);

	~ReadAsd();

	bool openFile();
	double *readTagDN();
	double *readWhiteDN();

	double *writeSpectral();
	double *meanSpectral(double *tagSpectral, n);

	float readSplice1();
	float readSplice2();


private:
	string _fileName;
	string _resultName;
	FILE *_p_fin;
	FILE *_p_fou;

	double *_p_spectral;
	double *_p_whitebord;
	double *_p_tagSpectral;
	double *_p_x;

	float _splice1, _splice2;

};

