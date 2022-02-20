class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string S = to_string(n);
        int noofdigit = S.size();
        vector<int> dp(noofdigit+1);
        dp[noofdigit] = 1;
        
        for(int i = noofdigit-1; i >= 0; i--){
            for(auto digit:digits){
                int Si = S[i]-'0';
                int di = stoi(digit);
                if(di<Si)
                    dp[i] += (int)pow(digits.size(),noofdigit-i-1);
                else if(di==Si)
                    dp[i] += dp[i+1];
            }
        }
        
        for(int i = 1; i < noofdigit; i++)
            dp[0] += (int)pow(digits.size(),i);
        return dp[0];
    }
};