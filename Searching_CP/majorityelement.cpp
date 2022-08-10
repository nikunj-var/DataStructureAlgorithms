//MAJORITY ELEMENT IS THE ELEMENT WHICH OCCURS N/2 TIMES IN THE ARRAY

// //approach1-brute force
// //tc-O(n^2)
// //sc-O(1)

// #include<iostream>
// #include<climits>
// #include<algorithm>
// using namespace std;

// int majorityelement(int arr[],int n){
//     int maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         int count=0;
//         for(int j=i+1;j<n;j++){
//             if(arr[i]==arr[j]){
//                 count++;
//             }
//         }
//         maxi=max(maxi,count);
//     }
//     if(maxi > n/2)
//         return maxi;
//     else
//         return -1;    
// }

// int main(){
//     int n;
//     int target;

//     cout<<"enter size of array";
//     cin>>n;

//     int arr[n];
//     cout<<"enter array";
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//    cout<<majorityelement(arr,n);
// }

//approach2-use binary search tree
//tc-O(nlogn)
//sc-O(n)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

class tree{
    public:
        int data;
        tree* left,*right;
        int count;
        int flag=0;
        tree(int data){
            left=NULL;
            right=NULL;
            this->data=data;
            count=1;
        }
        tree* insertion(tree*& root,int data,int n){
            if(root==NULL){
                root=new tree(data);
                return root;
            }
            tree* head=root;
            while(head){
                if(head->data > data){
                    if(head->left){
                        head->left=new tree(data);
                        break;
                    }
                    else{
                        head=head->left;
                    }
                    cout<<"inserted"<<endl;
                }
                else if(head->data < data){
                    if(head->right){
                        head->right=new tree(data);
                        break;
                    }
                    else{
                        head=head->right;
                    }
                    cout<<"inserted";
                }
                else{
                    head->count++;
                    cout<<head->data<<" "<<head->count<<endl;
                    if(head->count /2 >n){
                        cout<<head->data;
                    }
                }               
            }
            return root;
        }
};

int majorityelement(int arr[],int n){
    tree* root=NULL;
    tree* t;
    for(int i=0;i<n;i++){
        root=t->insertion(root,arr[i],n);
        
    }
    return -1;
}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    cout<<n/2;
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   cout<<majorityelement(arr,n);
}
