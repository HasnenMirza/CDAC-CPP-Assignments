//program to check the valid parenthesis.

#include<iostream>
#include<stack>
using namespace std;
bool valid_parenthesis(string s)
{
    stack <char>st;
    for (int i=0;i<s.length();i++)
    {
        if(s.at(i)=='('|| s.at(i)=='['||s.at(i)=='{')
        {
            st.push(s.at(i));
        }
        else {
            if (st.empty())
            {
                return false;
            }
        char c=st.top();
        if((c=='('&& s.at(i)==')'||c=='{'&& s.at(i)=='}'||c=='['&& s.at(i)==']'))
        {
            st.pop();
        }
        else {return false;}
     }
  
    }
    return true;
}
 int main(){

    string s="((([{}])))";
    bool result=valid_parenthesis(s);
    if(result){
        cout<<"It is a valid parenthesis!";
    }
    else
    cout<<"Not a valid parenthesis";
    return 0;
}