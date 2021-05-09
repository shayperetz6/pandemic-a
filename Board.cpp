#include "Board.hpp"
#include <map>
#include <iostream>
using namespace std;
namespace pandemic{
    map<City, int> cubes;
    int& Board:: operator[](City city){
        return cubes[city];
    }
    ostream &operator<<(std::ostream &os, const Board &board)
    {
        return os;
    }
      bool Board::is_clean()
    {
        return true;
    }
    void Board::remove_cures(){   
    }
}



