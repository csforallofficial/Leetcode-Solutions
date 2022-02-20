class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        vector<int> adj[numCourses];
        unordered_map<string,int> track;
        for(auto it:prerequisites){
            indegree[it[1]]++;
            string p = to_string(it[1]) + "_" + to_string(it[0]);
            if(track[p]==1)
                return ans;
            else{
            adj[it[0]].push_back(it[1]);
                string x = to_string(it[0]) + "_" + to_string(it[1]);
                track[x] = 1;
            }
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i]==0)
                q.push(i);
        while(!q.empty()){
            auto first = q.front();
            q.pop();
            ans.push_back(first);
            for(auto ad:adj[first]){
                indegree[ad]--;
                if(indegree[ad]==0)
                    q.push(ad);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()!=numCourses){
            vector<int> ret;
            return ret;
        }
        return ans;
    }
};