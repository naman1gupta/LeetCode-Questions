class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int& minChange, int currCity) {
        visited[currCity] = true;
        for (auto neighbourCity : adj[currCity]) {
            if (!visited[neighbourCity.first]) {
                if (neighbourCity.second == 1)
                    minChange++;
                dfs(adj, visited, minChange, neighbourCity.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto connection : connections) {
            adj[connection[0]].push_back({connection[1], 1}); // city away from 0
            adj[connection[1]].push_back({connection[0], -1}); // city toward 0
        }
        vector<bool> visited(n, false);
        int minChange = 0;
        dfs(adj, visited, minChange, 0);
        return minChange;
    }
};