class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(int i = 0; i < candyType.size(); i++)
            st.insert(candyType[i]);
        if(st.size()<candyType.size()/2)
            return st.size();
        else
            return candyType.size()/2;
    }
};