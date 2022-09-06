//heap is a complete binary tree which comes with a heap order property
//cbt(complete binary tree)-a tree every level is completely filled except the last level,nodes always add from the left

#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int *arr;
        int capacity;
        int size;
        heap(int c){
            capacity=c;
            size=0;
            arr=new int[c];
        }
        void insert(int key){
            if(size == capacity){
                cout<<"heap overflow";
                return;
            }
            size++;
            int ind=size;
            arr[ind]=key;
            while( ind > 1){
                int parent=ind/2;
                if(arr[parent] < arr[ind]){
                    swap(arr[parent],arr[ind]);
                    ind=parent;
                }
                else
                    return;
            }
        }
        void deletenode(){
            if(size == 0)
                return;
            arr[1]=arr[size];
            size--;
            int i=1;
            while(i < size){
                int left = 2*i;
                int right = 2*i + 1;
                if(left < size && arr[i] < arr[left]){
                    swap(arr[i] , arr[left]);
                    i=left;
                }
                else if(right < size && arr[i] < arr[right]){
                    swap(arr[i] , arr[right]);
                    i=right;
                }
                else{
                    return;
                }
            }    
        }
        void heapify(int arr[],int n,int i){
            int max=i;
            int left=2*i + 1;
            int right=2*i + 2;
            if(left < n && arr[max] < arr[left])
                max=left;
            if(right < n && arr[max] < arr[right])
                max=right;
            if(max != i){
                swap(arr[max],arr[i]);
                heapify(arr,n,max);
            }    
        }
};
int main(){
    heap h(10);
    h.insert(3);
    h.insert(2);
    h.deletenode();
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    for(int i=0;i<h.size;i++){
        cout<<h.arr[i]<<" ";
    }
}