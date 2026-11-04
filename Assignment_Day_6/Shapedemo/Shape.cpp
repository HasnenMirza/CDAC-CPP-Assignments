#include "Shape.h"
#include <cstring>
#include <iostream>
using namespace std;
Shape::Shape(char *c, int id){
    cout<< "In shape constructor..." << endl;
    color = new char[strlen(c) + 1];
    strcpy(color, c);
    this->id = id;
}
void Shape::display(){
    cout << "id : " << id << '\t' 
         << "color : " << color;
}
Shape::~Shape(){
    cout << "in shape destructor...." << endl;
    delete[] color;
}
