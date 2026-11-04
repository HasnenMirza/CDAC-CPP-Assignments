#include<iostream>
using namespace std;

//returns true if the number is prime otherwise return false
bool isPrime(int num){
    
    for(int i=2;i<num;i++){
       if(num%i==0){
         return false;
       }  
    }
    return true;
}

//returns addition of digits of a number
int findDigitAddition(int num){
   int sum=0;
   while(num>0){
     int d=num%10;
     sum+=d;
     num=num/10;
   } 
   return sum;
}

// function to find the factorial

int fact(int num){
  int factorial=1;
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
  return factorial;
}

// Function to print the multiplication table of a number
void printMultiTable(int num) {

    cout << "\nMultiplication Table for " << num << ":\n";
    for (int i = 1; i <= 10; ++i) {
        cout << num << " x " << i << " = " << (num * i) << "\n";
    }
}


int main(){
   int choice=0,num,result;
   bool status;
   do{
   cout<<"1. Check prime\n2.Factorial\n3. printtable \n 4. find addition of digits of a number\n5. exit\nchoice:";
   cin>>choice;
   switch(choice){
   case 1:
         cout<<"enter number"<<endl;
         cin>>num;
         status=isPrime(num);
         if(status){
             cout<<num <<" is prime"<<endl;
         }else{
             cout<<num<<" is not prime"<<endl;
         }
         break;
   case 2:
         cout<<"enter the number:"<<endl;
	 cin>>num;
	 result=fact(num);
	 cout<<" Factorial of the given number is:" << result<<endl;
         break;
   case 3:
         cout<<"enter the number :"<<endl;
	 cin>>num;
	 printMultiTable(num);
         break;
   case 4:
         cout<<"enter number"<<endl;
         cin>>num;
         result=findDigitAddition(num);
	 cout<<result<<endl;
         break;
   case 5: 
        cout<<"Thank you for using our code"<<endl;
   default:
         break;
   }  
   }while(choice!=5); 
   return 0;
}
