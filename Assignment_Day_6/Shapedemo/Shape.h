#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
using namespace std;
   class Shape{
   private:
      int id;
      char *color;
    public:
        Shape(char* c, int id);
        // double calculateArea(){
        //     cout << "In shape calculate area" << endl;
        //     return 0;
        // }
        int getId() const {
            return id;
        }
        virtual double calculateArea() const = 0;
        virtual void display();
        virtual double calculatePerimeter() const = 0;
        virtual ~Shape();
   };
#endif
