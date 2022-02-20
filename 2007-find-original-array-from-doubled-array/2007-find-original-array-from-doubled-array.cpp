class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        vector<int> ret;
        if(changed.size()%2)
            return ret;
        vector<int> freq(1e5+7,0);
        int maxi = INT_MIN;
        for(auto it:changed){
            maxi = max(maxi,it);
            freq[it]++;
        }
        int zercount = 0;
        if(freq[0]>=0 && freq[0]%2==0){
            zercount = freq[0]/2;
            freq[0] = 0;
        }
        while(zercount--)
            ans.push_back(0);
        for(int i = 1; i <= maxi/2; i++){
            if(freq[i]!=0){
                if(freq[i]<=freq[i*2]){
                    while(freq[i]--){
                        ans.push_back(i);
                        freq[i*2]--;
                    }
                } else
                    goto exit;
            }
        }
        for(int i = 0; i <= maxi; i++)
            if(freq[i]>0)
                goto exit;
        return ans;
        exit:
            return ret;
    }
};