//Check whether the given string is palindrome or not using stack.

#include <iostream>
#include<stack>
using namespace std;

int main(){

    string s;
    cout<<"Enter the string to check whether it is palindrom or not"<<endl;
getline(cin, s);
stack <char>st;
for(int i=0;i<s.length();i++){
    char c=s.at(i);
    st.push(c);
}
string rev="";
while(!st.empty()){
    char c=st.top();
    rev+=c;
    st.pop();
}
if(s==rev){
    cout<<"THe string is palindrome"<<endl;
}else cout<<"Not a palindrome string";

    return 0;
}