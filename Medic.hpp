#pragma once
#include "Player.hpp"
namespace pandemic {
class Medic : public Player {

        public:
        Medic(Board& b, City c): Player(b, c) {};
        Player& treat(City c) override;
        std::string role() override;
    };
}