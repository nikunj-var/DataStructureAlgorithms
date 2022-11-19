class Solution{
public:
    void reverse(stack<int> &st){
        if(st.empty())
            return;
        int a=st.top();
        st.pop();
        reverse(st);
        st.push(a);
    }
    vector<int> Reverse(stack<int> st){
        reverse(st);
        vector<int > ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};