class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;   
        }
        for(int i = 0; i < m; i++){
            bool flag = false;
            if(nums1[i]>nums2[0]){
                swap(nums1[i],nums2[0]);
                flag = true;
            }
            if(flag){
            int cur = nums2[0];
            int j = 0;
            while(j<n-1 && cur>nums2[j+1]){
                nums2[j]=nums2[j+1];
                j++;
            }
            nums2[j]=cur;
            }
        }
        int k = 0;
        for(int i = m; i < m+n; i++){
            nums1[i]=nums2[k++];
        }
    }
};