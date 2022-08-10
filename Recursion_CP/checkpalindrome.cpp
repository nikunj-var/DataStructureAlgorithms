#include<iostream>
#include<string>
using namespace std;

bool checkpalindrome(string& s,int i,int j){
    if(i>j)
        return true;

    if(s[i]!=s[j])
        return false;

    return checkpalindrome(s,i+1,j-1);     
}

int main(){
    string s;
    cout<<"enter string";
    cin>>s;

    if(checkpalindrome(s,0,s.length()-1))
        cout<<"palindrome";
    else
        cout<<"not palindrome";   
    
}