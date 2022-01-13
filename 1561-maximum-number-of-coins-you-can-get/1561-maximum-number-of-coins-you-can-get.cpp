class Solution {
public:
    int maxCoins(vector<int>& piles) {
       sort(piles.begin(),piles.end());
       int ans=0,n=piles.size();
        int times=n/3;
        while(times--)
        {
            n=n-2;
            cout<<n;
            ans+=piles[n];
        }
        return ans;  
    }
};