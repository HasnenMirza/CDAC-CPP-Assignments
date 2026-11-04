#include<iostream>
//using namespace std;


int main(){
    int a = 5;
    int b = 10;

    const int* ptr1 = &a;  // pointer to const int — *ptr1 is read-only
    int* const ptr2 = &a;  // const pointer to int — ptr2 cannot point elsewhere

    // You can change ptr1 to point somewhere else though (pointer itself is non-const)
    ptr1 = &b;  //  OK: ptr1 can point to another int

    // But you can change the value of what ptr2 points to
    *ptr2 = 30;  //  OK: modifying value through ptr2 is allowed

    std::cout << "a = " << a << std::endl;  // Output: a = 30
    std::cout << "b = " << b << std::endl;  // Output: b = 10

    return 0;
}

