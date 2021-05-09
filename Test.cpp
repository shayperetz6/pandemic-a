#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include <iostream>
#include <stdexcept>
using namespace pandemic;
using namespace std;

TEST_CASE("OperationsExpert Player")
{
    Board board;
    OperationsExpert player{board, City::NewYork};
    player.take_card(City::Miami )
        .take_card(City::Paris)
        .take_card(City::Moscow)
        .take_card(City::BuenosAires)
        .take_card(City::Seoul);
        CHECK_NOTHROW(player.build());
        CHECK(player.role() == string("OperationsExpert"));
        CHECK_NOTHROW(player.fly_direct(City::Miami));
        CHECK_THROWS(player.fly_direct(City::Miami));
        CHECK_NOTHROW(player.drive(City::SaoPaulo));
        CHECK_THROWS(player.drive(City::Milan));

}
TEST_CASE("Dispatcher Player")
{
    Board board;
     Dispatcher player{board, City::SanFrancisco};
     player.take_card(City::HongKong)
        .take_card(City::Paris)
        .take_card(City::Moscow)
        .take_card(City::BuenosAires)
        .take_card(City::Seoul);
    CHECK(player.role() == string("Dispatcher"));
      CHECK_THROWS(player.fly_direct(City::MexicoCity));
      OperationsExpert pl1{board, City::MexicoCity};
      CHECK_NOTHROW(player.fly_direct(City::MexicoCity));
}
TEST_CASE("Scientist Player")
{
    Board board;
    board[City::NewYork] = 4;
    Scientist player {board,City::NewYork,4};
      player.take_card(City::Montreal)           
        .take_card(City::Chicago)             
        .take_card(City::Lagos)            
        .take_card(City::NewYork)            
        .take_card(City::Riyadh);
    CHECK(player.role() == string("Scientist"));
    CHECK_THROWS(player.discover_cure(Color::Blue));
    OperationsExpert pl1{board, City::Miami};
    pl1.build();
    player.take_card(City::StPetersburg);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    CHECK_NOTHROW(player.treat(City::NewYork));
    CHECK_FALSE(!board.is_clean());
}
TEST_CASE("Researcher Player")
{
    Board board;
     board[City::NewYork] = 4;
    Researcher player {board,City::NewYork};
      player.take_card(City::Montreal)           
        .take_card(City::Chicago)             
        .take_card(City::Lagos)            
        .take_card(City::NewYork)            
        .take_card(City::Riyadh);
    CHECK(player.role() == string("Researcher"));
    CHECK_THROWS(player.discover_cure(Color::Blue));
    player.take_card(City::StPetersburg);
    player.take_card(City::Paris);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));

}
TEST_CASE("Medic Player")
{
    Board board;
    Medic player{board, City::Chicago};
    board[City::Chicago] = 4;
    player.take_card(City::Madrid)
        .take_card(City::Milan)
        .take_card(City::Tokyo)
        .take_card(City::Cairo);
    CHECK(player.role() == string("Medic"));
    CHECK_NOTHROW(player.treat(City::Chicago));
    CHECK(board[City::Chicago] == 0);

}
TEST_CASE("Virologist Player")
{
    Board board;
    Virologist player{board, City::LosAngeles};
      player.take_card(City::Baghdad)
        .take_card(City::Bangkok)
        .take_card(City::Beijing)
        .take_card(City::BuenosAires)
        .take_card(City::Mumbai);
    CHECK(player.role() == string("Virologist"));
    board[City::Beijing] = 4;
    CHECK_NOTHROW(player.treat(City::Beijing));
    CHECK(board[City::Lagos] == 3);
}
TEST_CASE("GeneSplicer Player")
{
    Board board;
    GeneSplicer player{board, City::Moscow};
    player.take_card(City::Moscow)
        .take_card(City::Sydney)
        .take_card(City::Istanbul)
        .take_card(City::Lagos)
        .take_card(City::Johannesburg);
    CHECK(player.role() == string("GeneSplicer"));
    board[City::Moscow] = 4;
    CHECK_NOTHROW(player.discover_cure(Color::Black));
    CHECK_NOTHROW(player.treat(City::Moscow));
    CHECK(board[City::Moscow] == 0);
}
TEST_CASE("FieldDoctor Player")
{
    Board board;
    FieldDoctor player{board, City::HongKong};
    CHECK(player.role() == string("FieldDoctor"));
    board[City::Bangkok] = 4;
    CHECK_NOTHROW(player.treat(City::Bangkok));
    CHECK(board[City::Chennai] == 3);

}
