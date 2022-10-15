// // QUESTION-MEDIAN OF TWO SORTED ARRAYS OF EQUAL SIZE.


// //APPROACH1-
// //using merge sort approach
// //keep track of count while comparing elements of two equal arrays if count becomes n we have reached the median.
// //take the average of the elements at indixes n-1 and n.
// //TC-O(n)


#include<iostream>
#include<algorithm>
using namespace std;

int getmedian(int arr1[],int arr2[],int n){
    int m1=-1,m2=-1;
    int i=0,j=0;
    for(int count=0;count<=n;count++){
        if(i==n){
            m1=m2;
            m2=arr2[0];
            break;
        }
        if(j==n){
            m1=m2;
            m2=arr1[0];
            break;
        }
        if(arr1[i] <= arr2[j]){
            m1=m2;
            m2=arr1[i];
            i++;
        }
        else{
            m1=m2;
            m2=arr2[j];
            j++;
        }
    }
    return (m1+m2)/2;
}

int main(){
    int n;
    
    cout<<"enter size of array";
    cin>>n;
    
    int arr1[n],arr2[n];
    cout<<"enter first array";
    
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    cout<<"enter second first array";
    
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"the median is "<<getmedian(arr1,arr2,n);
}

// //approach2-by comparing the median of two arrays
// //TC-O(logn)

#include<iostream>
#include<algorithm>
using namespace std;

//finds the median of the arrays
int median(int arr[],int n){
    if(n % 2==0){
        return (arr[n/2]+arr[n/2-1])/2;
    }
    return arr[n/2];
}


int getmedian(int arr1[],int arr2[],int n){
    if(n <= 0)
        return 0;
    if(n==1)
        return (arr1[0]+arr2[0])/2;
    if(n==2){
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;
    }


    //get median of first array
    int m1=median(arr1,n);
    //get median of second array
    int m2=median(arr2,n);

    //if both are equal return one of them
    if(m1==m2)
        return m1;

    //if m1 < m2 then  then median must exist in ar1[m1....] and
        //ar2[....m2]
    if(m1 < m2){
        if(n % 2 ==0){
            return getmedian(arr1+n/2-1,arr2,n-n/2+1);
        }
        return getmedian(arr1+n/2,arr2,n-n/2);
    }    

     /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    else{
         if(n % 2 ==0){
            return getmedian(arr2+n/2-1,arr1,n-n/2+1);
        }
        return getmedian(arr2+n/2,arr1,n-n/2);
    }

}

int main(){
    int n;
    
    cout<<"enter size of array";
    cin>>n;
    
    int arr1[n],arr2[n];
    cout<<"enter first array";
    
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    cout<<"enter second first array";
    
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"the median is "<<getmedian(arr1,arr2,n);
}

//FIND THE MEDIAN OF TWO SORTED ARRAYS OF DIFFERENT SIZES

//APPROACH1-

// Given two arrays are sorted. So they can be merged in O(m+n) time. Create a variable count to have a count of elements in the output array.
// If the value of (m+n) is odd then there is only one median else the median is the average of elements at index (m+n)/2 and ((m+n)/2 – 1).
// To merge the both arrays, keep two indices i and j initially assigned to 0. Compare the ith index of 1st array and jth index of second, increase the index of the smallest element and increase the count.
// Store (m+n)/2 and (m+n)/2-1 in two variables (In the below C++ code, m1 and m2 are used for this purpose).
//Check if the count reached (m+n) / 2. If (m+n) is odd return m1, If even return (m1+m2)/2.
//TC-O(m+n)


#include<iostream>
#include<algorithm>
using namespace std;

int getmedian(int arr1[],int arr2[],int m,int n){
    int i=0;
    int j=0;
    int count;
    int m1=-1,m2=-2;

    for(count=0;count<=(m+n)/2;count++){
        m1=m2;
        if(i!=m  && j!=n){
            m1=(arr1[i] > arr2[j])?arr2[j++]:arr1[i++];
        }
        else if(i < n){
            m1=arr1[i++];
        }
        else{
            m1=arr2[j++];
        }
    }
    if((m+n)%2==0){
        return (m1+m2)/2;
    }
    return m1;
}

int main(){
    int m,n;
    
    cout<<"enter size of first array";
    cin>>m;
    
    int arr1[m];
    cout<<"enter first array";
    
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }

    cout<<"enter size of second array";
    cin>>n;

    int arr2[n];
    cout<<"enter second array";
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"the median is "<<getmedian(arr1,arr2,m,n);
}

//APPROACH2-

//1.If the size of smaller array is 0. Return the median of a larger array.
//2.if the size of smaller array is 1. 
    //The size of the larger array is also 1. Return the median of two elements.
    //If the size of the larger array is odd. Then after adding the element from 2nd array, it will be even so the median will be an average of two mid elements. So the element from the smaller array will affect the median if and only if it lies between (m/2 – 1)th and (m/2 + 1)th element of the larger array. So, find the median in between the four elements, the element of the smaller array and (m/2)th, (m/2 – 1)th and (m/2 + 1)th element of a larger array
    //Similarly, if the size is even, then check for the median of three elements, the element of the smaller array and (m/2)th, (m/2 – 1)th element of a larger array
//3.If the size of smaller array is 2 
    //If the larger array also has two elements, find the median of four elements.
    //If the larger array has an odd number of elements, then the median will be one of the following 3 elements 
    //Middle element of larger array
    //Max of the second element of smaller array and element just before the middle, i.e M/2-1th element in a bigger array
    //Min of the first element of smaller array and element 
    //just after the middle in the bigger array, i.e M/2 + 1th element in the bigger array
//4.If the larger array has even number of elements, then the median will be one of the following 4 elements 
    //The middle two elements of the larger array
    //Max of the first element of smaller array and element just before the first middle element in the bigger array, i.e M/2 – 2nd element
    //Min of the second element of smaller array and element just after the second middle in the bigger array, M/2 + 1th element

#include<iostream>
#include<algorithm>
using namespace std;

float mof2(int a,int b){
    return (a+b)/2.0;
}

float mof3(int a,int b,int c){
    return a+b+c-max(a,max(b,c))-min(a,min(b,c));
}
float mof4(int a,int b,int c,int d){
    int maxi=max(a,max(b,max(c,d)));
    int mini=min(a,min(b,min(c,d)));

    return (a+b+c+d-maxi-mini)/2.0;
}

float mediansingle(int arr[],int n){
    if(n==0)
        return -1;
    if(n%2==0)
        return (double)(arr[n/2]+arr[n/2-1])/2;
    return arr[n/2];           
}

float getmedianutil(int arr1[],int m,int arr2[],int n){
    if(m == 0)
        return mediansingle(arr2,n);
    if(m==1){
        if(n==1)
            return mof2(arr1[0],arr2[0]);

        if(n%2 == 1)
            return mof2(arr2[n/2],mof3(arr1[0],arr2[n/2-1],arr2[n/2+1]));
        
        return mof3(arr2[n/2],arr2[n/2-1],arr1[0]);    
    }
    else if(m==2){
        if(n==2){
            return mof4(arr1[0],arr1[1],arr2[0],arr2[1]);
        }
        if(n%2==1){
            return mof3(arr2[n/2],max(arr1[0],arr2[n/2-1]),min(arr2[n/2+1],arr1[1]));
        }

        return mof4(arr2[n/2],arr2[n/2-1],max(arr1[0],arr2[n/2-2]),min(arr1[1],arr2[n/2+1]));
    }
    int index1=(m-1)/2;
    int index2=(n-1)/2;
    if(arr1[index1] <= arr2[index2]){
        return getmedianutil(arr1+index1,m/2+1,arr2,n-index1);
    }
    return getmedianutil(arr1,m/2+1,arr2+index1,n-index1);
}

int getmedian(int arr1[],int arr2[],int m,int n){
    if(m > n){
        return getmedianutil(arr2,n,arr1,m);
    }
    return getmedianutil(arr1,m,arr2,n);
}

int main(){
    int m,n;
    
    cout<<"enter size of first array";
    cin>>m;
    
    int arr1[m];
    cout<<"enter first array";
    
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }

    cout<<"enter size of second array";
    cin>>n;

    int arr2[n];
    cout<<"enter second array";
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"the median is "<<getmedian(arr1,arr2,m,n);
}