#include "readasd.h"

ReadAsd::ReadAsd()
{
    _vector_asd_data.clear();
}

ReadAsd::~ReadAsd()
{
    clearAllFile();
}

bool ReadAsd::addFileToAsdData(const std::string& file_path_name)
{
    FILE * file_asd = fopen(file_path_name.c_str(), "rb");
    if (file_asd == NULL)
    {
        return false;
    }
    AsdData * p_asd_data = new AsdData();
    p_asd_data->file_path_name = file_path_name;
    readSpliceFromAsdFile(p_asd_data,file_asd);
    readTagDNFromAsdFile(p_asd_data,file_asd);
    readWhiteDNFromAsdFile(p_asd_data,file_asd);
    fclose(file_asd);
    calculateTagSpectralAndx(p_asd_data);
    _vector_asd_data.push_back(p_asd_data);
    return true;

}

double *ReadAsd::getTagSpectralFromAsdFile(const std::__cxx11::string &file_path_name)
{
    for (int i = 0; i < _vector_asd_data.size(); i++)
    {
        if (_vector_asd_data[i]->file_path_name == file_path_name)
        {
            return _vector_asd_data[i]->p_tagSpectral;
        }
    }
}

double *ReadAsd::getxFromAsdFile(const std::__cxx11::string &file_path_name)
{
    for (int i = 0; i < _vector_asd_data.size(); i++)
    {
        if (_vector_asd_data[i]->file_path_name == file_path_name)
        {
            return _vector_asd_data[i]->p_x;
        }
    }
}

bool ReadAsd::getTagSpectralAndx(const std::__cxx11::string &file_path_name, double *&p_TagSpectral, double *&p_x)
{
    for (int i = 0; i < _vector_asd_data.size(); i++)
    {
        if (_vector_asd_data[i]->file_path_name == file_path_name)
        {
            p_TagSpectral =  _vector_asd_data[i]->p_tagSpectral;
            p_x = _vector_asd_data[i]->p_x;
            return true;
        }
    }
    return false;
}

void ReadAsd::readTagDNFromAsdFile(AsdData* p_asd_data, FILE*file_asd)
{
    fseek(file_asd, 484, SEEK_SET);
    fread(p_asd_data->p_spectral, sizeof(double) * ASDROWCOUT, ASDROWCOUT, file_asd);
}
void ReadAsd::readWhiteDNFromAsdFile(AsdData* p_asd_data, FILE*file_asd)
{
    int index = 484 + sizeof(double) * ASDROWCOUT + 20;
    fseek(file_asd, index, SEEK_SET);
    fread(p_asd_data->p_whitebord, sizeof(double) * ASDROWCOUT, ASDROWCOUT, file_asd);
}

void ReadAsd::readSpliceFromAsdFile(AsdData* p_asd_data, FILE*file_asd)
{

    fseek(file_asd, 444, SEEK_SET);
    fread(&(p_asd_data->splice1), sizeof(float), 1, file_asd);

    fseek(file_asd, 448, SEEK_SET);
    fread(&(p_asd_data->splice2), sizeof(float), 1, file_asd);
}

void ReadAsd::calculateTagSpectralAndx(AsdData* p_asd_data)
{
    for (int i = 0; i < ASDROWCOUT; i++)
    {
        p_asd_data->p_x[i] = 350 + i;
        p_asd_data->p_tagSpectral[i] = p_asd_data->p_spectral[i] / p_asd_data->p_whitebord[i];
    }
}

double* ReadAsd::meanSpectral(std::vector<std::string> vect_file_name)
{
    //注意mean这边内存应该放到外部去维护。
    double* mean = new double[ASDROWCOUT];
    const int size_asd = vect_file_name.size();
    int postion_vect_asd[size_asd];
    for (int i = 0; i < size_asd; i++)
    {
        postion_vect_asd[i] = findFilePostion(vect_file_name[i]);
    }
    double sum_mean;
    for (int i = 0; i < ASDROWCOUT; i++)
    {
        sum_mean = 0.0;
        for (int j = 0; j < size_asd; j++)
        {
            sum_mean += _vector_asd_data[postion_vect_asd[i]]->p_tagSpectral[i];
        }
        mean[i] = sum_mean / size_asd;
    }

    return mean;
}

void ReadAsd::clearAllFile()
{
    for (int i = 0; i < _vector_asd_data.size(); i++)
    {
        delete _vector_asd_data[i];
    }
    _vector_asd_data.clear();
}

int ReadAsd::findFilePostion(std::string file_path_name)
{

    for (int i = 0; i < _vector_asd_data.size(); i++)
    {
        if (_vector_asd_data[i]->file_path_name == file_path_name)
        {
            return i;
        }
    }
    return  -1;
}
