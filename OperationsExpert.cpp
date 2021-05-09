#include "OperationsExpert.hpp"
using namespace pandemic;
using namespace std;
#include <string>
Player& OperationsExpert::build()
{
    return *this;
}
string OperationsExpert::role()
{
    return "OperationsExpert";
}