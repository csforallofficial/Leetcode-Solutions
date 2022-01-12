class Solution {
public:
    
vector<vector<int>> dp;
    
    int solve(int i, int j, vector<int> &cuts) {
        int &res = dp[i][j];
        if (res > -1) return res;
        if (j - i == 1) {
            return res = 0;
        }
        res = 1e9;
        for (int k = i + 1; k < j; k++) {
            int cur = solve(i, k, cuts) + solve(k, j, cuts);
            res = min(cur, res);
        }
        res += cuts[j] - cuts[i];
        return res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int l = cuts.size() + 2;
        vector<int> cts(l);
        cts[0] = 0;
        sort(cuts.begin(), cuts.end());
        for (int i = 1; i < l - 1; i++) cts[i] = cuts[i - 1];
        cts[l - 1] = n;
        dp.resize(l, vector<int>(l, -1));
        return solve(0, l - 1, cts);
    }
};