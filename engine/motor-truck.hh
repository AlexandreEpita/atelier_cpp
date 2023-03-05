//
// Created by axcens on 27/02/23.
//

#pragma once

#include <iostream>

#include "vehicle.hh"

class MotorTruck : public Vehicle
{
public:
    MotorTruck(const std::string& model, int fuel, size_t nb_tires);
    void change_tires() const override;

private:
    size_t nb_tires_;
};