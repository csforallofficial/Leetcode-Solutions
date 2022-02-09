class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> res(2,0);
        res[0] = intervals[0][0];
        res[1] = intervals[0][1];
        for(int i = 0; i < n; i++){
            if(res[1]>=intervals[i][0]){
                res[0] = min(res[0],intervals[i][0]);
                res[1] = max(res[1],intervals[i][1]);
            } else{
                ans.push_back(res);
                res[0] = intervals[i][0];
                res[1] = intervals[i][1];
            }
        }
        ans.push_back(res);
        return ans;
    }
};