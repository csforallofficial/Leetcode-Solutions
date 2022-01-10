class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;int c=0;int pnc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[pnc]==nums[i])
                c++;
            else
            {
            pnc=i;
            ans=ans+((c-1)*(c))/2 ;   
            c=1;
            }
            if(i==nums.size()-1)
                ans+=((c-1)*c)/2;
            
        }

    return ans;
        
    }
};