class Solution {
public:
    int numSub(string s) {
        //'count' will store the answer
        long long count=0,mod=1000000007;
        int i=0,n=s.length();
        
        // iterate the string and look for substrings containing only 1s
        while(i<n) {
            long long tmp=0;
            while(i<n && s[i]=='1') {
                i++;
                tmp++;
            }
            
            // if a segment( with only 1s) is of length = tmp then there can be  (tmp*(tmp+1))/2 substrings from the segment
            long long curr=(tmp*(tmp+1))/2;
            
            // add the current result to the main result
            count=(count+curr)%mod;
            i++;
        }
        return count;
    }
};