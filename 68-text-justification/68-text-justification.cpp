class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        while(i<words.size()){
            int wc = 1;
            string ans = "";
            ans.append(words[i]);
            i++;
            int j = i;
            int curlen = ans.size();
            while(j<words.size() && (curlen+1+words[j].size())<=maxWidth){
                wc++;
                curlen += 1+words[j].size();
                j++;
            }
            if(j==words.size()){
                for(int x = i; x < j; x++){
                    ans.append(" ");
                    ans.append(words[x]);
                }
                int rem = maxWidth-curlen;
                while(rem--)
                    ans.append(" ");
            }
            else{
                if(wc==1){
                    int sp = maxWidth-curlen;
                    while(sp){
                        ans.append(" ");
                        sp--;
                    }
                } else{
                    int sp = wc-1;
                    int extragensp = (maxWidth-curlen)/sp+1;
                    int extrasp = (maxWidth-curlen)%sp;
                    for(int x = i; x < j; x++){
                        for(int y = 1; y <= extragensp; y++)
                            ans.append(" ");
                        if(extrasp){
                            ans.append(" ");
                            extrasp--;
                        }
                        ans.append(words[x]);
                    }
                }
            }
            res.push_back(ans);
            i = j;
        }
        return res;
        
    }
};