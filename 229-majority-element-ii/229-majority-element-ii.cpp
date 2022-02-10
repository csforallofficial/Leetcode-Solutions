class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==1)
            return nums;
        int cur1 = -1, cur2 = -1, count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cur1==nums[i]){
                count1++;
            } else if(cur2==nums[i]){
                count2++;
            } else if(count1==0){
                cur1 = nums[i];
                count1 = 1;
            } else if(count2==0){
                cur2 = nums[i];
                count2 = 1;
            } else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==cur1)
                count1++;
            else if(nums[i]==cur2)
                count2++;
        }
        if(count1>nums.size()/3)
        ans.push_back(cur1);
        if(count2>nums.size()/3)
        ans.push_back(cur2);
        return ans;
    }
};