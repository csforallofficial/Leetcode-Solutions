class Solution {
public:
    void reverse(vector<int>&nums, int start, int end)
    {        
        while(start <= end)
        {
            swap(nums[start++], nums[end--]);
        }
    }
    
    void rotate(vector<int>& nums, int k)
    {
        if(k==0)
            return;
        int n = nums.size();
        k = k%n;
        
        //reverse the entire array from 0th index to n-1th index
        reverse(nums, 0, n-1);
        //reverse the front of array from 0th to k-1th index
        reverse(nums, 0, k-1);
        //reverse right part of rest array from index k to n-1th index
        reverse(nums, k, n-1);
        
    }
};