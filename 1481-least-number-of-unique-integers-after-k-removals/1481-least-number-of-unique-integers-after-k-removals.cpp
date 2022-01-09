class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        vector<int> v;
        
        for ( auto u : arr ) cnt[u]++;
        for ( auto u : cnt ) v.push_back ( u.second );
        
        sort ( v.rbegin(), v.rend() );
        
        while ( !v.empty() ) {
            if ( v.back() <= k ) {
                k -= v.back();
                v.pop_back();
            }
            else break;
        }
        
        return v.size();
    }
};