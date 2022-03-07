class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> track;
        int A = 0, B = 0;
        for(int i = 0; i < guess.size(); i++)
            track[guess[i]]++;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i]==guess[i]){
                A++;
                track[secret[i]]--;
            }
        }
        for(int i = 0; i < secret.size(); i++){           
            if(secret[i]!=guess[i] && track[secret[i]]>0){
                B++;
                track[secret[i]]--;
            }
        }
        string ans = to_string(A);
        ans.push_back('A');
        ans += to_string(B);
        ans.push_back('B');
        return ans;
    }
};