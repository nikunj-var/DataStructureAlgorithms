#include <bits/stdc++.h>
using namespace std;
 
// custom data type for tree building
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


Node* constructtree(string s,int &start){
    if(start >= s.length() || s.length() == 0)
        return NULL;

    int num=0;
    Node* root=NULL;

    while(start < s.length() && s[start]!='(' && s[start] != ')'){
        int number=(int)(s[start]-'0');
        num=num*10 + number;
        start++;
    }    
    if(num > 0)
        root=new Node(num);

    if(start < s.length() && s[start] == '('){
        start++;
        root->left=constructtree(s,start);
    }    
    if(start < s.length() && s[start] == ')'){
        start++;
        return root;
    }
    if(start < s.length() && s[start] == '('){
        start++;
        root->right=constructtree(s,start);
    }
    if(start < s.length() && s[start] == ')'){
        start++;
    }
    return root;
}
void preorder(Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    // cin>>s;
    int start = 0;
    Node* root = constructtree(s, start);
    preorder(root);
    return 0;
}