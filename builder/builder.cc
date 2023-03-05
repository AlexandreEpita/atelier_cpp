//
// Created by axcens on 02/03/23.
//
#include "builder.hh"

Car Builder::get_car() const
{
    Car my_car = Car();
    my_car.engine_ = get_engine();
    my_car.body_ = get_body();
    my_car.wheels_ = std::array<std::unique_ptr<Wheel>, 4>(
        { get_wheel(), get_wheel(), get_wheel(), get_wheel() });
    return my_car;
}

std::unique_ptr<Wheel> JeepBuilder::get_wheel() const
{
    return std::make_unique<Wheel>(Wheel(22));
}

std::unique_ptr<Engine> JeepBuilder::get_engine() const
{
    return std::make_unique<Engine>(Engine(400));
}

std::unique_ptr<Body> JeepBuilder::get_body() const
{
    return std::make_unique<Body>(Body("SUV"));
}

std::unique_ptr<Wheel> NissanBuilder::get_wheel() const
{
    return std::make_unique<Wheel>(Wheel(16));
}

std::unique_ptr<Engine> NissanBuilder::get_engine() const
{
    return std::make_unique<Engine>(Engine(85));
}

std::unique_ptr<Body> NissanBuilder::get_body() const
{
    return std::make_unique<Body>(Body("hatchback"));
}
