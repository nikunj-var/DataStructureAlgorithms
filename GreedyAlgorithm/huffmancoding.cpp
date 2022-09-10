TC-O(nlogn)
SC-O(n)

class Node{
public:    
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

class cmp{
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
};
class Solution
{
	public:
	    void traverse(Node* root,vector<string>& ans,string temp){
	        if(!root->left && !root->right)
	        {
	            ans.push_back(temp);
	            return;
	        }
	        traverse(root->left,ans,temp+'0');
	        traverse(root->right,ans,temp+'1');
	    }
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{   
            priority_queue<Node*,vector<Node*> ,cmp> q;
            
            for(int i=0;i<n;i++){
                Node* temp=new Node(f[i]);
                q.push(temp);
            }
            
            while(q.size() > 1){
                auto a=q.top();
                q.pop();
                auto b=q.top();
                q.pop();
                Node* newnode=new Node(a->data+b->data);
                newnode->left=a;
                newnode->right=b;
                q.push(newnode);
            }
            Node* root=q.top();
            vector<string> ans;
            string temp="";
            
            traverse(root,ans,temp);
            return ans;
		}
};