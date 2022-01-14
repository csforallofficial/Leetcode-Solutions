class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int n = colors.length();
        int total_time=0;
        for(int i=0; i<n-1; i++){
            if(colors[i]==colors[i+1]){
                total_time += min(need[i], need[i+1]);
                need[i+1] = max(need[i], need[i+1]);
            }
        }
        return total_time;
    }
};