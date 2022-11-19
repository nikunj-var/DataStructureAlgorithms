class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==1)
                st.push(b);
            else if(M[b][a] == 1)
                st.push(a);
        }
        int cele=st.top();
        st.pop();
        bool rowcheck=false;
        bool colcheck= false;
        
        int zero=0;
        //rowcheck
        for(int i=0;i<n;i++){
            if(M[cele][i]==0)
                zero++;
        }
        if(zero==n)
            rowcheck=true;
        int one=0;
        for(int i=0;i<n;i++){
            if(M[i][cele]==1)
                one++;
        }
        if(one==n-1)
            colcheck=true;
        if(rowcheck && colcheck)
            return cele;
        return -1;    
    }
};