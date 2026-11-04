#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle :public Shape{
    double len, br;
    public:
        Rectangle(int id, char* c, double len, double br);
        double calculateArea() const override;
        double calculatePerimeter() const override;
        void display();
        ~Rectangle();
};

#endif