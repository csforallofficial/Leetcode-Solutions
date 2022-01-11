#include<string>

class Solution {
public:
    void BinarySum(TreeNode* root , string &binary , int &sum){
        if(root == NULL)
            return;
        
        //adds root value to string
        binary+= to_string(root->val);
        
        //make recursive calls in left
        BinarySum(root->left , binary ,sum);
        
        //on leaf node , add the sum
        if(root->left == NULL && root->right == NULL){
            //converts binary to decimal
            bitset<64> bits(binary);
            int number = bits.to_ulong();
            //adds the sum
            sum+=number;
            
            //pops last character from string when we backtrack
            binary.pop_back();
            return;
        }
        
        
        BinarySum(root->right , binary ,sum);
        binary.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        string binary="";
        int sum = 0;
        
        BinarySum(root , binary , sum);
        return sum;
    }
};