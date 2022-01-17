#define lli long long
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(!n) return 0;
        //precalculating answer for each power of 2
        vector<int> p(33 , 0);
        p[0] = 1;
        int cnt = 1;
        for(int i=1; i<31; i++) {
            cnt *= 2;
            p[i] = p[i-1] + cnt;
        }
        
        int bits = 32 - __builtin_clz(n);
        lli ans = 0;
        bool add = true;
        for(int i=bits-1; i>=0; i--) {
            if(n & (1<<i)) {
                if(add) ans += (lli)p[i] , add = false;
                else ans -= (lli)p[i] , add = true;
            }
        }
        
        return ans;
    }
};