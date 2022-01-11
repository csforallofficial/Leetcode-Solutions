class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
           int mod = 1e9 + 7;
          
           int pre_sum = 0,ev = 0, od = 0, ans = 0;
           
           for(int ele : arr){
               pre_sum += ele;
               
               if(pre_sum & 1){
                    od++;
                    ans = (ans + ev + 1) % mod;
               }
               
               else {
                   ev++;
                   ans = (ans + od ) % mod;
               }
           }
        
        return ans;
    }
};