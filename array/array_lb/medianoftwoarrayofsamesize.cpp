#include<iostream>
using namespace std;
 
double getMedian(int a1[],int a2[],int n){
    int m1=-1;
    int m2=-1;

    int i=0,j=0;

    for(int count=0;count<=n;count++){
        if(i == n){
            m1=m2;
            m2=a2[0];
            break;
        }
        if(j == n){
            m1=m2;
            m2=a2[0];
            break;
        }
        if(a1[i] <= a2[j]){
            m1=m2;
            m2=a1[i];
            i++;
        }
        else{
            m1=m2;
            m2=a2[j];
            j++;
        }
        m1=m2;
    }

    return (m1+m2)/2;
}

int main()
{
    int ar1[] = { 1, 6, 7, 8 };
    int ar2[] = { 2, 3, 4, 5 };
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";
    return 0;
}