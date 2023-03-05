//
// Created by axcens on 27/02/23.
//

#pragma once

class Point
{
public:
    void display() const;
    void move(int x, int y);

private:
    int x_;
    int y_;
};
