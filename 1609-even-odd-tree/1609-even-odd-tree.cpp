/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return true;
        if(root->val%2==0) return false;
        queue<TreeNode*> q;
        q.push(root);
        int currLev=-1; 
        while(!q.empty()){
            TreeNode* temp=q.front();
            int size=q.size();
            currLev++;
             int val;
                if(currLev%2==0){
                    val=INT_MIN;
                }
                else{
                    val=INT_MAX;
                }
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
               
                if(currLev%2==0){
                    if(temp->val%2==1 and temp->val>val){
                        val=temp->val;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(temp->val%2==0 and temp->val<val){
                        val=temp->val;
                    }
                    else{
                        return false;
                    }
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
        }
        return true;
    }
};