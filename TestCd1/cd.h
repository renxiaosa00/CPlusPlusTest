#ifndef CD_H
#define CD_H


class Cd
{
private:
    char *performers;
    char *label;
    int selections;
    double playtime;

public:
    Cd();
    Cd(const char *s1,const char *s2,int n,double x);
    Cd(const Cd &d);

    virtual ~Cd();
    virtual void Report() const;
    virtual Cd &operator =(const Cd &d);
};

class Classic : public Cd
{
private:
    char *work;

public:
    Classic();
    Classic(const char *c1,const char *s1,const char *s2,int n,double x);
    Classic(const Classic &c);

    virtual ~Classic();
    virtual void Report()const;
    //需要注意,对应书上的522页
    //virtual Cd &operator =(const Classic &c);
    virtual Classic &operator =(const Classic &c);
};

#endif // CD_H
