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
    vector<int> largestValues(TreeNode* root) {
        int i,j,k,c=0;
        queue<TreeNode*>q;
        vector<int>ans;
        if(!root)
            return ans;
        q.push(root);
        while(!q.empty()){
            int ll=q.size(),m=INT_MIN;
            while(ll >0){
                TreeNode* curr=q.front();
                q.pop();
                ll--;
                m=max(m,curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(m);
        }
        return ans;
    }
};