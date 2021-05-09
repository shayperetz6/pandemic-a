#include "Medic.hpp"
using namespace pandemic;
using namespace std;
#include <string>
Player& Medic::treat(City c)
{
    return *this;
}
string Medic::role()
{ 
    return "Medic";
}