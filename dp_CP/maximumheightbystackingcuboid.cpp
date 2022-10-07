class Solution {
public:
    bool check(vector<int> base,vector<int> newbox){
        if(newbox[0] <= base[0] && newbox[1] <= base[1] && newbox[2] <= base[2])
            return true;
        else    
            return false;    
    }
    int solve(int n,vector<vector<int>>& a){
        vector<int> currrow(n+1,0);
        vector<int> nextrow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                if(prev == -1 || check(a[curr],a[prev]))
                    take=a[curr][2]+nextrow[curr+1];
                int nottake=0+nextrow[prev+1];    
                currrow[prev+1]=max(take,nottake);
            }
            nextrow=currrow;
        }
        return nextrow[0];

    }
    int maxHeight(vector<vector<int>>& cuboids) {

        //step1:sort all dimenstion for every cuboid
        for( auto &a:cuboids){
            sort(a.begin(),a.end());
        }

        //step2:sort all cuboids basis of width
        sort(cuboids.begin(),cuboids.end());

        //step3:use logic os longest increasing subsequence
        return solve(cuboids.size(),cuboids);
    }
};