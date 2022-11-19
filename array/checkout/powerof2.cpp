// //approach1
#include<iostream>
using namespace std;

int powerof2(int n){
    if(n == 0)
        return 1;
    return 2*powerof2(n-1)    
}

int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    cout<<powerof2(n);
}

//approach2

#include<iostream>
using namespace std;

bool powerof2(int n,int &mul){
    
    if( mul == n){
        return true;
    }
    if(mul > n)
        return false;
        
    powerof2(n,mul*=2);

}

int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    int mul=1;
    cout<<powerof2(n,mul);
}