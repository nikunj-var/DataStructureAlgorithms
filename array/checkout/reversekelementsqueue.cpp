// Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

//solution
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    queue<int> ans;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        ans.push(q.front());
        q.pop();
    }
    return ans;
}