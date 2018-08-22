#ifndef DMA_H
#define DMA_H
#include <iostream>

class dmaABC
{
    char *label;
    int rating;

public:
    dmaABC(const char *l="null",int r=0);
    dmaABC(const dmaABC &rs);
    virtual ~dmaABC();
    dmaABC &operator=(const dmaABC &rs);
//    friend std::ostream &operator<<(std::ostream &os,
//                                    const dmaABC &rs);

    virtual void view()const=0;

};


class baseDMA:public dmaABC
{

public:
    baseDMA(const char *l="null",int r=0):dmaABC(l,r){}
    baseDMA(const baseDMA &rs):dmaABC(rs){}
    virtual ~baseDMA(){}
    baseDMA &operator=(const baseDMA &rs)
    {
        dmaABC::operator =(rs);
        return *this;
    }
//    friend std::ostream &operator<<(std::ostream &os,
//                                    const baseDMA &rs);

    virtual void view()const;
};

class lacksDMA:public dmaABC
{
private:
    enum{COL_LEN=40};
    char color[COL_LEN];
public:
    lacksDMA(const char *c="blank",const char *l="null",
            int r=0);
    lacksDMA(const char *c,const dmaABC &rs);
//    friend std::ostream &operator <<(std::ostream &os,
//                                     const lacksDMA &rs);

    virtual void view()const;

};

class hasDMA :public dmaABC
{
private:
    char *style;

public:
    hasDMA(const char *s="none",const char *l="null",
           int r=0);
    hasDMA(const char *s,const dmaABC &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    hasDMA &operator =(const hasDMA &rs);
//    friend std::ostream &operator <<(
//            std::ostream &os,const hasDMA &rs);

    virtual void view()const;
};

#endif // DMA_H
