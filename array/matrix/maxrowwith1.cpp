#include<vector>
using namespace std;
int rowWithMax1s(vector<vector<int> > arr, int m, int n) {
	    int j=n-1;
	    int maxrow=0;
	    
	    for(int i=0;i<m;i++){
	        
	        bool flag=false;
	        while(j>=0 && arr[i][j]==1)
	        {
	            j--;
	            flag=true;
	        }
	        if(flag){
	            maxrow=i;
	        }
	    }
	    if(maxrow == 0 && arr[0][n-1]==0)
	        return -1;
	   
	   return maxrow;     
	}
