#include <iostream>

#include "game.hh"
#include "lambdas.hh"
#include "player.hh"

int main()
{
    auto coop = grudger();
    auto cheat = detective();
    auto copy = copycat();
    auto test_game = [](auto strategy1, auto strategy2) {
        Game game(strategy1, strategy2);
        const auto& [score1, score2] = game.play(10);
        std::cout << score1 << " : " << score2 << '\n';
    };

    test_game(copy, cheat);
    test_game(copy, cheat);
    test_game(copy, cheat);
}
