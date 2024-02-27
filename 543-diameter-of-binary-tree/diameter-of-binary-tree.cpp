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
    int ans=0;
    int dfs(TreeNode* root){
        if (root==NULL) return 0;
     
        int r=dfs(root->right);
        
        int l=dfs(root->left);
        
        ans=max(ans, l+r);
        return 1+max(l, r); 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }

};