/*Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the
 number of queries. Query can be of two types:

SET x y : sets the value of the key x with value y
GET x : gets the key of x if present else returns -1.

The LRUCache class has two methods get() and set() which are defined as follows.

get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the 
cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new
 item.
In the constructor of the class the capacity of the cache should be intitialized.
 */


class LRUCache
{
    private:
    
    public:
    int capstorage=0;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> l;
    
    int capacity;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key) == mp.end())
            return -1;
        
            l.splice(l.begin(),l,mp[key]);
          
            return  mp[key]->second;
        
      
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {  
        if(mp.find(key)!=mp.end()){
            l.splice(l.begin(),l,mp[key]);
            mp[key]->second=value;
            return;
        }
        if(l.size()==capacity){
            auto del=l.back().first;
            l.pop_back();
            mp.erase(del);
        }
        l.push_front({key,value});
        mp[key]=l.begin();
    }
};
