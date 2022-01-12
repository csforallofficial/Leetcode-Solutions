class Solution {
private:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case '0': s[i]='1';
                    break;
                case '1': s[i]='0';
                    break;
            }
        }
        return s;
    }
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++){
            string tmp=invert(s);
            reverse(tmp.begin(),tmp.end());
            s=s+"1"+tmp;
        }
        return s[k-1];
    }
};