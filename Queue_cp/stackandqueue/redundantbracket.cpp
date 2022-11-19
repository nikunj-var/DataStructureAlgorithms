#include<iostream>
#include<stack>
using namespace std;

bool checkredundant(string str){
    stack<char> s;

    for(int i=0;i<str.length();i++){
        if(str[i] == ')'){
            char ch=s.top();
            s.pop();
            bool flag=false;
            while(!s.empty() && ch != '('){
                if(ch=='*' || ch=='-' || ch=='+' || ch=='/')
                    flag=true;
                ch=s.top();
                s.pop();    
            }
            if(!flag)
                return true;
        }
        else{
            s.push(str[i]);
        }
    }
    return false;
}

int main(){
    
    string s;
    cout<<"enter string";
    cin>>s;
    cout<<checkredundant(s);

}