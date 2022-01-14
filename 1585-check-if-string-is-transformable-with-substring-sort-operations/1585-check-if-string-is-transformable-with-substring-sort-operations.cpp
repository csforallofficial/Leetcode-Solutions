class Solution {
public:
    bool isTransformable(string s, string t) 
    {
        int n=t.size();
        vector<queue<int>>v(10);
        for(int i=0;i<n;i++)
            v[s[i]-'0'].push(i);
        for(int i=0;i<n;i++)
        {
            int d=t[i]-'0';
            if(v[d].empty())
                return false;
            int pos=v[d].front();
            v[d].pop();
            for(int j=0;j<d;j++)
            {
                if(!v[j].empty() && v[j].front()<pos)
                    return false;
            }
        }
        return true;
    }
};