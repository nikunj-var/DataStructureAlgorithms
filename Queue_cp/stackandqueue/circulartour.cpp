// QUESTION
// Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.

// The amount of petrol that every petrol pump has.
// Distance from that petrol pump to the next petrol pump.
// Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n). Assume for 1-litre petrol, the truck can go 1 unit of distance.
// For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where the truck can make a circular tour is 2nd petrol pump. Output should be “start = 1” (index of 2nd petrol pump).

//SOLUTION

// Another efficient solution can be to find out the first petrol pump where the amount of petrol is greater than or
// equal to the distance to be covered to reach the next petrol pump. Now we mark that petrol pump as start and now we 
//check whether we can finish the journey towards the end point. If in the middle, at any petrol pump, the amount of petrol is
// less than the distance to be covered to reach the next petrol pump, then we can say we cannot complete the circular tour
// from start. We again try to find out the next point from where we can start our journey i.e. the next petrol pump where the 
//amount of petrol is greater than or equal to the distance to be covered and we mark it as start. We need not look at
// any petrol pump in between the initial petrol pump marked as start and the new start as we know that we cannot complete
// the journey if we start from any middle petrol pump because eventually we will arrive at a point where amount of petrol is
// less than the distance. Now we repeat the process until we reach the last petrol pump and update our start as and when required.
// After we reach our last petrol pump, we try to reach our first petrol pump from the last and let’s say we have a remaining amount 
//of petrol as curr_petrol. Now we again start traveling from the first petrol pump and take the advantage of our curr_petrol and try
// to reach the start. If we can reach the start, then we may conclude that start can be our starting point.Now you might be wondering
// even after reaching the end of the array why we are not making any circular tour and after reaching the end we’re concluding the result.
// The main concept is that :-
// Let’s suppose we start at the 0’th pump moving on and at the middle we’ve negative fuel so we’ll restart our journey from the middle position.
// Now let’s suppose after reaching the end we’ve some fuel in our tank. We’re saying that the middle position will be
// the starting position. But why we’re not going back to the middle element ( from where we’ve started our journey) 
//from the end to just check whether it’s possible to make circular tour or not? It’s because we’ve already checked previously 
//that it’s possible to come from the 0’th index to the middle. So no need to check for the remaining part of the circular 
//tour since it will always be a valid tour.

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump arr[],int n)
    {
       
       int start;
       for(int i=0;i<n;i++){
           if(arr[i].petrol >= arr[i].distance){
               start=i;
               break;
           }
       }
       
       int i=start;
       int currpetrol=0;
       for(;i<n;){
           currpetrol+=(arr[i].petrol-arr[i].distance);
           
           if(currpetrol < 0){
               i++;
               for(;i<n;i++){
                   if(arr[i].petrol >= arr[i].distance){
                      start=i;
                      currpetrol=0;
                      break;
                       
                   }
               }
           }
           else{
              i++;
           }
       }
        
        if(currpetrol < 0)
            return -1;
            
       for(int i=0;i<start;i++){
           currpetrol+=(arr[i].petrol-arr[i].distance);
           
           if(currpetrol < 0)
            return -1;
       }
       return start;
    }
};

// Another simpler approach is to store the value of the capacity in some variable whenever the capacity becomes less than zero.

// In this case You have to traverse the array only once as compared to previous method which traverses the each index twice.


/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump arr[],int n)
    {
       
      int start=0;
      int deficit=0;
      int capacity=0;
      for(int i=0;i<n;i++){
          capacity+=arr[i].petrol - arr[i].distance;
          
          if(capacity < 0){
              start=i+1;
              deficit+=capacity;
              capacity=0;
          }
      }
      
      return (capacity+deficit >= 0)? start : -1;
    }
};
