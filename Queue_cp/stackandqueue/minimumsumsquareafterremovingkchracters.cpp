
//tc-O(k*logn)
//approach1-A Better Solution used to Priority Queue which has to the highest element on top. 

// Initialize empty priority queue.
// Count frequency of each character and Store into temp array.
// Remove K characters which have highest frequency from queue.
// Finally Count Sum of square of each element and return it.
// Below is the implementation of the above idea. 

class Solution{
public:
    int minValue(string s, int k){
          
       priority_queue<int> q;
       int l=s.length();
    
        int ans=0;
    
       if(k >= l)
        return 0;
        
        int freq[26]={0};
        
        for(int i=0;i<l;i++){
            freq[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i])
                q.push(freq[i]);
        }
        
        while(k--){
            int temp=q.top();
            q.pop();
            temp--;
            q.push(temp);
        }
        
        while(!q.empty()){
            int temp=q.top();
            q.pop();
            ans+=temp*temp;
        }
        return ans;
    }
};

//approach2-O(n)