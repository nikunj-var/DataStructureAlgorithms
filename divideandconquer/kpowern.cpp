#include<bits/stdc++.h>
using namespace std;
int a=1;
int exponential(int k,int n){
    if(n == 0)
        return 1;
    else{
        if(n%2 == 0){
            a=exponential(k,n-1);
            return a*k;
        }
        else{
            a=exponential(k,n/2);
            return a*a;
        }
    }    
}
int main(){
    cout<<exponential(2,3);
}