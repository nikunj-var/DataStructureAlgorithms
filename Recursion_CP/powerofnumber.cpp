#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;

    //recursive call
    int ans=power(a,b/2);
    if(b%2==0)
        return ans*ans;
    else
        return a*ans*ans;            
}

int main(){
    cout<<"enter number";
    int n;
    cin>>n;
    cout<<"enter power ";
    int p;
    cin>>p;
    cout<<power(n,p);
}