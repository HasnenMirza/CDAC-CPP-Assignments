#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle :public Shape{
    double radius;
    public:
        Circle(int id, char* c, double radius);
        double calculateArea() const override;
        double calculatePerimeter() const override;
        void display();
        ~Circle();
};

#endif