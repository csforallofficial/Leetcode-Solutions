class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        map<int, int> mp;
        mp[1] = n;
        int val = -1;
        if (m == n) return n;
        for (int i = n - 1; i >= 0; i--) {
            map<int, int> :: iterator it = mp.lower_bound(arr[i]);
            if (it == mp.end() || it->first > arr[i])   it = prev(it);
            //cout << it->first << ":" << it->second << endl;
            if (it->first == arr[i]) {
                mp[it->first + 1] = it->second;
                if ((it->second - it->first) == m)  return i;
                mp.erase(it->first);
            } else {
                mp[arr[i] + 1] = it->second;
                if (it->second - arr[i] == m)   return i;
                it->second = arr[i] - 1;
                if (it->second - it->first + 1 == m)    return i;
            }
        }
        
        return -1;
    }
};