#pragma once
#include <map>
#include "City.hpp"
namespace pandemic {
    class Board {
    public:
        int& operator[](City city);
        friend std::ostream& operator<<(std::ostream &os, const Board &board);
        bool is_clean();
        void remove_cures(); 
    };
}