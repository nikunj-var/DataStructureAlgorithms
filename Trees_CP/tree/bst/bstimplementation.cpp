#include<bits/stdc++.h>
using namespace std;

class tree{
    public:
        int data;
        tree* left;
        tree* right;
        tree(){
            left=NULL;
            right=NULL;
        }
        tree(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
        void insertion(tree*& root,int d){
            if(!root){
                root=new tree(d);
                return ;
            }
            tree* head=root;
            while(head){
                if(head->data > d){
                   if(!head->left){
                        head->left=new tree(d);
                        return;
                } 
                   else{
                    head=head->left;
                }
            }
            else{
                if(!head->right){
                    head->right=new tree(d);
                    return;
                }
                else
                    head=head->right;
                }
            }    
        }
        tree* search(tree* root,int d){
            if(!root)
                return NULL;
            if(root->data == d)
                return root;
            if(root->data > d){
                return search(root->left,d);
            }        
            return search(root->right,d);
        }
        void print(tree* root){
            if(!root)
                return;
            print(root->left);
            cout<<root->data<<" ";
            print(root->right);    
        }
};
int main(){
    tree t;
    tree* root=NULL;
    t.insertion(root,10);
    t.insertion(root,7);
    t.insertion(root,11);
    t.insertion(root,13);
    t.insertion(root,9);
    t.insertion(root,90);
    tree* s=t.search(root,100);
    if(!s){
        cout<<"not found";
    }
    else{
        cout<<"found"<<endl;
    }
    t.print(root);
    // cout<<endl;
    // t.deletenode(root,13);
    // t.print(root);
}