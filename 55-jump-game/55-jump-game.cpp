class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0, r = 0, far = 0, n = nums.size();
        bool flag = true;
        while(r<n-1){
            for(int i = l; i <= r; i++){
                far = max(far,nums[i]+i);
            }
            l = r+1;
            r = far;
            if(l>r){
                flag = false;
                break;
            }
        }
        return flag;
    }
};