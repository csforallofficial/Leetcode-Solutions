class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans = 1;
        int N = m + n -2;
        int R = m-1;
        for(int i = 1; i <= R; i++){
            ans = ans* (N-R+i)/i;
        }
        return (int)ans;
    }
};