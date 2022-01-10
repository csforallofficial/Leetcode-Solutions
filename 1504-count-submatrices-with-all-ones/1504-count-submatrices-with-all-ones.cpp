class Solution {
public:
    int count(vector<int> &arr,int height)
    {
        int ans=0;
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==height) //only of this height -> less or more will be covered in other
            {
                ans+=(1+st.size());
                st.push(height);
            }
            else
            {
                while(st.size()) st.pop();  //clear stack
            }
        }
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        //add rows downwards and then use monotonic stack
        //add upper rows in bottom line
        //count rectange of height only how many rows are added
        
        int ans=0;
        for(int i=mat.size()-1;i>=0;i--)
        {
            //check of this row with height=1
            ans+=count(mat[i],1);
            for(int j=i-1;j>=0;j--)
            {
                //ith row=ith row+jth row //update
                //count with height=i-j+1;
                //count using stack
                for(int k=0;k<mat[i].size();k++) mat[i][k]+=mat[j][k];
                ans+=count(mat[i],i-j+1);
            }
        }
        return ans;
    }
};