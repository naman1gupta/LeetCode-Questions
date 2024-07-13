class Solution {
public:
vector<vector<int>> adj;
vector<bool>visited;

    void dfs(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u);
        }
    }
    int connected_components(int n){
        int cc=0;
        for(int u=1;u<=n;u++){
            if(!visited[u]){
                dfs(u);
                cc++;
            }
        }
        return cc;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        adj.resize(isConnected.size()+10);visited.resize(isConnected.size()+10,false);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        return connected_components(isConnected.size());
    }
};