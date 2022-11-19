class Solution {
  public:
    
    unordered_map<string,int> m;
  
    string solve(Node* root){
        if(!root)
            return "$";
        
        string s="";
        if(!root->left && !root->right){
            s=to_string(root->data);
            return s;
        }
        
        s+=to_string(root->data)+"$"+solve(root->left)+"$"+solve(root->right);
        m[s]++;
        return s;
    }
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        m.clear();
         solve(root);
         for(auto it:m){
             if(it.second >= 2)
                return true;
         }
         return false;
    }
};