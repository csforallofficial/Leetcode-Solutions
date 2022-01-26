class Solution {
public:
    multiset<int>ms;
    
    void func(TreeNode * root){
        if(root == NULL){
            return;
        }
        
        ms.insert(root->val);
        func(root->left);
        func(root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        
        func(root1);
        func(root2);
        
        for(int x: ms){
            ans.push_back(x);
        }
        
        return ans;
    }
};