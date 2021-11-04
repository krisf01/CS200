// Programmer: Kristina Fout
// Programmer ID: 1866884

#ifndef Floor_H
#define Floor_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#include "Panel.h"
#include "Rider.h"

class Floor
{
    queue<Rider> upRiders, downRiders;
  
    public:
    Rider removeUpRider();
    Rider removeDownRider();
    
    Floor(const int, const char* const, const char* const); // elevation (inches above ground) of floor, name and label
    operator int() const {return elevation;}

    static const char* const UP;
    static const char* const DOWN;
    static int TOP, BOTTOM;
    
    bool hasUpRider( ) const {return !upRiders.empty() ? true : false;}
    bool hasDownRider( ) const {return !downRiders.empty() ? true : false;}
    void addRider(const Rider&);
    
    Panel panel;
    const string name; // name of floor, for example: Mezzanine
    const string label; // as it appears on the button panel
    const int elevation; // inches above ground level
    
   
    // for external reporting
    friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};

#endif
