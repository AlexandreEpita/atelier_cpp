//
// Created by axcens on 27/02/23.
//

#pragma once

#include <iostream>

#include "engine.hh"

class Vehicle
{
public:
    Vehicle(const std::string& model, int fuel);
    bool start();
    void stop();
    void cruise(int fuel);
    void fill(int fuel);
    virtual void change_tires() const = 0;

protected:
    const std::string model_;
    Engine engine_;
};
