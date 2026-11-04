#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "ShapeService.h"
#include "Triangle.h"

using namespace std;

int main(){
    Shape *sArr[100];
    int count = 0, id;
    int choice = 0;
    double area, perimeter;
    // readdata("shapedata.txt",sArr,count);
    cout<<count;
    do{
      cout << "1. add new shape\n 2.calculate area by id\n 3.calculate perimeter by id\n ";
      cout << "4. display count of given type\n 5. display all\n 6.count all types\n 0. exit\n";
      cin >> choice;
      int subChoice = 0,type;
      bool status = false;
      switch(choice){
        case 1:
            // add new shape
            cout << "1.Rectangle\n 2.Circle\n3.Triangle\n";
            cin >> subChoice;
            status = ShapeService::addNewShape(sArr , count, subChoice);
            if(status){
                cout << "Shape added..." << endl;
            }
            else{
                cout << "Not added..."<< endl;
            }
            break;
        case 2:
            // 2.calculate area by id
            cout << "enter id : ";
            cin >> id;
            area = ShapeService::findAreaById(sArr, count, id);
           //out << "Area : " << (area > 0 ? area  : -1) << endl;
            if (area >= 0) {
        cout << "Area: " << area << endl;
    } else {
        cout << "Shape with ID " << id << " not found!" << endl;
    }
            break;
        case 3:
            // calculate perimeter by ID
            cout << "enter id : ";
            cin >> id;
            perimeter= ShapeService::findperimeterByID(sArr,count,id);
            cout<<"Perimeter is equal to :"<< perimeter<<endl;
            break;
        case 4:
            // 4. display count of given type
            cout<<"enter type"<<endl;
            cout << "1.Rectangle\n 2.Circle\n3.Triangle\n";
            cin>>type;
         ShapeService::countByType(sArr,count, type);
         
            break;
        case 5:
            // display all shape
            ShapeService::displayAll(sArr, count);
            break;
        case 6:
            ShapeService::countAll(sArr, count);
            break;
        case 0:
            // add new shape
            // writedata("shapedata.txt",sArr)
            cout << "thankyou...." << endl;
            break;
        default:
            cout << "Wrong choice\n";
      }
      
    }while(choice != 0);
    return 0;
}