class Solution {
public:
  bool canConvertString(string s, string t, int k) {
    if(s.size() != t.size()) return false;
    int table[26];
    for(int i = 0; i != 26; i++) table[i] = i - 26;
    
    for(int i = 0; i != s.size(); i++)
      if(int def = t[i] - s[i])
        if((table[def > 0 ? def : def += 26] += 26) > k) return false;      
    
    return true;      
  }
};