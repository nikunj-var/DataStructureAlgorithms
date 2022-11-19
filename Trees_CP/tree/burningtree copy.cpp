#include <bits/stdc++.h>
using namespace std;
 

class Solution {
  public:
  Node* createmapping(Node* root,int target,map<Node*,Node*> &nodetoparent){
      
      Node* res = NULL;
      queue<Node*> q;
      q.push(root);
      nodetoparent[root]=NULL;
      while(!q.empty()){
          Node* front=q.front();
          q.pop();
          if(front->data==target){
              res=front;
              
          }
          if(front->left){
              nodetoparent[front->left]=front;
              q.push(front->left);
          }
          if(front->right){
              nodetoparent[front->right]=front;
              q.push(front->right);
          }
      }
      return res;
  }
  int burntree(Node* root,map<Node*,Node*> &nodetoparent){
      map<Node*,bool> visited;
      queue<Node*> q;
      q.push(root);
      visited[root]=true;
       int ans=0;
       while(!q.empty()){
           int size=q.size();
           bool flag=0;
           for(int i=0;i<size;i++){
               //process neighbouring node
               
               Node* front=q.front();
               q.pop();
               if(front->left && !visited[front->left]){
                   flag=1;
                   q.push(front->left);
                   visited[front->left]=1;
               }
                 if(front->right && !visited[front->right]){
                     flag=1;
                   q.push(front->right);
                   visited[front->right]=1;
               }
               if(nodetoparent[front] && !visited[nodetoparent[front]]){
                   flag=1;
                   q.push(nodetoparent[front]);
                   visited[nodetoparent[front]]=1;
               }
           }
           if(flag==1){
               ans++;
           }
       }
       return ans;
  }   
  int minTime(Node* root, int target) 
    {
        //algo
        //step1: create nodetoparent mapping
        //step2:find target node
        //step3;burn the tree in min time
       int ans;
       map<Node*,Node*> nodetoparent;
       Node* targetnode =createmapping(root,target,nodetoparent);
       ans=burntree(targetnode,nodetoparent);
       return ans;
       
    }
};