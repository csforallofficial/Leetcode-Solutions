class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mod = 1e9 + 7;
        vector<vector<long>> mindp(m, vector<long>(n, INT_MAX)), maxdp(m, vector<long>(n, INT_MIN));
        mindp[m - 1][n - 1] = maxdp[m - 1][n - 1] = grid[m - 1][n - 1];
        int dir[] = {0, 1, 0};
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (auto [ni, nj] : initializer_list<array<int, 2>>{{i + 1, j}, {i, j + 1}}) {
                    if (ni < m && nj < n) {
                        mindp[i][j] = min({mindp[i][j], 
                                           maxdp[ni][nj] * grid[i][j],
                                           mindp[ni][nj] * grid[i][j]});
                        maxdp[i][j] = max({maxdp[i][j], 
                                           maxdp[ni][nj] * grid[i][j],
                                           mindp[ni][nj] * grid[i][j]});
                    }
                }
            }
        }
        return max(-1l, maxdp[0][0]) % mod;
    }
};