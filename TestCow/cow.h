#ifndef COW_H
#define COW_H


class Cow
{
    char name[20];
    char *hobby;
    double weight;
    int len;

public:
    Cow();
    Cow(const char *nm, const char *ho, double wt);
    Cow(const Cow &c);
    ~Cow();
    Cow & operator=(const Cow &c);

    void ShowCow() const;

};

#endif // COW_H
