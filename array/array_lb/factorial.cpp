//FACTORIAL OF A LARGE NUMBER


//solution using linkedlist
#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void multiply(Node*& tail,int n){
    Node* temp=tail,*prevnode=tail;
    int carry=0;
    while(temp!=NULL){
        int data=temp->data*n + carry;
        
        temp->data=data%10;
        carry=data/10;
        prevnode=temp;
        temp=temp->next;
        
    }
    while(carry != 0){
        prevnode->next=new Node((int)carry%10);
        carry/=10;
        prevnode=prevnode->next;
    }
    
}

void store(Node* tail , vector<int> &ans){
    
        
        if(tail==NULL){
            return;
        }
        
        store(tail->next,ans);
        ans.push_back(tail->data);
        
}


vector<int> factorial(int n){
        vector<int> ans;
        
        Node* tail=new Node(1);
        
        for(int i=2;i<=n;i++){
            multiply(tail,i);
        }
        
        store(tail,ans);
        return ans;
    }

int main(){
    int n;
    cout<<"enter the number";
    cin>>n;
    
    vector<int> ans=factorial(n);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];    
}