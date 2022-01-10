class Solution {
public:
    bitset<100001> dp, v;
    bool winnerSquareGame(int n) {
        if (!n || v[n]) return dp[n];
        v[n] = 1;
        for (int i = 1; i * i <= n; i++) {
            if (!winnerSquareGame(n - i * i))
                return dp[n] = 1;
        }
        return false;
    }
};