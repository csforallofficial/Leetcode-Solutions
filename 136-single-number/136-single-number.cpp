class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> frequency;
        for(auto it:nums)
            frequency[it]++;
        int ans = -1;
        for(auto it:nums){
            if(frequency[it]==1){
                ans = it;
            }
        }
        return ans;
    }
};