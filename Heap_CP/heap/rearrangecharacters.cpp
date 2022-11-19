/*Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the
given string can be rearranged so that no 
adjacent characters in the string is equal.
Any correct rearrangement will show a output
of 1.*/
class Solution
{
    public:
    string rearrangeString(string str)
    {
        map<char,int> mp;
        for(int i=0;i<str.length();i++){
            mp[str[i]]++;
        }
       priority_queue<pair<int,char>> pq;
       for(auto it:mp){
           pq.push({it.second,it.first});
           
       }
       str="";
       auto it=pq.top();
       pq.pop();
       
       str+=it.second;
       it.first--;
       auto block=it;
       while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
          
           str+=it.second;
           it.first--;
           if(block.first > 0)
                pq.push(block);
            block=it;
       }
        if(block.first > 0)
            return "-1";
    return str;      
    
    }
   
};
