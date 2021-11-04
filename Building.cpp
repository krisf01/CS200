// Programmer: Kristina Fout
// Programmer ID: 1866884

#include "Building.h"
#include "Floor.h"
#include "Elevator.h"

#include <iostream>
using namespace std;

#include <cstdlib>
#include <cmath>

Floor Building::floors[] =
{
    Floor(0, "First Floor", "1"),
    Floor(100, "Second Floor", "2"),
    Floor(200, "Third Floor", "3"),
    Floor(305, "Fourth Floor", "4"),
    Floor(410, "Fifth Floor", "5")
};
const int Building::FLOORS = sizeof(floors) / sizeof(Floor);

Elevator Building::elevators[] =
{
    Elevator(12, 5, 0),
    Elevator(12, 5, 1),
    Elevator(12, 5, 2)
};
const int Building::ELEVATORS = sizeof(elevators) / sizeof(Elevator);

void Building::getDifferentInts(int& a, int& b)
{
    do
    {
        a = rand() % FLOORS;
        b = rand() % FLOORS;
    }   while (a == b);
}

int Building::getPoisson(double avg)
{
    int arrivals = 0;
    double probOfnArrivals = exp(-avg); // requires cmath
    for(double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib
        (randomValue -= probOfnArrivals) > 0.0;
        probOfnArrivals *= avg / ++arrivals);
    return arrivals;
}

void Building::placeNewRiders(double arrivalsPerSecond)
{
    int n = getPoisson(arrivalsPerSecond);
    for (int i = 0; i < n; i++)
    {
        int from, to;
        getDifferentInts(from, to);
        Rider rider(from, to);
        floors[from].addRider(rider);
    }
}

bool Building::openDoorToDisembarkRider(int e)
{
    if (!elevators[e].isOpen()) // if the door is closed...
        for (int f = 0; f < FLOORS; f++) // check each floor to see if its elevation matches
        if (floors[f] == elevators[e] &&
            elevators[e].panel.isLit(floors[f].label)) // ...and the elevator's panel has that floor lit
            {
                elevators[e].openDoorTo(f); // then open the door to that floor
                return true; // ...and report that an action was taken
            }
    return false; // if I get this far, no action was taken in this function
}

// the "action function" to perform one action per elevator per time step
void Building::action(double arrivalsPerSecond)
{
    placeNewRiders(arrivalsPerSecond);
  
  // one action per elevator
    for (int e = 0; e < ELEVATORS; e++)
    {
        if (openDoorToDisembarkRider(e)) continue;
        if (disembarkRider(e)) continue;
        if (boardRider(e)) continue;
    }
}

bool Building::disembarkRider(int e)
{
    if (elevators[e].isOpen() && elevators[e].hasRiderForFloor())
    {
        elevators[e].removeRider();
        return true;
    }
    return false;
}

bool Building::boardRider(int e)
{
    if (elevators[e].isOpen() && !elevators[e].isFull())
    {
        Floor& floor = floors[elevators[e].getFloorIndex()];
        if (elevators[e].goingUp() && floor.hasUpRider())
        {
            Rider rider = floor.removeUpRider();
            elevators[e].board(rider);
            return true;
        }
        else if (elevators[e].goingDown() && floor.hasDownRider())
        {
            Rider rider = floor.removeUpRider();
            elevators[e].board(rider);
            return true;
        }
    }
    return false;
}
