#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class student {
private:
    int sid, sage;
    float m1, m2, m3;
    char* sname;

public:
    // Constructors
    student();
    student(const char* name, int id, int age, float mark1, float mark2, float mark3);

    // Rule of Three: Copy Constructor & Copy Assignment
    student(const student& other);
    student& operator=(const student& other);

    // Setter methods
    void setSid(int id);
    void setName(const char* name);
    void setAge(int age);
    void setM1(float mark1);
    void setM2(float mark2);
    void setM3(float mark3);

    // Getter methods
    int getAge() const;
    const char* getName() const;
    int getSid() const;

    // Display prototype (Implementation is in student.cpp)
    void display() const;

    // Destructor
    ~student();
};

#endif