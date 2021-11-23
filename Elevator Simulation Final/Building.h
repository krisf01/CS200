// Programmer: Kristina Fout
// Programmer ID: 1866884

#ifndef Building_H
#define Building_H

#include "Floor.h"
#include "Elevator.h"

struct Building
{
    static Floor floors[];
    static Elevator elevators[];
    static const int FLOORS;
    static const int ELEVATORS;

    // helper functions
    static void getDifferentInts(int&, int&);
    static int getPoisson(double);
    static void placeNewRiders(double);
  
    // actions
    static void action(double); // the main "action function"
    static bool openDoorToDisembarkRider(int); // step 1 of 9
    static bool disembarkRider(int);
    static bool boardRider(int);
    static bool waitingForMoreRiders(int);
    static bool doneWaitingMove(int);
    static bool moveableMove(int); 
    static bool setIdleElevatorInMotion(int); 
    static bool sendIdleElevatorToCallingFloor(int);
};

#endif
