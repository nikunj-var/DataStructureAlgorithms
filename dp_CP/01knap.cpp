#include <iostream>
using namespace std;

int main(){
    int w,n;
    cout<<"Enter  weight of Knapsack";
    cin>>w;
    cout<<"enter number of items";
    cin>>n;
    
    int ben[n+1],wei[n+1];
    for(int i=1;i<=n;i++){
        cin>>wei[i];
        cin>>ben[i];
    }
    for(int i=1;i<=n;i++){
        cout<<"\n ITEM"<<i<<endl;
        cout<<"("<<ben[i];
        cout<<" ,"<< wei[i]<<")";
    }
    cout<<"\n";
    
    int b[n+1][w+1];
    for(int i=0;i<=w;i++)
    {
        b[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        b[i][0]=0;
    }
    // generate matrix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j < wei[i]){
                b[i][j]=b[i-1][j];
            }
            else{
                if((ben[i] + b[i-1][j-wei[i]]) > b[i-1][j]){
                    b[i][j]=ben[i] + b[i-1][j-wei[i]];
                }
                else{
                    b[i][j]=b[i-1][j];
                }
            }
        // cout<<b[i][j] <<" ";
        }
        cout<<"\n";
    }
    
    cout<<"\n\n\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"Knapsack 0-1 Solution"<<endl;
    
    int i=n,j=w;
    while(i > 0 && j > 0){
        if(b[i][j] != b[i-1][j]){
            cout<<"item "<<i;
            i--;
            j=j-wei[i];
        }
        else{
            i--;
        }
    }
    
}