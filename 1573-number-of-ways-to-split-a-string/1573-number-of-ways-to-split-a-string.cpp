class Solution {
public:
    long long mod = 1e9 + 7;
    
    long long ways (long long n){
        n = (long long) ((n - 1) * (n - 2) / 2 ) % mod;
        return n;
    }
    
    int numWays(string s) {
        int ones = 0;
        int n = s.size();
       
        for(char ch : s) { ones += ch - '0'; }
        
        if(ones % 3 != 0) return 0;
        if(ones==0 ) return  ways(n) % mod;
        
        int oneThird = ones / 3;
        ones = 0;
        long long ways1 = 0, ways2 = 0;
        
        for(char ch : s) {
            ones += ch - '0';
            
            if(ones == oneThird) ways1++;
            if(ones == 2 * oneThird) ways2++;
            
        }
        
        return (long long) (ways2 * ways1) % mod;
     }
};