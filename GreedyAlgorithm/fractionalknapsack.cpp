static bool cmp(pair<double,Item> a,pair<double,Item> b){
    return a.first > b.first;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>> v;
        for(int i=0;i<n;i++){
            double perunitvalue=(1.0 * arr[i].value)/arr[i].weight;
            pair<double,Item> p=make_pair(perunitvalue,arr[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        
        double totalvalue=0;
        for(int i=0;i<n;i++){
            if(v[i].second.weight > W){
                totalvalue+=W*v[i].first;
                W=0;
            }
            else{
                totalvalue+=v[i].second.value;
                W-=v[i].second.weight;
            }
        }
        return totalvalue;
    }
        
};