class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>&A) {
        int n = A.size();
        int l = -1;
        int r = n;
        for(int i = 0; i < n - 1; i++)
        {
            if(A[i] > A[i + 1])
            {
                l = i;
                break;
            }
        }
        for(int i = n - 1; i > 0; i--)
        {
            if(A[i] < A[i - 1])
            {
                r = i;
                break;
            }
                
        }
        if(l == -1)
            return 0;
        int count = min(n - l + 1,r);
        for(int i = l; i >= 0; i--)
        {
            auto r1 = lower_bound(A.begin() + r,A.end(),A[i]);
            int right = r1 - A.begin();
            count = min(count, right - i - 1) ;
        }
        return count;
        
    }
};