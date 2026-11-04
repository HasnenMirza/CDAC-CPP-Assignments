
#include<iostream>
#include "Triangle.h"
#include<cmath>
using namespace std;

Triangle::Triangle(int id, char *color, double a, double b, double c):Shape(color,id){
        Side_a=a;
        Side_b=b;
        Side_c=c;
}

double Triangle::calculateArea()const{ 
double s= (Side_a+Side_b+Side_c)/2.0;
    double area;
    area = sqrt((s*(s-Side_a)*(s-Side_b)*(s-Side_c))); 
    return area;
}

double Triangle::calculatePerimeter() const{
    return this->Side_a + this->Side_b+ this->Side_c;
}

void Triangle::display(){
    Shape::display();
    cout<<"Side a of triangle :"<< Side_a<<endl;
    cout<<"Side b of triangle :"<< Side_b<<endl;
    cout<<"Side c of triangle :"<< Side_c<<endl;
    cout<<"--------------------------------"<<endl;

}

Triangle::~Triangle(){
    cout << "in Triangle destructor...." << endl;
};