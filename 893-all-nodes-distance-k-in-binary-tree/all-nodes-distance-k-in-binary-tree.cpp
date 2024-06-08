/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void BuildGraph(TreeNode* root, unordered_map<int, vector<int>> &graph){
        if(root == nullptr){
            return;
        }
        
        int val = root->val;
        
        if(root->left){
            int left = root->left->val;
            graph[val].emplace_back(left);
            graph[left].emplace_back(val);
        }
        
        if(root->right){
            int right = root->right->val;
            graph[val].emplace_back(right);
            graph[right].emplace_back(val);
        }
        
        BuildGraph(root->left, graph);
        BuildGraph(root->right, graph);
    }    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == nullptr || target == nullptr || K < 0){
            return {};
        }
        
        if(K == 0){
            return {target->val};
        }
        
        // Build Graph
        unordered_map<int, vector<int>> graph;
        BuildGraph(root, graph);
        
        // Run BFS to find target nodes
        unordered_set<int> visited;
        
        queue<pair<int, int>> q;
        q.emplace(make_pair(target->val, 0));
        
        vector<int> result;
        
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            visited.insert(curr.first);
            
            for(auto &neighbor : graph[curr.first]){
                if(visited.count(neighbor) == 0){
                    int distance = curr.second + 1;
                    if(distance == K){
                        result.emplace_back(neighbor);
                    }
                    else if(distance < K){
                        q.emplace(make_pair(neighbor, distance));
                    }
                }
            }
        }
        
        return result;
    } 
};