class Solution {
public:
     string restoreString(string s, vector<int>& indices) {
        int n=s.length();
        for(int i=0;i<n;i++){
         while(indices[i]!=i){
             swap(s[i],s[indices[i]]);//now that the chars are shuffled
             swap(indices[i],indices[indices[i]]);//shuffle the indices too  
         }
        }
        return s;        
    }
};