class Solution {
public:

    int minFlips(string target) {
        int count=0;
        
        if(target[0]=='1') count++;

        for(int i=1; i<target.size(); i++){
            if(target[i-1]!=target[i]) count++;
        }
        
        return count;
    }
};