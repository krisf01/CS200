// Programmer: Kristina Fout
// Programmer ID: 1866884

#include "Rider.h"
#include "Building.h"

Rider::Rider(int from, int to):from(from), to(to), goingUp(Building::floors[to] > Building::floors[from] ? true : false), goingDown(Building::floors[to] < Building::floors[from] ? true : false)
{
}

Rider& Rider::operator=(const Rider& original)
{
    Rider& host = *this;
    if (this != &host)
    {
        const_cast<int&>(host.from) = original.from;
        const_cast<int&>(host.to) = original.to;
        const_cast<bool&>(host.goingUp) = original.goingUp;
        const_cast<bool&>(host.goingDown) = original.goingDown;
    }
 
    return host;
}
