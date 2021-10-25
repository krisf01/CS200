#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

#include <cstdlib>

class Leg
{
    const char* const startCity;
    const char* const endCity;
    const double distance;
    
    public:
    Leg(const char* const, const char* const, const double); // constructor
    Leg& operator=(const Leg&); // for swap()
    double getDistance() const {return distance;}
    void output(ostream&) const;
    friend class Route;
};

Leg::Leg(const char* startCity, const char* endCity, const double distance): startCity(startCity), endCity(endCity), distance(distance)
{
    
}

// assignment operator
Leg& Leg::operator=(const Leg& copy)
{
    if (this!= &copy)
    {
        const_cast<double&>(this->distance) = copy.distance;
        const_cast<const char* &>(this->startCity) = copy.startCity;
        const_cast<const char* &>(this->endCity) = copy.endCity;
    }
    
    return *this;
}

void Leg::output(ostream& out) const
{
    out << "Leg: " << startCity << " to " << endCity << ", " << fixed << setprecision(2) << distance << " miles " << endl;
}


class Route
{
    vector<const Leg*> legs;
    const double totalDis;
    
public:
    Route(const Leg&);
    Route(const Route&, const Leg&);
    Route& operator=(const Route&);
    double getDistance() const {return totalDis;}
    void output(ostream&) const;
};

ostream& rounding(ostream& out)
{
    out.setf(ios::fixed);
    out.precision(1);
    return out;
}

Route::Route(const Leg& leg):totalDis(leg.distance)
{
    legs.push_back(&leg);
}

Route::Route(const Route& route, const Leg& leg):legs(route.legs), totalDis(route.totalDis)
{
    try
    {
        if (strcmp(legs.back()->endCity, leg.startCity) != 0)
        {
            throw "Cities do not match!";
        }
    }
    catch (const char* error)
    {
        cout << error << endl;
    }
    legs.push_back(&leg);
}
        

Route& Route::operator=(const Route& copy)
{
    Route& routes = *this;
    if (this != &copy)
    {
        routes.legs = copy.legs;
        const_cast<double&>(copy.totalDis) = copy.totalDis;
    }
    return routes;
}


void Route::output(ostream& out) const
{
    out << endl << "Routes: " << legs[0]->startCity << " to ";
    for(int i = 0 ; i < legs.size() ; i++)
     {
         if (i < (legs.size() - 1)) out << legs[i]->endCity << " to ";
         else
             out << legs[i]->endCity << ", ";
     }
     out << totalDis << " miles.";
}

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
    
    // sorting by distance
    
    // create an array of 40 Leg Objects
    Leg a[] = {
    Leg("Concord","Walnut Creek", 2.1), Leg("Marin","San Rafael", 2.9), Leg("Pleasant Hill","Concord", 3.1),
    Leg("Pleasant Hill", "Pacheco", 3.9), Leg("Alameda", "Oakland", 4.3), Leg("Richmond", "Berkeley", 4.5), Leg("Martinez", "Pleasant Hill", 4.9), Leg("El Cerrito", "Richmond", 5.2), Leg("Novato", "San Rafael", 6.2), Leg("San Ramon", "Pleasanton", 6.7), Leg("Hayward", "Union City", 6.9), Leg("San Jose", "Cupertino", 7.5), Leg("San Leandro", "Hayward", 7.8), Leg("Union City", "Milpitas", 8.4), Leg("Fremont", "Union City", 8.5), Leg("Morgan Hill", "Gilroy", 9.3), Leg("Pleasanton", "Livermore", 9.8), Leg("Benicia", "Vallejo", 10.2), Leg("Martinez", "Benicia", 10.2), Leg("Morgan Hill", "San Jose", 11.5), Leg("San Francisco", "Daly City", 11.6), Leg("Vacaville", "Davis", 12.6), Leg("Fremont", "Milpitas", 13.1), Leg("Davis", "Sacremento", 13.6), Leg("Daly City", "San Mateo", 14.2), Leg("Marin", "Richmond", 14.5), Leg("Fairfield", "Vacaville", 14.9), Leg("Oakland", "Richmond", 15.2), Leg("Vallejo", "Novato", 16.3), Leg("Sunnyvale", "Cupertino", 16.4), Leg("Emeryville", "Berkeley", 16.9), Leg("Fremont", "San Ramon", 19.1), Leg("Livermore", "Tracy", 19.2), Leg("Tracy", "Stockton", 20.2), Leg("San Rafael", "San Francisco", 20.8), Leg("Fairfield", "Davis", 24.8), Leg("Vallejo", "Fairfield", 25), Leg("Vallejo", "Napa", 26), Leg("San Jose", "Santa Cruz", 30.5), Leg("Walnut Creek", "Fremont", 30.8)
    };
    
    Route routes[] = {
        Route(a[0]), Route(routes[0], a[1]), Route(routes[1], a[2]), Route(routes[2], a[3]), Route(routes[3], a[4]), Route(routes[4], a[5]), Route(routes[5], a[6]), Route(routes[6], a[7]), Route(routes[7], a[8]), Route(routes[8], a[9]), Route(routes[9], a[10])
    };
    
    // sorting
    const int legSize = sizeof(a)/sizeof(Leg);
      const int routeSize = sizeof(routes) / sizeof(Route);

      for(int i = 0 ; i < routeSize; i++)
      {
          for(int j = i+1; j < routeSize ; j++)
          {
              if(routes[i].getDistance() < routes[j].getDistance())
              {
                  swap(routes[i], routes[j]);
              }

          }

      }
      for (int k = 0; k < routeSize; k++)
      {
          routes[k].output(cout);
      }

      cout << endl << endl;

      //sorting function
      for (int i = 0; i < legSize; i++)
      {
          for (int j = i+1 ; j < legSize; j++)
          {
              if (a[i].getDistance() > a[j].getDistance())
              {
                  swap(a[i], a[j]);
              }

          }

      }

      //output
      for (int k = 0; k < legSize; k++)
      {
          a[k].output(cout);
      }

      return 0;
}

