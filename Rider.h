// Programmer: Kristina Fout
// Programmer ID: 1866884

#ifndef Rider_h
#define Rider_h

struct Rider
{
    const int from, to;
    bool goingUp, goingDown;
    Rider(int,int);
    Rider& operator=(const Rider&);
};

#endif
