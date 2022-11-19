void deletedeepest(Node* root,Node* del){
    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* flag=NULL;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        
   
        if(temp->left){
            if(temp->left == del){
                delete temp->left;
                temp->left=NULL;
            }
            else
                q.push(temp->left);
        }
          
        if(temp->right){
            if(temp->right == del){
                delete temp->right;
                temp->right=NULL;
            }
            else{
                 q.push(temp->right);
            }
        }
           
    }
}
struct Node* deletionBT(struct Node* root, int key)
{
    if(!root)
        return NULL;
    if(!root->left && !root->right){
        if(root->data == key){
            return NULL;
        }
        return root;
    }    
    
    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* flag=NULL;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        
        if(temp->data == key)
            flag=temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(flag){
        flag->data=temp->data;
        deletedeepest(root,temp);
    }
    
    return root;
}