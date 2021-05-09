#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {
    class Player {
    protected:
        Board board;
        City city;
    public:
        Player(Board &b, City c) {
            board = b;
            city = c;
        }
        Player& drive(City city);
        virtual Player& fly_direct(City city);
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City c);
        virtual std::string role();
        Player& take_card(City c);     
    };
}