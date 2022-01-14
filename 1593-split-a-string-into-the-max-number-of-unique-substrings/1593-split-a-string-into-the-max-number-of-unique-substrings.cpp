class Solution {
private:
    void backtrack(int &ans,string s,unordered_set<string>&seen){
        if(s.empty()){
            int len=seen.size();
            ans=max(ans,len);
        } else {
            for(int i=0;i<s.size();i++){
                string cnd=s.substr(0,i+1);
                if(seen.count(cnd)==0){
                    seen.insert(cnd);
                    backtrack(ans,s.substr(i+1),seen);
                    seen.erase(cnd);
                }
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        int ans=1;
        unordered_set<string>seen;
        backtrack(ans,s,seen);
        return ans;
    }
};