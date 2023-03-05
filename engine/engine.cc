//
// Created by axcens on 27/02/23.
//

#include "engine.hh"

Engine::Engine(int fuel)
    : fuel_(fuel)
{}

bool Engine::start()
{
    if (fuel_ > 0)
    {
        fuel_ -= 1;
        std::cout << "Engine starts with " << fuel_ << " units of fuel\n";
        return true;
    }
    return false;
}

void Engine::use(int consumed)
{
    if (fuel_ - consumed >= 0)
    {
        fuel_ -= consumed;
        std::cout << "Engine uses " << consumed << " fuel units\n";
    }
    else
    {
        std::cout << "Engine uses " << fuel_ << " fuel units\n";
        fuel_ = 0;
    }
}

void Engine::stop() const
{
    std::cout << "Stop Engine\n";
}

void Engine::fill(int fuel)
{
    if (fuel > 0)
    {
        fuel_ += fuel;
        std::cout << "Engine now has " << fuel_ << " fuel units\n";
    }
}