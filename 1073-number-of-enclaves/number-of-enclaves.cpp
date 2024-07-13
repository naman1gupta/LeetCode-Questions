class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and grid[i][j]==1) q.push({i,j});
            }
        }
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            vis[x][y]=true;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==1 and !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1 and !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};