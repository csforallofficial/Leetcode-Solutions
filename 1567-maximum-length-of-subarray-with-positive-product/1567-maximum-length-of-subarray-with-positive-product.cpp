class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg=0, temp, ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                pos = 0;
                neg = 0;
            }
            else if(nums[i] > 0){
                pos++;
                if(neg>0)
                    neg++;
            }
            else{
                if(neg>0)
                    temp = neg + 1;
                else
                    temp = 0;
                neg = pos+1;
                pos = temp;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};