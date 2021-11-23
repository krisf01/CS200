// updated test driver for version 5

// Programmer: Kristina Fout
// Programmer ID: 1866884

// c++ main.cpp Building.cpp Rider.cpp Panel.cpp Floor.cpp Elevator.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <cstdlib>
#include <ctime>

#include "Rider.h"
#include "Building.h"
#include "Floor.h"
#include "Panel.h"
#include "Elevator.h"

int main()
{
    srand(time(0)); rand();
    for (int i = 0;; i++)
    {
        cout << "-----------------------------------------------\n";
        cout << "-- Time " << i << " ---------------------------\n";
        for (int elevator = 0; elevator < Building::ELEVATORS; elevator++)
            cout << Building::elevators[elevator] << endl;
        for (int floor = 0; floor < Building::FLOORS; floor++)
            cout << Building::floors[floor] << endl;
        double myArrivalRate = 1; // you choose!
        Building::action(i < 300 ? myArrivalRate : 0);
        cin.get();
    }
}

