#ifndef READASD_H
#define READASD_H
#include<string>
#include <vector>

#define ASDROWCOUT 2151

struct AsdData
{
    std::string file_path_name;

    /*asd文件中获取的数据  -----------------------------begin*/
    double *p_spectral;
    double *p_whitebord;

    float splice1;
    float splice2;
    /*asd文件中获取的数据  -----------------------------end*/

    /*计算的数据  -----------------------------begin*/
    double *p_tagSpectral;
    double *p_x;
    /*计算的数据  -----------------------------begin*/

    AsdData ()
    {
       p_spectral = new double [ASDROWCOUT];
       p_whitebord = new double [ASDROWCOUT];
       p_tagSpectral = new double[ASDROWCOUT];
       p_x = new double[ASDROWCOUT];
    }
    ~AsdData()
    {
        delete[] p_spectral;
        delete[] p_whitebord;
        delete[] p_tagSpectral;
        delete[] p_x;
    }
};


class ReadAsd
{
public:
    ReadAsd();
    ~ReadAsd();

    //将不同路径的文件添加到_vector_asd_data中
    bool addFileToAsdData(const std::string& file_path_name);

    //得到指定asd文件的数据
    double* getTagSpectralFromAsdFile(const std::string& file_path_name);

    double *getxFromAsdFile(const std::string& file_path_name);

    bool getTagSpectralAndx(const std::string& file_path_name,double * &p_TagSpectral,double * &p_x);
    // 得到指定的几个asd文件的tagSpectral的均值
    double* meanSpectral(std::vector<std::string> vect_file_path_name);
    //清理所有文件
    void clearAllFile();

protected:
    //从指定asd文件中获取TagDN数据
    void readTagDNFromAsdFile(AsdData* p_asd_data,FILE*file_asd);
    //从指定asd文件中获取WhiteDN数据
    void readWhiteDNFromAsdFile(AsdData* p_asd_data, FILE*file_asd);
    //从指定asd文件中获取Splice数据
    void readSpliceFromAsdFile(AsdData* p_asd_data, FILE*file_asd);
    //计算TagSpectral x的数据
    void calculateTagSpectralAndx(AsdData* p_asd_data);
    //寻找指定文件名在_vector_asd_data的位置，用于接下来的索引
    int findFilePostion(std::string file_name);


private:

    std::vector<AsdData*> _vector_asd_data;

};

#endif // READASD_H
