class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string cur = string(n-1,'0');
        string debruijn = cur;
        solve(&visited,&debruijn,cur,n,k);
        return debruijn;
    }
    void solve(unordered_set<string> *visited, string *debruijn, string cur, int n, int k){
        for(int i = k-1; i >= 0; i--){
            string nex = cur + to_string(i);
            if(visited->find(nex)==visited->end()){
                visited->insert(nex);
                *debruijn += to_string(i);
                solve(visited,debruijn,nex.substr(1),n,k);
            }
        }
    }
};