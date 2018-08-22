#ifndef CD_H
#define CD_H


class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(char *s1,char *s2,int n,double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    virtual Cd &operator =(const Cd &d);
};

class Classic : public Cd
{
private:
    char work[1000];

public:
    Classic(char *c1,char *s1,char *s2,int n,double x);
    Classic(const Classic &c);
    Classic();

    virtual ~Classic();
    virtual void Report()const;
    virtual Cd &operator =(const Classic &c);
};

#endif // CD_H
