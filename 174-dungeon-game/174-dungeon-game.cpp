class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[n-1][m-1] = dungeon[n-1][m-1];
        if(dp[n-1][m-1]>0)
            dp[n-1][m-1] = 0;
        for(int i = n-2; i >= 0; i--){
            dp[i][m-1] = dungeon[i][m-1] + dp[i+1][m-1];
            if(dp[i][m-1]>0)
                dp[i][m-1] = 0;
        }
        for(int j = m-2; j >= 0; j--){
            dp[n-1][j] = dungeon[n-1][j] + dp[n-1][j+1];
            if(dp[n-1][j]>0)
                dp[n-1][j] = 0;
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                dp[i][j] = dungeon[i][j] + max(dp[i+1][j],dp[i][j+1]);
                if(dp[i][j] > 0)
                    dp[i][j] = 0;
            }
        }
        return 1+(-dp[0][0]);
    }
};