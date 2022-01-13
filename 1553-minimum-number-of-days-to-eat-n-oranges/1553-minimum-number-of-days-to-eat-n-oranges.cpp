class Solution {
public:
    int minDays(int n) {
        queue<int>q;
        q.push(n);
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            set<int>s;
            for(int i=0;i<sz;i++){
                int x=q.front();
                q.pop();
                if(x==0)return cnt;
                s.insert(x-1);
                if(x%2==0)s.insert(x/2);
                if(x%3==0)s.insert(x-2*(x/3));
            }
            for(auto x: s)q.push(x);
            cnt++;
        }
        return 0;
    }
};