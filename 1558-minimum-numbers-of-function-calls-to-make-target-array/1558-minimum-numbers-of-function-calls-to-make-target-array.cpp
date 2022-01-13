class Solution {
public:
    pair<int, int> Count(int num){
        int add = 0, mul = 0;
        while(num){
            if(num & 1){
                num--;
                add++;
            }
            else{
                mul++;
                num >>= 1;
            }
        }
        return {add, mul};
    }
    int minOperations(vector<int>& nums) {
        int add = 0, maxmul = 0;
        for(int num: nums){
            auto [tadd, tmul] = Count(num);
            add += tadd;
            maxmul = max(maxmul, tmul);
        }
        return add + maxmul;
    }
};