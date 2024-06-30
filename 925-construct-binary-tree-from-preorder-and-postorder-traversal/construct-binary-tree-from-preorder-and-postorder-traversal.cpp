class Solution {
public:
    int search(vector<int>& post, int start, int end, int element){
        for(int i = start; i <= end; i++){
            if(post[i] == element)
                return i;
        }
        return -1;
    }
    
    int preIndex = 0;
    
    TreeNode* solve(vector<int>& pre, vector<int>& post, int start, int end){
        // base case
        if(start > end || preIndex >= pre.size())
            return NULL;
        
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if(preIndex >= pre.size() || start == end)
            return root;
        int pos = search(post, start, end, pre[preIndex]);
        
        root->left = solve(pre, post, start, pos);
        root->right = solve(pre, post, pos + 1, end - 1);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = preorder.size();
        return solve(preorder, postorder, 0, n - 1);
    }
};