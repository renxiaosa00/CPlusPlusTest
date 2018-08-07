#ifndef Move_H
#define Move_H


class Move
{
public:
    //Move();
    Move(double a=0,double b=0);
    void showMove() const;
    //Move& add(const Move &m) const;
    void reset(double a=0,double b=0);
   Move Add(const Move& m)const;
   //Move Add1(Move &m);
    void Add2(double x1,double y1);
    ~Move();

private:
    double x;
    double y;
};

#endif // Move_H
