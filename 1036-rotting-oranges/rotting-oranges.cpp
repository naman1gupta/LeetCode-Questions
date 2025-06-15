class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int countfresh = 0;
        int count=0;
        int minutes = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({i,j});
                }else{
                    visited[i][j]=0;
                }
                if(grid[i][j]==1){
                    countfresh++;
                }
            }
        }
        while(!q.empty()){
            int arr1[]={-1,0,1,0};
            int arr2[]={0,1,0,-1};
            int size = q.size();
            bool is = false;
            while(size--){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + arr1[i];
                int ncol = col + arr2[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    visited[nrow][ncol]=2;
                    count++;
                    q.push({nrow,ncol});
                    is = true;
                }
            }
            
            }
            if(is)minutes++;
        }
        if(count!=countfresh)return -1;
     return minutes;
    }
};