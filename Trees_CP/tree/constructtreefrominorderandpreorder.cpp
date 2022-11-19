class Solution {
public:
    int findpos(vector<int>& inorder,int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele)
                return i;
        }
        return -1;
    }
   
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int &index,int inorderstart,int inorderend){
       
        if(index>=preorder.size()||inorderstart>inorderend)
            return NULL;
        
        int element=preorder[index++];
        
        TreeNode* root=new TreeNode(element);
        
        int pos=findpos(inorder,element );
      
        root->left=solve(preorder,inorder,index,inorderstart,pos-1);
     
        root->right=solve(preorder,inorder,index,pos+1,inorderend);
      
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        TreeNode* ans=solve(preorder,inorder,preindex,0,inorder.size()-1);
        return ans;
    }
};