#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle:public Shape{

    private:
    int Side_a,Side_b,Side_c;

    public:
    Triangle(int id, char *color, double a, double b, double c);

    void display();
    double calculateArea() const override;
    double calculatePerimeter() const override;

    ~Triangle();
};

#endif 