class Solution {
private:
    unordered_map<string, int> ranks;

    string key(int i, int j){
        return to_string(i) + "," + to_string(j);    
    }
    
    bool prefersOver(int partner, int desiredPartner, int undesiredPartner){
        string notPaired = key(partner, desiredPartner);
        string paired    = key(partner, undesiredPartner);
        
        // lower rank == greater the preference
        return ranks[notPaired] < ranks[paired]; 
    }
    
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        // find rank for every preference associated with a partner
        
        for(int partner = 0; partner < preferences.size(); partner++){
            for(int rank = 0; rank < preferences.at(partner).size(); rank++){
                int friendOfPartner = preferences.at(partner).at(rank);
                
                string k = key(partner, friendOfPartner);
                ranks[k] = rank;
            }
        }
        
        // find unhappy friends
        unordered_set<int> unhappy;
        
        for(int i = 0; i < pairs.size(); i++){
            int x = pairs.at(i).at(0), y = pairs.at(i).at(1);
            
            for(int j = i + 1; j < pairs.size(); j++){
                int u = pairs.at(j).at(0), v = pairs.at(j).at(1);
                
                if(prefersOver(x, u, y) && prefersOver(u, x, v)){
                    unhappy.insert(x);
                    unhappy.insert(u);
                }
                
                if(prefersOver(x, v, y) && prefersOver(v, x, u)){
                    unhappy.insert(x);
                    unhappy.insert(v);
                }
                
                if(prefersOver(y, u, x) && prefersOver(u, y, v)){
                    unhappy.insert(y);
                    unhappy.insert(u);
                }
                
                if(prefersOver(y, v, x) && prefersOver(v, y, u)){
                    unhappy.insert(y);
                    unhappy.insert(v);
                }
            }
        }
        
        return unhappy.size();
    }
};