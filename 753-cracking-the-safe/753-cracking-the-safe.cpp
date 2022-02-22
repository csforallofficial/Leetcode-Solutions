class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> track;
        string s = string(n-1,'0');
        string bruijn = s;
        solve(s,&bruijn,&track,n,k);
        return bruijn;
    }
    void solve(string s, string *bruijn, unordered_set<string> *track, int n, int k){
        for(int i = k-1; i >= 0; i--){
            string cur = s + to_string(i);
            if(track->find(cur)==track->end()){
                track->insert(cur);
                *bruijn += to_string(i);
                solve(cur.substr(1),bruijn,track,n,k);
            }
        }
    }
};