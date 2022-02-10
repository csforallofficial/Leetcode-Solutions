class Solution {
public:
    int dp[101][101];
    int helper(int i, int j, int m, int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        else
        return dp[i][j] = helper(i+1,j,m,n) + helper(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        int ans=helper(0,0,m,n);
        return ans;
    }
};