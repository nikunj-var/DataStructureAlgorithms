#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//approach1
bool checkrotation(string a,string b){
    if(a.length() != b.length())
        return false;
    string temp=a+a;
    return temp.find(b) != string::npos;
}

//approach2
bool checkrotation(string a,string b){
     if(a.length() != b.length())
        return false;
    queue<char> q1,q2;
    for(auto i:a)
        q1.push(i);
    for(auto j:b)
        q2.push(j);
    int size=a.length();
    while(size--){
        char c=q2.front();
        q2.pop();
        q2.push(c);
        if(q1==q2)
            return true;
    }        
    return false;
}



int main(){
    string a,b;
    a="abcd";
    b="bcda";
    cout<<checkrotation(a,b);
}
