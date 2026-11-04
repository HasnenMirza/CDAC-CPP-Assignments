#include<iostream>
using namespace std;

class MathUtils{
  private: 
     
     static long long factorial(int num) {
        if (num < 0) {
            return -1; 
        }

        long long fact = 1;
        for (int i = 1; i <= num; ++i) {
            fact *= i;
        }
        return fact; 
     }

  public:
       //this function can be called by using classname::functionname
       //it doesnot receive this pointer
       //static function can use only static members, to use nonstatic member you need to create object and then use it
       static int addition(int n1,int n2){

             return n1+n2;
       } 
       
       static int combination(int n,int r){
         int result;
         result=factorial(n)/(factorial(r)*factorial(n-r));
         return result;
       }

};

int main(){
   int num1=20,num2=30,result;
   result=MathUtils::addition(num1,num2);
   cout<<"answer : "<<result<<endl;
   cout<<"answer: "<<MathUtils::addition(num1,num2)<<endl;
   cout<<"answer: "<<MathUtils::combination(5,2)<<endl;
   return 0;
}
