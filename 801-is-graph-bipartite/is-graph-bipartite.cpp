class Solution {
public:
    bool helper(vector<vector<int>>& adj,vector<int>&color, int start) {
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto v:adj[node]){
                if(color[v]==-1){
                    color[v]=!color[node];
                    q.push(v);
                }
                else if(color[v]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n+10,-1);
        vector<vector<int>>adj(n+10);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(helper(adj,color,i)==false) return false;
            }
        }
        return true;
    }
};