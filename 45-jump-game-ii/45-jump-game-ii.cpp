class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, far = 0, n = nums.size(), ans = 0;
        while(r<n-1){
            for(int i = l; i <= r; i++){
                far = max(far,nums[i]+i);
            }
            l = r+1;
            r = far;
            ans++;
        }
        return ans;
    }
};