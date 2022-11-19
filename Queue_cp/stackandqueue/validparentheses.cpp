class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for(int i=0;i<str.length();i++){
            
            if(str[i] == '(')
                s.push(')');
           
            else if(str[i] == '{')
                s.push('}');
            
            else if(str[i] == '[')
                s.push(']');
            
            else if(s.empty() || str[i] != s.top())
                return false;
            
            else
                s.pop();
        }
        return s.empty();
    }
};