#include "Circle.h"
#include <iostream>

using namespace std;
Circle::Circle(int id, char*c,  double r): Shape(c, id), radius(r){
    cout << "In Circle constructor...." << endl;
}
// {
//     radius = r;
// }
double Circle::calculateArea() const {
  return (3.14 * this->radius * this->radius);
}
double Circle::calculatePerimeter() const {
  return (2 * 3.14 * this->radius);
}

void Circle::display(){
  Shape::display();
  cout << "radius : " << radius << endl; 
  cout << "------------------" << endl;
}


Circle::~Circle(){
    cout << "in Circle destructor...." << endl;
};