void threeWayPartition(vector<int>& arr,int a, int b)
{
        int low=0;
        int mid=0;
        int high=arr.size()-1;
        
        while(mid <= high){
            int c;
            if(arr[mid] < a){
                c=0;
            }
            else if(arr[mid] >= a && arr[mid] <= b){
                c=1;
            }
            else{
                c=2;
            }
            switch(c){
                case 0:swap(arr[low++],arr[mid++]);
                        break;
                case 1:mid++;
                        break;
                case 2:swap(arr[mid],arr[high--]);
                        break;
            }
        }
}