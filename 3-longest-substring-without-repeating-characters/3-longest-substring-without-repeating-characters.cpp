class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> track;
        int left = 0, right = 0, ans = 0;
        while(right<s.size()){
            if(track.find(s[right])!=track.end())
                left = max(left,track[s[right]]+1);
            track[s[right]] = right;
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};