void SortedStack :: sort()
{
    stack<int> tempstk;
    
    while(!s.empty()){
        int val=s.top();
        s.pop();

        while(!tempstk.empty() && tempstk.top() > val){
            s.push(tempstk.top());
            tempstk.pop();
        }
        
        tempstk.push(val);
    }
    while(!tempstk.empty()){
        s.push(tempstk.top());
        tempstk.pop();
    }
    

}