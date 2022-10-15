/*Create a set sptSet (shortest path tree set) that keeps track of vertices included in the shortest-path tree, i.e.,
 whose minimum distance from the source is calculated and finalized. Initially, this set is empty. 
Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign the
 distance value as 0 for the source vertex so that it is picked first. 
While sptSet doesn’t include all vertices 
Pick a vertex u which is not there in sptSet and has a minimum distance value. 
Include u to sptSet. 
Then update distance value of all adjacent vertices of u. 
To update the distance values, iterate through all adjacent vertices. 
For every adjacent vertex v, if the sum of the distance value of u (from source) and weight of edge u-v, is less than
the distance value of v, then update the distance value of v. 
*/


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        //sbse pehle ek distance vector banao jisme minimum distance store krni h
        vector<int> dist(v,INT_MAX);
        
        //ek set banao pair int type ka first int denotes distance and second int denotes node
        set<pair<int,int>> st;

        //source ki distance zero se initialize kr do
        dist[s]=0;
        
        //fir source and source ki distance set me daal do
        st.insert({0,s});
        
        //jab tk set khali na ho chalate jao
        while(!st.empty()){
            
            //top element nikalo
            auto top=*(st.begin());
            int nodedistance=top.first;
            int topnode=top.second;
            
            //topelement ko delete kr do
            st.erase(st.begin());
            
            //sare neighbors traverse karo
            for(auto nbr : adj[topnode]){
                
                //agar nodedistance ab tk jitna chala hai + jo neighbour node tk pahuchne me jo weight lagega
                //agr wo neighbor distance se choti hai to ek record me store krke distance or node check kro
                //ki set me hai ya nahi
                //agar hai to use delete kr do
                //neighbor ki distance ko update karo
                //or set me daal do
                if(nodedistance + nbr[1] < dist[nbr[0]]){
                    auto record=st.find(make_pair(dist[nbr[0]],nbr[0]));
                    
                    if(record!=st.end())
                        st.erase(record);
                    
                    dist[nbr[0]]=nodedistance+nbr[1];
                    st.insert(make_pair(dist[nbr[0]],nbr[0]));
                
                }
               
                
            }
        }
        return dist;
    }
};