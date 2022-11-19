// Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.

class Solution {
	public:
		string FirstNonRepeating(string A){
		    //store the count of char in map
		   unordered_map<char,int> m;
		   //store ans
		   string ans="";
		   queue<char> q;
		   for(int i=0;i<A.length();i++){
		       char ch=A[i];
		       m[ch]++;
		       q.push(ch);
		       while(!q.empty()){
		           if(m[q.front()]>1)
		             q.pop();
		           else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		       }
		       if(q.empty())
		            ans.push_back('#');
		   }
		   return ans;
		}

};