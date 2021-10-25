#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Leg
{
    const char* const startCity;
    const char* const endCity;
    const double distance;
    
    public:
    Leg(const char* const, const char* const, const double); // constructor
    Leg& operator=(const Leg&); // for swap()
    double getDistance() const;
    void output(ostream&) const;
};

Leg::Leg(const char* startCity, const char* endCity, const double distance): startCity(startCity), endCity(endCity), distance(distance)
{
    
}

double Leg::getDistance()const
{
    return distance;
}

// assignment operator
Leg& Leg::operator=(const Leg& leg)
{
    if (this!= &leg)
    {
        const_cast<double&>(this->distance) = leg.distance;
        const_cast<const char* &>(this->startCity) = leg.startCity;
        const_cast<const char* &>(this->endCity) = leg.endCity;
    }
    
    return *this;
}

void Leg::output(ostream& out) const
{
    out << "Leg: " << startCity << " to " << endCity << ", " << fixed << setprecision(2) << distance << " miles " << endl;
}

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
    
    double dist[40];
    
    // sorting by distance
    
    for(int i = 0; i < 40; i++)
    {
        dist[i] = ((double)(rand()%400))/10;
    }
    
    // create an array of 40 Leg Objects
    Leg a[] = {
    Leg("Concord","Walnut Creek",dist[0]), Leg("Marin","San Rafael",dist[1]), Leg("Pleasant Hill","Concord",dist[2]),
    Leg("Pleasant Hill", "Pacheco", dist[3]), Leg("Alameda", "Oakland", dist[4]), Leg("Richmond", "Berkeley", dist[5]), Leg("Martinez", "Pleasant Hill", dist[6]), Leg("El Cerrito", "Richmond", dist[7]), Leg("Novato", "San Rafael", dist[8]), Leg("San Ramon", "Pleasanton", dist[9]), Leg("Hayward", "Union City", dist[10]), Leg("San Jose", "Cupertino", dist[11]), Leg("San Leandro", "Hayward", dist[12]), Leg("Union City", "Milpitas", dist[13]), Leg("Fremont", "Union City", dist[14]), Leg("Morgan Hill", "Gilroy", dist[15]), Leg("Pleasanton", "Livermore", dist[16]), Leg("Benicia", "Vallejo", dist[17]), Leg("Martinez", "Benicia", dist[18]), Leg("Morgan Hill", "San Jose", dist[19]), Leg("San Francisco", "Daly City", dist[20]), Leg("Vacaville", "Davis", dist[21]), Leg("Fremont", "Milpitas", dist[22]), Leg("Davis", "Sacremento", dist[23]), Leg("Daly City", "San Mateo", dist[24]), Leg("Marin", "Richmond", dist[25]), Leg("Fairfield", "Vacaville", dist[26]), Leg("Oakland", "Richmond", dist[27]), Leg("Vallejo", "Novato", dist[28]), Leg("Sunnyvale", "Cupertino", dist[29]), Leg("Emeryville", "Berkeley", dist[30]), Leg("Fremont", "San Ramon", dist[31]), Leg("Livermore", "Tracy", dist[32]), Leg("Tracy", "Stockton", dist[33]), Leg("San Rafael", "San Francisco", dist[34]), Leg("Fairfield", "Davis", dist[35]), Leg("Vallejo", "Fairfield", dist[36]), Leg("Vallejo", "Napa", dist[37]), Leg("San Jose", "Santa Cruz", dist[38]), Leg("Walnut Creek", "Fremont", dist[39])
    };
    
    const int SIZE = sizeof(a) / sizeof(a[0]);
    
    // sorting
    int sort;
    for (int i = 0; i < SIZE-1; i++)
    {
        sort = i;
        for (int j = i+1; j < SIZE; j++)
        {
            if(a[j].getDistance() < a[sort].getDistance())
                sort = j;
        }
        if (sort != i)
        {
            Leg temp = a[i];
            a[i] = a[sort];
            a[sort] = temp;
        }
    }
    
    // displaying
    for (int i = 0; i < SIZE; i++)
    {
        a[i].output(cout);
    }
    
    return 0;
}
