#include "Researcher.hpp"
using namespace std;
#include<string>
namespace pandemic{
    Player& Researcher::discover_cure(Color c)
    {
        return *this;
    }
    string Researcher::role()
    { 
        return "Researcher"; 
    }
}
