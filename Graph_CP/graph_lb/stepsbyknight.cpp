/*Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
*/
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int n)
	{
	   int x1=k[0];
	   int y1=k[1];
	   int x2=t[0];
	   int y2=t[1];
	   
	   
	   vector<vector<int>> visited(n,vector<int> (n,0));
	   queue<pair<int,int>> q;
	   q.push({x1-1,y1-1});
	   
	   if(x1 == x2 && y1==y2)
        return 0;
	   while(!q.empty()){
	       auto curr=q.front();
	       q.pop();
	       
	       int i=curr.first;
	       int j=curr.second;
	       
	       if((i-2) >=0 && (i-2)<n && (j-1) >=0 && (j-1) < n && !visited[i-2][j-1]){
	           visited[i-2][j-1]=visited[i][j]+1;
	           q.push({i-2,j-1});
	       } 
	       if((i-1) >=0 && (i-1)<n && (j-2) >=0 && (j-2) < n && !visited[i-1][j-2]){
	           visited[i-1][j-2]=visited[i][j]+1;
	           q.push({i-1,j-2});
	       } 
	        if((i+2) >=0 && (i+2)<n && (j-1) >=0 && (j-1) < n && !visited[i+2][j-1]){
	           visited[i+2][j-1]=visited[i][j]+1;
	           q.push({i+2,j-1});
	       } 
	       if((i+1) >=0 && (i+1)<n && (j-2) >=0 && (j-2) < n && !visited[i+1][j-2]){
	           visited[i+1][j-2]=visited[i][j]+1;
	           q.push({i+1,j-2});
	       } 
	        if((i-2) >=0 && (i-2)<n && (j+1) >=0 && (j+1) < n && !visited[i-2][j+1]){
	           visited[i-2][j+1]=visited[i][j]+1;
	           q.push({i-2,j+1});
	       } 
	       if((i-1) >=0 && (i-1)<n && (j+2) >=0 && (j+2) < n && !visited[i-1][j+2]){
	           visited[i-1][j+2]=visited[i][j]+1;
	           q.push({i-1,j+2});
	       } 
	        if((i+2) >=0 && (i+2)<n && (j+1) >=0 && (j+1) < n && !visited[i+2][j+1]){
	           visited[i+2][j+1]=visited[i][j]+1;
	           q.push({i+2,j+1});
	       } 
	       if((i+1) >=0 && (i+1)<n && (j+2) >=0 && (j+2) < n && !visited[i+1][j+2]){
	           visited[i+1][j+2]=visited[i][j]+1;
	           q.push({i+1,j+2});
	       } 
	 
	   }
	   return visited[x2-1][y2-1];
	}
};
