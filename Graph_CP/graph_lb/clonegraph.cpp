//using bfs

class Solution {
public:
    Node* clonegraph(Node* node){
        map<Node*,Node*> m;
        Node* n=new Node();
        queue<Node*> q;
        q.push(node);
        n->val=node->val;
        m[node]=n;
        
        while(!q.empty()){
            Node* u=q.front();
            q.pop();
            
            vector<Node*> v=u->neighbors;
            for(int i=0;i<v.size();i++){
                if(m[v[i]] == NULL){
                    q.push(v[i]);
                    n=new Node();
                    n->val=v[i]->val;
                    m[v[i]]=n;
                }
                m[u]->neighbors.push_back(m[v[i]]);
            }
        }
        return m[node];
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        Node* newnode=clonegraph(node);
        return newnode;
    }
};

//using dfs

class Solution {
public:
    
    void dfs(Node* node,map<int,Node*>& m,Node* clone){
        for(auto adj:node->neighbors){
            if(m.find(adj->val) == m.end()){
                Node* newnode=new Node(adj->val);
                m[newnode->val]=newnode;
                clone->neighbors.push_back(newnode);
                dfs(adj,m,newnode);
            }
            else
                clone->neighbors.push_back(m[adj->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        Node* clone=new Node(node->val);
        map<int,Node*> visited;
        visited[clone->val]=clone;
        dfs(node,visited,clone);
        return clone;
    }
};