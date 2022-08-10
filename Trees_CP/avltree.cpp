#include<iostream>
using namespace std;

class tree{
    public:
        int data;
        int height;
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
            height=1;
        }
        int heightoftree(tree* root){
            if(root==NULL)
                return 0;
            return root->height;    
        }
        int getbalance(tree* root){
            if(root==NULL)
                return 0;
            return heightoftree(root->left) - heightoftree(root->right);    
        }
        tree* insert(tree* root,int value){
            if(root==NULL){
                root=new tree(value);
            }
            else if(root->data > value){
                root->left=insert(root->left,value);
            }
            else if(root->data < value){
                root->right=insert(root,value);
            }
            else{
                return root;
            }
            root->height=1 + max(heightoftree(root->left),heightoftree(root->right));

            int balance=getbalance(root);

            
        }
};