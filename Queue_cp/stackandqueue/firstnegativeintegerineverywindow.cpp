
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
               deque<long long int> dq;
               vector<long long int> ans;
               //process first window of size k
               for(int i=0;i<K;i++){
                   if(A[i]<0)
                   dq.push_back(i);
               }
               //store answer of first k sized window
               if(dq.size()>0){
                   ans.push_back(A[dq.front()]);
               }
               else{
                   ans.push_back(0);
               }
               //process for remaining window
               for(int i=K;i<N;i++){
                   //removal indices of out of window
                   if(!dq.empty()&&i-dq.front()>=K){
                       dq.pop_front();
                   }
                    if(A[i]<0)
                        dq.push_back(i);
                if(dq.size()>0){
                        ans.push_back(A[dq.front()]);
               }
               else{
                   ans.push_back(0);
                }
               }
               return ans;
 }
 