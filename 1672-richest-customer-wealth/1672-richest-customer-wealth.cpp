class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        unordered_map<int, int> acc;
        int n = accounts.size();
        int m = accounts[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                acc[i]+=accounts[i][j];
            ans=max(ans,acc[i]);
        }
        return ans;
    }
};