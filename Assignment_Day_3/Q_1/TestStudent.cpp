#include<iostream>
#include "student.h"
using namespace std;

int main(){
 student s("Kishori",10,20,12,34,33.3),s1;

 s1.setSid(10);
 s1.setName("xxx");
 s1.setAge(20);
 s1.setM1(12);
  s1.setM2(14);
 s1.setM3(15);

 student *s2=new student();
s2->setSid(20);
    s2->setName("yyyy");
    s2->setAge(30);
    s2->setM1(17);
    s2->setM2(19);
    s2->setM3(11);
 // display the data
 s.display();
 s1.display();
 s2->display(); 
 delete s2;
 return 0;  
}
