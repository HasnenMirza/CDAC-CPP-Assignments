#include<iostream>
#include<cstring> 
using namespace std;

int main(){
    char ch='a';
    char str[50],*name; // FIX: Added array size 50 to prevent crash
    cout<<"enter a string: ";
    cin>>str;    //acept the string upto 1st space chracter ot \n character
    // cin.getline(str, 50, '\n');   //to accept string with spaces
    int length=strlen(str);
    name=new char[length+1];
    strcpy(name,str);
    cout<<"Name : "<<name<<endl;

    // strcmp Comparison
    if (strcmp(name, "admin") == 0) {
        cout << "String match " << endl;
    } else {
        cout << "String not match!" << endl;
    }

    delete[] name;
    return 0;
}

