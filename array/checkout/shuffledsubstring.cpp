// Given strings str1 and str2. The task is to find if str1 is a substring in the shuffled form of str2 or not. Print “YES” if str1 is a substring in shuffled form of str2 else print “NO”. 

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//approach1-

// Let n = length of str1, m = length of str2. 

// If n > m, then string str1 can never be the substring of str2.
// Else sort the string str1.
// Traverse string str2 
// Put all the characters of str2 of length n in another string str.
// Sort the string str and Compare str and str1.
// If str = str1, then string str1 is a shuffled substring of string str2.
// else repeat the above process till ith index of str2 such that (i +n – 1 > m)(as after this index the length of remaining string str2 will be less than str1.
// If str is not equals to str1 in above steps, then string str1 can never be substring of str2.

bool shuffledstring(string a,string b){
    int n=a.length();
    int m=b.length();
    if(n > m)
        return false;
    
    sort(a.begin(),a.end());
    string str=b;
    sort(str.begin(),b.end());


    

}

int main(){
    string a,b;
    cout<<"enter first string ";
    cin>>a;
    cout<<"enter second string ";
    cin>>b;
    if(shuffledstring(a,b)){
        cout<<"string is shuffled";
    }
    else
    {
        cout<<"string is not shuffled";
    }
}