class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int res = INT_MAX; 
        set<int> pre = {arr[0]}, cur;
        for(auto x:arr){
            cur.insert(x);
            for(auto y:pre) cur.insert(x&y);
            for(auto& z:cur) res = min(res, abs(z-target));
            pre = move(cur);
        }          
        return res;
    }
};