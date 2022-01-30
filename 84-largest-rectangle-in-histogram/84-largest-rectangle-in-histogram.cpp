class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int rb[heights.size()];
        stack<int> st;
        rb[heights.size()-1] = heights.size();
        st.push(heights.size()-1);
        for(int i = heights.size()-2; i >= 0; i--){
            while(st.size()>0 && heights[i] <= heights[st.top()])
                st.pop();
            if(!st.size())
                rb[i] = heights.size();
            else
                rb[i] = st.top();
            st.push(i);
        }
        
        int lb[heights.size()];
        stack<int> s;
        lb[0] = -1;
        s.push(0);
        for(int i = 1; i < heights.size(); i++){
            while(s.size()>0 && heights[i] <= heights[s.top()])
                s.pop();
            if(!s.size())
                lb[i] = -1;
            else 
                lb[i] = s.top();
            s.push(i);
        }
        
        int width, area = 1, maxi = 0;
        for(int i = 0; i <= heights.size()-1; i++){
            width = rb[i]-lb[i]-1;
            area = width*heights[i];
            if(area > maxi)
                maxi = area;
        }
        return maxi;
    }
};