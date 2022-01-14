class Solution {
public:
    int solve(vector<int>&A, int s, int f, int fuel,vector<vector<int>>&DP)
    {
        int mod = 1e9 + 7;
        if(fuel < 0)
            return 0;
        
        if(DP[s][fuel] != -1)
            return DP[s][fuel];
        if(s == f)
        {
            int route = 1;
            for(int i = 0; i < A.size(); i++)
            {
                if(s == i)
                    continue;
                route += solve(A,i,f, fuel - abs(A[s] - A[i]),DP);
                route = route % mod;
            }
            DP[s][fuel] = route;
            return route;
        }
        
        int total = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(i == s)
                continue;
            total += solve(A,i,f, fuel - abs(A[s] - A[i]),DP);
            total = total % mod;
        }
        DP[s][fuel] = total;
        return total;
    }
    int countRoutes(vector<int>&A, int s, int f, int fuel) 
    {
        int n = A.size();
        vector<vector<int>>DP(n,vector<int>(fuel + 1,-1));
        return solve(A,s,f,fuel,DP);
    }
};