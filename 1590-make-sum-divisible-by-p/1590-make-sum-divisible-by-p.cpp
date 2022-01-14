class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp.insert({0,-1});
        int target=0;
        for(int i=0;i<n;i++)
        {
            target=(target+nums[i])%p;
        }
        if(target==0)
        {
            return 0;
        }
        int ans=n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=(sum+nums[i])%p;
            int want=(sum-target+p)%p;
            if(mp.find(want)!=mp.end())
            {
                ans=min(ans,i-mp[want]);
            }
            mp[sum]=i;
        }
        if(ans==n)
        {
            return -1;
        }
        return ans;
    }
};