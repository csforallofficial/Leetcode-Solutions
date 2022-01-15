class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_map<int,vector<int>>dp;
        for(int i=0;i<n;i++)
        {
            dp[arr[i]].push_back(i);
        }
        vector<int>vis(n+1000,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                if(temp==n-1)
                {
                    return level;
                }
                if(temp-1>=0&&vis[temp-1]==0)
                {
                    vis[temp-1]=1;
                    q.push(temp-1);
                }
                if(temp+1<n&&vis[temp+1]==0)
                {
                    vis[temp+1]=1;
                    q.push(temp+1);
                }
                for(auto &it:dp[arr[temp]])
                {
                    if(vis[it]==0)
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
                dp[arr[temp]].clear();
            }
            level++;
        }
        return 0;
    }
};