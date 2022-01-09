class TreeAncestor {
public:
    vector <int> v[500005];
    int level[500005];
    int parent[500005][32];
    TreeAncestor(int n, vector<int>& par) {
        for(int i = 0; i<n; i++)
            for(int j = 0; j<32; j++)
                parent[i][j] = -1;
        
        for(int i = 0; i<n; i++){
            if(par[i]!=-1){
                v[i].push_back(par[i]);
                v[par[i]].push_back(i);
            }
        }
        dfs(0,-1,0);
        fill_parent(n);
    }
    
    int getKthAncestor(int node, int k) {
        // Actually consider k in its binary form, in that way, when you find its 2nd bit set, then we only 
        // need to access parent[node][2], and dont need to raise it to 2^2, as our parent array already store that!
        int count = 0;
		// We deal with k in its binary form. When we encouter its set bit, we jump to an ancestor which is at that 
		// distance from it using parent/dp array. 
        while(k>0){
            if(k&1) node = parent[node][count];
            if(node==-1) return -1;
            k>>=1;            
            count++;
        }
        return node;
    }
protected:
	// The work of this DFS function is only to fill the level array and set the direct parent to each node.
    void dfs(int node, int par, int lev){
        level[node] = lev;
        parent[node][0] = par;
        
        for(auto u : v[node]){
            if(u!=par) 
                dfs(u,node,lev+1);
        }
    }
    
	// Filling the parent/dp array as explained above
    void fill_parent(int n){
        for(int j = 1; j<32; j++){
            for(int i = 0; i<n; i++){
                if(parent[i][j-1]!=-1){
                    int inter = parent[i][j-1];
                    parent[i][j] = parent[inter][j-1];
                }
            }
        }
    }
};