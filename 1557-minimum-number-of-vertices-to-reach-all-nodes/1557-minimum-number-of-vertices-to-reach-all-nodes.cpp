class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int>st(n,0), ans;
    for(auto &e: edges) st[e[1]] = 1;
    
    for(int i = 0; i != n; i++) if(st[i] == 0) ans.push_back(i);
    return ans;
  }
};