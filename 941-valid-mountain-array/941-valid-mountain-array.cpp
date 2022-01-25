class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i]<arr[i+1]) continue;
            for(int j=i; j<arr.size()-1; j++){
                if(i == 0) return false;
                i++;
                if(arr[j]>arr[j+1]) continue;
                else return false;
            }
            return true;
        }
        return false;
    }
};