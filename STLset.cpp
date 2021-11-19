#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    set <double> s;
    s.insert(123);
    s.insert(43);
    s.insert(7);
    
    cout << "Minimum in set is " << *(s.begin()) << endl;
}
