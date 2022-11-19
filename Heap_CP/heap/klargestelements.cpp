//print k largest elements

//using sorting
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    sort(arr,arr+n);
	    vector<int> ans;
	    for(int i=0;i<k;i++){
	        ans.push_back(arr[n-i-1]);
	    }
	    return ans;
	}

};

//using priorityqueue
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int> p;
	    
	    for(int i=0;i<n;i++){
	        p.push(arr[i]);
	    }
	    
	    vector<int> ans;
	    
	    while(k--){
	        ans.push_back(p.top());
	        p.pop();
	    }
	    return ans;
	}

};