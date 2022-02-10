class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]==cur){
                count++;
            } else{
                count--;
                if(count==0){
                    cur = nums[i];
                    count++;
                }
            }
        }
                       return cur;
    }
};