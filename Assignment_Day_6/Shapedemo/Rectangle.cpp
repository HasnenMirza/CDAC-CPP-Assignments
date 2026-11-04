#include "Rectangle.h"
#include <iostream>

using namespace std;
Rectangle::Rectangle(int id, char*c , double l, double b): Shape(c, id), len(l), br(b){
    cout << "In Rectangle constructor...." << endl;
    
// {
//     len = l;
//     br = b;
}
double Rectangle::calculateArea() const {
    cout << "in rect. calculate area" << endl;
  return this->len * this->br;
}
double Rectangle::calculatePerimeter() const  {
  return 2*(this->len + this->br);
}

void Rectangle::display(){
  Shape::display();
  cout << "length : " << len 
       << "breadth : " << br << endl;
  cout << "------------------" << endl;
}

Rectangle::~Rectangle(){
    cout << "in rectangle destructor...." << endl;
}