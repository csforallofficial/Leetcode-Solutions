class Solution {
public:
    int findmin(vector<int>& prices, int curr, int index){
        if(index == prices.size()){
            return 0;
        }
        if(prices[index] <= prices[curr]){
            return prices[index];
        }
        return findmin(prices, curr, index + 1);
    }
    
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> disprices;
        
        for(int i=0; i<prices.size(); i++){
            int v = findmin(prices, i, i + 1);
            disprices.push_back(prices[i] - v);
        }
        
        return disprices;
    }
};