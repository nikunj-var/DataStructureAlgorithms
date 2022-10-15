//given an array and an integer k find the element which appears more than n/k times

//approach1- For every picked element, count its occurrences by traversing the array, if count becomes more than n/k, then print the element. Time Complexity of this method would be O(n2.

//approach2-sorting ,after sort count the occurences of all elements in one scan
//tc-O(nlogn)
//sc-O(1)


#include<iostream>
#include<algorithm>
using namespace std;

class elementcount{
    public:
        int element;
        int count;
        elementcount(){
            count=0;
        }
};


void appearnbyktimes(int arr[],int n,int k){
    //step1
    elementcount temp[n-k];

    //step2
    for(int i=0;i<n;i++){
        //if element is already present in the temp array then increment its count by 1.
        int j;
        for(j=0;j<k-1;j++){
            if(temp[j].element==arr[i]){
                temp[j].count++;
            }
        }
        
        //if element is not present in array
        if(j == k-1){
            int l;
            //if there is any position availvale in the temp for the element
            for(l=0;l<k-1;l++){
                if(temp[l].count==0){
                    temp[l].element=arr[i];
                    temp[l].count++;
                    break;
                }
                //if the temp array is completely filled
                //then decrement the count of all array elements
                if(l == k-1){
                    for(l = 0;l < k-1;k++){
                        temp[l].count-=1;
                    }
                }
            }
        }
    }
    //step3
    //count the actual count of the number in the array
    for(int i=0;i<k-1;i++){
        int ac=0;
        for(int j=0;j<n;j++){
            if(arr[j]==temp[i].element){
                ac++;
            }
        }
        if(ac > n/k)
        {
            cout<<"the number is "<<temp[i].element<<endl;
        }
    }
    

}


int main(){
    int n,k;
    
    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter k";
    cin>>k;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    appearnbyktimes(arr,n,k);
}



