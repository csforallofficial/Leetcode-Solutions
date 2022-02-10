class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> track;
        for(int i = 0; i < nums.size(); i++)
            track[nums[i]]++;
        int fac = nums.size()/2;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(track[nums[i]]>fac){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};