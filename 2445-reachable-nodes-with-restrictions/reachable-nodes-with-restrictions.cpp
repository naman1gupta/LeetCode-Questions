class Solution {
public:
    int dfs(int i, int from, vector<vector<int>> &al) {
        return accumulate(begin(al[i]), end(al[i]), 1, [&](int s, int j){ 
            return s + (j == from ? 0 : dfs(j, i, al));
        });
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> al(n);
        unordered_set<int> rs(begin(restricted), end(restricted));      
        for (auto &e : edges)
            if (rs.count(e[0]) + rs.count(e[1]) == 0) {
                al[e[0]].push_back(e[1]);
                al[e[1]].push_back(e[0]);
            }
        return dfs(0, 0, al);
}
};