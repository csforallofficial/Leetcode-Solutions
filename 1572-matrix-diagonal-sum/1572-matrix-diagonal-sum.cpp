class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int pdig = 0;
        int sdig = 0;
        
        int res;
        
        // Getting the sum of the primary and secondary diagonals
        for(int i =0;i<n;i++){
            pdig += mat[i][i];
            sdig += mat[i][n-i-1];
        }
        
        // If the size is odd, middle term is added twice
        if(n%2!=0){
            res = pdig+sdig-mat[n/2][n/2];
        }
        else{
            
            res = pdig+sdig;
            
        }
        
        return res;
        
    }
};
