// Programmer: Kristina Fout
// Programmer ID: 1866884

#include "Building.h"
#include "Elevator.h"
#include "Panel.h"
#include "Rider.h"

#include <iostream>
#include <vector>
using namespace std;

#include <cstdlib>

Elevator::Elevator(unsigned int capacity, int speed, int start):speed(speed), CAPACITY(capacity), location(Building::floors[start])
{
    start = Building::floors[start];
    direction = IDLE;
    timer = 0;
    atFloorIndex = -1;

    for(int i = 0; i < Building::FLOORS; i++)
    {
        panel.addButton(Building::floors[i].label);
    }
}

ostream& operator<<(ostream& out, const Elevator& e)
{
    cout << "Elevator at ";
    cout.width(5);
    cout << e.location;

    cout.width(11);
    switch(e.direction)
    {
        case 1:
        cout << "going UP";
        break;
        case -1:
        cout << "going DOWN";
        break;
        case 0:
        cout << "IDLE";
        break;
  }
    cout.width(3);
    cout << e.riders.size() << " riders";

    cout.width(16);
    if(e.atFloorIndex != -1)
        cout << " door is OPEN|" << e.timer;
    else
    {
        cout.width(15);
        cout << " ";
    }
    cout << " " << e.panel;
    
    return out;
}

void Elevator::openDoorTo(int floorindex)
{
    this->panel.clear(Building::floors[floorindex].label);
    this->atFloorIndex = floorindex;
    this->resetTimer();
}

void Elevator::board(const Rider& r)
{
    this->riders.push_back(r); // add rider

    this->panel.press(Building::floors[r.to].label); // press button

    if(r.goingUp) // set direction of elevator
        this->direction = this->UP;
    else if(r.goingDown)
        this->direction = this->DOWN;
    else throw "BOARD ERROR!";

    this->resetTimer(); // reset close door timer
}

bool Elevator::hasRiderForFloor() const
{
    if(!isOpen())
    {
        return false;
    }
    for(int i = 0; i < riders.size(); i++)
    {
        if(riders[i].to == atFloorIndex)
        {
            return true;
        }
    }
      return false;
}

void Elevator::removeRider()
{
    for(int i = 0; i < riders.size(); i++)
    {
        if(riders[i].to == atFloorIndex)
        {
            riders.erase(riders.begin() + i);
            panel.clear(Building::floors[riders[i].to].label);
            resetTimer();
            break;
        }
     }
}
