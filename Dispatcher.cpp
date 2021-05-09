#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;
#include <string>
Player& Dispatcher:: fly_direct(City c){
    return *this;
}
std::string Dispatcher::role() {
     return "Dispatcher"; 
}

