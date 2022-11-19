char* reverse(char *s, int len)
{   char* ans=new char[len];
    stack<char> st;
    for(int i=0;i<len;i++){
        st.push(s[i]);
    }
    
    int i=0;
    while(i<len && !st.empty()){
        ans[i]=st.top();
        st.pop();
        i++;
    }
    return ans;
}