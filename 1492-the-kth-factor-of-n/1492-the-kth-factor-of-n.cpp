class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> fact;
        int sq = sqrt(n);
        
        for ( int i = 1; i <= sq; i++ ) {
            if ( n % i == 0 ) {
                fact.push_back ( i );
                if ( n / i != i ) fact.push_back ( n / i );
            }
        }
        
        sort ( fact.begin(), fact.end() );
        
        if ( k > fact.size() ) return -1;
        return fact[k-1];
    }
};